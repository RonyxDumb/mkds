/* Decompiled C draft; module arm9; ROM address 02124ed0. No matching claim. */
#include "types.h"
#include "deps/02124ed0_func_02124ed0.h"

void func_02124ed0(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(ushort *)(param_2 + 6);
  if (param_3 != 0) {
    uVar2 = uVar2 + *(ushort *)(param_3 + 6) & 0xffff;
  }
  uVar1 = Mem_AllocateHeap(param_1,uVar2 << 6);
  *param_4 = uVar1;
  func_02124efc(*param_4,uVar2);
  return;
}

