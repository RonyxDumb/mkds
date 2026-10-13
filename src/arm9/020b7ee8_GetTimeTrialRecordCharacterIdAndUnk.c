/* Decompiled C draft; module arm9; ROM address 020b7ee8. No matching claim. */
#include "types.h"
#include "deps/020b7ee8_GetTimeTrialRecordCharacterIdAndUnk.h"

void GetTimeTrialRecordCharacterIdAndUnk(undefined4 param_1,uint *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_30 [24];
  char local_18;
  byte bStack_17;
  
  uVar2 = *(uint *)(DAT_020b7fd4 & 0xfffffffc) >> (DAT_020b7fd4 & 3) * 8 |
          *(uint *)(DAT_020b7fd4 & 0xfffffffc) << (DAT_020b7fd4 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  TimeTrialRecord_CopyFrom_from_thumb
            (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_1,(int)(uintptr_t)(auStack_30));
  if (local_18 == '\0') {
    *param_2 = 0;
    *param_3 = 0;
    return;
  }
  *param_2 = (uint)bStack_17;
  switch(*(uint *)((uint)param_2 & 0xfffffffc) >> ((uint)param_2 & 3) * 8 |
         *(uint *)((uint)param_2 & 0xfffffffc) << ((uint)param_2 & 3) * -8 + 0x20) {
  case 0:
    break;
  case 1:
    goto LAB_020b7f98;
  case 2:
    break;
  case 3:
    goto LAB_020b7f98;
  case 4:
    goto LAB_020b7fac;
  case 5:
LAB_020b7fac:
    *param_3 = 9;
    return;
  case 6:
    goto LAB_020b7fc0;
  case 7:
LAB_020b7fc0:
    *param_3 = 10;
switchD_020b7f48_default:
    return;
  case 8:
    break;
  case 9:
LAB_020b7f98:
    *param_3 = 8;
    return;
  case 10:
    break;
  case 0xb:
    break;
  case 0xc:
  default:
    goto switchD_020b7f48_default;
  }
  *param_3 = 7;
  return;
}

