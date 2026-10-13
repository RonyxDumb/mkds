/* Decompiled C draft; module arm9; ROM address 021241c0. No matching claim. */
#include "types.h"
#include "deps/021241c0_func_021241c0.h"

void func_021241c0(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  func_0201ea58(param_3);
  iVar2 = *(int *)(param_5 + (uint)*(ushort *)(param_4 + 6) * 0x40 + param_2 * 0x40 + 0x3c);
  (**(code **)(iVar2 + 0x18))(iVar2,0);
  uVar1 = *(undefined4 *)(iVar2 + 0x30);
  iVar4 = *(int *)(iVar2 + 0x38) * 0x20;
  uVar3 = *(undefined4 *)(iVar2 + 0x34);
  Arm_FlushRange(uVar1,uVar3);
  if (param_1 == 0) {
    AllocateReserveTEQSub(0x13,iVar4,uVar1,uVar3);
    return;
  }
  AllocateReserveTEQSub(0x23,iVar4,uVar1,uVar3);
  return;
}

