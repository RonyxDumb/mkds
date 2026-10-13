/* Decompiled C draft; module arm9_ov000; ROM address 021a15b0. No matching claim. */
#include "types.h"
#include "deps/021a15b0_FUN_021a15b0.h"

void FUN_021a15b0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = -1;
  iVar1 = *DAT_021a15f0;
  do {
    if ((*(uint *)(iVar1 + DAT_021a15f4) & 1 << (uVar2 & 0xff)) != 0) {
      iVar3 = iVar3 + 1;
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x20);
  if (iVar3 == -1) {
    *(undefined1 *)(iVar1 + 0xe) = 0;
    return;
  }
  *(char *)(iVar1 + 0xe) = (char)iVar3;
  return;
}

