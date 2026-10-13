/* Decompiled C draft; module arm9; ROM address 020429c8. No matching claim. */
#include "types.h"
#include "deps/020429c8_func_020429c8.h"

void func_020429c8(undefined4 param_1)

{
  if (*(short *)(*piRam02042a0c + 0x60) != 0) {
    func_02042e0c();
  }
  if (*(short *)(*piRam02042a0c + 0x70) != 0) {
    func_02042c3c(param_1);
    return;
  }
  if (*(short *)(*piRam02042a0c + 0x90) != 0) {
    func_02042a10(param_1);
  }
  return;
}

