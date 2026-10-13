/* Decompiled C draft; module arm9; ROM address 020d2178. No matching claim. */
#include "types.h"
#include "deps/020d2178_func_020d2178.h"

uint func_020d2178(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (iRam020d21e8 <= (int)param_1) {
    uVar1 = _s32_div_f();
    uVar2 = 1 << (uVar1 & 0xff);
    param_1 = (int)((param_1 - iRam020d21e8 * uVar1) * 0x10000) >> 0x10;
  }
  if (99 < (int)param_1) {
    uVar1 = _s32_div_f(param_1,100);
    uVar2 = uVar2 | 1 << (uVar1 & 0xff);
    param_1 = (int)((param_1 + uVar1 * -100) * 0x10000) >> 0x10;
  }
  if (9 < (int)param_1) {
    uVar1 = _s32_div_f(param_1,10);
    uVar2 = uVar2 | 1 << (uVar1 & 0xff);
    param_1 = (int)((param_1 + uVar1 * -10) * 0x10000) >> 0x10;
  }
  if (0 < (int)param_1) {
    uVar2 = uVar2 | 1 << (param_1 & 0xff);
  }
  return uVar2;
}

