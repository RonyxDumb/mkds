/* Decompiled C draft; module arm9; ROM address 0214cc94. No matching claim. */
#include "types.h"
#include "deps/0214cc94_func_0214cc94.h"

void func_0214cc94(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  code *pcVar4;
  
  puVar2 = puRam0214ccd0;
  uVar1 = (uint)(puRam0214ccd0 + 4) & 3;
  uVar3 = *(uint *)((uint)(puRam0214ccd0 + 4) & 0xfffffffc);
  pcVar4 = (code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *puRam0214ccd0 = 0;
  uVar1 = (uint)(puVar2 + 5) & 3;
  uVar3 = *(uint *)((uint)(puVar2 + 5) & 0xfffffffc);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

