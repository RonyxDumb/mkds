/* Decompiled C draft; module arm9; ROM address 02079b40. No matching claim. */
#include "types.h"
#include "deps/02079b40_GetDriverKartIndexMod3.h"

undefined2 GetDriverKartIndexMod3(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam02079b5c & 0xfffffffc) >> (uRam02079b5c & 3) * 8 |
          *(uint *)(uRam02079b5c & 0xfffffffc) << (uRam02079b5c & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return *(undefined2 *)(param_1 * 0xb4 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x68);
}

