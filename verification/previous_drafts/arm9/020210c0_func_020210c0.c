/* Decompiled C draft; module arm9; ROM address 020210c0. No matching claim. */
#include "types.h"
#include "deps/020210c0_func_020210c0.h"

bool func_020210c0(uint param_1)

{
  uint uVar1;
  bool bVar2;
  
  Os_DisableIrq();
  uVar1 = *(uint *)(uRam02021110 & 0xfffffffc) >> (uRam02021110 & 3) * 8 |
          *(uint *)(uRam02021110 & 0xfffffffc) << (uRam02021110 & 3) * -8 + 0x20;
  if (uVar1 < param_1) {
    bVar2 = 0x7fffffff < param_1 - uVar1;
  }
  else if (uVar1 - param_1 < 0x80000000) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  Os_RestoreIrq();
  return bVar2;
}

