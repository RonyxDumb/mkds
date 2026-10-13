/* Decompiled C draft; module arm9; ROM address 0211ff74. No matching claim. */
#include "types.h"
#include "deps/0211ff74_func_0211ff74.h"

void func_0211ff74(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0211ffa8 & 0xfffffffc) >> (uRam0211ffa8 & 3) * 8 |
          *(uint *)(uRam0211ffa8 & 0xfffffffc) << (uRam0211ffa8 & 3) * -8 + 0x20) + 0x1f38;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    return;
  }
  uVar2 = *(uint *)(uRam0211ffac & 0xfffffffc) >> (uRam0211ffac & 3) * 8 |
          *(uint *)(uRam0211ffac & 0xfffffffc) << (uRam0211ffac & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x75c) = *(ushort *)(uVar2 + 0x75c) & 0xfffb;
  return;
}

