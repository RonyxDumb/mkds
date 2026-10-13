/* Decompiled C draft; module arm9; ROM address 020e35a0. No matching claim. */
#include "types.h"
#include "deps/020e35a0_func_020e35a0.h"

void func_020e35a0(int param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0xacU & 3;
  uVar3 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar2 = puRam020e35e0;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e35dc;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
  return;
}

