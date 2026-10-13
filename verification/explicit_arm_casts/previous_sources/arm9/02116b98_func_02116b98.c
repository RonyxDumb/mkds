/* Decompiled C draft; module arm9; ROM address 02116b98. No matching claim. */
#include "types.h"
#include "deps/02116b98_func_02116b98.h"

void func_02116b98(ushort *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_38 [36];
  
  func_02116ce8((char)param_1[1]);
  iVar1 = 1;
  if (9 < (byte)param_1[1]) {
    iVar1 = 2;
  }
  func_02116ccc(param_2 + iVar1 * 2,param_3);
  func_02116ce8(*(undefined1 *)((int)param_1 + 3),auStack_38,param_3);
  if (*(byte *)((int)param_1 + 3) < 10) {
    func_02116cb0(param_2 + ((uint)((iVar1 + 1) * 0x10000) >> 0xf),param_3);
    CopyMemory16(auStack_38,param_2 + ((uint)((iVar1 + 2) * 0x10000) >> 0xf),2);
  }
  else {
    CopyMemory16(auStack_38,param_2 + ((uint)((iVar1 + 1) * 0x10000) >> 0xf),4);
  }
  func_02116ccc(param_2 + (iVar1 + 3) * 2,param_3);
  func_02116ce8(*param_1,auStack_38,param_3);
  if (*param_1 < 100) {
    if (*param_1 < 10) {
      func_02116cb0(param_2 + ((uint)((iVar1 + 4) * 0x10000) >> 0xf),param_3);
      func_02116cb0(param_2 + ((uint)((iVar1 + 5) * 0x10000) >> 0xf),param_3);
      CopyMemory16(auStack_38,param_2 + ((uint)((iVar1 + 6) * 0x10000) >> 0xf),2);
    }
    else {
      func_02116cb0(param_2 + ((uint)((iVar1 + 4) * 0x10000) >> 0xf),param_3);
      CopyMemory16(auStack_38,param_2 + ((uint)((iVar1 + 5) * 0x10000) >> 0xf),4);
    }
  }
  else {
    CopyMemory16(auStack_38,param_2 + ((uint)((iVar1 + 4) * 0x10000) >> 0xf),6);
  }
  *(undefined2 *)(param_2 + (iVar1 + 7) * 2) = 0;
  return;
}

