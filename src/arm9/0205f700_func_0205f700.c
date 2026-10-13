/* Decompiled C draft; module arm9; ROM address 0205f700. No matching claim. */
#include "types.h"
#include "deps/0205f700_func_0205f700.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0205f700(void)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint unaff_r10;
  uint uStack_40;
  undefined1 auStack_34 [16];
  uint uVar10;
  
  bVar2 = false;
  uVar3 = *(uint *)(uRam0205f9ec & 0xfffffffc) >> (uRam0205f9ec & 3) * 8 |
          *(uint *)(uRam0205f9ec & 0xfffffffc) << (uRam0205f9ec & 3) * -8 + 0x20;
  uVar8 = 0xffffffff;
  uVar6 = 0;
  if (uVar3 != 0) {
    uVar6 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  uVar5 = 0;
  if ((uVar6 != 0) &&
     (uVar6 = uVar3 + 4 & 3, uVar3 = *(uint *)(uVar3 + 4 & 0xfffffffc), uVar5 = 0,
     (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) != 0xd)) {
    uVar5 = 1;
  }
  if (uVar5 == 0) {
    return;
  }
  uVar6 = (uint)*(char *)((*(uint *)(uRam0205f9f0 & 0xfffffffc) >> (uRam0205f9f0 & 3) * 8 |
                          *(uint *)(uRam0205f9f0 & 0xfffffffc) << (uRam0205f9f0 & 3) * -8 + 0x20) +
                         0x62);
  if (uVar6 == 0xffffffff) {
    return;
  }
  uVar3 = *(uint *)(uRam0205f9f4 & 0xfffffffc) >> (uRam0205f9f4 & 3) * 8 |
          *(uint *)(uRam0205f9f4 & 0xfffffffc) << (uRam0205f9f4 & 3) * -8 + 0x20;
  uVar6 = (uVar6 & 0xffff) * 0x8c + uVar3 + 0x14;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) == 4) {
    return;
  }
  uVar3 = uVar3 + 0x4cc;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 == 0 && uVar3 << uVar6 * -8 + 0x20 == 0) {
    return;
  }
  GetCurrentDate((undefined4 *)(void *)(auStack_34));
  uVar6 = GetDriverPlace((short)*(char *)((*(uint *)(uRam0205f9f0 & 0xfffffffc) >>
                                           (uRam0205f9f0 & 3) * 8 |
                                          *(uint *)(uRam0205f9f0 & 0xfffffffc) <<
                                          (uRam0205f9f0 & 3) * -8 + 0x20) + 0x62));
  uVar3 = *(uint *)(uRam0205f9f0 & 0xfffffffc) >> (uRam0205f9f0 & 3) * 8 |
          *(uint *)(uRam0205f9f0 & 0xfffffffc) << (uRam0205f9f0 & 3) * -8 + 0x20;
  if (*(char *)(uVar3 + 0x58) != '\0') {
    uVar8 = ((int)*(char *)(uVar3 + 0x62) & 0xffffU) * 0x30 + uVar3 + 0x74;
    uVar5 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  }
  uVar4 = *(uint *)(uRam0205f9f8 & 0xfffffffc) >> (uRam0205f9f8 & 3) * 8 |
          *(uint *)(uRam0205f9f8 & 0xfffffffc) << (uRam0205f9f8 & 3) * -8 + 0x20;
  uVar5 = 0;
  uVar9 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  uVar9 = uVar4 + 0x34;
  uVar10 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  uVar4 = uVar4 + 0x38;
  uVar9 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar9 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  if (*(char *)(uVar3 + 0x3d0) != '\0') {
    uStack_40 = 0;
    do {
      if (uVar5 != (int)*(char *)(uVar3 + 0x62)) {
        iVar7 = uVar5 * 0x30 + uVar3;
        uVar4 = iVar7 + 0x70;
        uVar1 = uVar4 & 3;
        uVar4 = *(uint *)(uVar4 & 0xfffffffc);
        uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
        if (((uVar4 != 1) && (uVar4 != 4)) && (uVar4 != 2)) {
          if (*(char *)(uVar3 + 0x58) == '\0') {
            uVar3 = GetDriverPlace(uVar5);
            if (uVar6 < uVar3) {
              unaff_r10 = 0;
            }
            else {
              unaff_r10 = 1;
            }
          }
          else {
            uVar4 = iVar7 + 0x74;
            uVar1 = uVar4 & 3;
            uVar4 = *(uint *)(uVar4 & 0xfffffffc);
            if (uVar8 == (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) {
              unaff_r10 = 2;
            }
            else {
              uVar4 = uVar3 + 0x1c & 3;
              uVar3 = *(uint *)(uVar3 + 0x1c & 0xfffffffc);
              uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
              if (uVar3 == 0) {
LAB_0205f8a4:
                uVar3 = GetDriverPlace(uVar5);
                unaff_r10 = (uint)(uVar3 <= uVar6);
              }
              else if (uVar3 == 1) {
                uVar3 = func_0205d480();
                unaff_r10 = uStack_40;
                if (uVar8 != uVar3) {
                  uVar3 = uVar5 * 0x8c +
                          (*(uint *)(uRam0205f9f4 & 0xfffffffc) >> (uRam0205f9f4 & 3) * 8 |
                          *(uint *)(uRam0205f9f4 & 0xfffffffc) << (uRam0205f9f4 & 3) * -8 + 0x20) +
                          0x14;
                  uVar4 = uVar3 & 3;
                  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
                  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) == 4) {
                    unaff_r10 = 2;
                  }
                  else {
                    unaff_r10 = 1;
                  }
                }
              }
              else if (uVar3 == 2) goto LAB_0205f8a4;
            }
          }
          uVar3 = *(uint *)(uRam0205f9ec & 0xfffffffc) >> (uRam0205f9ec & 3) * 8 |
                  *(uint *)(uRam0205f9ec & 0xfffffffc) << (uRam0205f9ec & 3) * -8 + 0x20;
          if (((uint)*(byte *)(uVar3 + 0x457) &
              1 << (*(ushort *)(uVar3 + (uint)*(ushort *)(uVar3 + uVar5 * 2 + 0x1e8c) * 2 + 0x1e8c)
                   & 0xff)) == 0) {
            func_0205fa00(uVar5,(uint)(uintptr_t)(auStack_34),0,unaff_r10);
          }
          if (unaff_r10 == 0) {
            if (uVar10 < (*(uint *)(uRam0205f9fc & 0xfffffffc) >> (uRam0205f9fc & 3) * 8 |
                         *(uint *)(uRam0205f9fc & 0xfffffffc) << (uRam0205f9fc & 3) * -8 + 0x20)) {
              uVar10 = uVar10 + 1;
              bVar2 = true;
            }
          }
          else if ((unaff_r10 == 1) &&
                  (uVar9 < (*(uint *)(uRam0205f9fc & 0xfffffffc) >> (uRam0205f9fc & 3) * 8 |
                           *(uint *)(uRam0205f9fc & 0xfffffffc) << (uRam0205f9fc & 3) * -8 + 0x20)))
          {
            uVar9 = uVar9 + 1;
            bVar2 = true;
          }
        }
      }
      uVar5 = uVar5 + 1 & 0xffff;
      uVar3 = *(uint *)(uRam0205f9f0 & 0xfffffffc) >> (uRam0205f9f0 & 3) * 8 |
              *(uint *)(uRam0205f9f0 & 0xfffffffc) << (uRam0205f9f0 & 3) * -8 + 0x20;
    } while (uVar5 < *(byte *)(uVar3 + 0x3d0));
  }
  uVar6 = uRam0205f9f8;
  if (!bVar2) {
    WriteFriendListSaveDataSection();
    return;
  }
  uVar8 = *(uint *)(uRam0205f9f8 & 0xfffffffc) >> (uRam0205f9f8 & 3) * 8 |
          *(uint *)(uRam0205f9f8 & 0xfffffffc) << (uRam0205f9f8 & 3) * -8 + 0x20;
  uVar3 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  *(uint *)((uVar8 >> uVar3 * 8 | uVar8 << uVar3 * -8 + 0x20) + 0x34) = uVar10;
  uVar3 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x38) = uVar9;
  SaveFriendList();
  return;
}

