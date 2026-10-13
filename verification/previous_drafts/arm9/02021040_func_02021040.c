/* Decompiled C draft; module arm9; ROM address 02021040. No matching claim. */
#include "types.h"
#include "deps/02021040_func_02021040.h"

int func_02021040(void)

{
  uint uVar1;
  int iVar2;
  
  Os_DisableIrq();
  iVar2 = 0;
  for (uVar1 = *(uint *)(uRam0202107c & 0xfffffffc) >> (uRam0202107c & 3) * 8 |
               *(uint *)(uRam0202107c & 0xfffffffc) << (uRam0202107c & 3) * -8 + 0x20; uVar1 != 0;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) {
    iVar2 = iVar2 + 1;
  }
  Os_RestoreIrq();
  return iVar2;
}

