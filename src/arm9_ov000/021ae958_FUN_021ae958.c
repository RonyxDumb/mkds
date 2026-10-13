/* Decompiled C draft; module arm9_ov000; ROM address 021ae958. No matching claim. */
#include "types.h"
#include "deps/021ae958_FUN_021ae958.h"

void FUN_021ae958(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_021af090();
  if (puVar1 != (undefined4 *)0x0) {
    func_0x0200dd94();
    *(undefined1 *)(puVar1 + 2) = 0;
    if (puVar1[1] - 1 < 2) {
      puVar1[1] = 0;
      func_0x0200df68(*puVar1);
    }
  }
  return;
}

