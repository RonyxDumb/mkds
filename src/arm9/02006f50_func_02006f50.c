/* Decompiled C draft; module arm9; ROM address 02006f50. No matching claim. */
#include "types.h"
#include "deps/02006f50_func_02006f50.h"

undefined4 func_02006f50(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)func_020070b8();
  iVar1 = param_2 * 0x68 + iRam02006f94;
  if ((*piVar2 == 4) && (piVar2[5] == param_1)) {
    *param_4 = *(undefined4 *)((int)piVar2 + iVar1 + 4);
    *param_3 = *(undefined4 *)((int)piVar2 + iVar1 + 0x10);
    return 1;
  }
  return 0;
}

