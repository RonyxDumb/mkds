/* Decompiled C draft; module arm9; ROM address 020b2bf0. No matching claim. */
#include "types.h"
#include "deps/020b2bf0_SaveDataHolderIsBusy.h"

void SaveDataHolderIsBusy(void)

{
  if (*(char *)((*(uint *)(uRam020b2c20 & 0xfffffffc) >> (uRam020b2c20 & 3) * 8 |
                *(uint *)(uRam020b2c20 & 0xfffffffc) << (uRam020b2c20 & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    SaveDataIoManagerIsBusy12(0);
  }
  return;
}

