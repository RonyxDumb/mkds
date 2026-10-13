/* Decompiled C draft; module arm9_ov000; ROM address 021a6944. No matching claim. */
#include "types.h"
#include "deps/021a6944_FUN_021a6944.h"

void FUN_021a6944(short *param_1)

{
  if (*param_1 == 0x12) {
    *(uint *)(DAT_021a696c + 0x24) = (uint)(ushort)param_1[1];
    if (param_1[1] == 0) {
      FUN_021a57a8();
    }
    func_0x0200df9c((uint *)(uintptr_t)(DAT_021a6970));
  }
  return;
}

