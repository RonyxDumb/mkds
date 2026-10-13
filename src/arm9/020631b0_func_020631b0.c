/* Decompiled C draft; module arm9; ROM address 020631b0. No matching claim. */
#include "types.h"
#include "deps/020631b0_func_020631b0.h"

void func_020631b0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0206321c & 0xfffffffc) >> (uRam0206321c & 3) * 8 |
          *(uint *)(uRam0206321c & 0xfffffffc) << (uRam0206321c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0x20) {
    func_02010fac(2,(int)*psRam02063220,(int)psRam02063220[1],(int)psRam02063220[2]);
    func_02010f98(2,uRam02063224);
    return;
  }
  return;
}

