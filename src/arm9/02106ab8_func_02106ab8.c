/* Decompiled C draft; module arm9; ROM address 02106ab8. No matching claim. */
#include "types.h"
#include "deps/02106ab8_func_02106ab8.h"

void func_02106ab8(void)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  bVar2 = false;
  iVar5 = GetCurrentSceneId();
  iVar3 = iRam02106c40;
  if ((iVar5 == 2) &&
     (uVar6 = (*(uint *)(uRam02106c3c & 0xfffffffc) >> (uRam02106c3c & 3) * 8 |
              *(uint *)(uRam02106c3c & 0xfffffffc) << (uRam02106c3c & 3) * -8 + 0x20) + 0xc,
     uVar7 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 1)) {
    return;
  }
  uVar6 = (*(uint *)(uRam02106c3c & 0xfffffffc) >> (uRam02106c3c & 3) * 8 |
          *(uint *)(uRam02106c3c & 0xfffffffc) << (uRam02106c3c & 3) * -8 + 0x20) + 8;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 2) {
    return;
  }
  pbVar1 = (byte *)(iRam02106c40 + 0x14);
  *(char *)(iRam02106c40 + 0x15) = *(char *)(iRam02106c40 + 0x15) + '\x01';
  uVar4 = uRam02106c44;
  if ((uint)*(byte *)(iVar3 + 0x15) == (uint)*pbVar1) {
    bVar2 = true;
  }
  else if ((uint)*(byte *)(iVar3 + 0x15) == *pbVar1 - 1) {
    *(undefined1 *)(iVar3 + 0x16) = 1;
    *(undefined4 *)(iVar3 + 0x10) = 1;
    func_0210d590(uVar4,0);
    uVar6 = iRam02106c40 + 8U & 3;
    uVar7 = *(uint *)(iRam02106c40 + 8U & 0xfffffffc);
    if (uVar7 >> uVar6 * 8 != 0 || uVar7 << uVar6 * -8 + 0x20 != 0) {
      NNS_SndPlayerSetTrackMute(uRam02106c48,uRam02106c4c,1);
    }
    func_0210d614(uRam02106c44,0x3e,0);
    *(undefined1 *)(iRam02106c40 + 0x16) = 1;
  }
  iVar3 = iRam02106c50;
  uVar7 = *(uint *)(uRam02106c3c & 0xfffffffc) >> (uRam02106c3c & 3) * 8 |
          *(uint *)(uRam02106c3c & 0xfffffffc) << (uRam02106c3c & 3) * -8 + 0x20;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if ((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) == 0x22) {
    if (bVar2) {
      return;
    }
    iVar5 = 7;
    do {
      func_0212c6f0(iVar3 + iVar5 * 4,0);
      uVar6 = uRam02106c58;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
    if (((*(uint *)(uRam02106c54 & 0xfffffffc) >> (uRam02106c54 & 3) * 8 |
         *(uint *)(uRam02106c54 & 0xfffffffc) << (uRam02106c54 & 3) * -8 + 0x20) & 1) != 0) {
      uVar7 = iRam02106c5c + 0xcU & 3;
      uVar8 = *(uint *)(iRam02106c5c + 0xcU & 0xfffffffc);
      if (uVar8 >> uVar7 * 8 != 0 || uVar8 << uVar7 * -8 + 0x20 != 0) {
        if (*(uint *)(uRam02106c58 & 0xfffffffc) >> (uRam02106c58 & 3) * 8 != 0 ||
            *(uint *)(uRam02106c58 & 0xfffffffc) << (uRam02106c58 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uRam02106c58,0);
        }
        if (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 != 0 ||
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20 != 0) {
          func_0212c6f0(uVar6,0);
        }
        NNSi_MaybeSndPlayerStartSeq(uVar6,0,uRam02106c60);
        return;
      }
      return;
    }
    return;
  }
  return;
}

