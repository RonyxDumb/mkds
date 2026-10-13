/* Decompiled C draft; module arm9; ROM address 02124b1c. No matching claim. */
#include "types.h"
#include "deps/02124b1c_func_02124b1c.h"

void func_02124b1c(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  
  iVar1 = FX_Div(uRam02124bc0,param_3);
  iVar2 = (int)*(short *)(iRam02124bc4 + ((param_2 >> 4) * 2 + 1) * 2);
  uVar5 = Multiply64(iVar2,iVar2 >> 0x1f,iVar1,iVar1 >> 0x1f);
  *(uint *)(param_1 + 0x14) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
  iVar3 = (int)*(short *)(iRam02124bc4 + (param_2 >> 4) * 4);
  uVar5 = Multiply64(iVar3,iVar3 >> 0x1f,iVar1,iVar1 >> 0x1f);
  *(uint *)(param_1 + 0x18) = (uint)uVar5 >> 0xc | (int)((ulonglong)uVar5 >> 0x20) << 0x14;
  *(int *)(param_1 + 0x1c) = -*(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x14);
  func_02146cb0((undefined4 *)(uintptr_t)(param_1 + 0x24),iVar3,iVar2);
  uVar4 = func_021488e8(*(undefined4 *)(param_1 + 0x24),param_3);
  *(undefined4 *)(param_1 + 0x24) = uVar4;
  uVar4 = func_021488e8(*(undefined4 *)(param_1 + 0x28),param_3);
  *(undefined4 *)(param_1 + 0x28) = uVar4;
  uVar4 = func_021488e8(*(undefined4 *)(param_1 + 0x2c),param_3);
  *(undefined4 *)(param_1 + 0x2c) = uVar4;
  uVar4 = func_021488e8(*(undefined4 *)(param_1 + 0x30),param_3);
  *(undefined4 *)(param_1 + 0x30) = uVar4;
  return;
}

