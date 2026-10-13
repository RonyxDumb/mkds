/* Decompiled C draft; module arm9; ROM address 02021080. No matching claim. */
#include "types.h"
#include "deps/02021080_func_02021080.h"

int func_02021080(void)

{
  uint uVar1;
  int iVar2;
  
  Os_DisableIrq();
  iVar2 = 0;
  for (uVar1 = *(uint *)(uRam020210bc & 0xfffffffc) >> (uRam020210bc & 3) * 8 |
               *(uint *)(uRam020210bc & 0xfffffffc) << (uRam020210bc & 3) * -8 + 0x20; uVar1 != 0;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) {
    iVar2 = iVar2 + 1;
  }
  Os_RestoreIrq();
  return iVar2;
}

