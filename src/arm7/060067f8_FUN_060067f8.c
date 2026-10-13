/* Decompiled C draft; module arm7; ROM address 060067f8. No matching claim. */
#include "types.h"
#include "deps/060067f8_FUN_060067f8.h"

void FUN_060067f8(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (*(short *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 10) {
    FUN_06007b28();
  }
  return;
}

