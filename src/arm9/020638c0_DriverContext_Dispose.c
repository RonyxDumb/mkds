/* Decompiled C draft; module arm9; ROM address 020638c0. No matching claim. */
#include "types.h"
#include "deps/020638c0_DriverContext_Dispose.h"

void DriverContext_Dispose(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x22cU & 3;
  uVar2 = *(uint *)(param_1 + 0x22cU & 0xfffffffc);
  (*(code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20))();
  return;
}

