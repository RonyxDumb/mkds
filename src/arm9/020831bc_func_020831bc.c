/* Decompiled C draft; module arm9; ROM address 020831bc. No matching claim. */
#include "types.h"
#include "deps/020831bc_func_020831bc.h"

void func_020831bc(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  char cVar17;
  uint uVar18;
  uint uVar19;
  
  if (param_2 == 0) {
    uVar15 = param_1 + 0x94U & 3;
    uVar18 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar19 = uVar18 >> uVar15 * 8 | uVar18 << uVar15 * -8 + 0x20;
    iVar8 = *(int *)(uVar19 + 0x3b0);
    iVar10 = *(int *)(uVar19 + 0x3b4);
    iVar12 = *(int *)(uVar19 + 0x3b8);
    iVar16 = (uint)*(ushort *)(uVar19 + 0x74) * 0x58 +
             (*(uint *)(uRam02083350 & 0xfffffffc) >> (uRam02083350 & 3) * 8 |
             *(uint *)(uRam02083350 & 0xfffffffc) << (uRam02083350 & 3) * -8 + 0x20);
    cVar17 = *(char *)(param_1 + 0x9a);
    cVar1 = *(char *)(param_1 + 0x99);
    bVar2 = *(byte *)(param_1 + 0x9b);
    uVar15 = iRam02083354 + (uint)*(byte *)(param_1 + 0x98) * 4;
    uVar18 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar15 = uVar15 >> uVar18 * 8 | uVar15 << uVar18 * -8 + 0x20;
    bVar7 = 1;
    iVar9 = StructMQRacerEntry_SomeFn_51(uVar19);
    if ((iVar9 == 0) &&
       (uVar18 = uVar19 + 0x2a4 & 3, uVar19 = *(uint *)(uVar19 + 0x2a4 & 0xfffffffc),
       iRam02083358 <= (int)(uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20))) {
      bVar7 = 0;
    }
    uVar18 = param_1 + 0x24U & 3;
    uVar19 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) =
         (uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20) & 0xfffffffd | (uint)bVar7 << 1;
    puVar11 = (uint *)(param_1 + 0x24);
    if ((cVar1 != '\0') && (cVar17 = cVar17 + '\x01', cVar17 == '\n')) {
      *puVar11 = (*(uint *)((uint)puVar11 & 0xfffffffc) >> ((uint)puVar11 & 3) * 8 |
                 *(uint *)((uint)puVar11 & 0xfffffffc) << ((uint)puVar11 & 3) * -8 + 0x20) &
                 0xfffffffe | 1;
    }
    iVar9 = (uint)bVar2 * 6 + iVar16;
    *(char *)(param_1 + 0x9a) = cVar17;
    uVar3 = *(undefined2 *)(iVar9 + 0x4e);
    iVar16 = (uint)bVar2 * 0xc + iVar16;
    *(undefined2 *)(param_1 + 0x50) = *(undefined2 *)(iVar9 + 0x4c);
    *(undefined2 *)(param_1 + 0x52) = uVar3;
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(iVar9 + 0x50);
    uVar18 = param_1 + 0x20U & 3;
    uVar19 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar13 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
    uVar19 = iVar16 + 0x34U & 3;
    uVar14 = *(uint *)(iVar16 + 0x34U & 0xfffffffc);
    uVar18 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar18 = (uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) + 4;
    uVar13 = uVar18 & 3;
    uVar18 = *(uint *)(uVar18 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) =
         (uVar14 >> uVar19 * 8 | uVar14 << uVar19 * -8 + 0x20) +
         (uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20);
    uVar18 = param_1 + 0x20U & 3;
    uVar19 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar13 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
    uVar19 = iVar16 + 0x38U & 3;
    uVar14 = *(uint *)(iVar16 + 0x38U & 0xfffffffc);
    uVar18 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar18 = (uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) + 8;
    uVar13 = uVar18 & 3;
    uVar18 = *(uint *)(uVar18 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         (uVar14 >> uVar19 * 8 | uVar14 << uVar19 * -8 + 0x20) +
         (uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20);
    uVar18 = param_1 + 0x20U & 3;
    uVar19 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar13 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
    uVar19 = iVar16 + 0x3cU & 3;
    uVar14 = *(uint *)(iVar16 + 0x3cU & 0xfffffffc);
    uVar18 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    uVar18 = (uVar13 >> uVar18 * 8 | uVar13 << uVar18 * -8 + 0x20) + 0xc;
    uVar13 = uVar18 & 3;
    uVar18 = *(uint *)(uVar18 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) =
         (uVar14 >> uVar19 * 8 | uVar14 << uVar19 * -8 + 0x20) +
         (uVar18 >> uVar13 * 8 | uVar18 << uVar13 * -8 + 0x20);
    lVar4 = (longlong)iVar8 * (longlong)(int)uVar15;
    lVar5 = (longlong)iVar10 * (longlong)(int)uVar15;
    lVar6 = (longlong)iVar12 * (longlong)(int)uVar15;
    *(uint *)(param_1 + 0x40) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    *(uint *)(param_1 + 0x44) = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) << 0x14;
    *(uint *)(param_1 + 0x48) = (uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) << 0x14;
    return;
  }
  return;
}

