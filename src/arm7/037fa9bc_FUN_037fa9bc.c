/* Decompiled C draft; module arm7; ROM address 037fa9bc. No matching claim. */
#include "types.h"
#include "deps/037fa9bc_FUN_037fa9bc.h"

void FUN_037fa9bc(void)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  code *pcVar9;
  undefined4 *puVar10;
  
  FUN_037f8850(4);
  puVar2 = DAT_037fab30;
  *DAT_037fab30 = *DAT_037fab30 & 0xffdf;
  *DAT_037fab34 =
       *(uint *)((uint)DAT_037fab34 & 0xfffffffc) >> ((uint)DAT_037fab34 & 3) * 8 |
       *(uint *)((uint)DAT_037fab34 & 0xfffffffc) << ((uint)DAT_037fab34 & 3) * -8 + 0x20 | 4;
  FUN_037fa920(((int)(uint)*puVar2 >> 8 | (*puVar2 & 0x80) << 1) - 1);
  uVar4 = DAT_037fab3c;
  puVar3 = DAT_037fab38;
  puVar2 = DAT_037fab30;
LAB_037fab14:
  do {
    puVar10 = (undefined4 *)
              (*(uint *)(DAT_037fab40 & 0xfffffffc) >> (DAT_037fab40 & 3) * 8 |
              *(uint *)(DAT_037fab40 & 0xfffffffc) << (DAT_037fab40 & 3) * -8 + 0x20);
    if (puVar10 == (undefined4 *)0x0) {
      return;
    }
    uVar1 = *puVar3;
    uVar5 = FUN_037fa920(uVar1);
    iVar6 = FUN_037fa96c((int)(uintptr_t)(puVar10),uVar5,uVar1);
    if (iVar6 == 0) {
      FUN_037fac40((int)(uintptr_t)(puVar10));
      if ((int)*(short *)(puVar10 + 4) != (uint)*puVar3) {
        return;
      }
      uVar8 = (uint)(puVar10 + 3) & 3;
      uVar7 = *(uint *)((uint)(puVar10 + 3) & 0xfffffffc);
      if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) != uVar5) {
        return;
      }
      FUN_037f8850(4);
      *puVar2 = *puVar2 & 0xffdf;
      FUN_037f881c(4);
    }
    else if (iVar6 != 1) {
      if (iVar6 == 2) {
        FUN_037fade0((int)(uintptr_t)(puVar10));
        FUN_037fae18((int)(uintptr_t)(puVar10));
        puVar10[3] = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                     *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 1;
      }
      goto LAB_037fab14;
    }
    pcVar9 = (code *)(*(uint *)((uint)puVar10 & 0xfffffffc) >> ((uint)puVar10 & 3) * 8 |
                     *(uint *)((uint)puVar10 & 0xfffffffc) << ((uint)puVar10 & 3) * -8 + 0x20);
    FUN_037fade0((int)(uintptr_t)(puVar10));
    *puVar10 = 0;
    if (pcVar9 != (code *)0x0) {
      uVar5 = (uint)(puVar10 + 1) & 3;
      uVar8 = *(uint *)((uint)(puVar10 + 1) & 0xfffffffc);
      (*pcVar9)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
    }
    uVar5 = (uint)(puVar10 + 7) & 3;
    uVar8 = *(uint *)((uint)(puVar10 + 7) & 0xfffffffc);
    if ((uVar8 >> uVar5 * 8 != 0 || uVar8 << uVar5 * -8 + 0x20 != 0) &&
       (uVar5 = (uint)(puVar10 + 9) & 3, uVar8 = *(uint *)((uint)(puVar10 + 9) & 0xfffffffc),
       uVar8 >> uVar5 * 8 == 0 && uVar8 << uVar5 * -8 + 0x20 == 0)) {
      *puVar10 = pcVar9;
      puVar10[3] = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                   *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 1;
      FUN_037fae18((int)(uintptr_t)(puVar10));
    }
  } while( true );
}

