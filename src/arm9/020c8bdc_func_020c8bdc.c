/* Decompiled C draft; module arm9; ROM address 020c8bdc. No matching claim. */
#include "types.h"
#include "deps/020c8bdc_func_020c8bdc.h"

void func_020c8bdc(void)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  short sVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int aiStack_30 [2];
  int iStack_28;
  
  uVar6 = func_020c0db0();
  uVar3 = uRam020c8d14;
  uVar8 = *(uint *)(uRam020c8d14 & 0xfffffffc) >> (uRam020c8d14 & 3) * 8 |
          *(uint *)(uRam020c8d14 & 0xfffffffc) << (uRam020c8d14 & 3) * -8 + 0x20;
  iVar11 = 0;
  uVar9 = uVar8 + 8 & 3;
  uVar7 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  iVar12 = iVar11;
  if ((int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) < 1) {
    return;
  }
  do {
    uVar9 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar12 * 4;
    uVar7 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar9 = uVar7 + 0x60 & 3;
    uVar8 = *(uint *)(uVar7 + 0x60 & 0xfffffffc);
    uVar10 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    uVar9 = uVar7 + 0x40 & 3;
    uVar8 = *(uint *)(uVar7 + 0x40 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) * (longlong)(int)uVar10
    ;
    uVar9 = uVar7 + 0x48 & 3;
    uVar8 = *(uint *)(uVar7 + 0x48 & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) * (longlong)(int)uVar10
    ;
    uVar10 = uVar7 + 4;
    uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar9 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    if (*(char *)((*(uint *)(uRam020c8d18 & 0xfffffffc) >> (uRam020c8d18 & 3) * 8 |
                  *(uint *)(uRam020c8d18 & 0xfffffffc) << (uRam020c8d18 & 3) * -8 + 0x20) + 0x57) ==
        '\0') {
      uVar5 = FX_Atan2(uVar9,uVar8);
      *(undefined2 *)
       ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
        *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar12 * 2 + 0xc) = uVar5;
    }
    else {
      sVar4 = FX_Atan2(-uVar9,uVar8);
      *(short *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar12 * 2 + 0xc) =
           sVar4 + -0x8000;
    }
    func_020b5ae8(uVar10,(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                         *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x14 + iVar11,
                  uVar6,0);
    aiStack_30[0] =
         (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
         *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + uVar8;
    uVar8 = uVar7 + 0xc & 3;
    uVar7 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    iStack_28 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + uVar9;
    func_020b5ae8(aiStack_30,
                  (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x2c + iVar11,uVar6,0)
    ;
    uVar8 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    iVar12 = iVar12 + 1;
    uVar9 = uVar8 + 8 & 3;
    uVar7 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    iVar11 = iVar11 + 8;
  } while (iVar12 < (int)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20));
  return;
}

