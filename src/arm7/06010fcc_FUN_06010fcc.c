/* Decompiled C draft; module arm7; ROM address 06010fcc. No matching claim. */
#include "types.h"
#include "deps/06010fcc_FUN_06010fcc.h"

undefined4 FUN_06010fcc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_2 + 2) = 1;
  if (*(ushort *)(param_1 + 0x10) < 2) {
    FUN_06009ecc(*(ushort *)(param_1 + 0x10));
    if (*(short *)(param_1 + 0x10) == 1) {
      FUN_0600a888();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

