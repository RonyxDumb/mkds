/* Decompiled C draft; module arm9; ROM address 0201ebe8. No matching claim. */
#include "types.h"
#include "deps/0201ebe8_func_0201ebe8.h"

int func_0201ebe8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 local_10;
  
  local_10 = (short)param_1;
  uVar1 = (uint)(param_1 << 0x12) >> 0x1e;
  iVar2 = ((int)local_10 << 0x14) >> 0x14;
  if (uVar1 != 1) {
    if (uVar1 == 2) {
      iVar2 = iVar2 - param_2;
    }
    return iVar2;
  }
  return iVar2 - (param_2 + 1) / 2;
}

