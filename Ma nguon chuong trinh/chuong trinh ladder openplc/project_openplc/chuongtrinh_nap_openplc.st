PROGRAM program0
  VAR
    van1 AT %QX100.0 : BOOL;
    quat1 AT %QX100.1 : BOOL;
    den1 AT %QX100.2 : BOOL;
    van2 AT %QX100.3 : BOOL;
    quat2 AT %QX100.4 : BOOL;
    den2 AT %QX100.5 : BOOL;
    cambien1 AT %IW100 : UINT;
    cambien2 AT %IW101 : UINT;
    set_nhietdo AT %MW7 : UINT;
    set_doam AT %MW8 : UINT;
    set_van1 AT %MW1 : UINT;
    set_manual AT %MW9 : UINT;
    set_van2 AT %MW2 : UINT;
    set_den1 AT %MW3 : UINT;
    set_den2 AT %MW4 : UINT;
    set_quat1 AT %MW5 : UINT;
    set_quat2 AT %MW6 : UINT;
  END_VAR
  VAR_TEMP
    temp_manual : BOOL;
    temp_van1 : BOOL;
    temp_van2 : BOOL;
    temp_den1 : BOOL;
    temp_den2 : BOOL;
    temp_quat1 : BOOL;
    temp_quat2 : BOOL;
    temp_nhietdo : BOOL;
    temp_doam : BOOL;
    temp_MUL_nhietdo : UINT;
    temp_cambien2_udint : UDINT;
    temp_MUL_doam : UDINT;
  END_VAR
  VAR
    result_nhietdo AT %MW10 : UINT;
    result_doam AT %MW11 : UINT;
  END_VAR
  VAR_TEMP
    temp_result_doam_udint : UDINT;
  END_VAR
  VAR
    time_bat_den AT %MW12 : UINT;
  END_VAR
  VAR_TEMP
    temp_time_bat_den : TIME;
    temp_time_bat_den_delay : TIME;
  END_VAR
  VAR
    time_bat_den_delay AT %MW13 : UINT;
  END_VAR
  VAR_TEMP
    temp_start_stop : BOOL;
  END_VAR
  VAR
    start_stop AT %MW14 : UINT;
  END_VAR
  VAR
    TON0 : TON;
    TON1 : TON;
    temp_on1 : BOOL;
    temp_on0 : BOOL;
    UINT_TO_BOOL6_OUT : BOOL;
    UINT_TO_BOOL2_OUT : BOOL;
    UINT_TO_BOOL5_OUT : BOOL;
    UINT_TO_BOOL11_OUT : BOOL;
    UINT_TO_BOOL14_OUT : BOOL;
    UINT_TO_BOOL17_OUT : BOOL;
    UINT_TO_BOOL20_OUT : BOOL;
    UINT_TO_BOOL59_OUT : BOOL;
    MUL70_OUT : UINT;
    DIV74_OUT : UINT;
    UINT_TO_UDINT121_OUT : UDINT;
    MUL78_OUT : UDINT;
    DIV82_OUT : UDINT;
    UDINT_TO_UINT122_OUT : UINT;
    GT22_OUT : BOOL;
    LT26_OUT : BOOL;
    UINT_TO_TIME89_OUT : TIME;
    UINT_TO_TIME92_OUT : TIME;
  END_VAR

  UINT_TO_BOOL6_OUT := UINT_TO_BOOL(set_manual);
  temp_manual := UINT_TO_BOOL6_OUT;
  UINT_TO_BOOL2_OUT := UINT_TO_BOOL(set_den1);
  temp_den1 := UINT_TO_BOOL2_OUT;
  UINT_TO_BOOL5_OUT := UINT_TO_BOOL(set_den2);
  temp_den2 := UINT_TO_BOOL5_OUT;
  UINT_TO_BOOL11_OUT := UINT_TO_BOOL(set_quat1);
  temp_quat1 := UINT_TO_BOOL11_OUT;
  UINT_TO_BOOL14_OUT := UINT_TO_BOOL(set_quat2);
  temp_quat2 := UINT_TO_BOOL14_OUT;
  UINT_TO_BOOL17_OUT := UINT_TO_BOOL(set_van1);
  temp_van1 := UINT_TO_BOOL17_OUT;
  UINT_TO_BOOL20_OUT := UINT_TO_BOOL(set_van2);
  temp_van2 := UINT_TO_BOOL20_OUT;
  UINT_TO_BOOL59_OUT := UINT_TO_BOOL(start_stop);
  temp_start_stop := UINT_TO_BOOL59_OUT;
  MUL70_OUT := MUL(cambien1, 50);
  temp_MUL_nhietdo := MUL70_OUT;
  DIV74_OUT := DIV(temp_MUL_nhietdo, 1024);
  result_nhietdo := DIV74_OUT;
  UINT_TO_UDINT121_OUT := UINT_TO_UDINT(cambien2);
  temp_cambien2_udint := UINT_TO_UDINT121_OUT;
  MUL78_OUT := MUL(temp_cambien2_udint, 100);
  temp_MUL_doam := MUL78_OUT;
  DIV82_OUT := DIV(temp_MUL_doam, 1024);
  temp_result_doam_udint := DIV82_OUT;
  UDINT_TO_UINT122_OUT := UDINT_TO_UINT(temp_result_doam_udint);
  result_doam := UDINT_TO_UINT122_OUT;
  GT22_OUT := GT(result_nhietdo, set_nhietdo);
  temp_nhietdo := GT22_OUT;
  LT26_OUT := LT(result_doam, set_doam);
  temp_doam := LT26_OUT;
  UINT_TO_TIME89_OUT := UINT_TO_TIME(time_bat_den);
  temp_time_bat_den := UINT_TO_TIME89_OUT;
  UINT_TO_TIME92_OUT := UINT_TO_TIME(time_bat_den_delay);
  temp_time_bat_den_delay := UINT_TO_TIME92_OUT;
  TON0(IN := NOT(temp_on1), PT := temp_time_bat_den);
  temp_on0 := TON0.Q;
  TON1(IN := temp_on0, PT := temp_time_bat_den_delay);
  temp_on1 := TON1.Q;
  quat1 := (NOT(temp_manual) AND temp_nhietdo OR temp_quat1 AND temp_manual) AND temp_start_stop;
  quat2 := (NOT(temp_manual) AND temp_nhietdo OR temp_quat2 AND temp_manual) AND temp_start_stop;
  van1 := (NOT(temp_manual) AND temp_doam OR temp_van1 AND temp_manual) AND temp_start_stop;
  van2 := (NOT(temp_manual) AND temp_doam OR temp_van2 AND temp_manual) AND temp_start_stop;
  den1 := (NOT(temp_manual) AND NOT(temp_on0) OR temp_den1 AND temp_manual) AND temp_start_stop;
  den2 := (NOT(temp_manual) AND NOT(temp_on0) OR temp_den2 AND temp_manual) AND temp_start_stop;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
