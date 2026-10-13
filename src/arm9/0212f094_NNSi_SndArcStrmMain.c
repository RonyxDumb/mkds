/* Decompiled C draft; module arm9; ROM address 0212f094. No matching claim. */
#include "types.h"
#include "deps/0212f094_NNSi_SndArcStrmMain.h"

void NNSi_SndArcStrmMain(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  uint uVar6;
  
  iVar2 = iRam0212f1a8;
  iVar8 = 0;
  iVar7 = iRam0212f1a4;
  do {
    uVar6 = iVar7 + 0x110U & 3;
    uVar5 = *(uint *)(iVar7 + 0x110U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)(uVar6 << 0x1f) < 0) {
      uVar5 = iVar7 + 0x114U & 3;
      uVar3 = *(uint *)(iVar7 + 0x114U & 0xfffffffc);
      if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
        func_0212efb8(iVar7);
      }
      else {
        if (((int)(uVar6 << 0x1d) < 0) &&
           (uVar6 = iVar7 + 0x118U & 3, uVar5 = *(uint *)(iVar7 + 0x118U & 0xfffffffc),
           uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0)) {
          func_0212c948(iVar7);
          uVar6 = iVar7 + 0x110U & 3;
          uVar5 = *(uint *)(iVar7 + 0x110U & 0xfffffffc);
          *(uint *)(iVar7 + 0x110) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20 | 2;
          uVar6 = iVar7 + 0x110U & 3;
          uVar5 = *(uint *)(iVar7 + 0x110U & 0xfffffffc);
          *(uint *)(iVar7 + 0x110) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xfffffffb;
        }
        uVar6 = iVar7 + 0x110U & 3;
        uVar5 = *(uint *)(iVar7 + 0x110U & 0xfffffffc);
        if ((int)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) << 0x1e) < 0) {
          NNS_Snd_func_02068a34(iVar7 + 0xe8);
          uVar6 = iVar7 + 0x154U & 3;
          uVar5 = *(uint *)(iVar7 + 0x154U & 0xfffffffc);
          sVar1 = *(short *)(iVar2 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 2);
          iVar4 = func_0212f7f8(iVar7 + 0xe8);
          uVar6 = iVar7 + 0x158U & 3;
          uVar5 = *(uint *)(iVar7 + 0x158U & 0xfffffffc);
          uVar3 = (int)*(short *)(iVar2 + (iVar4 >> 8) * 2) + (int)sVar1;
          if (uVar3 != (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20)) {
            func_0212c8a4(iVar7,uVar3);
            *(uint *)(iVar7 + 0x158) = uVar3;
          }
          uVar6 = iVar7 + 0x110U & 3;
          uVar5 = *(uint *)(iVar7 + 0x110U & 0xfffffffc);
          if (((int)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) << 0x1c) < 0) &&
             (iVar4 = NNS_Snd_func_02068a4c(iVar7 + 0xe8), iVar4 != 0)) {
            func_0212efb8(iVar7);
          }
        }
      }
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x160;
  } while (iVar8 < 4);
  return;
}

