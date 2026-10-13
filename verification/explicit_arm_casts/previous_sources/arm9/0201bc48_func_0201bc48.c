/* Decompiled C draft; module arm9; ROM address 0201bc48. No matching claim. */
#include "types.h"
#include "deps/0201bc48_func_0201bc48.h"

void func_0201bc48(int param_1,int param_2)

{
  short sVar1;
  longlong lVar2;
  longlong lVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  uint uVar10;
  
  uVar7 = (uint)*(ushort *)(param_2 + 0x2e);
  uVar9 = param_1 + 0x40U & 3;
  uVar13 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar9 = (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) + 0x20;
  uVar13 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
  uVar9 = param_1 + 0x3cU & 3;
  uVar5 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  uVar13 = uVar10 & 3;
  uVar10 = *(uint *)(uVar10 & 0xfffffffc);
  sVar1 = *(short *)((uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20) + 0x30);
  iVar6 = (int)((uVar7 & 0x1f) * (((uVar7 << 0x16) >> 0x1b) + 1)) >> 5;
  uVar13 = param_1 + 0x44U & 3;
  uVar10 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar13 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
  *puRam0201c088 =
       uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20 | 0xc0 | ((uVar7 << 0x10) >> 0x1a) << 0x18 |
       iVar6 << 0x10;
  if (iVar6 == 0) {
    return;
  }
  uVar9 = param_2 + 0x30U & 3;
  uVar5 = *(uint *)(param_2 + 0x30U & 0xfffffffc);
  uVar10 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  uVar9 = param_1 + 0x40U & 3;
  uVar5 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar9 = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) + 0x20;
  uVar5 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar5 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  lVar2 = (longlong)(int)uVar10 * (longlong)(int)sVar1 + 0x800;
  uVar9 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20;
  uVar9 = uVar7 + 0x48 & 3;
  uVar5 = *(uint *)(uVar7 + 0x48 & 0xfffffffc);
  uVar14 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  uVar9 = ((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) << 1) >> 0x1d;
  if (uVar9 == 0) {
    uVar9 = (uint)*(short *)(param_2 + 0x34);
    uVar5 = (uint)((ulonglong)uVar9 * (ulonglong)uVar10);
    lVar2 = (longlong)(int)uVar14 * (longlong)(int)uVar9 + 0x800;
    uVar14 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uVar10 = uVar5 + 0x800 >> 0xc |
             (((int)uVar10 >> 0x1f) * uVar9 +
              uVar10 * ((int)uVar9 >> 0x1f) + (int)((ulonglong)uVar9 * (ulonglong)uVar10 >> 0x20) +
             (uint)(0xfffff7ff < uVar5)) * 0x100000;
  }
  else if (uVar9 == 1) {
    lVar2 = (longlong)(int)uVar14 * (longlong)(int)*(short *)(param_2 + 0x34) + 0x800;
    uVar14 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
  }
  else if (uVar9 == 2) {
    uVar9 = (uint)*(short *)(param_2 + 0x34);
    uVar5 = (uint)((ulonglong)uVar9 * (ulonglong)uVar10);
    uVar10 = uVar5 + 0x800 >> 0xc |
             (((int)uVar10 >> 0x1f) * uVar9 +
              uVar10 * ((int)uVar9 >> 0x1f) + (int)((ulonglong)uVar9 * (ulonglong)uVar10 >> 0x20) +
             (uint)(0xfffff7ff < uVar5)) * 0x100000;
  }
  if ((int)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
            *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) << 8) < 0) {
    uVar9 = param_2 + 8U & 3;
    uVar15 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar5 = param_2 + 0x38U & 3;
    uVar11 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    uVar12 = uVar7 + 4 & 3;
    uVar7 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    iStack_60 = ((uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) +
                (uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20)) -
                (uVar7 >> uVar12 * 8 | uVar7 << uVar12 * -8 + 0x20);
    uVar9 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar5 = param_2 + 0xcU & 3;
    uVar15 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar9 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0x20;
    uVar7 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar12 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x3cU & 3;
    uVar11 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar9 = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) + 8;
    uVar12 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iStack_5c = ((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) +
                (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20)) -
                (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
    uVar9 = param_1 + 0x40U & 3;
    uVar7 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar5 = param_2 + 0x10U & 3;
    uVar15 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar9 = (uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20) + 0x20;
    uVar7 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar12 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
    uVar7 = param_2 + 0x40U & 3;
    uVar11 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    uVar9 = uVar12 & 3;
    uVar12 = *(uint *)(uVar12 & 0xfffffffc);
    uVar9 = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) + 0xc;
    uVar12 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iStack_58 = ((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) +
                (uVar11 >> uVar7 * 8 | uVar11 << uVar7 * -8 + 0x20)) -
                (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20);
    func_02147288(&iStack_60,uVar13,&iStack_60);
    iVar6 = (int)(uint)*(ushort *)(param_2 + 0x20) >> 4;
    iVar8 = (int)*(short *)(iRam0201c08c + iVar6 * 4);
    iVar6 = (int)*(short *)(iRam0201c08c + (iVar6 * 2 + 1) * 2);
    iStack_30 = iStack_60;
    uStack_34 = 0x1000;
    iStack_2c = iStack_5c;
    lVar2 = (longlong)iVar6 * (longlong)(int)uVar14 + 0x800;
    uStack_54 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    iStack_28 = iStack_58;
    lVar2 = (longlong)iVar8 * (longlong)(int)uVar14 + 0x800;
    uStack_50 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    lVar2 = (longlong)-iVar8 * (longlong)(int)uVar10 + 0x800;
    lVar3 = (longlong)iVar6 * (longlong)(int)uVar10 + 0x800;
    uStack_48 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uStack_44 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
    uStack_4c = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    *puRam0201c090 = 0;
    puVar4 = puRam0201c094;
    uVar9 = param_1 + 0x40U & 3;
    uVar13 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar9 = (uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) + 0x20;
    uVar13 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar13 = uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20;
    uVar9 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar7 = uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20;
    uVar9 = uVar7 + 0xc & 3;
    uVar14 = *(uint *)(uVar7 + 0xc & 0xfffffffc);
    uVar13 = uVar7 + 8 & 3;
    uVar10 = *(uint *)(uVar7 + 8 & 0xfffffffc);
    uVar5 = uVar7 + 4 & 3;
    uVar7 = *(uint *)(uVar7 + 4 & 0xfffffffc);
    *puRam0201c094 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
    *puVar4 = uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20;
    *puVar4 = uVar14 >> uVar9 * 8 | uVar14 << uVar9 * -8 + 0x20;
    G3_MultMtx43(&uStack_54);
  }
  else {
    uVar9 = param_2 + 8U & 3;
    uVar12 = *(uint *)(param_2 + 8U & 0xfffffffc);
    uVar5 = param_2 + 0x38U & 3;
    uVar7 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
    iStack_60 = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) +
                (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    uVar9 = param_2 + 0xcU & 3;
    uVar12 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
    uVar5 = param_2 + 0x3cU & 3;
    uVar7 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    iStack_5c = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) +
                (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    uVar9 = param_2 + 0x10U & 3;
    uVar12 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
    uVar5 = param_2 + 0x40U & 3;
    uVar7 = *(uint *)(param_2 + 0x40U & 0xfffffffc);
    iStack_58 = (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) +
                (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
    func_02147288(&iStack_60,uVar13,&iStack_60);
    iVar6 = (int)(uint)*(ushort *)(param_2 + 0x20) >> 4;
    iVar8 = (int)*(short *)(iRam0201c08c + iVar6 * 4);
    iVar6 = (int)*(short *)(iRam0201c08c + (iVar6 * 2 + 1) * 2);
    iStack_30 = iStack_60;
    uStack_34 = 0x1000;
    iStack_2c = iStack_5c;
    lVar3 = (longlong)iVar6 * (longlong)(int)uVar14 + 0x800;
    lVar2 = (longlong)iVar8 * (longlong)(int)uVar14 + 0x800;
    uStack_54 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
    uStack_50 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    lVar2 = (longlong)-iVar8 * (longlong)(int)uVar10 + 0x800;
    lVar3 = (longlong)iVar6 * (longlong)(int)uVar10 + 0x800;
    uStack_48 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uStack_44 = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000;
    uStack_4c = 0;
    uStack_40 = 0;
    uStack_3c = 0;
    uStack_38 = 0;
    iStack_28 = iStack_58;
    *puRam0201c090 = 0;
    G3_MultMtx43(&uStack_54);
  }
  uVar9 = param_1 + 0x40U & 3;
  uVar13 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar5 = (uint)*(ushort *)(param_2 + 0x36);
  uVar9 = (uint)*(ushort *)((uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) + 0x72);
  *puRam0201c098 =
       (int)((uVar5 & 0x1f) * (uVar9 & 0x1f)) >> 5 |
       ((int)((uVar5 & 0x3e0) * (uVar9 & 0x3e0)) >> 0xf) << 5 |
       ((int)((uVar5 & 0x7c00) * (uVar9 & 0x7c00)) >> 0x19) << 10;
  uVar9 = param_1 + 0x40U & 3;
  uVar13 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar9 = uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20;
  func_0201c690((int)*(short *)(uVar9 + 0x7c),(int)*(short *)(uVar9 + 0x7e),0,0);
  return;
}

