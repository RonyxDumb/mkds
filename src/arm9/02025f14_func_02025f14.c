/* Decompiled C draft; module arm9; ROM address 02025f14. No matching claim. */
#include "types.h"
#include "deps/02025f14_func_02025f14.h"

void func_02025f14(int *param_1,int param_2)

{
  if (param_2 == 0) {
    if ((*param_1 == 2) || (*param_1 == 3)) {
      func_02025f54();
      return;
    }
  }
  else if (param_2 == 2) {
    if ((*param_1 == 0) || (*param_1 == 1)) {
      func_02025f54();
      return;
    }
  }
  else {
    func_02025f54();
  }
  return;
}

