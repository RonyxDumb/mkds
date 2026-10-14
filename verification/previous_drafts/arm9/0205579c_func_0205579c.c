/* Decompiled C draft; module arm9; ROM address 0205579c. No matching claim. */
#include "types.h"
#include "deps/0205579c_func_0205579c.h"

void func_0205579c(int param_1,int param_2)

{
  if (param_1 == 0) {
    if (*psRam02055804 == 2) {
      func_0204e1a8();
      return;
    }
    func_02055808();
    return;
  }
  if (param_2 != 0) {
    func_0204e1a8();
    return;
  }
  func_02055808();
  return;
}

