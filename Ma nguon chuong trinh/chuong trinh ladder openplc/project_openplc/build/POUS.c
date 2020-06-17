void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->VAN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUAT1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DEN1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VAN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->QUAT2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DEN2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAMBIEN1,0,retain)
  __INIT_VAR(data__->CAMBIEN2,0,retain)
  __INIT_VAR(data__->SET_NHIETDO,0,retain)
  __INIT_VAR(data__->SET_DOAM,0,retain)
  __INIT_VAR(data__->SET_VAN1,0,retain)
  __INIT_VAR(data__->SET_MANUAL,0,retain)
  __INIT_VAR(data__->SET_VAN2,0,retain)
  __INIT_VAR(data__->SET_DEN1,0,retain)
  __INIT_VAR(data__->SET_DEN2,0,retain)
  __INIT_VAR(data__->SET_QUAT1,0,retain)
  __INIT_VAR(data__->SET_QUAT2,0,retain)
  __INIT_VAR(data__->RESULT_NHIETDO,0,retain)
  __INIT_VAR(data__->RESULT_DOAM,0,retain)
  __INIT_VAR(data__->TIME_BAT_DEN,0,retain)
  __INIT_VAR(data__->TIME_BAT_DEN_DELAY,0,retain)
  __INIT_VAR(data__->START_STOP,0,retain)
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  __INIT_VAR(data__->TEMP_ON1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TEMP_ON0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL6_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL2_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL5_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL11_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL20_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_BOOL59_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MUL70_OUT,0,retain)
  __INIT_VAR(data__->DIV74_OUT,0,retain)
  __INIT_VAR(data__->UINT_TO_UDINT121_OUT,0,retain)
  __INIT_VAR(data__->MUL78_OUT,0,retain)
  __INIT_VAR(data__->DIV82_OUT,0,retain)
  __INIT_VAR(data__->UDINT_TO_UINT122_OUT,0,retain)
  __INIT_VAR(data__->GT22_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->LT26_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->UINT_TO_TIME89_OUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->UINT_TO_TIME92_OUT,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables
  __SET_VAR(data__->,TEMP_MANUAL,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_VAN1,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_VAN2,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_DEN1,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_DEN2,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_QUAT1,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_QUAT2,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_NHIETDO,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_DOAM,,__BOOL_LITERAL(FALSE));
  __SET_VAR(data__->,TEMP_MUL_NHIETDO,,0);
  __SET_VAR(data__->,TEMP_CAMBIEN2_UDINT,,0);
  __SET_VAR(data__->,TEMP_MUL_DOAM,,0);
  __SET_VAR(data__->,TEMP_RESULT_DOAM_UDINT,,0);
  __SET_VAR(data__->,TEMP_TIME_BAT_DEN,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  __SET_VAR(data__->,TEMP_TIME_BAT_DEN_DELAY,,__time_to_timespec(1, 0, 0, 0, 0, 0));
  __SET_VAR(data__->,TEMP_START_STOP,,__BOOL_LITERAL(FALSE));

  __SET_VAR(data__->,UINT_TO_BOOL6_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_MANUAL,)));
  __SET_VAR(data__->,TEMP_MANUAL,,__GET_VAR(data__->UINT_TO_BOOL6_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL2_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_DEN1,)));
  __SET_VAR(data__->,TEMP_DEN1,,__GET_VAR(data__->UINT_TO_BOOL2_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL5_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_DEN2,)));
  __SET_VAR(data__->,TEMP_DEN2,,__GET_VAR(data__->UINT_TO_BOOL5_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL11_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_QUAT1,)));
  __SET_VAR(data__->,TEMP_QUAT1,,__GET_VAR(data__->UINT_TO_BOOL11_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL14_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_QUAT2,)));
  __SET_VAR(data__->,TEMP_QUAT2,,__GET_VAR(data__->UINT_TO_BOOL14_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL17_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_VAN1,)));
  __SET_VAR(data__->,TEMP_VAN1,,__GET_VAR(data__->UINT_TO_BOOL17_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL20_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->SET_VAN2,)));
  __SET_VAR(data__->,TEMP_VAN2,,__GET_VAR(data__->UINT_TO_BOOL20_OUT,));
  __SET_VAR(data__->,UINT_TO_BOOL59_OUT,,UINT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->START_STOP,)));
  __SET_VAR(data__->,TEMP_START_STOP,,__GET_VAR(data__->UINT_TO_BOOL59_OUT,));
  __SET_VAR(data__->,MUL70_OUT,,MUL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->CAMBIEN1,),
    (UINT)50));
  __SET_VAR(data__->,TEMP_MUL_NHIETDO,,__GET_VAR(data__->MUL70_OUT,));
  __SET_VAR(data__->,DIV74_OUT,,DIV__UINT__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->TEMP_MUL_NHIETDO,),
    (UINT)1024));
  __SET_VAR(data__->,RESULT_NHIETDO,,__GET_VAR(data__->DIV74_OUT,));
  __SET_VAR(data__->,UINT_TO_UDINT121_OUT,,UINT_TO_UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->CAMBIEN2,)));
  __SET_VAR(data__->,TEMP_CAMBIEN2_UDINT,,__GET_VAR(data__->UINT_TO_UDINT121_OUT,));
  __SET_VAR(data__->,MUL78_OUT,,MUL__UDINT__UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UDINT)__GET_VAR(data__->TEMP_CAMBIEN2_UDINT,),
    (UDINT)100));
  __SET_VAR(data__->,TEMP_MUL_DOAM,,__GET_VAR(data__->MUL78_OUT,));
  __SET_VAR(data__->,DIV82_OUT,,DIV__UDINT__UDINT__UDINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->TEMP_MUL_DOAM,),
    (UDINT)1024));
  __SET_VAR(data__->,TEMP_RESULT_DOAM_UDINT,,__GET_VAR(data__->DIV82_OUT,));
  __SET_VAR(data__->,UDINT_TO_UINT122_OUT,,UDINT_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UDINT)__GET_VAR(data__->TEMP_RESULT_DOAM_UDINT,)));
  __SET_VAR(data__->,RESULT_DOAM,,__GET_VAR(data__->UDINT_TO_UINT122_OUT,));
  __SET_VAR(data__->,GT22_OUT,,GT__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->RESULT_NHIETDO,),
    (UINT)__GET_VAR(data__->SET_NHIETDO,)));
  __SET_VAR(data__->,TEMP_NHIETDO,,__GET_VAR(data__->GT22_OUT,));
  __SET_VAR(data__->,LT26_OUT,,LT__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->RESULT_DOAM,),
    (UINT)__GET_VAR(data__->SET_DOAM,)));
  __SET_VAR(data__->,TEMP_DOAM,,__GET_VAR(data__->LT26_OUT,));
  __SET_VAR(data__->,UINT_TO_TIME89_OUT,,UINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->TIME_BAT_DEN,)));
  __SET_VAR(data__->,TEMP_TIME_BAT_DEN,,__GET_VAR(data__->UINT_TO_TIME89_OUT,));
  __SET_VAR(data__->,UINT_TO_TIME92_OUT,,UINT_TO_TIME(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->TIME_BAT_DEN_DELAY,)));
  __SET_VAR(data__->,TEMP_TIME_BAT_DEN_DELAY,,__GET_VAR(data__->UINT_TO_TIME92_OUT,));
  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->TEMP_ON1,)));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->TEMP_TIME_BAT_DEN,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,TEMP_ON0,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->TEMP_ON0,));
  __SET_VAR(data__->TON1.,PT,,__GET_VAR(data__->TEMP_TIME_BAT_DEN_DELAY,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,TEMP_ON1,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->,QUAT1,,(((!(__GET_VAR(data__->TEMP_MANUAL,)) && __GET_VAR(data__->TEMP_NHIETDO,)) || (__GET_VAR(data__->TEMP_QUAT1,) && __GET_VAR(data__->TEMP_MANUAL,))) && __GET_VAR(data__->TEMP_START_STOP,)));
  __SET_VAR(data__->,QUAT2,,(((!(__GET_VAR(data__->TEMP_MANUAL,)) && __GET_VAR(data__->TEMP_NHIETDO,)) || (__GET_VAR(data__->TEMP_QUAT2,) && __GET_VAR(data__->TEMP_MANUAL,))) && __GET_VAR(data__->TEMP_START_STOP,)));
  __SET_VAR(data__->,VAN1,,(((!(__GET_VAR(data__->TEMP_MANUAL,)) && __GET_VAR(data__->TEMP_DOAM,)) || (__GET_VAR(data__->TEMP_VAN1,) && __GET_VAR(data__->TEMP_MANUAL,))) && __GET_VAR(data__->TEMP_START_STOP,)));
  __SET_VAR(data__->,VAN2,,(((!(__GET_VAR(data__->TEMP_MANUAL,)) && __GET_VAR(data__->TEMP_DOAM,)) || (__GET_VAR(data__->TEMP_VAN2,) && __GET_VAR(data__->TEMP_MANUAL,))) && __GET_VAR(data__->TEMP_START_STOP,)));
  __SET_VAR(data__->,DEN1,,(((!(__GET_VAR(data__->TEMP_MANUAL,)) && !(__GET_VAR(data__->TEMP_ON0,))) || (__GET_VAR(data__->TEMP_DEN1,) && __GET_VAR(data__->TEMP_MANUAL,))) && __GET_VAR(data__->TEMP_START_STOP,)));
  __SET_VAR(data__->,DEN2,,(((!(__GET_VAR(data__->TEMP_MANUAL,)) && !(__GET_VAR(data__->TEMP_ON0,))) || (__GET_VAR(data__->TEMP_DEN2,) && __GET_VAR(data__->TEMP_MANUAL,))) && __GET_VAR(data__->TEMP_START_STOP,)));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





