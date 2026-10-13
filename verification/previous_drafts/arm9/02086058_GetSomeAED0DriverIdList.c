/* Decompiled C draft; module arm9; ROM address 02086058. No matching claim. */
#include "types.h"
#include "deps/02086058_GetSomeAED0DriverIdList.h"

int GetSomeAED0DriverIdList(void)

{
  return (*(uint *)(uRam02086068 & 0xfffffffc) >> (uRam02086068 & 3) * 8 |
         *(uint *)(uRam02086068 & 0xfffffffc) << (uRam02086068 & 3) * -8 + 0x20) + 0x94;
}

