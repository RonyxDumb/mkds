/* Decompiled C draft; module arm9_ov000; ROM address 02187fb8. No matching claim. */
#include "types.h"
#include "deps/02187fb8_FUN_02187fb8.h"

void FUN_02187fb8(void)

{
  if (*DAT_02187ff8 != 0) {
    if (*DAT_02187ffc != 0) {
      FUN_02187274();
    }
    FUN_02186474();
    if (*(int *)(*DAT_02187ff8 + DAT_02188000) != 0) {
      func_0x0200e084(*DAT_02187ff8 + DAT_02188004);
    }
    *(undefined4 *)(*DAT_02187ff8 + 4) = 0xfffffff9;
  }
  return;
}

