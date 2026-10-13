/* Decompiled C draft; module arm9_ov003; ROM address 021d17d4. No matching claim. */
#include "types.h"
#include "deps/021d17d4_FUN_021d17d4.h"

void FUN_021d17d4(int param_1,int param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = *(uint **)(param_1 + 8);
  if (param_2 < 0) {
    uVar2 = *puVar1 & DAT_021d188c;
    uVar3 = *puVar1;
    *puVar1 = (param_3 & DAT_021d1884) << 0x10 | *puVar1 & DAT_021d1888 | param_4 & 0xff;
    iVar4 = 1;
    if (1 < *(byte *)(param_1 + 0xc)) {
      do {
        puVar1 = puVar1 + 2;
        *puVar1 = (((*puVar1 & DAT_021d188c) >> 0x10) + (param_3 - (uVar2 >> 0x10)) & DAT_021d1884)
                  << 0x10 | *puVar1 & DAT_021d1888 |
                            (*puVar1 & 0xff) + (param_4 - (uVar3 & 0xff)) & 0xff;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0xc));
    }
    return;
  }
  puVar1[param_2 * 2] =
       (param_3 & DAT_021d1884) << 0x10 | puVar1[param_2 * 2] & DAT_021d1888 | param_4 & 0xff;
  return;
}

