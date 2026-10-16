/* Decompiled C draft; module arm9; ROM address 02122734. No matching claim. */
#include "types.h"
#include "deps/02122734_func_02122734.h"

int func_02122734(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = *(uint *)(uRam02122774 & 0xfffffffc) >> (uRam02122774 & 3) * 8 |
          *(uint *)(uRam02122774 & 0xfffffffc) << (uRam02122774 & 3) * -8 + 0x20;
  do {
    if (param_1 == *(char *)(uVar1 + 0x1f4e)) {
      return iVar2;
    }
    iVar2 = (iVar2 + 1) * 0x1000000 >> 0x18;
    uVar1 = uVar1 + 1;
  } while (iVar2 < 4);
  return -1;
}

