/* Decompiled C draft; module arm9_ov003; ROM address 021d2658. No matching claim. */
#include "types.h"
#include "deps/021d2658_FUN_021d2658.h"

void FUN_021d2658(int param_1,int param_2,short *param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  
  uVar3 = (ushort)DAT_021d2708;
  if (param_1 != 1) {
    if (param_2 == 0) {
      uVar1 = param_3[3];
      sVar2 = param_3[1];
      *DAT_021d271c = *param_3 << 8 & uVar3 | param_3[2] & 0xffU;
      *DAT_021d2720 = sVar2 << 8 & uVar3 | uVar1 & 0xff;
      return;
    }
    uVar1 = param_3[3];
    sVar2 = param_3[1];
    *DAT_021d2724 = *param_3 << 8 & uVar3 | param_3[2] & 0xffU;
    *DAT_021d2728 = sVar2 << 8 & uVar3 | uVar1 & 0xff;
    return;
  }
  if (param_2 == 0) {
    uVar1 = param_3[3];
    sVar2 = param_3[1];
    *DAT_021d270c = *param_3 << 8 & uVar3 | param_3[2] & 0xffU;
    *DAT_021d2710 = sVar2 << 8 & uVar3 | uVar1 & 0xff;
    return;
  }
  uVar1 = param_3[3];
  sVar2 = param_3[1];
  *DAT_021d2714 = *param_3 << 8 & uVar3 | param_3[2] & 0xffU;
  *DAT_021d2718 = sVar2 << 8 & uVar3 | uVar1 & 0xff;
  return;
}

