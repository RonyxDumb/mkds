/* Decompiled C draft; module arm9; ROM address 020d5148. No matching claim. */
#include "types.h"
#include "deps/020d5148_func_020d5148.h"

void func_020d5148(short param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 0x1c +
          (*(uint *)(uRam020d5178 & 0xfffffffc) >> (uRam020d5178 & 3) * 8 |
          *(uint *)(uRam020d5178 & 0xfffffffc) << (uRam020d5178 & 3) * -8 + 0x20);
  *(undefined4 *)(iVar1 + 0x10) = param_2;
  if ((*(ushort *)(iVar1 + 0x14) & 0x400) != 0) {
    *(ushort *)(iVar1 + 0x14) = *(ushort *)(iVar1 + 0x14) | *puRam020d517c;
  }
  return;
}

