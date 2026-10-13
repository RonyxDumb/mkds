/* Decompiled C draft; module arm9; ROM address 02085778. No matching claim. */
#include "types.h"
#include "deps/02085778_func_02085778.h"

void func_02085778(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (*(uint *)(uRam02085818 & 0xfffffffc) >> (uRam02085818 & 3) * 8 == 0 &&
      *(uint *)(uRam02085818 & 0xfffffffc) << (uRam02085818 & 3) * -8 + 0x20 == 0) {
    return;
  }
  func_0208552c();
  uVar3 = uRam02085820;
  uVar2 = uRam0208581c;
  uVar7 = 1;
  uVar6 = 0;
  if (*(char *)((*(uint *)(uRam0208581c & 0xfffffffc) >> (uRam0208581c & 3) * 8 |
                *(uint *)(uRam0208581c & 0xfffffffc) << (uRam0208581c & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  do {
    uVar4 = GetDriverPlace(uVar6);
    uVar5 = uVar6 * 0x30 +
            (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x70;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) != 1) {
      if (uVar4 == 1) {
        *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x88) = uVar6;
      }
      if (uVar7 <= uVar4) {
        *(uint *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x84) = uVar6;
        uVar7 = uVar4;
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < *(byte *)((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                             *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x3d0));
  return;
}

