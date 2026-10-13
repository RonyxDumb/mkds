/* Decompiled C draft; module arm9; ROM address 020aa5d8. No matching claim. */
#include "types.h"
#include "deps/020aa5d8_func_020aa5d8.h"

undefined4 func_020aa5d8(wchar_t param_1)

{
  wchar_t *pwVar1;
  
  pwVar1 = wcschr(*(wchar_t **)(iRam020aa5fc + 4),param_1);
  if (pwVar1 != (wchar_t *)0x0) {
    return 1;
  }
  return 0;
}

