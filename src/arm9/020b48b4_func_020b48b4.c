/* Decompiled C draft; module arm9; ROM address 020b48b4. No matching claim. */
#include "types.h"
#include "deps/020b48b4_func_020b48b4.h"

void func_020b48b4(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 != 0) {
    iVar1 = Common_FindBlockByMagic(param_2,uRam020b48e8);
    if (iVar1 != 0) {
      *param_1 = iVar1 + 8;
    }
    return;
  }
  return;
}

