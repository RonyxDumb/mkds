/* Decompiled C draft; module arm9; ROM address 0213ed2c. No matching claim. */
#include "types.h"
#include "deps/0213ed2c_func_0213ed2c.h"

int func_0213ed2c(ushort *param_1,ushort *param_2,int param_3)

{
  uint uVar1;
  
  if (param_3 != 0) {
    do {
      uVar1 = (uint)*param_1;
      if (uVar1 != *param_2) {
        return uVar1 - *param_2;
      }
    } while ((uVar1 != 0) &&
            (param_3 = param_3 + -1, param_1 = param_1 + 1, param_2 = param_2 + 1, param_3 != 0));
  }
  return 0;
}

