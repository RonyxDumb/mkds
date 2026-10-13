/* Decompiled C draft; module arm9; ROM address 020c1bc0. No matching claim. */
#include "types.h"
#include "deps/020c1bc0_func_020c1bc0.h"

void func_020c1bc0(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = *(uint *)(uRam020c1dc4 & 0xfffffffc) >> (uRam020c1dc4 & 3) * 8 |
          *(uint *)(uRam020c1dc4 & 0xfffffffc) << (uRam020c1dc4 & 3) * -8 + 0x20;
  uVar9 = uVar8 + 0xb0;
  uVar2 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20;
  uVar2 = iRam020c1dcc *
          ((int)((longlong)iRam020c1dc8 * (longlong)(int)uVar10 >> 0x21) - ((int)uVar10 >> 0x1f));
  *(uint *)(uVar8 + 0xb0) = uVar10 + 1;
  uVar9 = uRam020c1dd4;
  if (uVar10 == uVar2) {
    bVar1 = true;
    uVar8 = *(uint *)(uRam020c1dd0 & 0xfffffffc) >> (uRam020c1dd0 & 3) * 8 |
            *(uint *)(uRam020c1dd0 & 0xfffffffc) << (uRam020c1dd0 & 3) * -8 + 0x20;
    uVar2 = 0;
    if (*(char *)(uVar8 + 0x3d0) != '\0') {
      do {
        uVar7 = uVar8 + 0x1c & 3;
        uVar3 = *(uint *)(uVar8 + 0x1c & 0xfffffffc);
        if (((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) == 1) ||
           (uVar7 = uVar8 + 8 & 3, uVar8 = *(uint *)(uVar8 + 8 & 0xfffffffc),
           (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) == 2)) {
          uVar4 = Int32ToInt8(uVar2);
          iVar5 = GetSomeLUMaxIndex();
          iVar6 = Int32ToInt8(uVar4);
          uVar8 = (uint)*(byte *)(iVar6 * 10 +
                                  iVar5 * 0x50 +
                                  (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                                  *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 5);
        }
        else {
          uVar4 = Int32ToInt8(uVar2);
          iVar5 = GetSomeLUMaxIndex();
          iVar6 = Int32ToInt8(uVar4);
          uVar8 = (uint)*(ushort *)
                         (iVar5 * 0x50 +
                          (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
                          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + iVar6 * 10);
        }
        iVar5 = (*(uint *)(uRam020c1dc4 & 0xfffffffc) >> (uRam020c1dc4 & 3) * 8 |
                *(uint *)(uRam020c1dc4 & 0xfffffffc) << (uRam020c1dc4 & 3) * -8 + 0x20) + uVar2 * 4;
        uVar7 = iVar5 + 0x20;
        uVar3 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        uVar7 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
        if (((int)uVar7 < (int)uVar8) && ((int)uVar7 < 1000)) {
          bVar1 = false;
          *(uint *)(iVar5 + 0x20) = uVar7 + 1;
        }
        uVar8 = *(uint *)(uRam020c1dd0 & 0xfffffffc) >> (uRam020c1dd0 & 3) * 8 |
                *(uint *)(uRam020c1dd0 & 0xfffffffc) << (uRam020c1dd0 & 3) * -8 + 0x20;
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < *(byte *)(uVar8 + 0x3d0));
    }
    uVar9 = uRam020c1dc4;
    if (bVar1) {
      *(undefined4 *)
       ((*(uint *)(uRam020c1dc4 & 0xfffffffc) >> (uRam020c1dc4 & 3) * 8 |
        *(uint *)(uRam020c1dc4 & 0xfffffffc) << (uRam020c1dc4 & 3) * -8 + 0x20) + 0xac) =
           uRam020c1dd8;
      uVar2 = uRam020c1dd0;
      *(undefined4 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0xb0) = 0;
      *(undefined4 *)
       ((*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
        *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20) + 0xb0) = 0;
      uVar9 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      uVar2 = uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20;
      uVar9 = uVar2 + 0x1c;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      if (((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) == 1) ||
         (uVar2 = uVar2 + 8, uVar9 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
         (uVar2 >> uVar9 * 8 | uVar2 << uVar9 * -8 + 0x20) == 2)) {
        NNSi_MaybeSndPlayerStartSeq(uRam020c1ddc,0,0x29);
      }
    }
    else {
      NNSi_MaybeSndPlayerStartSeq(uRam020c1ddc,0,0x29);
    }
  }
  uVar9 = uRam020c1dc4;
  if ((*(ushort *)(iRam020c1de0 + 0x2e0) & 1) == 0) {
    return;
  }
  if ((int)uVar10 < 0x2d) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c1dc4 & 0xfffffffc) >> (uRam020c1dc4 & 3) * 8 |
    *(uint *)(uRam020c1dc4 & 0xfffffffc) << (uRam020c1dc4 & 3) * -8 + 0x20) + 0xac) = uRam020c1dd8;
  uVar2 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  *(undefined4 *)((uVar9 >> uVar2 * 8 | uVar9 << uVar2 * -8 + 0x20) + 0xb0) = 0;
  return;
}

