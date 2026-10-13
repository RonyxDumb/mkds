/* Decompiled C draft; module arm9_ov003; ROM address 021c81b8. No matching claim. */
#include "types.h"
#include "deps/021c81b8_FUN_021c81b8.h"

void FUN_021c81b8(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte local_18 [16];
  
  pbVar4 = local_18;
  iVar3 = 0xe;
  pbVar5 = DAT_021c8234;
  do {
    bVar1 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    *pbVar4 = bVar1;
    pbVar4 = pbVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  uVar2 = (uint)local_18[*DAT_021c8238];
  if (2 < uVar2) {
    iVar3 = uVar2 * 8;
    FUN_021bf760(3,*(undefined2 *)(DAT_021c823c + iVar3),*(undefined2 *)(DAT_021c8240 + iVar3),
                 *(undefined2 *)(DAT_021c8244 + iVar3));
    return;
  }
  iVar3 = DAT_021c823c + uVar2 * 8;
  FUN_021bf760(1,*(undefined2 *)(DAT_021c823c + uVar2 * 8),*(undefined2 *)(iVar3 + 4),
               *(short *)(iVar3 + 2) + (ushort)*DAT_021c8248 * 0x1d);
  return;
}

