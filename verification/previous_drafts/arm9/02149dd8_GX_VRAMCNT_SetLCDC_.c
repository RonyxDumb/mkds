/* Decompiled C draft; module arm9; ROM address 02149dd8. No matching claim. */
#include "types.h"
#include "deps/02149dd8_GX_VRAMCNT_SetLCDC_.h"

void GX_VRAMCNT_SetLCDC_(uint param_1)

{
  if ((param_1 & 1) != 0) {
    *puRam02149e6c = 0x80;
  }
  if ((param_1 & 2) != 0) {
    *puRam02149e70 = 0x80;
  }
  if ((param_1 & 4) != 0) {
    *puRam02149e74 = 0x80;
  }
  if ((param_1 & 8) != 0) {
    *puRam02149e78 = 0x80;
  }
  if ((param_1 & 0x10) != 0) {
    *puRam02149e7c = 0x80;
  }
  if ((param_1 & 0x20) != 0) {
    *puRam02149e80 = 0x80;
  }
  if ((param_1 & 0x40) != 0) {
    *puRam02149e84 = 0x80;
  }
  if ((param_1 & 0x80) != 0) {
    *puRam02149e88 = 0x80;
  }
  if ((param_1 & 0x100) != 0) {
    *puRam02149e8c = 0x80;
  }
  return;
}

