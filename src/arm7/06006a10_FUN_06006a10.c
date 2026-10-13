/* Decompiled C draft; module arm7; ROM address 06006a10. No matching claim. */
#include "types.h"
#include "deps/06006a10_FUN_06006a10.h"

uint FUN_06006a10(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = thunk_FUN_038068e0(param_3);
  iVar2 = DAT_06006a9c - (uint)*DAT_06006a98;
  if (iVar2 < 0) {
    iVar2 = iVar2 + DAT_06006aa0;
  }
  uVar3 = (int)((longlong)DAT_06006aa4 * (longlong)(iVar2 * 0x7f) >> 0x23) - (iVar2 * 0x7f >> 0x1f);
  if (uVar3 * 10 < (uint)((param_1 + 0x22) * 4 + param_2 * iVar1 + 1000)) {
    uVar3 = 0;
  }
  return uVar3 & 0xffff;
}

