/* Decompiled C draft; module arm9; ROM address 0203ef58. No matching claim. */
#include "types.h"
#include "deps/0203ef58_func_0203ef58.h"

bool func_0203ef58(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  
  uVar6 = DAT_0203f274;
  uVar4 = *(uint *)(DAT_0203f274 & 0xfffffffc) >> (DAT_0203f274 & 3) * 8 |
          *(uint *)(DAT_0203f274 & 0xfffffffc) << (DAT_0203f274 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 8 & 3;
  uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  switch(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) {
  case 0:
    bVar8 = true;
    uVar5 = 0;
    if (*(char *)(uVar4 + 0x3d0) != '\0') {
      do {
        uVar6 = uVar5 * 0x30 + uVar4 + 0x70;
        uVar2 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
        bVar7 = false;
        if ((uVar6 < 4) && ((1 << (uVar6 & 0xff) & 0xdU) != 0)) {
          bVar7 = bVar8;
        }
        if (bVar7 != false) {
          uVar6 = uVar5 * 0x8c +
                  (*(uint *)(DAT_0203f278 & 0xfffffffc) >> (DAT_0203f278 & 3) * 8 |
                  *(uint *)(DAT_0203f278 & 0xfffffffc) << (DAT_0203f278 & 3) * -8 + 0x20) + 0x14;
          uVar2 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
          if (((uVar6 == 1) || (uVar6 == 2)) || (bVar7 = false, uVar6 == 3)) {
            bVar7 = bVar8;
          }
          if (bVar7 == false) {
            return false;
          }
        }
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < *(byte *)(uVar4 + 0x3d0));
    }
    break;
  case 1:
    bVar8 = false;
    uVar5 = (*(uint *)(DAT_0203f278 & 0xfffffffc) >> (DAT_0203f278 & 3) * 8 |
            *(uint *)(DAT_0203f278 & 0xfffffffc) << (DAT_0203f278 & 3) * -8 + 0x20) + 0x14;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if (((uVar5 == 1) || (uVar5 == 2)) || (uVar5 == 3)) {
      bVar8 = true;
    }
    break;
  case 2:
    bVar8 = true;
    uVar5 = 0;
    if (*(char *)(uVar4 + 0x3d0) != '\0') {
      do {
        uVar2 = uVar5 * 0x30 + uVar4 + 0x70;
        uVar4 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
        bVar7 = false;
        if ((uVar2 < 4) && ((1 << (uVar2 & 0xff) & 0xdU) != 0)) {
          bVar7 = bVar8;
        }
        if ((bVar7 != false) && (iVar3 = func_020a1084(uVar5), iVar3 == 0)) {
          return false;
        }
        uVar4 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
        uVar5 = uVar5 + 1 & 0xffff;
      } while (uVar5 < *(byte *)(uVar4 + 0x3d0));
    }
    break;
  case 3:
    bVar8 = true;
    uVar5 = *(uint *)(DAT_0203f278 & 0xfffffffc) >> (DAT_0203f278 & 3) * 8 |
            *(uint *)(DAT_0203f278 & 0xfffffffc) << (DAT_0203f278 & 3) * -8 + 0x20;
    iVar3 = GetCurrentRacerCount();
    if ((int)(uint)*(ushort *)(uVar5 + 0xe) < (int)(iVar3 - (*(ushort *)(uVar5 + 0x10) + 1))) {
      uVar5 = 0;
      iVar3 = GetCurrentRacerCount();
      if (iVar3 != 0) {
        do {
          iVar3 = IsRacer_Player_Ghost_UnkNet3(uVar5);
          if (((iVar3 != 0) && (iVar3 = IsRacerFinishedRace(uVar5), iVar3 == 0)) &&
             (iVar3 = IsRacerFinishStatus4(uVar5), iVar3 == 0)) {
            bVar8 = false;
            break;
          }
          uVar5 = uVar5 + 1 & 0xffff;
          uVar6 = GetCurrentRacerCount();
        } while (uVar5 < uVar6);
      }
    }
    if ((bVar8 == false) && (iVar3 = GetCurrentRaceRules_0(), iVar3 == 1)) {
      func_0203f280();
      iVar3 = IsRacerFinishedRace();
      if (iVar3 != 0) {
        bVar8 = true;
      }
    }
    break;
  case 4:
    bVar8 = false;
    if (*(char *)(uVar4 + 0x2f) == '\x06') {
      bVar8 = *(short *)((*(uint *)(DAT_0203f278 & 0xfffffffc) >> (DAT_0203f278 & 3) * 8 |
                         *(uint *)(DAT_0203f278 & 0xfffffffc) << (DAT_0203f278 & 3) * -8 + 0x20) +
                        0xe) != 0;
    }
    break;
  case 5:
    iVar3 = func_0x0219bb50();
    uVar5 = (uint)*(char *)((*(uint *)(DAT_0203f27c & 0xfffffffc) >> (DAT_0203f27c & 3) * 8 |
                            *(uint *)(DAT_0203f27c & 0xfffffffc) << (DAT_0203f27c & 3) * -8 + 0x20)
                            + iVar3 + 6);
    if ((int)uVar5 < 0) {
      bVar8 = false;
    }
    else {
      uVar2 = *(uint *)(DAT_0203f278 & 0xfffffffc) >> (DAT_0203f278 & 3) * 8 |
              *(uint *)(DAT_0203f278 & 0xfffffffc) << (DAT_0203f278 & 3) * -8 + 0x20;
      uVar4 = (uint)*(byte *)((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                              *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x3d0);
      uVar6 = (uint)*(ushort *)(uVar2 + 0x10);
      if ((int)(uVar4 - uVar6) < 2) {
        bVar8 = false;
      }
      else {
        uVar5 = (uVar5 & 0xffff) * 0x8c + uVar2 + 0x14;
        uVar1 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
        bVar8 = false;
        if (((uVar5 == 1) || (uVar5 == 2)) || (uVar5 == 3)) {
          bVar8 = true;
        }
        if (bVar8) {
          bVar8 = uVar4 <= *(ushort *)(uVar2 + 0xe) + uVar6;
        }
        else {
          bVar8 = (int)(uVar4 - 1) <= (int)(*(ushort *)(uVar2 + 0xe) + uVar6);
        }
      }
    }
    break;
  default:
    bVar8 = false;
  }
  return bVar8;
}

