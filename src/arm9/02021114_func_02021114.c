/* Decompiled C draft; module arm9; ROM address 02021114. No matching claim. */
#include "types.h"
#include "deps/02021114_func_02021114.h"

uint func_02021114(void)

{
  uint uVar1;
  
  Os_DisableIrq();
  if (*(uint *)(uRam02021148 & 0xfffffffc) >> (uRam02021148 & 3) * 8 == 0 &&
      *(uint *)(uRam02021148 & 0xfffffffc) << (uRam02021148 & 3) * -8 + 0x20 == 0) {
    uVar1 = *(uint *)(uRam0202114c & 0xfffffffc) >> (uRam0202114c & 3) * 8 |
            *(uint *)(uRam0202114c & 0xfffffffc) << (uRam0202114c & 3) * -8 + 0x20;
  }
  else {
    uVar1 = *(uint *)(uRam02021150 & 0xfffffffc) >> (uRam02021150 & 3) * 8 |
            *(uint *)(uRam02021150 & 0xfffffffc) << (uRam02021150 & 3) * -8 + 0x20;
  }
  Os_RestoreIrq();
  return uVar1;
}

