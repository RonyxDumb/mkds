/* Decompiled C draft; module arm9; ROM address 02104144. No matching claim. */
#include "types.h"
#include "deps/02104144_func_02104144.h"

void func_02104144(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  
  if (*(uint *)(uRam02104320 & 0xfffffffc) >> (uRam02104320 & 3) * 8 == 0 &&
      *(uint *)(uRam02104320 & 0xfffffffc) << (uRam02104320 & 3) * -8 + 0x20 == 0) {
    return;
  }
  iVar9 = func_0203c5e4();
  puVar4 = puRam02104330;
  puVar3 = puRam0210432c;
  puVar2 = puRam02104328;
  if (iVar9 == 0) {
    *puRam02104324 = *puRam02104324 & 0xcfff | 8;
    puVar5 = puRam02104334;
    uVar1 = param_1 + 8U & 3;
    uVar12 = *(uint *)(param_1 + 8U & 0xfffffffc);
    *puVar2 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    puVar6 = puRam02104338;
    uVar1 = param_1 + 0xcU & 3;
    uVar12 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *puVar3 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    uVar7 = uRam0210433c;
    uVar1 = param_1 + 0x10U & 3;
    uVar12 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    *puVar4 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x14U & 3;
    uVar12 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    *puVar5 = uVar12 >> uVar1 * 8 | uVar12 << uVar1 * -8 + 0x20;
    *puVar6 = 0;
    G3_LoadMtx44(uVar7);
    puVar6 = puRam02104338;
    *puRam02104338 = 3;
    puVar8 = puRam02104340;
    iVar9 = 0;
    *puRam02104340 = 0;
    *puVar6 = 2;
    *puVar8 = 0;
    puVar6 = puRam02104344;
    *puRam02104344 = 0x64000;
    *puVar6 = 0x64000;
    uVar1 = uRam02104320;
    *puVar6 = 0x64000;
    puVar5 = puRam02104358;
    puVar4 = puRam02104354;
    puVar3 = puRam02104350;
    puVar2 = puRam0210434c;
    if (0 < (int)(*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                 *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20)) {
      iVar11 = 0;
      uVar12 = (uint)*puRam02104348;
      do {
        uVar14 = param_1 + 4U & 3;
        uVar15 = *(uint *)(param_1 + 4U & 0xfffffffc);
        uVar13 = *(uint *)(uRam0210435c & 0xfffffffc) >> (uRam0210435c & 3) * 8 |
                 *(uint *)(uRam0210435c & 0xfffffffc) << (uRam0210435c & 3) * -8 + 0x20;
        *puVar2 = uVar15 >> uVar14 * 8 | uVar15 << uVar14 * -8 + 0x20 | uVar12 << 0x18;
        iVar10 = uVar13 + iVar11;
        *puRam02104360 = 1;
        *puVar3 = 0;
        uVar13 = uVar13 + iVar11;
        uVar14 = uVar13 & 3;
        uVar13 = *(uint *)(uVar13 & 0xfffffffc);
        iVar9 = iVar9 + 1;
        *puVar4 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
        *puVar4 = 0;
        uVar13 = param_1 + 0x1cU & 3;
        uVar14 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
        iVar11 = iVar11 + 0x34;
        *puVar3 = ((int)((uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) << 8) >> 0x10) <<
                  0x10;
        uVar13 = iVar10 + 4U & 3;
        uVar14 = *(uint *)(iVar10 + 4U & 0xfffffffc);
        uVar12 = uVar12 + 1;
        *puVar5 = uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20;
        uVar13 = param_1 + 0x18U & 3;
        uVar15 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
        uVar14 = param_1 + 0x1cU & 3;
        uVar16 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
        *puVar3 = (int)((uVar15 >> uVar13 * 8 | uVar15 << uVar13 * -8 + 0x20) << 8) >> 0x10 &
                  0xffffU | ((int)((uVar16 >> uVar14 * 8 | uVar16 << uVar14 * -8 + 0x20) << 8) >>
                            0x10) << 0x10;
        uVar13 = iVar10 + 8U & 3;
        uVar14 = *(uint *)(iVar10 + 8U & 0xfffffffc);
        *puVar5 = uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20;
        uVar13 = param_1 + 0x18U & 3;
        uVar14 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
        *puVar3 = (int)((uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20) << 8) >> 0x10 & 0xffff
        ;
        uVar13 = iVar10 + 0xcU & 3;
        uVar14 = *(uint *)(iVar10 + 0xcU & 0xfffffffc);
        *puVar5 = uVar14 >> uVar13 * 8 | uVar14 << uVar13 * -8 + 0x20;
        *puRam02104364 = 0;
      } while (iVar9 < (int)(*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20));
      return;
    }
    return;
  }
  return;
}

