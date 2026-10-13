/* Decompiled C draft; module arm9; ROM address 020250a8. No matching claim. */
#include "types.h"
#include "deps/020250a8_func_020250a8.h"

void func_020250a8(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FX_Div(0x1000,*(uint *)(uRam02025104 & 0xfffffffc) >> (uRam02025104 & 3) * 8 |
                        *(uint *)(uRam02025104 & 0xfffffffc) << (uRam02025104 & 3) * -8 + 0x20);
  uVar1 = uRam02025108 & 3;
  uVar3 = *(uint *)(uRam02025108 & 0xfffffffc);
  *puRam0202510c = uVar2;
  uVar2 = FX_Div(0x1000,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = uRam02025110 & 3;
  uVar3 = *(uint *)(uRam02025110 & 0xfffffffc);
  *puRam02025114 = uVar2;
  uVar2 = FX_Div(0x1000,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *puRam02025118 = uVar2;
  return;
}

