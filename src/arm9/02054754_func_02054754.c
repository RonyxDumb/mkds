/* Decompiled C draft; module arm9; ROM address 02054754. No matching claim. */
#include "types.h"
#include "deps/02054754_func_02054754.h"

undefined4 func_02054754(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  byte bVar9;
  bool bVar10;
  
  uVar8 = 0;
  uVar5 = *(uint *)(uRam02054930 & 0xfffffffc) >> (uRam02054930 & 3) * 8 |
          *(uint *)(uRam02054930 & 0xfffffffc) << (uRam02054930 & 3) * -8 + 0x20;
  iVar7 = uVar5 + iRam02054934;
  if (uVar5 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  bVar10 = false;
  if ((uVar2 != 0) &&
     (uVar2 = uVar5 + 4 & 3, uVar3 = *(uint *)(uVar5 + 4 & 0xfffffffc),
     (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 0xd)) {
    bVar10 = true;
  }
  if (!bVar10) {
    return 1;
  }
  if ((*(ushort *)(uVar5 + 0x454) & 4) == 0) {
    return 1;
  }
  iVar4 = func_0204ffbc(*(ushort *)(uVar5 + 0x454) & 4);
  if (iVar4 == 0) {
    uVar5 = iVar7 + 0x10U & 3;
    uVar2 = *(uint *)(iVar7 + 0x10U & 0xfffffffc);
    if (uVar2 >> uVar5 * 8 != 0 || uVar2 << uVar5 * -8 + 0x20 != 0) {
      uVar5 = iVar7 + 0xcU & 3;
      uVar2 = *(uint *)(iVar7 + 0xcU & 0xfffffffc);
      uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
      uVar5 = *(uint *)(uRam02054930 & 0xfffffffc) >> (uRam02054930 & 3) * 8 |
              *(uint *)(uRam02054930 & 0xfffffffc) << (uRam02054930 & 3) * -8 + 0x20;
      bVar9 = *(byte *)(uVar2 + 6);
      bVar10 = false;
      if (*(char *)(uVar5 + 0x15ec) == '\0') {
        bVar10 = (bVar9 & 1) != 0;
      }
      else if ((bVar9 & 2) != 0) {
        bVar10 = true;
      }
      if (bVar10) {
        uVar8 = 1;
        if ((*(ushort *)(uVar5 + 0x454) & 8) == 0) {
          *(undefined4 *)(uVar5 + 4) = 8;
        }
        else {
          *(undefined4 *)(uVar5 + 4) = 9;
        }
        *(undefined2 *)
         ((*(uint *)(uRam02054930 & 0xfffffffc) >> (uRam02054930 & 3) * 8 |
          *(uint *)(uRam02054930 & 0xfffffffc) << (uRam02054930 & 3) * -8 + 0x20) + 0x15f4) = 0;
      }
      else {
        if (uVar5 == 0) {
          uVar3 = 0;
        }
        else {
          uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                  *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
        }
        if (uVar3 == 1) {
          bVar10 = false;
          uVar3 = 1;
          do {
            if (((uint)*(byte *)(uVar5 + 0x87) & 1 << uVar3) != 0) {
              uVar6 = iVar7 + uVar3 * 4 + 0x10;
              uVar1 = uVar6 & 3;
              uVar6 = *(uint *)(uVar6 & 0xfffffffc);
              if (uVar6 >> uVar1 * 8 == 0 && uVar6 << uVar1 * -8 + 0x20 == 0) {
                bVar10 = false;
                uVar3 = 8;
              }
              else {
                if (*(char *)(uVar5 + 0x15ec) == '\0') {
                  bVar9 = 1;
                }
                else {
                  bVar9 = 2;
                }
                if ((bVar9 & *(byte *)(uVar2 + uVar3 * 8 + 6) & 0x7f) == 0) {
                  bVar10 = false;
                  uVar3 = 8;
                }
                else {
                  bVar10 = true;
                }
              }
            }
            uVar3 = uVar3 + 1 & 0xff;
          } while (uVar3 < 8);
          if (bVar10) {
            *(byte *)(uVar5 + 0x8b) = *(byte *)(uVar5 + 0x8b) | 1;
          }
        }
      }
    }
    return uVar8;
  }
  return 1;
}

