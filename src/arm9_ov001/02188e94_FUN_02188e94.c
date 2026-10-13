/* Decompiled C draft; module arm9_ov001; ROM address 02188e94. No matching claim. */
#include "types.h"
#include "deps/02188e94_FUN_02188e94.h"

void FUN_02188e94(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  
  pcVar1 = (code *)*param_2;
  *param_2 = 0;
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  return;
}

