/* Decompiled C draft; module arm9; ROM address 02004dc0. No matching claim. */
#include "types.h"
#include "deps/02004dc0_Fs_Initialize.h"

void Fs_Initialize(void)

{
  if (*(uint *)((uint)puRam02004df8 & 0xfffffffc) >> ((uint)puRam02004df8 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02004df8 & 0xfffffffc) << ((uint)puRam02004df8 & 3) * -8 + 0x20 == 0) {
    *puRam02004df8 = 1;
    Fs_InitializeMountRom();
    return;
  }
  return;
}

