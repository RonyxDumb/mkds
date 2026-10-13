/* Decompiled C draft; module arm9; ROM address 020e49c0. No matching claim. */
#include "types.h"
#include "deps/020e49c0_func_020e49c0.h"

void func_020e49c0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0xb8U & 3;
  uVar3 = *(uint *)(param_1 + 0xb8U & 0xfffffffc);
  *(uint *)(param_1 + 4) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar2 = uRam020e4a14;
  uVar1 = param_1 + 0xc0U & 3;
  uVar3 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
  return;
}

