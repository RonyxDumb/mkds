/* Decompiled C draft; module arm9; ROM address 020aa650. No matching claim. */
#include "types.h"
#include "deps/020aa650_func_020aa650.h"

wchar_t func_020aa650(wchar_t param_1)

{
  wchar_t *pwVar1;
  int extraout_r1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int unaff_r6;
  
  if ((param_1 == L'\0') || (param_1 == wRam020aa6d8)) {
    return param_1;
  }
  iVar4 = 0;
  puVar2 = puRam020aa6dc;
  do {
    pwVar1 = wcschr((wchar_t *)*puVar2,param_1);
    if (pwVar1 != (wchar_t *)0x0) {
      unaff_r6 = _s32_div_f((int)pwVar1 - puRam020aa6dc[iVar4],2);
      break;
    }
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  if (3 < iVar4) {
    return param_1;
  }
  iVar3 = 1;
  do {
    _s32_div_f(iVar4 + iVar3,4);
    if ((uint)*(ushort *)(unaff_r6 * 2 + puRam020aa6dc[extraout_r1]) != wRam020aa6d8) {
      return (uint)*(ushort *)(puRam020aa6dc[extraout_r1] + unaff_r6 * 2);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return param_1;
}

