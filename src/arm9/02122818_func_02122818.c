/* Decompiled C draft; module arm9; ROM address 02122818. No matching claim. */
#include "types.h"
#include "deps/02122818_func_02122818.h"

void func_02122818(void)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar3;
  
  uVar6 = *(uint *)(uRam0212295c & 0xfffffffc) >> (uRam0212295c & 3) * 8 |
          *(uint *)(uRam0212295c & 0xfffffffc) << (uRam0212295c & 3) * -8 + 0x20;
  uVar3 = uVar6 + 0x1950 & 3;
  uVar2 = *(uint *)(uVar6 + 0x1950 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((2 < (int)uVar3) && ((int)uVar3 < 9)) {
    if (uVar3 == 3) {
      iVar4 = func_0x0219bb50();
      uVar6 = *(uint *)(uRam0212295c & 0xfffffffc) >> (uRam0212295c & 3) * 8 |
              *(uint *)(uRam0212295c & 0xfffffffc) << (uRam0212295c & 3) * -8 + 0x20;
      uVar3 = iVar4 * 0x44 + uVar6 + 0x1e50;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 1) {
        return;
      }
    }
    uVar3 = uRam0212295c;
    uVar2 = 0;
    if (*(char *)(uVar6 + 0x1f53) != '\0') {
      do {
        uVar6 = func_0x0219bb50();
        if (uVar2 != uVar6) {
          uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
          if ((((uint)*(byte *)(uVar6 + 0x1f55) & 1 << uVar2) != 0) &&
             (uVar5 = uVar6 + uVar2 * 4 + 0x1984, uVar1 = uVar5 & 3,
             uVar5 = *(uint *)(uVar5 & 0xfffffffc),
             300 < (int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))) {
            *(byte *)(uVar6 + 0x1f56) = *(byte *)(uVar6 + 0x1f56) | (byte)(1 << uVar2);
          }
        }
        uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < *(byte *)(uVar6 + 0x1f53));
    }
  }
  uVar3 = uRam0212295c;
  uVar2 = 0;
  if (*(char *)(uVar6 + 0x1f53) != '\0') {
    do {
      uVar6 = func_0x0219bb50();
      if ((uVar2 != uVar6) &&
         (uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20,
         ((uint)*(byte *)(uVar6 + 0x1f55) & 1 << uVar2) != 0)) {
        iVar4 = uVar6 + uVar2 * 4;
        uVar6 = iVar4 + 0x1984;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        *(uint *)(iVar4 + 0x1984) = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 1;
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < *(byte *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                               *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x1f53));
    return;
  }
  return;
}

