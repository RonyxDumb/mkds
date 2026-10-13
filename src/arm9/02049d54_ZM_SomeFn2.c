/* Decompiled C draft; module arm9; ROM address 02049d54. No matching claim. */
#include "types.h"
#include "deps/02049d54_ZM_SomeFn2.h"

void ZM_SomeFn2(void)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar2 = (*(uint *)(uRam02049d88 & 0xfffffffc) >> (uRam02049d88 & 3) * 8 |
          *(uint *)(uRam02049d88 & 0xfffffffc) << (uRam02049d88 & 3) * -8 + 0x20) + 0x100;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)();
    return;
  }
  return;
}

