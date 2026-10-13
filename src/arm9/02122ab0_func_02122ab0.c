/* Decompiled C draft; module arm9; ROM address 02122ab0. No matching claim. */
#include "types.h"
#include "deps/02122ab0_func_02122ab0.h"

void func_02122ab0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam02122ae0;
  *(undefined1 *)
   ((*(uint *)(uRam02122ae0 & 0xfffffffc) >> (uRam02122ae0 & 3) * 8 |
    *(uint *)(uRam02122ae0 & 0xfffffffc) << (uRam02122ae0 & 3) * -8 + 0x20) + 0x19ad) = 0;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(undefined2 *)(uVar2 + 0x18) = 2;
  *(undefined2 *)(uVar2 + 0x1a) = 1;
  return;
}

