/* Decompiled C draft; module arm9_ov000; ROM address 0219bbfc. No matching claim. */
#include "types.h"
#include "deps/0219bbfc_FUN_0219bbfc.h"

undefined4 FUN_0219bbfc(void)

{
  int iVar1;
  
  if ((*DAT_0219bc6c != 0) && (iVar1 = FUN_0219c39c(), iVar1 == 0)) {
    iVar1 = *DAT_0219bc6c;
    if ((*(int *)(iVar1 + 0x24) == 5) || (*(int *)(iVar1 + 0x24) == 6)) {
      if (*(char *)(iVar1 + DAT_0219bc70) == '\0') {
        FUN_0219d558(1,DAT_0219bc74,0);
        FUN_0219b110();
        FUN_0219b8a8(3);
        return 1;
      }
      *(undefined1 *)(iVar1 + 0x2d) = 1;
      FUN_021988e8(*(undefined4 *)*DAT_0219bc6c);
      *(undefined1 *)(*DAT_0219bc6c + 0x2d) = 0;
      return 0;
    }
  }
  return 0xffffffff;
}

