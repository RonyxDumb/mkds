/* Decompiled C draft; module arm9; ROM address 0210d980. No matching claim. */
#include "types.h"
#include "deps/0210d980_Sound_IsGlobalSdatUsed.h"

uint Sound_IsGlobalSdatUsed(void)

{
  return *(uint *)(uRam0210d98c & 0xfffffffc) >> (uRam0210d98c & 3) * 8 |
         *(uint *)(uRam0210d98c & 0xfffffffc) << (uRam0210d98c & 3) * -8 + 0x20;
}

