/* Decompiled C draft; module arm9; ROM address 020367c4. No matching claim. */
#include "types.h"
#include "deps/020367c4_VblankIRQHandler.h"

void VblankIRQHandler(void)

{
  uint uVar1;
  uint uVar3;
  code *pcVar2;
  
  if (*(uint *)(uRam02036818 & 0xfffffffc) >> (uRam02036818 & 3) * 8 != 0 ||
      *(uint *)(uRam02036818 & 0xfffffffc) << (uRam02036818 & 3) * -8 + 0x20 != 0) {
    func_02037a04();
    uVar1 = (*(uint *)(uRam02036818 & 0xfffffffc) >> (uRam02036818 & 3) * 8 |
            *(uint *)(uRam02036818 & 0xfffffffc) << (uRam02036818 & 3) * -8 + 0x20) + 0xb8;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    pcVar2 = (code *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)();
    }
  }
  uVar1 = iRam0203681c + 0x3ff8U & 3;
  uVar3 = *(uint *)(iRam0203681c + 0x3ff8U & 0xfffffffc);
  *(uint *)(iRam0203681c + 0x3ff8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 1;
  return;
}

