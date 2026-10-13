/* Decompiled C draft; module arm9_ov000; ROM address 02187274. No matching claim. */
#include "types.h"
#include "deps/02187274_FUN_02187274.h"

void FUN_02187274(char *param_1)

{
  char *pcVar1;
  
  if (*param_1 == -1) {
    func_0x0200ed34((int)(uintptr_t)(param_1 + DAT_021872ac));
    pcVar1 = param_1 + DAT_021872b0;
    pcVar1[0] = '\x01';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    func_0x0200ecc4((int)(uintptr_t)(param_1 + DAT_021872ac));
    if (*(int *)(param_1 + DAT_021872b4) != 0) {
      func_0x0200e084((int)(uintptr_t)(param_1 + DAT_021872b8));
    }
  }
  return;
}

