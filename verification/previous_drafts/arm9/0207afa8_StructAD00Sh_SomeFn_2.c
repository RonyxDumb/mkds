/* Decompiled C draft; module arm9; ROM address 0207afa8. No matching claim. */
#include "types.h"
#include "deps/0207afa8_StructAD00Sh_SomeFn_2.h"

uint StructAD00Sh_SomeFn_2(int param_1,undefined4 param_2,undefined2 param_3)

{
  uint uVar1;
  uint uVar2;
  
  Model_CreateFromNsbmd();
  uVar2 = param_1 + 4U & 3;
  uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0x6c) = param_3;
  *(undefined2 *)(param_1 + 0x6e) = 0xd;
  *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) | 1;
  ModelBlock_SomeTexPltFn_8(uVar2,0,3);
  func_02013588(uVar2,0,0);
  uVar2 = param_1 + 4U & 3;
  uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
  return uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
}

