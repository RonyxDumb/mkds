/* Decompiled C draft; module arm9; ROM address 02005210. No matching claim. */
#include "types.h"
#include "deps/02005210_Fs_OverlayInfo_End.h"

void Fs_OverlayInfo_End(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  uint uVar12;
  
  puVar3 = puRam02005310;
  puVar15 = (undefined4 *)0x0;
  while( true ) {
    uVar9 = param_1 + 8U & 3;
    uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar6 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    uVar12 = param_1 + 4U & 3;
    uVar11 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
    uVar9 = uVar12 + (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) +
                     (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
    Os_DisableIrq();
    puVar16 = (undefined4 *)
              (*(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
              *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20);
    puVar10 = puVar15;
    puVar14 = puVar15;
    puVar13 = puVar15;
    puVar8 = puVar16;
    while (puVar2 = puVar8, puVar1 = puVar13, puVar2 != (undefined4 *)0x0) {
      uVar6 = (uint)(puVar2 + 2) & 3;
      uVar4 = *(uint *)((uint)(puVar2 + 2) & 0xfffffffc);
      uVar5 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      puVar8 = (undefined4 *)
               (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
               *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20);
      uVar6 = (uint)(puVar2 + 1) & 3;
      uVar4 = *(uint *)((uint)(puVar2 + 1) & 0xfffffffc);
      uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
      if ((((uVar5 == 0) && (uVar12 <= uVar6)) && (uVar6 < uVar9)) ||
         ((puVar13 = puVar2, uVar12 <= uVar5 && (uVar5 < uVar9)))) {
        puVar13 = puVar2;
        if (puVar10 != (undefined4 *)0x0) {
          *puVar10 = puVar2;
          puVar13 = puVar14;
        }
        if (puVar16 == puVar2) {
          *puVar3 = puVar8;
          puVar16 = puVar8;
        }
        *puVar2 = 0;
        puVar10 = puVar2;
        puVar14 = puVar13;
        puVar13 = puVar1;
        if (puVar1 != (undefined4 *)0x0) {
          *puVar1 = puVar8;
        }
      }
    }
    Os_RestoreIrq();
    if (puVar14 == (undefined4 *)0x0) break;
    do {
      uVar9 = (uint)(puVar14 + 1) & 3;
      uVar6 = *(uint *)((uint)(puVar14 + 1) & 0xfffffffc);
      pcVar7 = (code *)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
      puVar10 = (undefined4 *)
                (*(uint *)((uint)puVar14 & 0xfffffffc) >> ((uint)puVar14 & 3) * 8 |
                *(uint *)((uint)puVar14 & 0xfffffffc) << ((uint)puVar14 & 3) * -8 + 0x20);
      if (pcVar7 != (code *)0x0) {
        uVar9 = (uint)(puVar14 + 2) & 3;
        uVar6 = *(uint *)((uint)(puVar14 + 2) & 0xfffffffc);
        (*pcVar7)(uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20);
      }
      puVar14 = puVar10;
    } while (puVar10 != (undefined4 *)0x0);
  }
  return;
}

