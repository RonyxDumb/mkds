/* Decompiled C draft; module arm9; ROM address 02081298. No matching claim. */
#include "types.h"
#include "deps/02081298_func_02081298.h"

void func_02081298(int param_1,int param_2)

{
  if (param_2 == 0) {
    func_0208335c();
    if (*(byte *)(param_1 + 0x98) < 7) {
      *(byte *)(param_1 + 0x98) = *(byte *)(param_1 + 0x98) + 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x99) = 1;
    }
    return;
  }
  return;
}

