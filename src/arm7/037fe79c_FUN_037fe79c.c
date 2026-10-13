/* Decompiled C draft; module arm7; ROM address 037fe79c. No matching claim. */
#include "types.h"
#include "deps/037fe79c_FUN_037fe79c.h"

uint FUN_037fe79c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = param_1 + 0x28U & 3;
  uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar2 = FUN_037fe7ec(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  iVar4 = FUN_037fe7ec(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  return (uVar2 | iVar4 << 8) & 0xffff;
}

