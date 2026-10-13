/* Decompiled C draft; module arm9; ROM address 020aa094. No matching claim. */
#include "types.h"
#include "deps/020aa094_func_020aa094.h"

wchar_t func_020aa094(undefined4 *param_1,wchar_t param_2)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t wVar3;
  undefined4 *puVar4;
  int iVar5;
  
  iVar5 = 0;
  puVar4 = param_1;
  do {
    pwVar1 = wcschr((wchar_t *)*puVar4,param_2);
    if (pwVar1 != (wchar_t *)0x0) {
      iVar2 = _s32_div_f((int)pwVar1 - param_1[iVar5],2);
      wVar3 = (wchar_t)*(ushort *)(param_1[1 - iVar5] + iVar2 * 2);
      if (wVar3 != wRam020aa0e8) {
        return wVar3;
      }
      return param_2;
    }
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return param_2;
}

