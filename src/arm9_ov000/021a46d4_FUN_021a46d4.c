/* Decompiled C draft; module arm9_ov000; ROM address 021a46d4. No matching claim. */
#include "types.h"
#include "deps/021a46d4_FUN_021a46d4.h"

void FUN_021a46d4(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  
  iVar3 = FUN_0218e5e4();
  piVar1 = DAT_021a4714;
  if (iVar3 != 0) {
    *DAT_021a4714 = 0;
    iVar2 = DAT_021a4718;
    do {
      iVar6 = *piVar1 * 4;
      puVar5 = *(undefined1 **)(*(int *)(iVar3 + 0xc) + iVar6);
      if (puVar5 == (undefined1 *)0x0) {
        return;
      }
      iVar4 = iVar2 + iVar6;
      *(undefined1 *)(iVar2 + iVar6) = *puVar5;
      *(undefined1 *)(iVar4 + 1) = puVar5[1];
      *(undefined1 *)(iVar4 + 2) = puVar5[2];
      *(undefined1 *)(iVar4 + 3) = puVar5[3];
      iVar6 = *piVar1;
      *piVar1 = iVar6 + 1;
    } while (iVar6 + 1 < 5);
  }
  return;
}

