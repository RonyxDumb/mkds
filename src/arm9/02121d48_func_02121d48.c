/* Decompiled C draft; module arm9; ROM address 02121d48. No matching claim. */
#include "types.h"
#include "deps/02121d48_func_02121d48.h"

undefined4 func_02121d48(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (*(uint *)(uRam02121d90 & 0xfffffffc) >> (uRam02121d90 & 3) * 8 |
          *(uint *)(uRam02121d90 & 0xfffffffc) << (uRam02121d90 & 3) * -8 + 0x20) + 0x1950;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((4 < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) &&
     (iVar3 = func_02120644(), iVar3 == 0)) {
    return 1;
  }
  return 0;
}

