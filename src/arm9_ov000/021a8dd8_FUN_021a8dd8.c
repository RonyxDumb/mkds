/* Decompiled C draft; module arm9_ov000; ROM address 021a8dd8. No matching claim. */
#include "types.h"
#include "deps/021a8dd8_FUN_021a8dd8.h"

undefined4 FUN_021a8dd8(int param_1,int param_2,uint param_3)

{
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (param_2 == 3) {
    if (*(char *)(param_1 + 0x72) != '\x01') {
      return 4;
    }
    return 0;
  }
  if (param_2 == 4) {
    if ((param_3 & 4) == 0) {
      *(undefined1 *)(param_1 + 0x72) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x72) = 0;
    }
  }
  return 0;
}

