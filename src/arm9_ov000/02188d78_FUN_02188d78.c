/* Decompiled C draft; module arm9_ov000; ROM address 02188d78. No matching claim. */
#include "types.h"
#include "deps/02188d78_FUN_02188d78.h"

void FUN_02188d78(short *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_02188584(0x10);
  if (*param_1 == 5) {
    if (param_1[1] != 0) {
      iVar2 = *(int *)(param_1 + 4);
      if (iVar2 == 0xd) {
        *(undefined1 *)(iVar1 + DAT_02188de0) = 1;
        return;
      }
      if (iVar2 != 0xf) {
        if (iVar2 != 0x11) {
          *(undefined1 *)(iVar1 + DAT_02188de0) = 4;
          return;
        }
        *(undefined1 *)(iVar1 + DAT_02188de0) = 3;
        return;
      }
      *(undefined1 *)(iVar1 + DAT_02188de0) = 2;
      return;
    }
  }
  else if (*param_1 == 7) {
    FUN_02188ca8(*(undefined4 *)(param_1 + 2));
  }
  return;
}

