/* Decompiled C draft; module arm9; ROM address 0203ee28. No matching claim. */
#include "types.h"
#include "deps/0203ee28_RaceModeDefault_SomeFn.h"

void RaceModeDefault_SomeFn(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  
  uVar3 = uRam0203ef50;
  uVar10 = 0;
  uVar4 = *(uint *)(uRam0203ef4c & 0xfffffffc) >> (uRam0203ef4c & 3) * 8 |
          *(uint *)(uRam0203ef4c & 0xfffffffc) << (uRam0203ef4c & 3) * -8 + 0x20;
  bVar1 = *(byte *)(uVar4 + 0x3d0);
  if (bVar1 != 0) {
    do {
      bVar2 = false;
      uVar7 = (*(uint *)(uRam0203ef54 & 0xfffffffc) >> (uRam0203ef54 & 3) * 8 |
              *(uint *)(uRam0203ef54 & 0xfffffffc) << (uRam0203ef54 & 3) * -8 + 0x20) +
              uVar10 * 0x8c + 0x14;
      uVar5 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
      if (((uVar7 == 1) || (uVar7 == 2)) || (uVar7 == 3)) {
        bVar2 = true;
      }
      if ((!bVar2) && (uVar7 != 4)) {
        uVar7 = uVar4 + 8 & 3;
        uVar5 = *(uint *)(uVar4 + 8 & 0xfffffffc);
        uVar4 = *(uint *)(uRam0203ef54 & 0xfffffffc) >> (uRam0203ef54 & 3) * 8 |
                *(uint *)(uRam0203ef54 & 0xfffffffc) << (uRam0203ef54 & 3) * -8 + 0x20;
        iVar9 = uVar4 + 0x14 + uVar10 * 0x8c;
        uVar8 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
        uVar4 = uVar8;
        if ((uVar5 >> uVar7 * 8 == 0 && uVar5 << uVar7 * -8 + 0x20 == 0) &&
           (uVar7 = iVar9 + 0x44U & 3, uVar5 = *(uint *)(iVar9 + 0x44U & 0xfffffffc), uVar4 = uVar3,
           0 < (int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20))) {
          iVar6 = FX_Inv();
          uVar4 = uVar8 * iVar6 >> 0xc;
          if (uVar3 < uVar4) {
            uVar4 = uVar3;
          }
        }
        MaybeConvertElapsedTime(iVar9 + 0x22,iVar9 + 0x23,iVar9 + 0x20,0,uVar4);
        NotifyDriverFinished(iVar9,0);
      }
      uVar4 = *(uint *)(uRam0203ef4c & 0xfffffffc) >> (uRam0203ef4c & 3) * 8 |
              *(uint *)(uRam0203ef4c & 0xfffffffc) << (uRam0203ef4c & 3) * -8 + 0x20;
      bVar1 = *(byte *)(uVar4 + 0x3d0);
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < bVar1);
  }
  *(ushort *)
   ((*(uint *)(uRam0203ef54 & 0xfffffffc) >> (uRam0203ef54 & 3) * 8 |
    *(uint *)(uRam0203ef54 & 0xfffffffc) << (uRam0203ef54 & 3) * -8 + 0x20) + 0xe) = (ushort)bVar1;
  return;
}

