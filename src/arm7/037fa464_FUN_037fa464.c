/* Decompiled C draft; module arm7; ROM address 037fa464. No matching claim. */
#include "types.h"
#include "deps/037fa464_FUN_037fa464.h"

void FUN_037fa464(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar4;
  undefined4 *puVar6;
  code *pcVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  uint uVar3;
  uint uVar5;
  
  *DAT_037fa558 = 0;
  FUN_037f8850(0x10);
  *DAT_037fa55c =
       *(uint *)((uint)DAT_037fa55c & 0xfffffffc) >> ((uint)DAT_037fa55c & 3) * 8 |
       *(uint *)((uint)DAT_037fa55c & 0xfffffffc) << ((uint)DAT_037fa55c & 3) * -8 + 0x20 | 0x10;
  uVar10 = FUN_037fa278();
  puVar1 = DAT_037fa560;
  uVar3 = (uint)((ulonglong)uVar10 >> 0x20);
  puVar6 = (undefined4 *)
           (*(uint *)((uint)DAT_037fa560 & 0xfffffffc) >> ((uint)DAT_037fa560 & 3) * 8 |
           *(uint *)((uint)DAT_037fa560 & 0xfffffffc) << ((uint)DAT_037fa560 & 3) * -8 + 0x20);
  if (puVar6 != (undefined4 *)0x0) {
    uVar2 = (uint)(puVar6 + 3) & 3;
    uVar8 = *(uint *)((uint)(puVar6 + 3) & 0xfffffffc);
    uVar5 = (uint)(puVar6 + 4) & 3;
    uVar4 = *(uint *)((uint)(puVar6 + 4) & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    bVar9 = uVar5 <= uVar3;
    if (uVar3 == uVar5) {
      bVar9 = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) <= (uint)uVar10;
    }
    if (bVar9) {
      uVar3 = (uint)(puVar6 + 6) & 3;
      uVar2 = *(uint *)((uint)(puVar6 + 6) & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      *DAT_037fa560 = uVar3;
      if (uVar3 == 0) {
        puVar1[1] = 0;
      }
      else {
        *(undefined4 *)(uVar3 + 0x14) = 0;
      }
      pcVar7 = (code *)(*(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                       *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20);
      uVar3 = (uint)(puVar6 + 7) & 3;
      uVar4 = *(uint *)((uint)(puVar6 + 7) & 0xfffffffc);
      uVar2 = (uint)(puVar6 + 8) & 3;
      uVar5 = *(uint *)((uint)(puVar6 + 8) & 0xfffffffc);
      if ((uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) &&
          (uVar4 >> uVar3 * 8 == 0 && uVar4 << uVar3 * -8 + 0x20 == 0)) {
        *puVar6 = 0;
      }
      if (pcVar7 != (code *)0x0) {
        uVar3 = (uint)(puVar6 + 1) & 3;
        uVar2 = *(uint *)((uint)(puVar6 + 1) & 0xfffffffc);
        (*pcVar7)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
      }
      uVar3 = (uint)(puVar6 + 7) & 3;
      uVar4 = *(uint *)((uint)(puVar6 + 7) & 0xfffffffc);
      uVar2 = (uint)(puVar6 + 8) & 3;
      uVar5 = *(uint *)((uint)(puVar6 + 8) & 0xfffffffc);
      if ((uVar5 >> uVar2 * 8 != 0 || uVar5 << uVar2 * -8 + 0x20 != 0) ||
          (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0)) {
        *puVar6 = pcVar7;
        FUN_037fa6e4((int)(uintptr_t)(puVar6),0,0);
      }
      if (*(uint *)((uint)DAT_037fa560 & 0xfffffffc) >> ((uint)DAT_037fa560 & 3) * 8 != 0 ||
          *(uint *)((uint)DAT_037fa560 & 0xfffffffc) << ((uint)DAT_037fa560 & 3) * -8 + 0x20 != 0) {
        FUN_037fa884();
      }
    }
    else {
      FUN_037fa884((int)(uintptr_t)(puVar6));
    }
  }
  return;
}

