/* Decompiled C draft; module arm9; ROM address 020162b0. No matching claim. */
#include "types.h"
#include "deps/020162b0_func_020162b0.h"

void func_020162b0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = puRam020162c8;
  uVar1 = (uint)(puRam020162c8 + 2) & 3;
  uVar3 = *(uint *)((uint)(puRam020162c8 + 2) & 0xfffffffc);
  *puRam020162c8 = 0;
  puVar2[1] = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  return;
}

