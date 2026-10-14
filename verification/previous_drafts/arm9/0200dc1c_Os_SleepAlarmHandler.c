/* Decompiled C draft; module arm9; ROM address 0200dc1c. No matching claim. */
#include "types.h"
#include "deps/0200dc1c_Os_SleepAlarmHandler.h"

void Os_SleepAlarmHandler(undefined4 *param_1)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  
  uVar1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  *param_1 = 0;
  UNRECOVERED_JUMPTABLE = pcRam0200dc38;
  *(undefined4 *)(uVar1 + 0xb0) = 0;
                    /* WARNING: Could not recover jumptable at 0x0200dc34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}

