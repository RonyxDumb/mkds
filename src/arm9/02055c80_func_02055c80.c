/* Decompiled C draft; module arm9; ROM address 02055c80. No matching claim. */
#include "types.h"
#include "deps/02055c80_func_02055c80.h"

void func_02055c80(undefined1 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam02055cb8;
  uVar2 = *(uint *)(uRam02055cb8 & 0xfffffffc) >> (uRam02055cb8 & 3) * 8 |
          *(uint *)(uRam02055cb8 & 0xfffffffc) << (uRam02055cb8 & 3) * -8 + 0x20;
  if ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) != 2) {
    return;
  }
  *(ushort *)(uVar2 + 8) = *(ushort *)(uVar2 + 8) | 2;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xc) = 0x1000;
  *(undefined1 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 10) = param_1;
  return;
}

