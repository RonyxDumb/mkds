/* Decompiled C draft; module arm9; ROM address 02008d30. No matching claim. */
#include "types.h"
#include "deps/02008d30_func_02008d30.h"

void func_02008d30(int param_1)

{
  if (*(char *)(*piRam02008d58 + 6) !=
      *(char *)(*piRam02008d5c + iRam02008d60 * param_1 + iRam02008d64)) {
    func_02008a4c();
  }
  return;
}

