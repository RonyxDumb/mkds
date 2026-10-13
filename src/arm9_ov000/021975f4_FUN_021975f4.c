/* Decompiled C draft; module arm9_ov000; ROM address 021975f4. No matching claim. */
#include "types.h"
#include "deps/021975f4_FUN_021975f4.h"

int FUN_021975f4(int param_1)

{
  if (param_1 == 0) {
    param_1 = *DAT_02197624;
  }
  if (param_1 == 0) {
    FUN_02197190(*DAT_02197628 ^ DAT_0219762c,(char *)(uintptr_t)(DAT_02197630));
    return DAT_02197630;
  }
  return param_1 + 0x10;
}

