/* Decompiled C draft; module arm7; ROM address 037f8f48. No matching claim. */
#include "types.h"
#include "deps/037f8f48_FUN_037f8f48.h"

void FUN_037f8f48(void)

{
  undefined2 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  
  puVar1 = DAT_037f9018;
  if (*(uint *)(DAT_037f901c & 0xfffffffc) >> (DAT_037f901c & 3) * 8 == 0 &&
      *(uint *)(DAT_037f901c & 0xfffffffc) << (DAT_037f901c & 3) * -8 + 0x20 == 0) {
    if ((DAT_037f9018[1] == 0) && (iVar3 = FUN_037fafc8(), iVar3 != 0x12)) {
      uVar4 = *(uint *)(DAT_037f9020 & 0xfffffffc) >> (DAT_037f9020 & 3) * 8 |
              *(uint *)(DAT_037f9020 & 0xfffffffc) << (DAT_037f9020 & 3) * -8 + 0x20;
      uVar5 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
      uVar5 = FUN_037f9028();
      if (((uVar4 != uVar5) && (uVar5 != 0)) &&
         ((uVar2 = uVar4 + 0x48 & 3, uVar6 = *(uint *)(uVar4 + 0x48 & 0xfffffffc),
          (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) == 2 ||
          (iVar3 = FUN_037f96dc(uVar4), iVar3 == 0)))) {
        pcVar7 = (code *)(*(uint *)(DAT_037f9024 & 0xfffffffc) >> (DAT_037f9024 & 3) * 8 |
                         *(uint *)(DAT_037f9024 & 0xfffffffc) << (DAT_037f9024 & 3) * -8 + 0x20);
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(uVar4,uVar5);
        }
        puVar1 = puVar1 + 6;
        uVar2 = (uint)puVar1 & 3;
        uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
        pcVar7 = (code *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
        if (pcVar7 != (code *)0x0) {
          (*pcVar7)(uVar4,uVar5);
        }
        *(uint *)(DAT_037f9018 + 2) = uVar5;
        FUN_037f9710(uVar5);
      }
    }
    else {
      *puVar1 = 1;
    }
  }
  return;
}

