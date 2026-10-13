/* Decompiled C draft; module arm9; ROM address 020641b8. No matching claim. */
#include "types.h"
#include "deps/020641b8_DriverContext_Fn2_Default.h"

void DriverContext_Fn2_Default(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  return;
}

