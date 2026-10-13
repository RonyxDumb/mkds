/* Decompiled C draft; module arm9; ROM address 020446e0. No matching claim. */
#include "types.h"
#include "deps/020446e0_Scene_Menu2_FinalizeImpl.h"

void Scene_Menu2_FinalizeImpl(void)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  uint uVar3;
  
  uVar7 = uRam02044934;
  uVar5 = *(uint *)(uRam02044934 & 0xfffffffc) >> (uRam02044934 & 3) * 8 |
          *(uint *)(uRam02044934 & 0xfffffffc) << (uRam02044934 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x1f0 & 3;
  uVar2 = *(uint *)(uVar5 + 0x1f0 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 != 0) {
    if (uVar3 == 2) {
      uVar3 = (*(uint *)(uRam0204493c & 0xfffffffc) >> (uRam0204493c & 3) * 8 |
              *(uint *)(uRam0204493c & 0xfffffffc) << (uRam0204493c & 3) * -8 + 0x20) + 0x1c;
      uVar7 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((int)((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) << 0x1d) < 0) {
        *(undefined4 *)(uVar5 + 500) = 0;
      }
      else {
        *(undefined4 *)(uVar5 + 500) = 4;
      }
      return;
    }
    if (uVar3 != 4) {
      *(undefined4 *)(uVar5 + 500) = 0;
      return;
    }
    return;
  }
  uVar3 = uVar5 + 0x1e8 & 3;
  uVar2 = *(uint *)(uVar5 + 0x1e8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (uVar3 == 0x34) {
    *(undefined4 *)(uVar5 + 0x1e8) = 0x34;
    *(undefined4 *)
     ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 500) = 5;
    uVar3 = 3;
    do {
      StructCO_ConfigureRacerDefault(uVar3,uVar3,uVar3 * 3,4,0xffffffff,3);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 8);
    *(undefined1 *)
     ((*(uint *)(uRam02044934 & 0xfffffffc) >> (uRam02044934 & 3) * 8 |
      *(uint *)(uRam02044934 & 0xfffffffc) << (uRam02044934 & 3) * -8 + 0x20) + 0x24b) = 0;
    return;
  }
  if (uVar3 - 0x35 < 2) {
    *(undefined4 *)(uVar5 + 500) = 6;
    *(undefined4 *)
     ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1f8) = 1;
    uVar3 = 0;
    do {
      uVar2 = 0;
      if (*(char *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x3d0) != '\0') {
        do {
          iVar4 = GetSomeRacerPosition(uVar2 & 0xffff);
          if (uVar3 + 1 == iVar4) break;
          uVar2 = (int)((uVar2 + 1) * 0x1000000) >> 0x18;
        } while ((int)uVar2 <
                 (int)(uint)*(byte *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                                      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) +
                                     0x3d0));
      }
      uVar2 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
              *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x1e8;
      uVar5 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) != 0x36) {
        StructCO_ConfigureRacerDefault(uVar3,uVar3,uVar3 * 3,1,0xffffffff,3);
      }
      uVar3 = uVar3 + 1 & 0xff;
      if (7 < uVar3) {
        *(undefined1 *)
         ((*(uint *)(uRam02044934 & 0xfffffffc) >> (uRam02044934 & 3) * 8 |
          *(uint *)(uRam02044934 & 0xfffffffc) << (uRam02044934 & 3) * -8 + 0x20) + 0x24b) = 0;
        return;
      }
    } while( true );
  }
  uVar7 = 0;
  do {
    iVar4 = (int)uVar7 >> 0x1f;
    uVar6 = (int)(uVar7 + ((uint)((int)uVar7 >> 1) >> 0x1e)) >> 2 & 0xff;
    uVar8 = (uVar7 * 0x40000000 + iVar4 >> 0x1e | iVar4 << 2) - iVar4 & 0xff;
    uVar2 = iRam02044938 + uVar6 * 0x10 + uVar8 * 4;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar3 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) break;
    bVar9 = uVar7 == 0x1f;
    uVar7 = uVar7 + 1;
    if (bVar9) {
      uVar6 = 0;
      uVar8 = 3;
    }
  } while (uVar7 < 0x20);
  *(ushort *)(uVar5 + 0x248) = (short)uVar8 + 1U & 0xff;
  uVar7 = uRam02044934;
  *(undefined4 *)
   ((*(uint *)(uRam02044934 & 0xfffffffc) >> (uRam02044934 & 3) * 8 |
    *(uint *)(uRam02044934 & 0xfffffffc) << (uRam02044934 & 3) * -8 + 0x20) + 500) = 3;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)((uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20) + 0x1ec) = uVar6;
  return;
}

