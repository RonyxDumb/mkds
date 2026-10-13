/* Decompiled C draft; module arm9; ROM address 02080e88. No matching claim. */
#include "types.h"
#include "deps/02080e88_func_02080e88.h"

void func_02080e88(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0xc4U & 3;
  uVar2 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  *(int *)(param_1 + 0x6c) =
       (int)(short)((ushort)(uVar2 >> uVar1 * 8) | (ushort)(uVar2 << uVar1 * -8 + 0x20));
  return;
}

