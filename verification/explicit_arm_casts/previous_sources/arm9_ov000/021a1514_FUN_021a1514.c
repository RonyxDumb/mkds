/* Decompiled C draft; module arm9_ov000; ROM address 021a1514. No matching claim. */
#include "types.h"
#include "deps/021a1514_FUN_021a1514.h"

int FUN_021a1514(undefined4 *param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*DAT_021a157c == 0) {
    return 0;
  }
  func_0x0214d168(DAT_021a1580,0,0x20);
  iVar1 = DAT_021a1584;
  iVar5 = 0;
  iVar3 = *DAT_021a157c;
  pbVar2 = DAT_021a1580;
  iVar4 = iVar3;
  do {
    if ((*(uint *)(iVar3 + iVar1) & 1 << (uint)*(byte *)(iVar4 + DAT_021a1588)) == 0) break;
    *pbVar2 = *(byte *)(iVar4 + DAT_021a1588);
    iVar4 = iVar4 + 1;
    pbVar2 = pbVar2 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 <= (int)(uint)*(byte *)(iVar3 + 0xe));
  *param_1 = DAT_021a1580;
  return *(byte *)(*DAT_021a157c + 0xe) + 1;
}

