/* Decompiled C draft; module arm9_ov001; ROM address 0219f6a0. No matching claim. */
#include "types.h"
#include "deps/0219f6a0_FUN_0219f6a0.h"

int FUN_0219f6a0(char param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_18;
  
  iVar2 = 8;
  iVar3 = 0;
  do {
    iVar1 = func_0x0205fd78(param_1 + '\x01',iVar3 + 1U & 0xff,&local_18);
    if (iVar1 == 0) {
      iVar2 = 9;
    }
    else if (local_18 < iVar2) {
      iVar2 = local_18;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  return iVar2;
}

