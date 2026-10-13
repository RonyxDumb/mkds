/* Decompiled C draft; module arm9_ov000; ROM address 02186474. No matching claim. */
#include "types.h"
#include "deps/02186474_FUN_02186474.h"

void FUN_02186474(void)

{
  int *piVar1;
  
  if (*DAT_021864c8 != 0) {
    func_0x0200ed34(*DAT_021864c8 + DAT_021864cc);
    piVar1 = DAT_021864c8;
    *(undefined4 *)(*DAT_021864c8 + DAT_021864d0) = 1;
    func_0x0200ecc4(*piVar1 + DAT_021864cc);
    if (*(int *)(*DAT_021864c8 + DAT_021864d4) != 0) {
      FUN_02187274();
    }
    if (*(int *)(*DAT_021864c8 + DAT_021864d8) != 0) {
      func_0x0200e084(*DAT_021864c8 + DAT_021864dc);
    }
  }
  return;
}

