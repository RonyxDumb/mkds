/* Decompiled C draft; module arm9; ROM address 02046740. No matching claim. */
#include "types.h"
#include "deps/02046740_PrepareForCourseIntro.h"

void PrepareForCourseIntro(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = uRam02046798;
  uVar1 = *(uint *)(uRam02046798 & 0xfffffffc) >> (uRam02046798 & 3) * 8 |
          *(uint *)(uRam02046798 & 0xfffffffc) << (uRam02046798 & 3) * -8 + 0x20;
  *(short *)(uVar1 + 0x248) = *(short *)(uVar1 + 0x60) + 1;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar1 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if (*(ushort *)(uVar1 + 0x248) < 5) {
    uVar3 = uVar1 + 0x1ec & 3;
    uVar2 = *(uint *)(uVar1 + 0x1ec & 0xfffffffc);
    uVar3 = iRam0204679c + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x10 +
            (*(ushort *)(uVar1 + 0x248) - 1) * 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar1 + 0x1e8) = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02046798 & 0xfffffffc) >> (uRam02046798 & 3) * 8 |
    *(uint *)(uRam02046798 & 0xfffffffc) << (uRam02046798 & 3) * -8 + 0x20) + 500) = 3;
  return;
}

