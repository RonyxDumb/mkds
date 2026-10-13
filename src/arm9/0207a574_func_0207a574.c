/* Decompiled C draft; module arm9; ROM address 0207a574. No matching claim. */
#include "types.h"
#include "deps/0207a574_func_0207a574.h"

undefined4 func_0207a574(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(char *)((*(uint *)(uRam0207a5b8 & 0xfffffffc) >> (uRam0207a5b8 & 3) * 8 |
                    *(uint *)(uRam0207a5b8 & 0xfffffffc) << (uRam0207a5b8 & 3) * -8 + 0x20) + 0x62)
          * iRam0207a5c0 +
          (*(uint *)(uRam0207a5bc & 0xfffffffc) >> (uRam0207a5bc & 3) * 8 |
          *(uint *)(uRam0207a5bc & 0xfffffffc) << (uRam0207a5bc & 3) * -8 + 0x20);
  uVar2 = iVar3 + 0x180;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) &&
     (uVar2 = iVar3 + 0x48, uVar1 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
     ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x4000000) == 0)) {
    return 0;
  }
  return 1;
}

