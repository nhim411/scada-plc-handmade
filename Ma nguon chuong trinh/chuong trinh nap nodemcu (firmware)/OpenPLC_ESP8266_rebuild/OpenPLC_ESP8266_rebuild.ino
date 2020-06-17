#include <SimpleKalmanFilter.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>//AP IP address: 192.168.244.1
#include "modbus.h"

SimpleKalmanFilter bo_loc(2, 2, 0.001); //Khai báo hàm thuật toán Kalman

#define NODE_PIN_D0		16
#define NODE_PIN_D1		5
#define NODE_PIN_D2		4
#define NODE_PIN_D3		0
#define NODE_PIN_D4		2
#define NODE_PIN_D5		14
#define NODE_PIN_D6		12
#define NODE_PIN_D7		13
#define NODE_PIN_D8		15

uint8_t pinMask_DIN[] = { NODE_PIN_D4, NODE_PIN_D5, NODE_PIN_D6, NODE_PIN_D7 };
uint8_t pinMask_DOUT[] = { NODE_PIN_D0, NODE_PIN_D1, NODE_PIN_D2, NODE_PIN_D3 };
uint8_t pinMask_AIN[] = { A0 };
uint8_t pinMask_AOUT[] = { NODE_PIN_D8 };

unsigned char modbus_buffer[100];

int processModbusMessage(unsigned char *buffer, int bufferSize);



extern bool mb_discrete_input[MAX_DISCRETE_INPUT];
extern bool mb_coils[MAX_COILS];
extern uint16_t mb_input_regs[MAX_INP_REGS];
extern uint16_t mb_holding_regs[MAX_HOLD_REGS];

//Create the modbus server instance
WiFiServer server(502);

void pinConfig()
{
  pinMode(NODE_PIN_D0, OUTPUT);
  pinMode(NODE_PIN_D1, OUTPUT);
  pinMode(NODE_PIN_D2, OUTPUT);
  pinMode(NODE_PIN_D3, OUTPUT);
  pinMode(NODE_PIN_D4, INPUT);
  pinMode(NODE_PIN_D5, INPUT);
  pinMode(NODE_PIN_D6, INPUT);
  pinMode(NODE_PIN_D7, INPUT);

  pinMode(NODE_PIN_D8, OUTPUT);
}

const char* serverName = "http://lhnam.000webhostapp.com/plc_ip_address.php";
String apiKeyValue = "abc123"; //Chuỗi key xác thực
String device = "NODEMCU-PLC3";  // Têm thiết bị

void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFiManager wifiManager;
  //ifiManager.resetSettings();//reset settings - for testing
  if (!wifiManager.autoConnect("NODEMCU-PLC3")) {
    Serial.println("failed to connect, we should reset as see if it connects");
    delay(3000);
    ESP.reset();
    delay(5000);
  }
  //Kết nối thành công
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP());
  String ip = WiFi.localIP().toString();
  Serial.println(ip);
  
  //gửi IP Address đến server để lưu vào SQL
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    String httpRequestData = "api_key=" + apiKeyValue + "&device=" + device + "&value=" + ip + "";
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);
    // Send HTTP POST request
    int httpResponseCode = http.POST(httpRequestData);
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  // Start the server
  server.begin();
  Serial.println("Server started");

  pinConfig();
  updateIO();
}

void PrintHex(uint8_t *data, uint8_t length) // prints 8-bit data in hex with leading zeroes
{
  for (int i = 0; i < length; i++)
  {
    if (data[i] < 0x10)
      Serial.print("0");
    Serial.print(data[i], HEX); Serial.print(" ");
  }
  Serial.println();
}

void updateIO()
{
  for (int i = 0; i < sizeof(pinMask_DIN); i++)
  {
    mb_discrete_input[i] = digitalRead(pinMask_DIN[i]);
  }

  for (int i = 0; i < sizeof(pinMask_DOUT); i++)
  {
    digitalWrite(pinMask_DOUT[i], mb_coils[i]);
  }

  for (int i = 0; i < sizeof(pinMask_AIN); i++)
  {
    
    mb_input_regs[i] = bo_loc.updateEstimate((analogRead(pinMask_AIN[i])));
  }

  for (int i = 0; i < sizeof(pinMask_AOUT); i++)
  {
    analogWrite(pinMask_AOUT[i], mb_holding_regs[i]);
  }
}

void loop()
{
  WiFiClient client = server.available();
  if (!client)
    return;

  Serial.println("new client!");

  while (client.connected())
  {
    // Wait until the client sends some data
    while (!client.available())
    {
      delay(1);
      if (!client.connected())
        return;
    }

    int i = 0;
    while (client.available())
    {
      modbus_buffer[i] = client.read();
      i++;
      if (i == 100)
        break;
    }

    //DEBUG
    /*
      Serial.print("Received MB frame: ");
      PrintHex(modbus_buffer, i);
    */

    updateIO();
    unsigned int return_length = processModbusMessage(modbus_buffer, i);
    client.write((const uint8_t *)modbus_buffer, return_length);
    updateIO();
    delay(1);
  }

  Serial.println("Client disonnected");
  delay(1);
}
