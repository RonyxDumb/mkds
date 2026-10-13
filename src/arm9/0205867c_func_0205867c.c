/* Decompiled C draft; module arm9; ROM address 0205867c. No matching claim. */
#include "types.h"
#include "deps/0205867c_func_0205867c.h"

undefined4 func_0205867c(int param_1,int param_2,int param_3,int *param_4,undefined2 *param_5)

{
  int iVar1;
  
  iVar1 = iRam020586a8 - param_3 * param_2;
  if (iVar1 < 1) {
    return 0;
  }
  if (param_3 < iVar1) {
    iVar1 = param_3;
  }
  *param_5 = (short)iVar1;
  *param_4 = param_1 + param_3 * param_2;
  return 1;
}

