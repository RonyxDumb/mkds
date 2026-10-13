/* Decompiled C draft; module arm9; ROM address 020569a8. No matching claim. */
#include "types.h"
#include "deps/020569a8_func_020569a8.h"

void func_020569a8(undefined4 param_1)

{
  Mem_CpuCopy8(param_1,*(int *)(*piRam020569d4 + 4) + 8,uRam020569d8);
  *(byte *)(*(int *)(*piRam020569d4 + 4) + 4) =
       *(byte *)(*(int *)(*piRam020569d4 + 4) + 4) & 0xfe | 1;
  func_02056430();
  return;
}

