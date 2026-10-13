/* Decompiled C draft; module arm9; ROM address 02133458. No matching claim. */
#include "types.h"
#include "deps/02133458_func_02133458.h"

ulonglong func_02133458(uint param_1,uint param_2,uint param_3)

{
  param_3 = param_3 & 0x3f;
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (param_3 < 0x20) {
    return CONCAT44(param_2 >> param_3,param_1 >> param_3 | param_2 << (0x20 - param_3 & 0xff));
  }
  return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
}

