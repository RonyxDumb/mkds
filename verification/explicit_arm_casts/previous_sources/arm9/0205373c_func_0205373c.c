/* Decompiled C draft; module arm9; ROM address 0205373c. No matching claim. */
#include "types.h"
#include "deps/0205373c_func_0205373c.h"

bool func_0205373c(void)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  int iVar11;
  undefined1 auStack_64 [64];
  uint uVar9;
  
  uVar6 = uRam02053aa4;
  uVar10 = *(uint *)(uRam02053aa4 & 0xfffffffc) >> (uRam02053aa4 & 3) * 8 |
           *(uint *)(uRam02053aa4 & 0xfffffffc) << (uRam02053aa4 & 3) * -8 + 0x20;
  uVar9 = uVar10 + 0x15bc & 3;
  uVar8 = *(uint *)(uVar10 + 0x15bc & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  iVar11 = uVar10 + iRam02053aa8;
  *(char *)(uVar10 + 0x1606) =
       (char)*(undefined2 *)(uVar9 + (uint)*(ushort *)(uVar9 + 0x808) * 0x200 + 2);
  uVar9 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  *(ushort *)(uVar9 + 0x454) = *(ushort *)(uVar9 + 0x454) & 0xffef;
  uVar9 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  if (uVar9 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
            *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
  }
  if (uVar6 == 1) {
    if (*(char *)(uVar9 + 0x84) == '\0') {
      return false;
    }
    func_02053ab0();
  }
  else if (uVar6 == 2) {
    if (*(ushort *)(uVar9 + 0x432) == uRam02053aac) {
      return false;
    }
    func_02053ab0();
  }
  uVar6 = uRam02053aa4;
  uVar10 = *(uint *)(uRam02053aa4 & 0xfffffffc) >> (uRam02053aa4 & 3) * 8 |
           *(uint *)(uRam02053aa4 & 0xfffffffc) << (uRam02053aa4 & 3) * -8 + 0x20;
  uVar9 = uVar10 + 4 & 3;
  uVar8 = *(uint *)(uVar10 + 4 & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if (uVar9 == 8) {
    uVar9 = iVar11 + 0x34U & 3;
    uVar6 = *(uint *)(iVar11 + 0x34U & 0xfffffffc);
    uVar9 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
    if ((uVar9 != 0) && (uVar9 == 5)) {
      return false;
    }
  }
  else if (uVar9 == 9) {
    uVar9 = iVar11 + 0x34U & 3;
    uVar8 = *(uint *)(iVar11 + 0x34U & 0xfffffffc);
    uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    if (uVar9 == 0) {
      if (uVar10 == 0) {
        uVar9 = 0;
      }
      else {
        uVar9 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
      }
      if (uVar9 == 1) {
        uVar9 = 1;
        do {
          uVar8 = uVar6 & 3;
          uVar10 = *(uint *)(uVar6 & 0xfffffffc);
          uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
          if (((uint)*(byte *)(uVar8 + 0x15f6) & 1 << (uVar9 & 0xff)) != 0) {
            *(undefined2 *)(uVar8 + (uVar9 - 1) * 2 + 0x15f8) = 0;
          }
          uVar9 = uVar9 + 1 & 0xffff;
        } while (uVar9 < 8);
      }
    }
    else if (uVar9 == 5) {
      return false;
    }
  }
  uVar6 = *(uint *)(uRam02053aa4 & 0xfffffffc) >> (uRam02053aa4 & 3) * 8 |
          *(uint *)(uRam02053aa4 & 0xfffffffc) << (uRam02053aa4 & 3) * -8 + 0x20;
  bVar3 = true;
  uVar9 = uVar6 + 0x15bc;
  uVar8 = uVar9 & 3;
  uVar10 = *(uint *)(uVar9 & 0xfffffffc);
  uVar6 = uVar6 + 0x15c0;
  uVar9 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  iVar4 = func_0214461c(uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20,
                        uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20,0);
  uVar9 = uRam02053aa4;
  if (iVar4 == 0) {
    bVar3 = false;
  }
  else {
    bVar1 = *(byte *)(iVar4 + 4);
    if (bVar1 != 0) {
      uVar6 = 0;
      do {
        uVar10 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                 *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
        uVar8 = 1 << (uVar6 & 0xff);
        uVar2 = *(undefined2 *)(uVar10 + uVar6 * 8 + 0x1e52);
        if (((*(byte *)(uVar10 + 0x15f6) & uVar8) != 0) && ((bVar1 & uVar8) != 0)) {
          *(byte *)(uVar10 + 0x15f6) = *(byte *)(uVar10 + 0x15f6) & ~(byte)uVar8;
          uVar10 = (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                   *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 4;
          uVar7 = uVar10 & 3;
          uVar10 = *(uint *)(uVar10 & 0xfffffffc);
          if ((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) == 9) {
            func_0203c2e4(uVar2);
          }
          uVar10 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                   *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
          if (uVar10 == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                    *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20;
          }
          if (uVar7 == 1) {
            *(byte *)(uVar10 + 0x1eac) = *(byte *)(uVar10 + 0x1eac) & ~(byte)uVar8;
          }
        }
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < 8);
    }
    Mem_CpuCopy8(iVar4,auStack_64,8);
  }
  uVar9 = uRam02053aa4;
  if (bVar3) {
    uVar6 = 1;
    do {
      uVar8 = uVar9 & 3;
      uVar10 = *(uint *)(uVar9 & 0xfffffffc);
      uVar8 = uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20;
      if (((uint)*(byte *)(uVar8 + 0x15f6) & 1 << (uVar6 & 0xff)) != 0) {
        uVar10 = uVar8 + 0x15bc & 3;
        uVar5 = *(uint *)(uVar8 + 0x15bc & 0xfffffffc);
        uVar7 = uVar8 + 0x15c0 & 3;
        uVar8 = *(uint *)(uVar8 + 0x15c0 & 0xfffffffc);
        iVar4 = func_0214461c(uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20,
                              uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20,uVar6);
        if (iVar4 == 0) {
          bVar3 = false;
          break;
        }
        Mem_CpuCopy8(iVar4,auStack_64 + uVar6 * 8,8);
      }
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < 8);
  }
  uVar6 = uRam02053aa4;
  uVar9 = 0;
  do {
    if ((bVar3) &&
       (uVar8 = uVar6 & 3, uVar10 = *(uint *)(uVar6 & 0xfffffffc),
       ((uint)*(byte *)((uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + 0x15f6) &
       1 << (uVar9 & 0xff)) != 0)) {
      uVar8 = iVar11 + 0xcU & 3;
      uVar10 = *(uint *)(iVar11 + 0xcU & 0xfffffffc);
      Mem_CpuCopy8(auStack_64 + uVar9 * 8,
                   (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) + uVar9 * 8,8);
      *(undefined4 *)(iVar11 + uVar9 * 4 + 0x10) = 1;
    }
    else {
      *(undefined4 *)(iVar11 + uVar9 * 4 + 0x10) = 0;
    }
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 8);
  return bVar3;
}

