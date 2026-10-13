/* Decompiled C draft; module arm9; ROM address 02068eac. No matching claim. */
#include "types.h"
#include "deps/02068eac_DriverContext_IsKilledOrBeingKilled.h"

bool DriverContext_IsKilledOrBeingKilled(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x60) != 0;
}

