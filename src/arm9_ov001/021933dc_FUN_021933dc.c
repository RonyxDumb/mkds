/* Decompiled C draft; module arm9_ov001; ROM address 021933dc. No matching claim. */
#include "types.h"
#include "deps/021933dc_FUN_021933dc.h"

void FUN_021933dc(void)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  byte *pbVar4;
  int iVar5;
  
  puVar1 = PTR_data_ov001_02193444;
  iVar5 = 0;
  puVar3 = PTR_data_ov001_02193440;
  pbVar4 = PTR_data_ov001_0219343c;
  do {
    iVar2 = *(int *)puVar1;
    if ((iVar5 == *(int *)(iVar2 + 8)) && (*(int *)(iVar2 + 0x14) != 0)) {
      *(undefined4 *)(*(int *)(iVar2 + 0x20) + (uint)*pbVar4 * 0x40) = 1;
      func_0x02124a20(*puVar3,0xe,*(undefined4 *)(*(int *)puVar1 + 0x24),
                      *(undefined4 *)(*(int *)puVar1 + 0x30));
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + 0x20) + (uint)*pbVar4 * 0x40) = 0;
      func_0x02124a20(*puVar3,0xf,*(undefined4 *)(*(int *)puVar1 + 0x24),
                      *(undefined4 *)(*(int *)puVar1 + 0x30));
    }
    pbVar4 = pbVar4 + 1;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}

