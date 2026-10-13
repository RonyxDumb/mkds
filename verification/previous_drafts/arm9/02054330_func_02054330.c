/* Decompiled C draft; module arm9; ROM address 02054330. No matching claim. */
#include "types.h"
#include "deps/02054330_func_02054330.h"

void func_02054330(void)

{
  int iVar1;
  uint uVar2;
  
  do {
    iVar1 = func_02054f58();
  } while (iVar1 != 1);
  uVar2 = *(uint *)(uRam02054364 & 0xfffffffc) >> (uRam02054364 & 3) * 8 |
          *(uint *)(uRam02054364 & 0xfffffffc) << (uRam02054364 & 3) * -8 + 0x20;
  *(byte *)(uVar2 + 0x456) = *(byte *)(uVar2 + 0x456) & 0xfe;
  return;
}

