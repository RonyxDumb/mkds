/* Decompiled C draft; module arm7; ROM address 060050b8. No matching claim. */
#include "types.h"
#include "deps/060050b8_FUN_060050b8.h"

void FUN_060050b8(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar8;
  ushort *puVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined1 auStack_218 [512];
  uint uVar7;
  
  iVar2 = FUN_06000680();
  uVar3 = iVar2 + 0x154cU & 3;
  uVar6 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar7 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  puVar9 = (ushort *)
           (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
           *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20);
  uVar3 = param_1 + 4U & 3;
  uVar6 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar8 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  if ((puVar9[0x71] == 2) &&
     (((uint)puVar9[0xf9] & (1 << (*(ushort *)(uVar7 + 0x46) & 0xff)) >> 1) == 0)) {
    puVar4 = (undefined2 *)thunk_FUN_03807424();
    *puVar4 = 0xe;
    puVar4[1] = 6;
    puVar4[2] = 10;
    thunk_FUN_038074cc();
  }
  else {
    uVar6 = (uint)(puVar9 + 6) & 3;
    uVar7 = *(uint *)((uint)(puVar9 + 6) & 0xfffffffc);
    if (uVar7 >> uVar6 * 8 != 0 || uVar7 << uVar6 * -8 + 0x20 != 0) {
      puVar9[6] = 0;
      puVar9[7] = 0;
      FUN_06006d24(DAT_06005370);
    }
    FUN_06007bfc();
    uVar5 = thunk_FUN_037faf70();
    if (((uint)*puVar9 + DAT_06005374 & 0xffff) < 2) {
      puVar9[0x42] = 0;
      puVar9[0x18] = 0;
      puVar9[0x19] = 1;
      puVar9[0x44] = 0;
      puVar9[0x4d] = 0;
      puVar9[0x4e] = 0x3c;
      puVar9[0x398] = 0;
      puVar9[0x399] = 0;
      puVar9[0x45] = 0;
      puVar9[0x46] = 0;
      puVar9[0x47] = 0;
      puVar9[0x48] = 0;
      puVar9[0x1d] = 0;
      *(uint *)(puVar9 + 0x24) = uVar8;
      puVar9[0x23] = (ushort)uVar3;
      *(uint *)(puVar9 + 0x26) = uVar8 + (uVar3 & 0xffff);
      puVar9[0x22] = 0;
      uVar3 = param_1 + 0xcU & 3;
      uVar6 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(puVar9 + 0x28) = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      uVar3 = param_1 + 0x10U & 3;
      uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      puVar9[0x2a] = (ushort)(uVar6 >> uVar3 * 8) | (ushort)(uVar6 << uVar3 * -8 + 0x20);
      uVar3 = param_1 + 0x14U & 3;
      uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      puVar9[0x1a] = (ushort)(uVar6 >> uVar3 * 8) | (ushort)(uVar6 << uVar3 * -8 + 0x20);
      if (puVar9[0x1a] == 0) {
        puVar9[0x1a] = 0x10;
      }
      uVar3 = param_1 + 0x18U & 3;
      uVar6 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
      puVar9[0x4c] = (ushort)(uVar6 >> uVar3 * 8) | (ushort)(uVar6 << uVar3 * -8 + 0x20);
      uVar3 = param_1 + 0x1cU & 3;
      uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
      uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      bVar10 = uVar3 != 0;
      if (bVar10) {
        uVar3 = 1;
      }
      uVar1 = (ushort)uVar3;
      if (!bVar10) {
        uVar1 = 0;
      }
      puVar9[0x49] = uVar1;
      uVar3 = param_1 + 0x20U & 3;
      uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
      uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      bVar10 = uVar3 != 0;
      if (bVar10) {
        uVar3 = 1;
      }
      uVar1 = (ushort)uVar3;
      if (!bVar10) {
        uVar1 = 0;
      }
      puVar9[0x4a] = uVar1;
      uVar3 = param_1 + 0x24U & 3;
      uVar6 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
      uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
      bVar10 = uVar3 != 0;
      if (bVar10) {
        uVar3 = 1;
      }
      uVar1 = (ushort)uVar3;
      if (!bVar10) {
        uVar1 = 0;
      }
      puVar9[0x4b] = uVar1;
      puVar9[0x1b] = 0;
      puVar9[0x1c] = 0;
      puVar9[0x1e] = 0;
      puVar9[0x1f] = 0;
      puVar9[0x5d] = (ushort)DAT_06005370;
      puVar9[0x5e] = 4;
      uVar3 = param_1 + 0x28U & 3;
      uVar6 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
      puVar9[0x6d] = (ushort)(uVar6 >> uVar3 * 8 != 0 || uVar6 << uVar3 * -8 + 0x20 != 0);
      uVar11 = thunk_FUN_037fa278();
      iVar2 = 0;
      do {
        *(uint *)(puVar9 + iVar2 * 4 + 0x39a) = (uint)uVar11 | 1;
        *(int *)(puVar9 + iVar2 * 4 + 0x39c) = (int)((ulonglong)uVar11 >> 0x20);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x10);
      FUN_060000dc();
      puVar9[0x65] = 0;
      FUN_060066dc();
      if (*puVar9 == 8) {
        *puVar9 = 10;
      }
      else if (*puVar9 == 7) {
        *puVar9 = 9;
      }
      puVar4 = (undefined2 *)thunk_FUN_03807424();
      *puVar4 = 0xe;
      puVar4[1] = 0;
      puVar4[2] = 10;
      thunk_FUN_038074cc();
      puVar9[6] = 1;
      puVar9[7] = 0;
      thunk_FUN_037faf84(uVar5);
      iVar2 = FUN_06002274(auStack_218,0);
      if (*(short *)(iVar2 + 4) != 0) {
        puVar4 = (undefined2 *)thunk_FUN_03807424();
        *puVar4 = 0xe;
        puVar4[1] = 1;
        puVar4[2] = (short)DAT_06005378;
        puVar4[3] = *(undefined2 *)(iVar2 + 4);
        thunk_FUN_038074cc();
      }
    }
    else {
      thunk_FUN_037faf84();
      puVar4 = (undefined2 *)thunk_FUN_03807424();
      *puVar4 = 0xe;
      puVar4[1] = 3;
      puVar4[2] = 10;
      thunk_FUN_038074cc();
    }
  }
  return;
}

