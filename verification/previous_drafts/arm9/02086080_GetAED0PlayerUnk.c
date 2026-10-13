/* Decompiled C draft; module arm9; ROM address 02086080. No matching claim. */
#include "types.h"
#include "deps/02086080_GetAED0PlayerUnk.h"

uint GetAED0PlayerUnk(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02086094 & 0xfffffffc) >> (uRam02086094 & 3) * 8 |
          *(uint *)(uRam02086094 & 0xfffffffc) << (uRam02086094 & 3) * -8 + 0x20) + param_1 * 4 +
          0x124;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

