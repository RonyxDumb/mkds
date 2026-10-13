/* Decompiled C draft; module arm9; ROM address 020a1520. No matching claim. */
#include "types.h"
#include "deps/020a1520_func_020a1520.h"

undefined2 func_020a1520(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar4 = uRam020a16bc;
  uVar5 = *(uint *)(uRam020a16bc & 0xfffffffc) >> (uRam020a16bc & 3) * 8 |
          *(uint *)(uRam020a16bc & 0xfffffffc) << (uRam020a16bc & 3) * -8 + 0x20;
  uVar7 = uVar5 + 0x3b4 & 3;
  uVar3 = *(uint *)(uVar5 + 0x3b4 & 0xfffffffc);
  if (-1 < (int)(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
    return 0;
  }
  uVar7 = *(ushort *)(uVar5 + 0x3a4) + 1;
  if (2 < uVar7) {
    uVar7 = 3;
  }
  *(short *)(uVar5 + 0x3a4) = (short)uVar7;
  uVar5 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar7 = iRam020a16c0 + (uint)*(ushort *)(uVar5 + 0x3a4) * 4;
  uVar3 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(ushort *)(uVar5 + 0x3a2) = (ushort)(uVar7 >> uVar3 * 8) | (ushort)(uVar7 << uVar3 * -8 + 0x20);
  uVar3 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar7 = uVar3 + 0x3b0;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  uVar3 = uVar3 + 0x3ac;
  uVar7 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar5 != (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20)) {
    uVar7 = *(uint *)(uRam020a16c4 & 0xfffffffc) >> (uRam020a16c4 & 3) * 8 |
            *(uint *)(uRam020a16c4 & 0xfffffffc) << (uRam020a16c4 & 3) * -8 + 0x20;
    uVar3 = 0;
    bVar1 = *(byte *)(uVar7 + 0x3d0);
    if (-1 < (int)uVar5) {
      uVar2 = (uint)bVar1;
      do {
        while (uVar2 = uVar2 - 1, -1 < (int)uVar2) {
          uVar6 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
          uVar8 = uVar6;
          uVar9 = 0;
          do {
            if ((uVar2 & 0xffff) == (uint)*(ushort *)(uVar8 + 0x48)) {
              uVar7 = uVar9 & 0xffff;
              break;
            }
            uVar9 = uVar9 + 1;
            uVar8 = uVar8 + 0x70;
            uVar7 = 0;
          } while ((int)uVar9 < 8);
          uVar8 = uVar7 * 0x70 + uVar6 + 0x4c;
          uVar9 = uVar8 & 3;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc);
          if (uVar3 == (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20)) {
            uVar7 = MaybeKillDriverDirect();
          }
        }
        func_020a1790(uVar7);
        uVar7 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x3b4;
        uVar2 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
        if (-1 < (int)uVar7) {
          return 0;
        }
        uVar3 = uVar3 + 1;
        uVar2 = (uint)bVar1;
      } while ((int)uVar3 <= (int)uVar5);
    }
  }
  if (((*(uint *)(uRam020a16c8 & 0xfffffffc) >> (uRam020a16c8 & 3) * 8 |
       *(uint *)(uRam020a16c8 & 0xfffffffc) << (uRam020a16c8 & 3) * -8 + 0x20) & 1) != 0) {
    func_02108ea0(0);
    uVar4 = GetSomeSndPlayer();
    uVar7 = iRam020a16cc + 0xcU & 3;
    uVar3 = *(uint *)(iRam020a16cc + 0xcU & 0xfffffffc);
    if (uVar3 >> uVar7 * 8 != 0 || uVar3 << uVar7 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar4,0);
      }
      if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar4,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar4,0,0x4b);
    }
  }
  return *(undefined2 *)
          ((*(uint *)(uRam020a16bc & 0xfffffffc) >> (uRam020a16bc & 3) * 8 |
           *(uint *)(uRam020a16bc & 0xfffffffc) << (uRam020a16bc & 3) * -8 + 0x20) + 0x3a2);
}

