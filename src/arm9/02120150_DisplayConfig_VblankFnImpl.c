/* Decompiled C draft; module arm9; ROM address 02120150. No matching claim. */
#include "types.h"
#include "deps/02120150_DisplayConfig_VblankFnImpl.h"

void DisplayConfig_VblankFnImpl(void)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = uRam021201e0;
  bVar2 = false;
  uVar4 = *(uint *)(uRam021201e0 & 0xfffffffc) >> (uRam021201e0 & 3) * 8 |
          *(uint *)(uRam021201e0 & 0xfffffffc) << (uRam021201e0 & 3) * -8 + 0x20;
  if ((uVar4 != 0) &&
     (uVar1 = uVar4 + 0x1f30 & 3, uVar3 = *(uint *)(uVar4 + 0x1f30 & 0xfffffffc),
     uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0)) {
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  uVar1 = uVar4 + 0x1f3c & 3;
  uVar3 = *(uint *)(uVar4 + 0x1f3c & 0xfffffffc);
  *(uint *)(uVar4 + 0x1f3c) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  if (*(short *)(uVar5 + 0x16) != 5) {
    return;
  }
  uVar5 = uVar5 + 0x1f38;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
    func_0205ccec();
    return;
  }
  return;
}

