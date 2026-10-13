/* Decompiled C draft; module arm7; ROM address 060012c4. No matching claim. */
#include "types.h"
#include "deps/060012c4_FUN_060012c4.h"

void FUN_060012c4(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined8 uVar15;
  
  iVar3 = FUN_06000680();
  uVar5 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = (int)(uint)*(byte *)(param_1 + 0x1f) >> 2;
  if ((*(byte *)(param_1 + 0x1f) & 2) == 0) {
    uVar5 = uVar5 + 0x19;
  }
  if (uVar5 < *(ushort *)(uVar4 + 0xba)) {
    *(short *)(uVar4 + 0xba) = (short)uVar5;
  }
  uVar5 = uVar4 + 0xc & 3;
  uVar6 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  if (uVar6 >> uVar5 * 8 != 0 || uVar6 << uVar5 * -8 + 0x20 != 0) {
    if (*(short *)(uVar4 + 0x32) == 1) {
      *(undefined2 *)(uVar4 + 0x32) = 0;
    }
    sVar1 = *(short *)(uVar4 + 0x8e);
    *(ushort *)(uVar4 + 0x44) = *(ushort *)(uVar4 + 0x44) ^ 1;
    uVar5 = uVar4 + (uint)*(ushort *)(uVar4 + 0x44) * 4 + 0x48;
    uVar6 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar5 = *(ushort *)(param_1 + 0x16) + 0x30;
    if (*(ushort *)(uVar4 + 0x46) < uVar5) {
      uVar5 = (uint)*(ushort *)(uVar4 + 0x46);
    }
    thunk_FUN_037fb390(param_1 + 0x10,uVar6,uVar5);
    uVar7 = thunk_FUN_037faf70();
    bVar12 = *(short *)(uVar4 + 0x84) == 1;
    if (bVar12) {
      thunk_FUN_037fa564(uVar4 + 0x58);
    }
    *(undefined2 *)(uVar4 + 0x84) = 1;
    *(undefined2 *)(uVar4 + 0x56) = *(undefined2 *)(uVar6 + 10);
    uVar2 = *(ushort *)(param_1 + 0x18);
    bVar13 = (uVar2 & 0x2000) != 0;
    *(ushort *)(uVar4 + 0x90) = (ushort)bVar13;
    uVar8 = thunk_FUN_03806b2c((((uint)*(ushort *)(uVar6 + 10) - (uint)*(ushort *)(uVar6 + 0xc) &
                                0xffff) + 0x80) * 0x10 * DAT_060015b4,0x40);
    iVar3 = thunk_FUN_03806b2c(uVar8,0x400);
    thunk_FUN_037fa670(uVar4 + 0x58,iVar3,iVar3 >> 0x1f,DAT_060015b8,0);
    bVar14 = (uVar2 & 0x6000) == 0x6000;
    if (bVar14) {
      *(undefined2 *)(uVar4 + 0x8a) = 0;
    }
    *(ushort *)(uVar4 + 0x8e) = (ushort)((uVar2 & 0x2800) == 0x2800);
    *(ushort *)(uVar4 + 0x8c) = (ushort)bVar14;
    thunk_FUN_037faf84(uVar7);
    if (bVar12) {
      if (sVar1 == 1) {
        FUN_06006f18(bVar12,0);
      }
      puVar9 = (undefined2 *)thunk_FUN_03807424();
      *puVar9 = 0xe;
      puVar9[1] = 9;
      puVar9[2] = 0xd;
      *(undefined4 *)(puVar9 + 4) = 0;
      thunk_FUN_038074cc();
    }
    if (bVar13) {
      thunk_FUN_037fb390(param_1 + 0x28,uVar6 + 0x18,6);
      thunk_FUN_037fb390(param_1 + 0x2e,uVar6 + 0x1e,6);
      if (*(ushort *)(uVar6 + 6) < 2) {
        *(undefined2 *)(uVar6 + 6) = 0;
        *(undefined2 *)(uVar4 + 0x30) = 0;
        puVar9 = (undefined2 *)thunk_FUN_03807424();
        *puVar9 = 0xe;
        puVar9[1] = 0xe;
        puVar9[2] = 0xc;
        *(uint *)(puVar9 + 4) = uVar6;
        thunk_FUN_038074cc();
        thunk_FUN_03807480();
      }
      else {
        *(ushort *)(uVar6 + 6) = *(ushort *)(uVar6 + 6) - 2;
        *(ushort *)(uVar4 + 0x30) = (ushort)((*(ushort *)(uVar6 + 0x30) & 0x8000) != 0);
        puVar9 = (undefined2 *)thunk_FUN_03807424();
        *puVar9 = 0xe;
        puVar9[1] = 0;
        puVar9[2] = 0xc;
        *(uint *)(puVar9 + 4) = uVar6;
        thunk_FUN_038074cc();
        if (*(short *)(uVar6 + 6) != 0) {
          FUN_06006ab0(0,*(undefined2 *)(uVar6 + 0x30),(ushort *)(uintptr_t)(uVar6 + 0x32),*(short *)(uVar6 + 6),uVar6);
          thunk_FUN_03807480();
        }
      }
      uVar5 = uVar4 + 0x7b4 & 3;
      uVar11 = *(uint *)(uVar4 + 0x7b4 & 0xfffffffc);
      uVar6 = uVar4 + 0x7b8 & 3;
      uVar10 = *(uint *)(uVar4 + 0x7b8 & 0xfffffffc);
      if ((uVar10 >> uVar6 * 8 != 0 || uVar10 << uVar6 * -8 + 0x20 != 0) ||
          (uVar11 >> uVar5 * 8 != 0 || uVar11 << uVar5 * -8 + 0x20 != 0)) {
        uVar15 = thunk_FUN_037fa278();
        *(uint *)(uVar4 + 0x734) = (uint)uVar15 | 1;
        *(int *)(uVar4 + 0x738) = (int)((ulonglong)uVar15 >> 0x20);
      }
    }
    else if (1 < *(ushort *)(uVar6 + 6)) {
      *(ushort *)(uVar4 + 0x30) = (ushort)((*(ushort *)(uVar6 + 0x30) & 0x8000) != 0);
    }
  }
  return;
}

