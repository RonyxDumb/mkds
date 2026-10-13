/* Decompiled C draft; module arm9; ROM address 0203d568. No matching claim. */
#include "types.h"
#include "deps/0203d568_func_0203d568.h"

void func_0203d568(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  Struct5624_SetXflag2(0);
  if (*(char *)((*(uint *)(uRam0203d830 & 0xfffffffc) >> (uRam0203d830 & 3) * 8 |
                *(uint *)(uRam0203d830 & 0xfffffffc) << (uRam0203d830 & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    uVar4 = *(uint *)(uRam0203d834 & 0xfffffffc) >> (uRam0203d834 & 3) * 8 |
            *(uint *)(uRam0203d834 & 0xfffffffc) << (uRam0203d834 & 3) * -8 + 0x20;
    uVar2 = uVar4 + 0xc;
    uVar5 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar5 * 8 == 0 && uVar2 << uVar5 * -8 + 0x20 == 0) {
      uVar2 = 0;
    }
    else {
      uVar4 = uVar4 + 0x10;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    }
  }
  else {
    uVar2 = 1;
  }
  if ((uVar2 != 0) &&
     (WaitForWorkerTask(),
     uVar2 = (*(uint *)(uRam0203d834 & 0xfffffffc) >> (uRam0203d834 & 3) * 8 |
             *(uint *)(uRam0203d834 & 0xfffffffc) << (uRam0203d834 & 3) * -8 + 0x20) + 0xc,
     uVar4 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
     uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0)) {
    func_02145d38();
  }
  uVar5 = *(uint *)(uRam0203d838 & 0xfffffffc) >> (uRam0203d838 & 3) * 8 |
          *(uint *)(uRam0203d838 & 0xfffffffc) << (uRam0203d838 & 3) * -8 + 0x20;
  uVar2 = uVar5 + 8 & 3;
  uVar4 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  if (uVar2 == 2) {
    uVar2 = uVar5 + 0xc & 3;
    uVar4 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
    if (((uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) &&
        (iVar3 = GetNextSceneId(), iVar3 != 10)) &&
       ((iVar3 = GetNextSceneId(), uVar4 = uRam0203d840, uVar2 = uRam0203d838, iVar3 != 6 ||
        (uVar5 = (*(uint *)(uRam0203d83c & 0xfffffffc) >> (uRam0203d83c & 3) * 8 |
                 *(uint *)(uRam0203d83c & 0xfffffffc) << (uRam0203d83c & 3) * -8 + 0x20) + 0x74,
        uVar7 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
        (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 2)))) {
      bVar1 = false;
      uVar5 = *(uint *)(uRam0203d840 & 0xfffffffc) >> (uRam0203d840 & 3) * 8 |
              *(uint *)(uRam0203d840 & 0xfffffffc) << (uRam0203d840 & 3) * -8 + 0x20;
      if (uVar5 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      }
      if ((uVar7 != 0) &&
         (uVar7 = uVar5 + 4 & 3, uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc),
         (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 0xd)) {
        bVar1 = true;
      }
      if (bVar1) {
        uVar5 = 0;
        uVar7 = *(uint *)(uRam0203d838 & 0xfffffffc) >> (uRam0203d838 & 3) * 8 |
                *(uint *)(uRam0203d838 & 0xfffffffc) << (uRam0203d838 & 3) * -8 + 0x20;
        if (*(char *)(uVar7 + 0x3d0) != '\0') {
          do {
            uVar7 = uVar5 * 0x30 + uVar7 + 0x70;
            uVar6 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            if ((uVar7 >> uVar6 * 8 == 0 && uVar7 << uVar6 * -8 + 0x20 == 0) &&
               (uVar7 = uVar4 & 3, uVar6 = *(uint *)(uVar4 & 0xfffffffc),
               uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,
               ((uint)*(byte *)(uVar7 + 0x15f6) &
               1 << (*(ushort *)(uVar7 + uVar5 * 2 + 0x1e8c) & 0xff)) == 0)) {
              func_0204451c(uVar5);
            }
            uVar7 = uVar2 & 3;
            uVar6 = *(uint *)(uVar2 & 0xfffffffc);
            uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
            uVar5 = uVar5 + 1 & 0xffff;
          } while (uVar5 < *(byte *)(uVar7 + 0x3d0));
        }
      }
    }
  }
  else if (uVar2 == 3) {
    uVar2 = uVar5 + 0xc & 3;
    uVar4 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
    if (((uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) &&
        (iVar3 = GetNextSceneId(), iVar3 != 10)) &&
       ((iVar3 = GetNextSceneId(), uVar4 = uRam0203d840, uVar2 = uRam0203d838, iVar3 != 6 ||
        (uVar5 = (*(uint *)(uRam0203d83c & 0xfffffffc) >> (uRam0203d83c & 3) * 8 |
                 *(uint *)(uRam0203d83c & 0xfffffffc) << (uRam0203d83c & 3) * -8 + 0x20) + 0x74,
        uVar7 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
        (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 2)))) {
      bVar1 = false;
      uVar5 = *(uint *)(uRam0203d840 & 0xfffffffc) >> (uRam0203d840 & 3) * 8 |
              *(uint *)(uRam0203d840 & 0xfffffffc) << (uRam0203d840 & 3) * -8 + 0x20;
      if (uVar5 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      }
      if ((uVar7 != 0) &&
         (uVar7 = uVar5 + 4 & 3, uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc),
         (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 0xd)) {
        bVar1 = true;
      }
      if (bVar1) {
        uVar5 = 0;
        uVar7 = *(uint *)(uRam0203d838 & 0xfffffffc) >> (uRam0203d838 & 3) * 8 |
                *(uint *)(uRam0203d838 & 0xfffffffc) << (uRam0203d838 & 3) * -8 + 0x20;
        if (*(char *)(uVar7 + 0x3d0) != '\0') {
          do {
            uVar7 = uVar5 * 0x30 + uVar7 + 0x70;
            uVar6 = uVar7 & 3;
            uVar7 = *(uint *)(uVar7 & 0xfffffffc);
            if ((uVar7 >> uVar6 * 8 == 0 && uVar7 << uVar6 * -8 + 0x20 == 0) &&
               (uVar7 = uVar4 & 3, uVar6 = *(uint *)(uVar4 & 0xfffffffc),
               uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,
               ((uint)*(byte *)(uVar7 + 0x15f6) &
               1 << (*(ushort *)(uVar7 + uVar5 * 2 + 0x1e8c) & 0xff)) == 0)) {
              func_0204451c(uVar5);
            }
            uVar7 = uVar2 & 3;
            uVar6 = *(uint *)(uVar2 & 0xfffffffc);
            uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
            uVar5 = uVar5 + 1 & 0xffff;
          } while (uVar5 < *(byte *)(uVar7 + 0x3d0));
        }
      }
    }
  }
  else if (uVar2 == 4) {
    ResetGlobalAR();
  }
  iVar3 = iRam0203d844;
  uVar4 = uRam0203d838;
  uVar2 = 0;
  uVar5 = *(uint *)(uRam0203d838 & 0xfffffffc) >> (uRam0203d838 & 3) * 8 |
          *(uint *)(uRam0203d838 & 0xfffffffc) << (uRam0203d838 & 3) * -8 + 0x20;
  if (*(char *)(uVar5 + 0x3d0) == '\0') {
    return;
  }
  do {
    uVar5 = uVar2 * 0x30 + uVar5 + 0x7c;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    func_0204a928((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * 0x5c + iVar3 + 0x28);
    uVar5 = uVar4 & 3;
    uVar7 = *(uint *)(uVar4 & 0xfffffffc);
    uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < *(byte *)(uVar5 + 0x3d0));
  return;
}

