/* Decompiled C draft; module arm9; ROM address 02004db0. No matching claim. */
#include "types.h"
#include "deps/02004db0_Fs_IsInitialized.h"

uint Fs_IsInitialized(void)

{
  return *(uint *)(uRam02004dbc & 0xfffffffc) >> (uRam02004dbc & 3) * 8 |
         *(uint *)(uRam02004dbc & 0xfffffffc) << (uRam02004dbc & 3) * -8 + 0x20;
}

