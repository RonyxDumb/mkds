/* Decompiled C draft; module arm9; ROM address 0205f498. No matching claim. */
#include "types.h"
#include "deps/0205f498_func_0205f498.h"

void func_0205f498(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined1 auStack_38 [20];
  
  bVar3 = false;
  uVar4 = *(uint *)(uRam0205f6ec & 0xfffffffc) >> (uRam0205f6ec & 3) * 8 |
          *(uint *)(uRam0205f6ec & 0xfffffffc) << (uRam0205f6ec & 3) * -8 + 0x20;
  bVar2 = false;
  if (uVar4 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  }
  if ((uVar7 != 0) &&
     (uVar7 = uVar4 + 4 & 3, uVar4 = *(uint *)(uVar4 + 4 & 0xfffffffc),
     (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) != 0xd)) {
    bVar2 = true;
  }
  if (!bVar2) {
    return;
  }
  uVar4 = (uint)*(char *)((*(uint *)(uRam0205f6f0 & 0xfffffffc) >> (uRam0205f6f0 & 3) * 8 |
                          *(uint *)(uRam0205f6f0 & 0xfffffffc) << (uRam0205f6f0 & 3) * -8 + 0x20) +
                         0x62);
  if (uVar4 == 0xffffffff) {
    return;
  }
  uVar4 = (uVar4 & 0xffff) * 0x8c +
          (*(uint *)(uRam0205f6f4 & 0xfffffffc) >> (uRam0205f6f4 & 3) * 8 |
          *(uint *)(uRam0205f6f4 & 0xfffffffc) << (uRam0205f6f4 & 3) * -8 + 0x20) + 0x14;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) == 4) {
    return;
  }
  iVar5 = func_020a128c();
  if (iVar5 == 0) {
    return;
  }
  GetCurrentDate((undefined4 *)(void *)(auStack_38));
  uVar6 = *(uint *)(uRam0205f6f0 & 0xfffffffc) >> (uRam0205f6f0 & 3) * 8 |
          *(uint *)(uRam0205f6f0 & 0xfffffffc) << (uRam0205f6f0 & 3) * -8 + 0x20;
  uVar7 = *(uint *)(uRam0205f6f8 & 0xfffffffc) >> (uRam0205f6f8 & 3) * 8 |
          *(uint *)(uRam0205f6f8 & 0xfffffffc) << (uRam0205f6f8 & 3) * -8 + 0x20;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  uVar4 = 0;
  uVar7 = uVar8 + 0x3c;
  uVar10 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
  uVar8 = uVar8 + 0x40;
  uVar7 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  if (*(char *)(uVar6 + 0x3d0) != '\0') {
    do {
      if ((((uVar4 != (int)*(char *)(uVar6 + 0x62)) &&
           (uVar8 = uVar4 * 0x30 + uVar6 + 0x70, uVar1 = uVar8 & 3,
           uVar8 = *(uint *)(uVar8 & 0xfffffffc),
           uVar8 = uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20, uVar8 != 1)) && (uVar8 != 4)) &&
         (uVar8 != 2)) {
        iVar9 = 2;
        iVar5 = func_020a100c((int)*(char *)(uVar6 + 0x62) & 0xffff);
        if (iVar5 == 0) {
          iVar5 = func_020a100c(uVar4);
          if ((iVar5 != 0) &&
             (uVar8 = uVar4 * 0x8c +
                      (*(uint *)(uRam0205f6f4 & 0xfffffffc) >> (uRam0205f6f4 & 3) * 8 |
                      *(uint *)(uRam0205f6f4 & 0xfffffffc) << (uRam0205f6f4 & 3) * -8 + 0x20) + 0x14
             , uVar6 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
             (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) != 4)) {
            iVar9 = 1;
          }
        }
        else {
          iVar5 = func_020a100c(uVar4);
          if (iVar5 == 0) {
            iVar9 = 0;
          }
        }
        uVar8 = *(uint *)(uRam0205f6ec & 0xfffffffc) >> (uRam0205f6ec & 3) * 8 |
                *(uint *)(uRam0205f6ec & 0xfffffffc) << (uRam0205f6ec & 3) * -8 + 0x20;
        if (((uint)*(byte *)(uVar8 + 0x457) &
            1 << (*(ushort *)(uVar8 + (uint)*(ushort *)(uVar8 + uVar4 * 2 + 0x1e8c) * 2 + 0x1e8c) &
                 0xff)) == 0) {
          func_0205fa00(uVar4,(uint)(uintptr_t)(auStack_38),1,iVar9);
        }
        if (iVar9 == 0) {
          if (uVar10 < (*(uint *)(uRam0205f6fc & 0xfffffffc) >> (uRam0205f6fc & 3) * 8 |
                       *(uint *)(uRam0205f6fc & 0xfffffffc) << (uRam0205f6fc & 3) * -8 + 0x20)) {
            bVar3 = true;
            uVar10 = uVar10 + 1;
          }
        }
        else if ((iVar9 == 1) &&
                (uVar7 < (*(uint *)(uRam0205f6fc & 0xfffffffc) >> (uRam0205f6fc & 3) * 8 |
                         *(uint *)(uRam0205f6fc & 0xfffffffc) << (uRam0205f6fc & 3) * -8 + 0x20))) {
          bVar3 = true;
          uVar7 = uVar7 + 1;
        }
      }
      uVar6 = *(uint *)(uRam0205f6f0 & 0xfffffffc) >> (uRam0205f6f0 & 3) * 8 |
              *(uint *)(uRam0205f6f0 & 0xfffffffc) << (uRam0205f6f0 & 3) * -8 + 0x20;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < *(byte *)(uVar6 + 0x3d0));
  }
  uVar4 = uRam0205f6f8;
  if (bVar3) {
    uVar6 = *(uint *)(uRam0205f6f8 & 0xfffffffc) >> (uRam0205f6f8 & 3) * 8 |
            *(uint *)(uRam0205f6f8 & 0xfffffffc) << (uRam0205f6f8 & 3) * -8 + 0x20;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 0x3c) = uVar10;
    uVar8 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar8 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    uVar4 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *(uint *)((uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) + 0x40) = uVar7;
    SaveFriendList();
    return;
  }
  WriteFriendListSaveDataSection();
  return;
}

