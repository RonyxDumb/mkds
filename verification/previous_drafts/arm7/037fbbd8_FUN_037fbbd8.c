/* Decompiled C draft; module arm7; ROM address 037fbbd8. No matching claim. */
#include "types.h"
#include "deps/037fbbd8_FUN_037fbbd8.h"

bool FUN_037fbbd8(int param_1)

{
  return (*(byte *)(param_1 * 0x10 + 0x4000403) & 0x80) != 0;
}

