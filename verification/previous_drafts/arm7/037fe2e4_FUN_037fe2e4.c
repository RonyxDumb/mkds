/* Decompiled C draft; module arm7; ROM address 037fe2e4. No matching claim. */
#include "types.h"
#include "deps/037fe2e4_FUN_037fe2e4.h"

int FUN_037fe2e4(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 < 0x10) {
    uVar2 = (uint)*(byte *)(param_1 + param_2 + 8);
    if (uVar2 == 0xff) {
      iVar1 = 0;
    }
    else {
      iVar1 = DAT_037fe30c + uVar2 * 0x40;
    }
    return iVar1;
  }
  return 0;
}

