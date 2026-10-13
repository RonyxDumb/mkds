/* Decompiled C draft; module arm9; ROM address 0205ef70. No matching claim. */
#include "types.h"
#include "deps/0205ef70_func_0205ef70.h"

void func_0205ef70(void)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iStack_3c;
  undefined1 auStack_34 [16];
  uint uVar13;
  
  uVar3 = *(uint *)(uRam0205f200 & 0xfffffffc) >> (uRam0205f200 & 3) * 8 |
          *(uint *)(uRam0205f200 & 0xfffffffc) << (uRam0205f200 & 3) * -8 + 0x20;
  uVar12 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
  uVar12 = uVar3 + 0x44;
  uVar13 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  uVar13 = uVar12 >> uVar13 * 8 | uVar12 << uVar13 * -8 + 0x20;
  uVar3 = uVar3 + 0x48;
  uVar12 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20;
  func_0205b32c();
  uVar12 = *(uint *)(uRam0205f204 & 0xfffffffc) >> (uRam0205f204 & 3) * 8 |
           *(uint *)(uRam0205f204 & 0xfffffffc) << (uRam0205f204 & 3) * -8 + 0x20;
  if (*(ushort *)(uVar12 + 0x60) < 4) {
    return;
  }
  uVar11 = *(uint *)(uRam0205f208 & 0xfffffffc) >> (uRam0205f208 & 3) * 8 |
           *(uint *)(uRam0205f208 & 0xfffffffc) << (uRam0205f208 & 3) * -8 + 0x20;
  uVar4 = uVar11 + 0x4cc;
  uVar10 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uVar4 >> uVar10 * 8 == 0 && uVar4 << uVar10 * -8 + 0x20 == 0) {
    return;
  }
  uVar12 = ((int)*(char *)(uVar12 + 0x62) & 0xffffU) * 0x8c + uVar11 + 0x14;
  uVar4 = uVar12 & 3;
  uVar12 = *(uint *)(uVar12 & 0xfffffffc);
  if ((uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20) == 4) {
    return;
  }
  GetCurrentDate(auStack_34);
  iVar5 = GetSomeRacerPosition
                    ((short)*(char *)((*(uint *)(uRam0205f204 & 0xfffffffc) >>
                                       (uRam0205f204 & 3) * 8 |
                                      *(uint *)(uRam0205f204 & 0xfffffffc) <<
                                      (uRam0205f204 & 3) * -8 + 0x20) + 0x62));
  uVar6 = Int32ToInt8((short)*(char *)((*(uint *)(uRam0205f204 & 0xfffffffc) >>
                                        (uRam0205f204 & 3) * 8 |
                                       *(uint *)(uRam0205f204 & 0xfffffffc) <<
                                       (uRam0205f204 & 3) * -8 + 0x20) + 0x62));
  iVar7 = GetSomeLUMaxIndex();
  iVar8 = Int32ToInt8(uVar6);
  uVar4 = (uint)*(byte *)((*(uint *)(uRam0205f20c & 0xfffffffc) >> (uRam0205f20c & 3) * 8 |
                          *(uint *)(uRam0205f20c & 0xfffffffc) << (uRam0205f20c & 3) * -8 + 0x20) +
                         0x1f54);
  uVar12 = (int)((uVar4 - 1) * 0x1000000) >> 0x18;
  sVar1 = *(short *)(iVar7 * 0x50 +
                     (*(uint *)(uRam0205f210 & 0xfffffffc) >> (uRam0205f210 & 3) * 8 |
                     *(uint *)(uRam0205f210 & 0xfffffffc) << (uRam0205f210 & 3) * -8 + 0x20) +
                    iVar8 * 10);
  if (0 < (int)uVar12) {
    if (uVar3 < uVar12) {
      uVar3 = 0;
    }
    else {
      uVar3 = uVar3 - uVar12;
    }
  }
  uVar12 = *(uint *)(uRam0205f204 & 0xfffffffc) >> (uRam0205f204 & 3) * 8 |
           *(uint *)(uRam0205f204 & 0xfffffffc) << (uRam0205f204 & 3) * -8 + 0x20;
  iVar7 = (int)((uVar4 - *(byte *)(uVar12 + 0x3d0)) * 0x10000) >> 0x10;
  if (0 < iVar7) {
    uVar13 = uVar13 + iVar7;
    uVar4 = *(uint *)(uRam0205f214 & 0xfffffffc) >> (uRam0205f214 & 3) * 8 |
            *(uint *)(uRam0205f214 & 0xfffffffc) << (uRam0205f214 & 3) * -8 + 0x20;
    if (uVar4 < uVar13) {
      uVar13 = uVar4;
    }
  }
  uVar4 = 0;
  if (*(byte *)(uVar12 + 0x3d0) != 0) {
    iStack_3c = 0;
    do {
      if (uVar4 != (int)*(char *)(uVar12 + 0x62)) {
        iVar8 = GetSomeRacerPosition(uVar4);
        iVar7 = iStack_3c;
        if ((iVar8 <= iVar5) && (iVar8 = GetSomeRacerPosition(uVar4), iVar7 = 2, iVar8 < iVar5)) {
          iVar7 = 1;
        }
        uVar6 = Int32ToInt8(uVar4);
        iVar8 = GetSomeLUMaxIndex();
        iVar9 = Int32ToInt8(uVar6);
        if (sVar1 == *(short *)(iVar8 * 0x50 +
                                (*(uint *)(uRam0205f210 & 0xfffffffc) >> (uRam0205f210 & 3) * 8 |
                                *(uint *)(uRam0205f210 & 0xfffffffc) <<
                                (uRam0205f210 & 3) * -8 + 0x20) + iVar9 * 10)) {
          iVar7 = 2;
        }
        func_0205fa00(uVar4,auStack_34,2,iVar7);
        if (iVar7 == 0) {
          if (uVar13 < (*(uint *)(uRam0205f214 & 0xfffffffc) >> (uRam0205f214 & 3) * 8 |
                       *(uint *)(uRam0205f214 & 0xfffffffc) << (uRam0205f214 & 3) * -8 + 0x20)) {
            uVar13 = uVar13 + 1;
          }
        }
        else if ((iVar7 == 1) &&
                (uVar3 < (*(uint *)(uRam0205f214 & 0xfffffffc) >> (uRam0205f214 & 3) * 8 |
                         *(uint *)(uRam0205f214 & 0xfffffffc) << (uRam0205f214 & 3) * -8 + 0x20))) {
          uVar3 = uVar3 + 1;
        }
      }
      uVar12 = *(uint *)(uRam0205f204 & 0xfffffffc) >> (uRam0205f204 & 3) * 8 |
               *(uint *)(uRam0205f204 & 0xfffffffc) << (uRam0205f204 & 3) * -8 + 0x20;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < *(byte *)(uVar12 + 0x3d0));
  }
  func_0x0219bb50();
  uVar2 = GetTKSomeSize();
  uVar4 = uRam0205f200;
  uVar10 = *(uint *)(uRam0205f200 & 0xfffffffc) >> (uRam0205f200 & 3) * 8 |
           *(uint *)(uRam0205f200 & 0xfffffffc) << (uRam0205f200 & 3) * -8 + 0x20;
  uVar12 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  *(undefined2 *)((uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) + 0x24) = uVar2;
  uVar10 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar12 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  *(uint *)((uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20) + 0x44) = uVar13;
  uVar13 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
           *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar12 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  *(uint *)((uVar13 >> uVar12 * 8 | uVar13 << uVar12 * -8 + 0x20) + 0x48) = uVar3;
  SaveFriendList();
  return;
}

