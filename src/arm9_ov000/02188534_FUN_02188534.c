/* Decompiled C draft; module arm9_ov000; ROM address 02188534. No matching claim. */
#include "types.h"
#include "deps/02188534_FUN_02188534.h"

void FUN_02188534(uint param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_02188584(1);
  iVar3 = FUN_02188584(0x10);
  *(char *)(iVar2 + 9) = (char)param_1;
  if (((param_1 < 0x10) && (*(byte *)(iVar2 + 0x16) < param_1)) &&
     (*(char *)(iVar2 + 0x16) = (char)param_1, 7 < param_1)) {
    uVar1 = FUN_021884d8(*(undefined1 *)(iVar3 + DAT_02188578));
    *(undefined1 *)(iVar2 + 0x15) = uVar1;
    *(undefined1 *)(iVar2 + 0x14) =
         *(undefined1 *)(iVar3 + (uint)*(byte *)(iVar3 + DAT_0218857c) * 4 + DAT_02188580);
  }
  return;
}

