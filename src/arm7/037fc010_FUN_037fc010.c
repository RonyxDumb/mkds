/* Decompiled C draft; module arm7; ROM address 037fc010. No matching claim. */
#include "types.h"
#include "deps/037fc010_FUN_037fc010.h"

uint FUN_037fc010(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = DAT_037fc080;
  if ((DAT_037fc080 <= param_1) && (iVar2 = param_1, 0 < param_1)) {
    iVar2 = 0;
  }
  uVar1 = thunk_FUN_03801218(iVar2 + DAT_037fc084);
  if (iVar2 < -0xf0) {
    iVar2 = 3;
  }
  else if (iVar2 < -0x78) {
    iVar2 = 2;
  }
  else if (iVar2 < -0x3c) {
    iVar2 = 1;
  }
  else {
    iVar2 = 0;
  }
  return uVar1 & 0xffff | iVar2 << 8;
}

