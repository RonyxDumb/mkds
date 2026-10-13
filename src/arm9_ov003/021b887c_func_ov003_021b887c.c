/* Decompiled C draft; module arm9_ov003; ROM address 021b887c. No matching claim. */
#include "types.h"
#include "deps/021b887c_func_ov003_021b887c.h"

undefined4 func_ov003_021b887c(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = func_ov003_021b7c44(*(undefined2 *)(param_1 + 8));
  if (iVar1 < 1) {
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 6) != 'p') {
    return 0xffffffff;
  }
  func_ov003_021b7d90(param_2,param_1 + 0xc);
  return 0;
}

