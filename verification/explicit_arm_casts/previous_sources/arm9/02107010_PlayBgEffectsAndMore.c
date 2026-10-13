/* Decompiled C draft; module arm9; ROM address 02107010. No matching claim. */
#include "types.h"
#include "deps/02107010_PlayBgEffectsAndMore.h"

void PlayBgEffectsAndMore(void)

{
  byte bVar1;
  bool bVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  bool bVar9;
  uint uVar10;
  
  if ((*psRam021073a4 == 2) && (iVar4 = GetCurrentSceneId(), iVar4 == 6)) {
    return;
  }
  func_02111118();
  *puRam021073a8 = 0;
  func_02109178();
  iVar4 = iRam021073ac;
  bVar2 = false;
  *(undefined4 *)(iRam021073ac + 4) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0x7f;
  *(undefined4 *)(iVar4 + 0x10) = 0x7f;
  *(undefined4 *)(iVar4 + 8) = 0;
  iVar4 = GetCurrentSceneId();
  if (iVar4 == 2) {
    bVar9 = true;
    uVar5 = (*(uint *)(uRam021073b0 & 0xfffffffc) >> (uRam021073b0 & 3) * 8 |
            *(uint *)(uRam021073b0 & 0xfffffffc) << (uRam021073b0 & 3) * -8 + 0x20) + 0xc;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
    if ((uVar5 != 0) && (uVar5 != 2)) {
      bVar9 = false;
    }
    if (bVar9) {
      bVar2 = true;
    }
  }
  if (bVar2) {
    func_0210d9a0(iRam021073b4,2);
    *puRam021073a8 = 1;
    uVar6 = GetSomeCXSseqId();
    func_0210d614(uRam021073b8,uVar6,0);
    uVar10 = *(uint *)(uRam021073b0 & 0xfffffffc) >> (uRam021073b0 & 3) * 8 |
             *(uint *)(uRam021073b0 & 0xfffffffc) << (uRam021073b0 & 3) * -8 + 0x20;
    *puRam021073bc = 0;
    uVar5 = uVar10 + 8 & 3;
    uVar7 = *(uint *)(uVar10 + 8 & 0xfffffffc);
    iVar4 = iRam021073c0;
    if ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) == 4) {
      bVar1 = *(byte *)(uVar10 + 0x2e);
      if (bVar1 < 0x12) {
        iVar4 = iRam021073c8;
        if ((bVar1 < 0x11) && (iVar4 = iRam021073c0, bVar1 == 9)) {
          iVar4 = iRam021073c4;
        }
      }
      else if ((((bVar1 < 0x34) && (0x30 < bVar1)) && (iVar4 = iRam021073cc, bVar1 != 0x31)) &&
              (iVar4 = iRam021073c0, bVar1 == 0x33)) {
        iVar4 = 0x228;
      }
    }
    iVar8 = iVar4;
    if (((iVar4 == iRam021073c0) &&
        (uVar5 = *(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
                 *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20, iVar8 = iRam021073d4,
        uVar5 != 0x13)) && ((iVar8 = iRam021073d8, uVar5 != 0x22 && (iVar8 = iVar4, uVar5 == 0x25)))
       ) {
      iVar8 = iRam021073d0;
    }
    if (iVar8 != iRam021073c0) {
      func_0212c6f0(uRam021073dc,0);
      uVar5 = uRam021073dc;
      if ((((*(uint *)((uint)puRam021073a8 & 0xfffffffc) >> ((uint)puRam021073a8 & 3) * 8 |
            *(uint *)((uint)puRam021073a8 & 0xfffffffc) << ((uint)puRam021073a8 & 3) * -8 + 0x20) &
           1) != 0) &&
         (uVar7 = iRam021073b4 + 0xcU & 3, uVar10 = *(uint *)(iRam021073b4 + 0xcU & 0xfffffffc),
         uVar10 >> uVar7 * 8 != 0 || uVar10 << uVar7 * -8 + 0x20 != 0)) {
        if (*(uint *)(uRam021073dc & 0xfffffffc) >> (uRam021073dc & 3) * 8 != 0 ||
            *(uint *)(uRam021073dc & 0xfffffffc) << (uRam021073dc & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uRam021073dc,0);
        }
        if (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 != 0 ||
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar5,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar5,0,iVar8);
      }
      *puRam021073bc = 1;
    }
    uVar5 = (*(uint *)(uRam021073b0 & 0xfffffffc) >> (uRam021073b0 & 3) * 8 |
            *(uint *)(uRam021073b0 & 0xfffffffc) << (uRam021073b0 & 3) * -8 + 0x20) + 8;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 2) {
      uVar5 = (*(uint *)(uRam021073e0 & 0xfffffffc) >> (uRam021073e0 & 3) * 8 |
              *(uint *)(uRam021073e0 & 0xfffffffc) << (uRam021073e0 & 3) * -8 + 0x20) + 0x104;
      uVar7 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      func_02110534(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
      uVar3 = GetCurrentLapCount();
      *(undefined1 *)(iRam021073e4 + 0x14) = uVar3;
    }
  }
  else {
    iVar4 = GetCurrentSceneId();
    if (iVar4 == 2) {
      uVar5 = (*(uint *)(uRam021073b0 & 0xfffffffc) >> (uRam021073b0 & 3) * 8 |
              *(uint *)(uRam021073b0 & 0xfffffffc) << (uRam021073b0 & 3) * -8 + 0x20) + 0xc;
      uVar7 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      if ((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) - 3 < 2) {
        func_0210d9a0(iRam021073b4,2);
        *puRam021073a8 = 2;
      }
      else {
        iVar4 = Sound_IsGlobalSdatUsed();
        if (iVar4 != 0) {
          uVar6 = Sound_GetActiveSdat();
          Sound_MaybeSetActiveSdat(uRam021073e8);
          iVar4 = iRam021073c0;
          uVar5 = 1;
          do {
            iVar8 = Sound_GetPlayerInfoEntry(uVar5);
            if ((iVar8 != 0) && ((iVar4 >> (uVar5 & 0xff) & 1U) != 0)) {
              MaybeSetPlayerVolume(uVar5,0x7f);
            }
            uVar5 = uVar5 + 1;
          } while ((int)uVar5 < 8);
          Sound_MaybeSetActiveSdat(uVar6);
        }
        iVar4 = iRam021073b4;
        *(undefined4 *)(iRam021073ac + 4) = 0x7f000;
        func_0210d9a0(iVar4,3);
        *puRam021073a8 = 0;
      }
    }
    else {
      iVar4 = Sound_IsGlobalSdatUsed();
      if (iVar4 != 0) {
        uVar6 = Sound_GetActiveSdat();
        Sound_MaybeSetActiveSdat(uRam021073e8);
        iVar4 = iRam021073c0;
        uVar5 = 1;
        do {
          iVar8 = Sound_GetPlayerInfoEntry(uVar5);
          if ((iVar8 != 0) && ((iVar4 >> (uVar5 & 0xff) & 1U) != 0)) {
            MaybeSetPlayerVolume(uVar5,0x7f);
          }
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < 8);
        Sound_MaybeSetActiveSdat(uVar6);
      }
      iVar4 = iRam021073b4;
      *(undefined4 *)(iRam021073ac + 4) = 0x7f000;
      func_0210d9a0(iVar4,2);
      *puRam021073a8 = 0;
    }
  }
  func_0210d6cc(uRam021073b8);
  return;
}

