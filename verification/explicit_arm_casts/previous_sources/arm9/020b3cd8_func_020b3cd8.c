/* Decompiled C draft; module arm9; ROM address 020b3cd8. No matching claim. */
#include "types.h"
#include "deps/020b3cd8_func_020b3cd8.h"

void func_020b3cd8(void)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  int aiStack_68 [8];
  uint auStack_48 [9];
  uint uVar9;
  
  uVar3 = *(uint *)(uRam020b3f5c & 0xfffffffc) >> (uRam020b3f5c & 3) * 8 |
          *(uint *)(uRam020b3f5c & 0xfffffffc) << (uRam020b3f5c & 3) * -8 + 0x20;
  uVar9 = uVar3 + 8 & 3;
  uVar8 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if (uVar9 == 1) {
    return;
  }
  if (uVar9 == 4) {
    return;
  }
  uVar8 = (uint)*(byte *)(uVar3 + 0x3d0);
  uVar9 = 0;
  if (uVar8 != 0) {
    do {
      uVar8 = uVar3 + 0x1c & 3;
      uVar10 = *(uint *)(uVar3 + 0x1c & 0xfffffffc);
      if (((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) == 1) ||
         (uVar8 = uVar3 + 8 & 3, uVar10 = *(uint *)(uVar3 + 8 & 0xfffffffc),
         (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) == 2)) {
        uVar3 = uVar9 * 0x30 + uVar3 + 0x70;
        uVar8 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
        bVar7 = 0;
        if ((uVar3 < 4) && ((1 << (uVar3 & 0xff) & 0xdU) != 0)) {
          bVar7 = 1;
        }
        uVar4 = Int32ToInt8(uVar9);
        iVar5 = GetSomeLUMaxIndex();
        iVar6 = Int32ToInt8(uVar4);
        bVar1 = *(byte *)(iVar6 * 10 +
                          iVar5 * 0x50 +
                          (*(uint *)(uRam020b3f60 & 0xfffffffc) >> (uRam020b3f60 & 3) * 8 |
                          *(uint *)(uRam020b3f60 & 0xfffffffc) << (uRam020b3f60 & 3) * -8 + 0x20) +
                         5);
        iVar5 = GetDriverPlace(uVar9);
        aiStack_68[uVar9] = ((uint)bVar1 * 0x10 + (uint)bVar7 * 8 + 8) - iVar5;
      }
      else {
        uVar3 = uVar9 * 0x30 + uVar3 + 0x70;
        uVar8 = uVar3 & 3;
        uVar3 = *(uint *)(uVar3 & 0xfffffffc);
        uVar3 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
        bVar7 = 0;
        if ((uVar3 < 4) && (bVar7 = 0, (1 << (uVar3 & 0xff) & 0xdU) != 0)) {
          bVar7 = 1;
        }
        uVar4 = Int32ToInt8(uVar9);
        iVar5 = GetSomeLUMaxIndex();
        iVar6 = Int32ToInt8(uVar4);
        uVar2 = *(ushort *)
                 (iVar5 * 0x50 +
                  (*(uint *)(uRam020b3f60 & 0xfffffffc) >> (uRam020b3f60 & 3) * 8 |
                  *(uint *)(uRam020b3f60 & 0xfffffffc) << (uRam020b3f60 & 3) * -8 + 0x20) +
                 iVar6 * 10);
        iVar5 = GetDriverPlace(uVar9);
        aiStack_68[uVar9] = ((uint)uVar2 * 0x10 + (uint)bVar7 * 8 + 8) - iVar5;
      }
      uVar3 = *(uint *)(uRam020b3f5c & 0xfffffffc) >> (uRam020b3f5c & 3) * 8 |
              *(uint *)(uRam020b3f5c & 0xfffffffc) << (uRam020b3f5c & 3) * -8 + 0x20;
      uVar8 = (uint)*(byte *)(uVar3 + 0x3d0);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < uVar8);
  }
  uVar9 = 0;
  if (uVar8 != 0) {
    do {
      auStack_48[uVar9] = uVar9;
      aiStack_68[uVar9] = -aiStack_68[uVar9];
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < *(byte *)(uVar3 + 0x3d0));
  }
  func_020ae770(auStack_48,aiStack_68,*(undefined1 *)(uVar3 + 0x3d0));
  uVar3 = uRam020b3f5c;
  uVar10 = *(uint *)(uRam020b3f5c & 0xfffffffc) >> (uRam020b3f5c & 3) * 8 |
           *(uint *)(uRam020b3f5c & 0xfffffffc) << (uRam020b3f5c & 3) * -8 + 0x20;
  uVar8 = (uint)*(byte *)(uVar10 + 0x3d0);
  uVar9 = 0;
  if (uVar8 == 0) {
    return;
  }
  do {
    uVar11 = 0;
    if (uVar8 != 0) {
      do {
        if (uVar9 == auStack_48[uVar11]) {
          func_0205d76c(uVar9,uVar11 + 1 & 0xff);
          break;
        }
        uVar11 = uVar11 + 1 & 0xffff;
      } while (uVar11 < *(byte *)(uVar10 + 0x3d0));
    }
    uVar8 = uVar3 & 3;
    uVar10 = *(uint *)(uVar3 & 0xfffffffc);
    uVar10 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
    uVar8 = (uint)*(byte *)(uVar10 + 0x3d0);
    uVar9 = uVar9 + 1 & 0xffff;
    if (uVar8 <= uVar9) {
      return;
    }
  } while( true );
}

