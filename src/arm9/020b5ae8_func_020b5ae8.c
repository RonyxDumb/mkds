/* Decompiled C draft; module arm9; ROM address 020b5ae8. No matching claim. */
#include "types.h"
#include "deps/020b5ae8_func_020b5ae8.h"

undefined4 func_020b5ae8(uint param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar2;
  
  uVar11 = *(uint *)(uRam020b5dc8 & 0xfffffffc) >> (uRam020b5dc8 & 3) * 8 |
           *(uint *)(uRam020b5dc8 & 0xfffffffc) << (uRam020b5dc8 & 3) * -8 + 0x20;
  uVar9 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
          *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
  uVar17 = uVar11 + 4 & 3;
  uVar1 = *(uint *)(uVar11 + 4 & 0xfffffffc);
  uVar2 = uVar1 >> uVar17 * 8 | uVar1 << uVar17 * -8 + 0x20;
  uVar17 = uVar11 + 0x20 & 3;
  uVar1 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
  uVar16 = uVar1 >> uVar17 * 8 | uVar1 << uVar17 * -8 + 0x20;
  uVar17 = uVar11 + 0x24 & 3;
  uVar1 = *(uint *)(uVar11 + 0x24 & 0xfffffffc);
  uVar15 = uVar1 >> uVar17 * 8 | uVar1 << uVar17 * -8 + 0x20;
  uVar17 = uVar11 + 0x4c & 3;
  uVar13 = *(uint *)(uVar11 + 0x4c & 0xfffffffc);
  uVar12 = uVar11 + 0x50 & 3;
  uVar3 = *(uint *)(uVar11 + 0x50 & 0xfffffffc);
  uVar1 = uVar11 + 0x5c & 3;
  uVar10 = *(uint *)(uVar11 + 0x5c & 0xfffffffc);
  uVar14 = uVar11 + 0x60 & 3;
  uVar11 = *(uint *)(uVar11 + 0x60 & 0xfffffffc);
  uVar4 = func_020b57b4((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                        *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
                        (uVar13 >> uVar17 * 8 | uVar13 << uVar17 * -8 + 0x20),
                        uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20,
                        uVar11 >> uVar14 * 8 | uVar11 << uVar14 * -8 + 0x20);
  iVar5 = SomeFxProduct(0x200000,uVar4);
  uVar14 = param_1 + 8 & 3;
  uVar13 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar1 = *(uint *)(uRam020b5dc8 & 0xfffffffc) >> (uRam020b5dc8 & 3) * 8 |
          *(uint *)(uRam020b5dc8 & 0xfffffffc) << (uRam020b5dc8 & 3) * -8 + 0x20;
  uVar17 = uVar1 + 100;
  uVar10 = uVar17 & 3;
  uVar11 = *(uint *)(uVar17 & 0xfffffffc);
  uVar1 = uVar1 + 0x68;
  uVar17 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar4 = func_020b57b4((uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20) -
                        (uVar3 >> uVar12 * 8 | uVar3 << uVar12 * -8 + 0x20),
                        uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20,
                        uVar1 >> uVar17 * 8 | uVar1 << uVar17 * -8 + 0x20);
  iVar6 = SomeFxProduct(0x200000,uVar4);
  if (param_4 != 0) {
    uVar14 = *(uint *)(uRam020b5dc8 & 0xfffffffc) >> (uRam020b5dc8 & 3) * 8 |
             *(uint *)(uRam020b5dc8 & 0xfffffffc) << (uRam020b5dc8 & 3) * -8 + 0x20;
    uVar17 = uVar14 + 0x10 & 3;
    uVar1 = *(uint *)(uVar14 + 0x10 & 0xfffffffc);
    uVar12 = uVar1 >> uVar17 * 8 | uVar1 << uVar17 * -8 + 0x20;
    uVar17 = uVar14 + 0x14 & 3;
    uVar1 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
    uVar1 = uVar1 >> uVar17 * 8 | uVar1 << uVar17 * -8 + 0x20;
    uVar17 = uVar14 + 0x18 & 3;
    uVar14 = *(uint *)(uVar14 + 0x18 & 0xfffffffc);
    uVar17 = uVar14 >> uVar17 * 8 | uVar14 << uVar17 * -8 + 0x20;
    iVar7 = func_020b5250(iVar5);
    iVar8 = func_020b5250(iVar6);
    if (((((int)uVar12 <= (int)(iVar7 - uVar17)) || ((int)(iVar7 + uVar17) <= (int)uVar12)) ||
        ((int)uVar1 <= (int)(iVar8 - uVar17))) || ((int)(iVar8 + uVar17) <= (int)uVar1)) {
      return 0;
    }
  }
  if (param_5 == 0) {
    iVar7 = func_020b5250(uVar9);
    if (iVar7 < 1) {
      iVar7 = func_020b5250(uVar9);
      uVar4 = FUN_02132440(iVar7 << 0xc);
      func_021329f8(uVar4,0x3f000000);
    }
    else {
      iVar7 = func_020b5250(uVar9);
      uVar4 = FUN_02132440(iVar7 << 0xc);
      func_02131234(0x3f000000,uVar4);
    }
    uVar9 = func_021322c8();
    iVar7 = func_020b5250(uVar2);
    if (iVar7 < 1) {
      iVar7 = func_020b5250(uVar2);
      uVar4 = FUN_02132440(iVar7 << 0xc);
      func_021329f8(uVar4,0x3f000000);
    }
    else {
      iVar7 = func_020b5250(uVar2);
      uVar4 = FUN_02132440(iVar7 << 0xc);
      func_02131234(0x3f000000,uVar4);
    }
    uVar2 = func_021322c8();
  }
  iVar7 = func_020b523c();
  if (iVar7 == 0) {
    iVar7 = SomeFxProduct(uVar16,iVar5 - uVar9);
    iVar8 = SomeFxProduct(uVar15,iVar6 - uVar2);
    iVar7 = func_020b5250(iVar7 - iVar8);
    iVar5 = SomeFxProduct(uVar15,iVar5 - uVar9);
    iVar6 = SomeFxProduct(uVar16,iVar6 - uVar2);
    iVar5 = func_020b5250(iVar5 + iVar6);
  }
  else {
    iVar7 = SomeFxProduct(-uVar16,iVar5 - uVar9);
    iVar8 = SomeFxProduct(uVar15,iVar6 - uVar2);
    iVar7 = func_020b5250(iVar7 + iVar8);
    iVar5 = SomeFxProduct(uVar15,iVar5 - uVar9);
    iVar6 = SomeFxProduct(uVar16,iVar6 - uVar2);
    iVar5 = func_020b5250(iVar5 + iVar6);
  }
  iVar7 = iVar7 + 0x80;
  iVar6 = iVar5 + 0x60;
  if (((-0x20 < iVar7) && (iVar7 < 0x120)) && (-0x20 < iVar6)) {
    if (iVar6 < 0xe0) {
      *param_2 = iVar7;
    }
    if (iVar5 + -0x80 < 0 != SBORROW4(iVar6,0xe0)) {
      param_2[1] = iVar6;
      return 1;
    }
  }
  *param_2 = iVar7;
  param_2[1] = iVar6;
  return 0;
}

