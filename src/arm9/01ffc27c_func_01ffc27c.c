/* Decompiled C draft; module arm9; ROM address 01ffc27c. No matching claim. */
#include "types.h"
#include "deps/01ffc27c_func_01ffc27c.h"

undefined4 func_01ffc27c(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  short sVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  bool bVar15;
  undefined1 auStack_20 [12];
  uint uVar10;
  
  iVar3 = iRam01ffc4fc;
  iVar4 = iRam01ffc4f8;
  iVar2 = iRam01ffc4f4;
  uVar10 = param_1 + 0x2ccU & 3;
  uVar7 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar9 = param_1 + 0x4cU & 3;
  uVar5 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  iVar8 = (int)*(short *)((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) + 0x30);
  bVar15 = ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 0x30000000) != 0;
  uVar14 = 0;
  puVar13 = (undefined4 *)auStack_20;
  if (bVar15) {
    puVar13 = (undefined4 *)&stack0xffffffec;
  }
  uVar12 = 0;
  uVar6 = 1;
  if (bVar15) {
    return 0;
  }
  uVar10 = param_1 + 0x2a8U & 3;
  uVar9 = *(uint *)(param_1 + 0x2a8U & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  uVar9 = uVar10;
  if ((int)uVar10 < 1) {
    uVar9 = -uVar10;
  }
  if ((int)uVar9 < 0x2000) {
    if ((int)uVar10 < 1) {
      uVar10 = -uVar10;
    }
    iVar8 = (iVar8 + (short)((uint)(iVar8 * ((int)uVar10 >> 1)) >> 0xc)) * 0x8000 >> 0x10;
  }
  uVar10 = param_1 + 0x44U & 3;
  uVar9 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  if (((uVar10 & 0x800) != 0) && ((uVar10 & 2) != 0)) {
    uVar9 = param_1 + 0x2c4U & 3;
    uVar5 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
    iVar8 = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) * 0x168;
    if (param_2 == 0) {
      if ((uVar10 & 0x100) == 0) {
        iVar4 = 1;
      }
      else {
        iVar4 = -1;
      }
      iVar8 = iVar8 * iVar4;
    }
    sVar11 = (short)iVar8;
    uVar10 = param_1 + 0x7cU & 3;
    uVar9 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) & 2) != 0) {
      sVar11 = (short)(iVar8 << 1);
    }
    *(short *)(param_1 + 0x236) = *(short *)(param_1 + 0x236) - sVar11;
    uVar10 = param_1 + 0x78U & 3;
    uVar9 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    uVar1 = *(ushort *)(iVar2 + (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * 0x5c);
    if ((uVar1 & 0x20) == 0) {
      if ((uVar1 & 0x10) != 0) {
        uVar10 = param_1 + 0x48U & 3;
        uVar9 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
        *(uint *)(param_1 + 0x48) = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20 | 0x10;
      }
    }
    else {
      uVar10 = param_1 + 0x48U & 3;
      uVar9 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20 | 8;
    }
    return 1;
  }
  if ((uVar10 & 0x10) == 0) {
    uVar10 = param_1 + 0x78U & 3;
    uVar9 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    uVar1 = *(ushort *)(iRam01ffc4f4 + (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * 0x5c);
    if ((uVar1 & 0x40) == 0) {
      if (((uVar1 & 0x80) != 0) &&
         (*(short *)(param_1 + 0x234) = *(short *)(param_1 + 0x234) + -300,
         *(short *)(param_1 + 0x234) < iVar3)) {
        *(short *)(param_1 + 0x234) = (short)iVar3;
      }
    }
    else {
      *(short *)(param_1 + 0x234) = *(short *)(param_1 + 0x234) + 0x96;
      if (iVar4 < *(short *)(param_1 + 0x234)) {
        *(short *)(param_1 + 0x234) = (short)iVar4;
      }
    }
    uVar14 = 1;
  }
  uVar10 = param_1 + 0x44U & 3;
  uVar9 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar9 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
  uVar10 = uVar9 & 0x100;
  if (((uVar10 != 0) &&
      (uVar5 = param_1 + 0x78U & 3, uVar7 = *(uint *)(param_1 + 0x78U & 0xfffffffc),
      (*(ushort *)(iRam01ffc4f4 + (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) * 0x5c) & 2) !=
      0)) || ((uVar10 != 0 && ((uVar9 & 10) == 0)))) {
    uVar6 = 0xffffffff;
    iVar8 = (short)iVar8 * -0x10000 >> 0x10;
  }
  uVar10 = param_1 + 0x78U & 3;
  uVar9 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  uVar1 = *(ushort *)(iRam01ffc4f4 + (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20) * 0x5c);
  if ((uVar1 & 0x20) == 0) {
    if ((uVar1 & 0x10) != 0) {
      *puVar13 = uVar14;
      puVar13[1] = 0x10;
      uVar12 = func_01ffc158(param_1,iVar8,uVar6,0xffffffff);
    }
  }
  else {
    *puVar13 = uVar14;
    puVar13[1] = 8;
    uVar12 = func_01ffc158(param_1,iVar8,uVar6,1);
  }
  return uVar12;
}

