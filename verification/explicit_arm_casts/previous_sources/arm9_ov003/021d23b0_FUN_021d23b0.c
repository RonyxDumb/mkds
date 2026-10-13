/* Decompiled C draft; module arm9_ov003; ROM address 021d23b0. No matching claim. */
#include "types.h"
#include "deps/021d23b0_FUN_021d23b0.h"

int FUN_021d23b0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5,
                int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  
  iVar1 = FUN_021d1cd4(*(undefined4 *)(*DAT_021d243c + DAT_021d2440));
  *(char *)(iVar1 + 0x36) = (char)param_2;
  *(char *)(iVar1 + 0x37) = (char)param_3;
  uVar2 = FUN_021d309c(param_1,param_3 * param_2,param_4,&local_18);
  *(undefined4 *)(iVar1 + 0x30) = uVar2;
  *(short *)(iVar1 + 0x34) = (short)local_18;
  uVar2 = func_0x020231e4(param_2,param_3);
  *param_5 = uVar2;
  iVar3 = DAT_021d2448;
  if (param_1 == 1) {
    iVar3 = DAT_021d2444;
  }
  func_0x02023374(iVar1,iVar3 + local_18 * 0x80,param_2,param_3,4);
  (**(code **)(iVar1 + 0x18))(iVar1,0);
  iVar3 = *DAT_021d243c;
  *(int *)(iVar1 + 0x20) = iVar1;
  *(int *)(iVar1 + 0x24) = iVar3 + param_6 * 0xc;
  *(undefined4 *)(iVar1 + 0x28) = 1;
  *(undefined4 *)(iVar1 + 0x2c) = 1;
  return iVar1;
}

