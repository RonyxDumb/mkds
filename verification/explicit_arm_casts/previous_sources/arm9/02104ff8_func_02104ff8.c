/* Decompiled C draft; module arm9; ROM address 02104ff8. No matching claim. */
#include "types.h"
#include "deps/02104ff8_func_02104ff8.h"

void func_02104ff8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  iVar3 = iRam0210514c;
  iVar2 = iRam02105148;
  uVar4 = (*(uint *)(uRam02105144 & 0xfffffffc) >> (uRam02105144 & 3) * 8 |
          *(uint *)(uRam02105144 & 0xfffffffc) << (uRam02105144 & 3) * -8 + 0x20) + 8;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
    uVar4 = 0;
    do {
      uVar5 = iVar3 + uVar4 * 4;
      uVar7 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
      iVar1 = uVar4 * 4;
      if ((-1 < (int)uVar5) &&
         (iVar8 = (uVar4 & 0xffff) * 0x210 +
                  (*(uint *)(uRam02105150 & 0xfffffffc) >> (uRam02105150 & 3) * 8 |
                  *(uint *)(uRam02105150 & 0xfffffffc) << (uRam02105150 & 3) * -8 + 0x20),
         uVar7 = iVar8 + 0x30, uVar6 = uVar7 & 3, uVar7 = *(uint *)(uVar7 & 0xfffffffc),
         (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) == 0x13)) {
        if (uVar5 == 0) {
          func_020f47e4(iVar8 + 0x30,0x11);
          uVar7 = uRam02105144;
          *(undefined4 *)(iVar2 + uVar4 * 4) = 0;
          uVar5 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          if ((uVar4 == (int)*(char *)((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 0x62)) &&
             (((*(uint *)(uRam02105154 & 0xfffffffc) >> (uRam02105154 & 3) * 8 |
               *(uint *)(uRam02105154 & 0xfffffffc) << (uRam02105154 & 3) * -8 + 0x20) & 1) != 0)) {
            func_02108ea0(0);
            uVar7 = GetSomeSndPlayer();
            uVar5 = iRam02105158 + 0xcU & 3;
            uVar6 = *(uint *)(iRam02105158 + 0xcU & 0xfffffffc);
            if (uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0) {
              if (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 != 0 ||
                  *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20 != 0) {
                func_0212c6f0(uVar7,0);
              }
              if (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 != 0 ||
                  *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20 != 0) {
                func_0212c6f0(uVar7,0);
              }
              NNSi_MaybeSndPlayerStartSeq(uVar7,0,0x3f);
            }
          }
        }
        else {
          uVar7 = iVar2 + iVar1;
          uVar6 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          if ((uVar7 >> uVar6 * 8 != 0 || uVar7 << uVar6 * -8 + 0x20 != 0) && (0 < (int)uVar5)) {
            uVar5 = iVar3 + iVar1 & 3;
            uVar7 = *(uint *)(iVar3 + iVar1 & 0xfffffffc);
            *(uint *)(iVar3 + iVar1) = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) - 1;
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 8);
    return;
  }
  return;
}

