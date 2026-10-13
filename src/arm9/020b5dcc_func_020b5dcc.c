/* Decompiled C draft; module arm9; ROM address 020b5dcc. No matching claim. */
#include "types.h"
#include "deps/020b5dcc_func_020b5dcc.h"

void func_020b5dcc(undefined1 param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int local_28 [2];
  int local_20;
  uint uVar17;
  
  uVar11 = *(uint *)(uRam020b5f64 & 0xfffffffc) >> (uRam020b5f64 & 3) * 8 |
           *(uint *)(uRam020b5f64 & 0xfffffffc) << (uRam020b5f64 & 3) * -8 + 0x20;
  uVar8 = *(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
          *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20;
  uVar1 = uVar11 + 4 & 3;
  uVar16 = *(uint *)(uVar11 + 4 & 0xfffffffc);
  uVar17 = uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20;
  uVar1 = uVar11 + 0x20 & 3;
  uVar16 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
  uVar15 = uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20;
  uVar1 = uVar11 + 0x24 & 3;
  uVar16 = *(uint *)(uVar11 + 0x24 & 0xfffffffc);
  uVar14 = uVar16 >> uVar1 * 8 | uVar16 << uVar1 * -8 + 0x20;
  uVar16 = uVar11 + 0x4c & 3;
  uVar13 = *(uint *)(uVar11 + 0x4c & 0xfffffffc);
  uVar2 = uVar11 + 0x50 & 3;
  uVar12 = *(uint *)(uVar11 + 0x50 & 0xfffffffc);
  GetDriverMaybeSfxPosition(local_28,param_1);
  uVar11 = *(uint *)(uRam020b5f64 & 0xfffffffc) >> (uRam020b5f64 & 3) * 8 |
           *(uint *)(uRam020b5f64 & 0xfffffffc) << (uRam020b5f64 & 3) * -8 + 0x20;
  uVar1 = uVar11 + 0x5c;
  uVar10 = uVar1 & 3;
  uVar9 = *(uint *)(uVar1 & 0xfffffffc);
  uVar11 = uVar11 + 0x60;
  uVar1 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar3 = func_020b57b4(local_28[0] - (uVar13 >> uVar16 * 8 | uVar13 << uVar16 * -8 + 0x20),
                        uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20,
                        uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20);
  iVar4 = SomeFxProduct(0x200000,uVar3);
  uVar11 = *(uint *)(uRam020b5f64 & 0xfffffffc) >> (uRam020b5f64 & 3) * 8 |
           *(uint *)(uRam020b5f64 & 0xfffffffc) << (uRam020b5f64 & 3) * -8 + 0x20;
  uVar1 = uVar11 + 100;
  uVar16 = uVar1 & 3;
  uVar10 = *(uint *)(uVar1 & 0xfffffffc);
  uVar11 = uVar11 + 0x68;
  uVar1 = uVar11 & 3;
  uVar11 = *(uint *)(uVar11 & 0xfffffffc);
  uVar3 = func_020b57b4(local_20 - (uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20),
                        uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20,
                        uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20);
  iVar5 = SomeFxProduct(0x200000,uVar3);
  iVar6 = func_020b523c();
  if (iVar6 != 0) {
    iVar5 = iVar5 - uVar17;
    iVar4 = iVar4 - uVar8;
    iVar6 = SomeFxProduct(-uVar15,iVar4);
    iVar7 = SomeFxProduct(uVar14,iVar5);
    iVar6 = func_020b5250(iVar6 + iVar7);
    *param_2 = iVar6 + 0x80;
    iVar4 = SomeFxProduct(uVar14,iVar4);
    iVar5 = SomeFxProduct(uVar15,iVar5);
    iVar4 = func_020b5250(iVar4 + iVar5);
    param_2[1] = iVar4 + 0x60;
    return;
  }
  iVar4 = iVar4 - uVar8;
  iVar5 = iVar5 - uVar17;
  iVar6 = SomeFxProduct(uVar15,iVar4);
  iVar7 = SomeFxProduct(uVar14,iVar5);
  iVar6 = func_020b5250(iVar6 - iVar7);
  *param_2 = iVar6 + 0x80;
  iVar4 = SomeFxProduct(uVar14,iVar4);
  iVar5 = SomeFxProduct(uVar15,iVar5);
  iVar4 = func_020b5250(iVar4 + iVar5);
  param_2[1] = iVar4 + 0x60;
  return;
}

