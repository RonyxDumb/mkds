/* Decompiled C draft; module arm7; ROM address 037f9028. No matching claim. */
#include "types.h"
#include "deps/037f9028_FUN_037f9028.h"

void FUN_037f9028(void)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  uVar2 = DAT_037f9050 + 8U & 3;
  uVar1 = *(uint *)(DAT_037f9050 + 8U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  while( true ) {
    if (uVar2 == 0) {
      return;
    }
    uVar1 = uVar2 + 0x48 & 3;
    uVar3 = *(uint *)(uVar2 + 0x48 & 0xfffffffc);
    if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) break;
    uVar1 = uVar2 + 0x4c & 3;
    uVar2 = *(uint *)(uVar2 + 0x4c & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  }
  return;
}

