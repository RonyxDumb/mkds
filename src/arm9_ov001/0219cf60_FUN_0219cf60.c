/* Decompiled C draft; module arm9_ov001; ROM address 0219cf60. No matching claim. */
#include "types.h"
#include "deps/0219cf60_FUN_0219cf60.h"

void FUN_0219cf60(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint local_30;
  int local_24;
  
  local_24 = *DAT_0219d01c;
  iVar3 = *(int *)(local_24 + 8);
  bVar2 = *(byte *)(DAT_0219d020 + iVar3);
  iVar8 = 0;
  if (-1 < (int)((uint)*(byte *)(DAT_0219d024 + iVar3 * 4) -
                (uint)*(byte *)(DAT_0219d028 + iVar3 * 4))) {
    local_30 = (uint)DAT_0219d02c[1];
    bVar1 = *DAT_0219d02c;
    do {
      iVar6 = 0;
      iVar4 = DAT_0219d030 + iVar3 * 4;
      uVar5 = (uint)*(byte *)(DAT_0219d030 + iVar3 * 4);
      if (-1 < (int)(*(byte *)(iVar4 + 1) - uVar5)) {
        iVar7 = iVar6;
        do {
          *(undefined2 *)(iVar6 + (uint)bVar1 * 2 + local_30 * 0x40 + *DAT_0219d01c + 0x30) =
               *(undefined2 *)
                (*(int *)((uint)bVar2 * 4 + *DAT_0219d01c + DAT_0219d034) + iVar6 + uVar5 * 2 +
                 (iVar8 + (uint)*(byte *)(iVar4 + 2)) * 0x40 + 0xc);
          iVar6 = iVar6 + 2;
          iVar7 = iVar7 + 1;
          local_24 = *DAT_0219d01c;
          iVar3 = *(int *)(local_24 + 8);
          iVar4 = DAT_0219d030 + iVar3 * 4;
          uVar5 = (uint)*(byte *)(DAT_0219d030 + iVar3 * 4);
        } while (iVar7 <= (int)(*(byte *)(iVar4 + 1) - uVar5));
      }
      local_30 = local_30 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 <= (int)((uint)*(byte *)(iVar4 + 3) - (uint)*(byte *)(iVar4 + 2)));
  }
  func_0x02016468(10,0,local_24 + 0x30,DAT_0219d038);
  return;
}

