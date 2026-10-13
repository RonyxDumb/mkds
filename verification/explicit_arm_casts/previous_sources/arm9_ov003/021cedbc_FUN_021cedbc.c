/* Decompiled C draft; module arm9_ov003; ROM address 021cedbc. No matching claim. */
#include "types.h"
#include "deps/021cedbc_FUN_021cedbc.h"

void FUN_021cedbc(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_20 [12];
  
  iVar4 = DAT_021cee84;
  iVar2 = DAT_021cee80;
  iVar5 = 0;
  uVar3 = (uint)*(byte *)(*DAT_021cee7c + 0x1c);
  if (*(char *)(DAT_021cee80 + uVar3) != '\0') {
    do {
      FUN_021d250c(iVar4 + uVar3 * 8 + (uint)*(byte *)(iVar5 + DAT_021cee88 + uVar3 * 2) * 4,
                   DAT_021cee8c + uVar3 * 4,auStack_20);
      iVar1 = FUN_021d2a34(auStack_20);
      if (iVar1 != 0) {
        *(char *)(*DAT_021cee7c + 0x1b) = (char)iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
      uVar3 = (uint)*(byte *)(*DAT_021cee7c + 0x1c);
    } while (iVar5 < (int)(uint)*(byte *)(iVar2 + uVar3));
  }
  iVar2 = FUN_021d2b04(1);
  if (iVar2 != 0) {
    *(undefined1 *)(*DAT_021cee7c + 0x1b) =
         *(undefined1 *)(DAT_021cee90 + (uint)*(byte *)(*DAT_021cee7c + 0x1c) * 2);
  }
  iVar2 = FUN_021d2b04(2);
  if (iVar2 != 0) {
    *(undefined1 *)(*DAT_021cee7c + 0x1b) =
         *(undefined1 *)(DAT_021cee94 + (uint)*(byte *)(*DAT_021cee7c + 0x1c) * 2);
  }
  iVar2 = 0;
  iVar4 = *DAT_021cee7c;
  if (*(char *)(DAT_021cee80 + (uint)*(byte *)(iVar4 + 0x1c)) != '\0') {
    do {
      if (iVar2 == *(char *)(iVar4 + 0x1b)) {
        FUN_021ceb80();
        return;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(DAT_021cee80 + (uint)*(byte *)(iVar4 + 0x1c)));
  }
  *(undefined1 *)(iVar4 + 0x1b) = 0xff;
  return;
}

