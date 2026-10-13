/* Decompiled C draft; module arm9; ROM address 02082fec. No matching claim. */
#include "types.h"
#include "deps/02082fec_func_02082fec.h"

void func_02082fec(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  byte bVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  char cVar19;
  uint uVar20;
  uint uVar21;
  
  if (param_2 == 0) {
    uVar17 = param_1 + 0x94U & 3;
    uVar20 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar21 = uVar20 >> uVar17 * 8 | uVar20 << uVar17 * -8 + 0x20;
    iVar9 = *(int *)(uVar21 + 0x3b0);
    iVar11 = *(int *)(uVar21 + 0x3b4);
    iVar14 = *(int *)(uVar21 + 0x3b8);
    bVar7 = 1;
    iVar18 = (uint)*(ushort *)(uVar21 + 0x74) * 0x58 +
             (*(uint *)(uRam020831b0 & 0xfffffffc) >> (uRam020831b0 & 3) * 8 |
             *(uint *)(uRam020831b0 & 0xfffffffc) << (uRam020831b0 & 3) * -8 + 0x20);
    bVar8 = true;
    cVar19 = *(char *)(param_1 + 0x9a);
    cVar1 = *(char *)(param_1 + 0x99);
    bVar2 = *(byte *)(param_1 + 0x9b);
    uVar17 = iRam020831b4 + (uint)*(byte *)(param_1 + 0x98) * 4;
    uVar20 = uVar17 & 3;
    uVar17 = *(uint *)(uVar17 & 0xfffffffc);
    uVar17 = uVar17 >> uVar20 * 8 | uVar17 << uVar20 * -8 + 0x20;
    iVar10 = StructMQRacerEntry_SomeFn_51(uVar21);
    if ((iVar10 == 0) &&
       (uVar20 = uVar21 + 0x2a4 & 3, uVar12 = *(uint *)(uVar21 + 0x2a4 & 0xfffffffc),
       iRam020831b8 <= (int)(uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20))) {
      bVar8 = false;
    }
    if ((!bVar8) &&
       (uVar20 = uVar21 + 0x500 & 3, uVar12 = *(uint *)(uVar21 + 0x500 & 0xfffffffc),
       (uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20) < 0x5001)) {
      bVar7 = 0;
    }
    uVar20 = param_1 + 0x24U & 3;
    uVar12 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) =
         (uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20) & 0xfffffffd | (uint)bVar7 << 1;
    puVar13 = (uint *)(param_1 + 0x24);
    if ((cVar1 != '\0') && (cVar19 = cVar19 + '\x01', cVar19 == '\n')) {
      *puVar13 = (*(uint *)((uint)puVar13 & 0xfffffffc) >> ((uint)puVar13 & 3) * 8 |
                 *(uint *)((uint)puVar13 & 0xfffffffc) << ((uint)puVar13 & 3) * -8 + 0x20) &
                 0xfffffffe | 1;
    }
    iVar10 = (uint)bVar2 * 6 + iVar18;
    *(char *)(param_1 + 0x9a) = cVar19;
    uVar3 = *(undefined2 *)(iVar10 + 0x4e);
    iVar18 = (uint)bVar2 * 0xc + iVar18;
    *(undefined2 *)(param_1 + 0x50) = *(undefined2 *)(iVar10 + 0x4c);
    *(undefined2 *)(param_1 + 0x52) = uVar3;
    *(undefined2 *)(param_1 + 0x54) = *(undefined2 *)(iVar10 + 0x50);
    uVar20 = param_1 + 0x20U & 3;
    uVar12 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar15 = uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20;
    uVar12 = iVar18 + 0x34U & 3;
    uVar16 = *(uint *)(iVar18 + 0x34U & 0xfffffffc);
    uVar20 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar20 = (uVar15 >> uVar20 * 8 | uVar15 << uVar20 * -8 + 0x20) + 4;
    uVar15 = uVar20 & 3;
    uVar20 = *(uint *)(uVar20 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) =
         (uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) +
         (uVar20 >> uVar15 * 8 | uVar20 << uVar15 * -8 + 0x20);
    uVar20 = param_1 + 0x20U & 3;
    uVar12 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar15 = uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20;
    uVar12 = iVar18 + 0x38U & 3;
    uVar16 = *(uint *)(iVar18 + 0x38U & 0xfffffffc);
    uVar20 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar20 = (uVar15 >> uVar20 * 8 | uVar15 << uVar20 * -8 + 0x20) + 8;
    uVar15 = uVar20 & 3;
    uVar20 = *(uint *)(uVar20 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         (uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) +
         (uVar20 >> uVar15 * 8 | uVar20 << uVar15 * -8 + 0x20);
    uVar20 = param_1 + 0x20U & 3;
    uVar12 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar15 = uVar12 >> uVar20 * 8 | uVar12 << uVar20 * -8 + 0x20;
    uVar12 = iVar18 + 0x3cU & 3;
    uVar16 = *(uint *)(iVar18 + 0x3cU & 0xfffffffc);
    uVar20 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    uVar20 = (uVar15 >> uVar20 * 8 | uVar15 << uVar20 * -8 + 0x20) + 0xc;
    uVar15 = uVar20 & 3;
    uVar20 = *(uint *)(uVar20 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) =
         (uVar16 >> uVar12 * 8 | uVar16 << uVar12 * -8 + 0x20) +
         (uVar20 >> uVar15 * 8 | uVar20 << uVar15 * -8 + 0x20);
    uVar20 = param_1 + 0x2cU & 3;
    uVar15 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    uVar12 = uVar21 + 0x500 & 3;
    uVar21 = *(uint *)(uVar21 + 0x500 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) =
         (uVar15 >> uVar20 * 8 | uVar15 << uVar20 * -8 + 0x20) +
         ((uVar21 >> uVar12 * 8 | uVar21 << uVar12 * -8 + 0x20) >> 4);
    lVar4 = (longlong)iVar9 * (longlong)(int)uVar17;
    lVar5 = (longlong)iVar11 * (longlong)(int)uVar17;
    lVar6 = (longlong)iVar14 * (longlong)(int)uVar17;
    *(uint *)(param_1 + 0x40) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    *(uint *)(param_1 + 0x44) = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) << 0x14;
    *(uint *)(param_1 + 0x48) = (uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) << 0x14;
    return;
  }
  return;
}

