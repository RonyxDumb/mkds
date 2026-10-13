/* Decompiled C draft; module arm7; ROM address 06006ab0. No matching claim. */
#include "types.h"
#include "deps/06006ab0_FUN_06006ab0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_06006ab0(uint param_1,undefined4 param_2,ushort *param_3,uint param_4,undefined4 param_5)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  undefined2 *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  ushort uVar13;
  int iVar14;
  uint uVar15;
  ushort *puVar16;
  bool bVar17;
  bool bVar18;
  int iStack_54;
  int iStack_48;
  ushort auStack_c [6];
  
  iVar4 = FUN_06000680();
  uVar15 = iVar4 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x154cU & 0xfffffffc);
  uVar5 = uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20;
  uVar15 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar15 = uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20;
  if (param_4 == 0) {
    return;
  }
  if (*(ushort *)(uVar15 + 400) < param_4) {
    return;
  }
  if (param_1 == *(ushort *)(uVar15 + 0x184)) {
    return;
  }
  if (0xf < param_1) {
    return;
  }
  if ((param_4 & 1) != 0) {
    return;
  }
  bVar3 = true;
  if ((int)param_4 < 1) {
    return;
  }
  iVar4 = uVar15 + 500 + param_1 * 0x10;
  iStack_54 = 0x200;
  iStack_48 = 2;
  do {
    if (bVar3) {
      bVar3 = false;
      puVar12 = auStack_c;
      puVar16 = param_3;
    }
    else {
      puVar16 = param_3 + 1;
      param_4 = param_4 - 2;
      puVar12 = param_3;
    }
    uVar13 = *puVar12;
    iVar14 = (uVar13 & 0xff) << 1;
    if ((uVar13 & 0xff) == 0) {
      iVar14 = iStack_54;
    }
    bVar17 = (uVar13 & 0x1000) == 0;
    bVar18 = (uVar13 & 0x800) == 0;
    iVar7 = iStack_48;
    if (bVar17) {
      iVar7 = 0;
    }
    iVar6 = iStack_48;
    if (bVar18) {
      iVar6 = 0;
    }
    iVar7 = iVar14 + iVar6 + iVar7;
    param_4 = param_4 - iVar7;
    if ((int)param_4 < 0) {
      return;
    }
    uVar5 = uVar13 & 0xf00;
    puVar11 = (ushort *)((int)puVar16 + iVar14);
    param_3 = (ushort *)((int)puVar16 + iVar7);
    puVar12 = puVar11;
    uVar13 = (ushort)DAT_06006d20;
    if (bVar18) {
LAB_06006c90:
      if (((bVar17) || (((uint)*puVar12 & 1 << (*(ushort *)(uVar15 + 0x184) & 0xff)) != 0)) &&
         (iVar14 != 0)) {
        puVar10 = (undefined2 *)thunk_FUN_03807424();
        *puVar10 = 0x82;
        puVar10[1] = 0;
        puVar10[2] = 0x15;
        puVar10[3] = (short)(uVar5 >> 8);
        *(undefined4 *)(puVar10 + 4) = param_5;
        *(ushort **)(puVar10 + 6) = puVar16;
        puVar10[8] = (short)iVar14;
        puVar10[9] = (short)param_1;
        puVar10[0x10] = *(undefined2 *)(uVar15 + 0x184);
        puVar10[0xd] = uVar13;
        thunk_FUN_038074cc();
      }
    }
    else {
      uVar8 = (uVar5 << 8) >> 0x10 & 7;
      puVar9 = (ushort *)(iVar4 + uVar8 * 2);
      uVar1 = *(ushort *)(iVar4 + uVar8 * 2);
      puVar12 = puVar11 + 1;
      uVar2 = *puVar11;
      if ((uVar1 & 1) != 0) {
        *puVar9 = uVar2 << 1;
        uVar13 = uVar2;
        goto LAB_06006c90;
      }
      uVar13 = uVar2 * 2;
      if (0xff < (ushort)(uVar1 + uVar2 * -2)) {
        *puVar9 = uVar13;
        goto LAB_06006c90;
      }
    }
    if ((int)param_4 < 1) {
      return;
    }
  } while( true );
}

