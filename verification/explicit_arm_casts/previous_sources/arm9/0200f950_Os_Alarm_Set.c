/* Decompiled C draft; module arm9; ROM address 0200f950. No matching claim. */
#include "types.h"
#include "deps/0200f950_Os_Alarm_Set.h"

void Os_Alarm_Set(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  longlong lVar2;
  
  if ((param_1 == (undefined4 *)0x0) ||
     (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 != 0 ||
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 != 0)) {
    Os_Terminate();
  }
  uVar1 = Os_DisableIrq();
  param_1[7] = 0;
  param_1[8] = 0;
  *param_1 = param_4;
  param_1[1] = param_5;
  lVar2 = Os_GetTick();
  lVar2 = lVar2 + CONCAT44(param_3,param_2);
  Os_InsertAlarm(param_1,(int)lVar2,(int)((ulonglong)lVar2 >> 0x20));
  Os_RestoreIrq(uVar1);
  return;
}

