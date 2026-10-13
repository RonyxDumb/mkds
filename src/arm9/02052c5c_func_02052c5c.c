/* Decompiled C draft; module arm9; ROM address 02052c5c. No matching claim. */
#include "types.h"
#include "deps/02052c5c_func_02052c5c.h"

uint func_02052c5c(void)

{
  longlong lVar1;
  uint uVar2;
  uint local_18;
  int local_14;
  int local_10;
  
  GetCurrentTime(&local_18);
  if (0x11 < local_18) {
    local_18 = local_18 - 0x12;
  }
  uVar2 = OS_GetTickLo();
  uVar2 = uVar2 | ((local_18 * 0x3c + local_14) * 0x3c + local_10) * 0x10000;
  lVar1 = (ulonglong)uRam02052cec * (ulonglong)uVar2;
  return uVar2 * iRam02052ce8 + (int)((ulonglong)lVar1 >> 0x20) +
         (uint)CARRY4((uint)lVar1,uRam02052cf0) >> 0x10 | 0x8000;
}

