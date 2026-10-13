/* Decompiled C draft; module arm9_ov003; ROM address 021b9134. No matching claim. */
#include "types.h"
#include "deps/021b9134_func_ov003_021b9134.h"

undefined4 func_ov003_021b9134(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == -1) {
    *piRam021b9168 = -1;
    return 0;
  }
  if (*piRam021b9168 != param_1) {
    *piRam021b9168 = param_1;
    uVar1 = func_ov003_021ba18c();
    return uVar1;
  }
  return 0;
}

