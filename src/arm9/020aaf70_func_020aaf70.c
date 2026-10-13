/* Decompiled C draft; module arm9; ROM address 020aaf70. No matching claim. */
#include "types.h"
#include "deps/020aaf70_func_020aaf70.h"

uint func_020aaf70(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(short *)((int)param_1 + 0xe) != 0) {
    do {
      if (*(ushort *)(param_1 + 3) + 1 == (uint)*(ushort *)(*param_1 + uVar1 * 8 + 6)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1 & 0xffff;
    } while (uVar1 < *(ushort *)((int)param_1 + 0xe));
  }
  return 0;
}

