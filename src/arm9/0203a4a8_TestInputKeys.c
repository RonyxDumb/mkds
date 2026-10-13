/* Decompiled C draft; module arm9; ROM address 0203a4a8. No matching claim. */
#include "types.h"
#include "deps/0203a4a8_TestInputKeys.h"

ushort TestInputKeys(int param_1,ushort param_2)

{
  return *(ushort *)(iRam0203a4c8 + param_1 * 0x5c) & param_2;
}

