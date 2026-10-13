/* Decompiled C draft; module arm9_ov000; ROM address 02188584. No matching claim. */
#include "types.h"
#include "deps/02188584_FUN_02188584.h"

undefined4 FUN_02188584(uint param_1)

{
  if ((param_1 & 1) != 0) {
    return *DAT_021885d8;
  }
  if ((param_1 & 2) != 0) {
    return *DAT_021885dc;
  }
  if ((param_1 & 4) != 0) {
    return *DAT_021885e0;
  }
  if ((param_1 & 8) != 0) {
    return *DAT_021885e4;
  }
  if ((param_1 & 0x10) != 0) {
    return *DAT_021885e8;
  }
  return 0;
}

