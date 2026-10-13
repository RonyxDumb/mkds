/* Decompiled C draft; module arm9_ov000; ROM address 021ae270. No matching claim. */
#include "types.h"
#include "deps/021ae270_FUN_021ae270.h"

void FUN_021ae270(void)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(DAT_021ae28c + 4) + 0xa4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = *(int *)(DAT_021ae28c + 4);
    *(undefined1 *)(piVar1 + 2) = 0;
    piVar1[0x11] = 0;
    piVar1[0x18] = 0;
    piVar1[0xe] = 0;
  }
  return;
}

