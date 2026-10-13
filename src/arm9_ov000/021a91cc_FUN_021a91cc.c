/* Decompiled C draft; module arm9_ov000; ROM address 021a91cc. No matching claim. */
#include "types.h"
#include "deps/021a91cc_FUN_021a91cc.h"

void FUN_021a91cc(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_021a91fc;
  do {
    if ((*(char *)(iVar1 + 0x5a) != '\0') && (0xef < param_1 - *(int *)(iVar1 + 0x50))) {
      *(undefined1 *)(iVar1 + 0x5a) = 0;
    }
    iVar1 = iVar1 + 0x5c;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  return;
}

