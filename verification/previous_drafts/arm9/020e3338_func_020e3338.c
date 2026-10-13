/* Decompiled C draft; module arm9; ROM address 020e3338. No matching claim. */
#include "types.h"
#include "deps/020e3338_func_020e3338.h"

void func_020e3338(int param_1)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  
  uVar1 = param_1 + 0xacU & 3;
  uVar3 = *(uint *)(param_1 + 0xacU & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar2 = puRam020e3378;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020e3374;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
  return;
}

