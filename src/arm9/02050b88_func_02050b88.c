/* Decompiled C draft; module arm9; ROM address 02050b88. No matching claim. */
#include "types.h"
#include "deps/02050b88_func_02050b88.h"

void func_02050b88(uint param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar4 = uRam02050d74;
  uVar6 = *(uint *)(uRam02050d74 & 0xfffffffc) >> (uRam02050d74 & 3) * 8 |
          *(uint *)(uRam02050d74 & 0xfffffffc) << (uRam02050d74 & 3) * -8 + 0x20;
  iVar7 = uVar6 + 0x44 + (param_1 - 1) * 8;
  if (*(ushort *)(iVar7 + 6) == uRam02050d78) {
    return;
  }
  *(short *)(iVar7 + 6) = (short)uRam02050d78;
  *(char *)(uVar6 + 0x84) = *(char *)(uVar6 + 0x84) + -1;
  uVar12 = 0;
  do {
    uVar10 = 1 << (uVar12 & 0xff);
    if ((1 << (param_1 & 0xff) & 0xffffU & uVar10) != 0) {
      uVar11 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
               *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      uVar3 = uVar11 + 4 & 3;
      uVar8 = *(uint *)(uVar11 + 4 & 0xfffffffc);
      if (uVar11 == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
      }
      bVar1 = (byte)uVar10;
      if ((uVar9 == 1) &&
         (*(byte *)(uVar11 + 0x87) = *(byte *)(uVar11 + 0x87) & ~bVar1,
         (uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) == 9)) {
        uVar10 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        *(byte *)(uVar10 + 0x8a) = *(byte *)(uVar10 + 0x8a) | bVar1;
      }
      uVar10 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
               *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      *(byte *)(uVar10 + 0x457) = *(byte *)(uVar10 + 0x457) & ~bVar1;
    }
    uVar12 = uVar12 + 1 & 0xffff;
  } while (uVar12 < 8);
  uVar4 = *(uint *)(uRam02050d74 & 0xfffffffc) >> (uRam02050d74 & 3) * 8 |
          *(uint *)(uRam02050d74 & 0xfffffffc) << (uRam02050d74 & 3) * -8 + 0x20;
  if (uVar4 == 0) {
    uVar12 = 0;
  }
  else {
    uVar12 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
             *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if ((uVar12 == 1) && ((*(ushort *)(uVar4 + 0x454) & 0x100) != 0)) {
    bVar2 = false;
    if ((*(ushort *)(uVar4 + 0x454) & 0x40) != 0) {
      if (uVar4 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      }
      bVar5 = true;
      if ((uVar12 != 1) && (*psRam02050d7c != 2)) {
        bVar5 = false;
      }
      if (bVar5) {
        bVar2 = true;
      }
    }
    if (bVar2) {
      if (uVar4 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                 *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      }
      if (uVar12 == 1) {
        func_0204bcb4(*(undefined1 *)(uVar4 + 0x457));
      }
    }
  }
  uVar12 = uRam02050d74;
  uVar4 = *(uint *)(uRam02050d74 & 0xfffffffc) >> (uRam02050d74 & 3) * 8 |
          *(uint *)(uRam02050d74 & 0xfffffffc) << (uRam02050d74 & 3) * -8 + 0x20;
  *(byte *)(uVar4 + 0x8b) = *(byte *)(uVar4 + 0x8b) | 8;
  uVar10 = uRam02050d74;
  uVar8 = *(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
          *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20;
  uVar4 = uVar8 + 4 & 3;
  uVar3 = *(uint *)(uVar8 + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 != 7) && (uVar4 != 8)) {
    if (uVar4 == 9) {
      if (*(char *)(uVar6 + 0x84) == '\0') {
        *(undefined4 *)(uVar8 + 8) = 0;
        *(undefined4 *)
         ((*(uint *)(uVar12 & 0xfffffffc) >> (uVar12 & 3) * 8 |
          *(uint *)(uVar12 & 0xfffffffc) << (uVar12 & 3) * -8 + 0x20) + 0x10) = 0;
      }
      return;
    }
    return;
  }
  *(undefined4 *)(uVar8 + 8) = 0;
  uVar4 = uVar10 & 3;
  uVar6 = *(uint *)(uVar10 & 0xfffffffc);
  *(undefined4 *)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) + 0x10) = 0;
  return;
}

