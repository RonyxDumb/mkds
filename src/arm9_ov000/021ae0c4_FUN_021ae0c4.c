/* Decompiled C draft; module arm9_ov000; ROM address 021ae0c4. No matching claim. */
#include "types.h"
#include "deps/021ae0c4_FUN_021ae0c4.h"

void FUN_021ae0c4(int param_1)

{
  func_0x0200dd94();
  if ((byte)(*(char *)(param_1 + 8) - 3U) < 2) {
    FUN_021aefa8(param_1,0x19);
    *(undefined1 *)(param_1 + 8) = 7;
    return;
  }
  if (*(char *)(param_1 + 8) != '\0') {
    FUN_021aefb4(param_1,0x1a);
  }
  return;
}

