/* Decompiled C draft; module arm9; ROM address 0205a630. No matching claim. */
#include "types.h"
#include "deps/0205a630_func_0205a630.h"

bool func_0205a630(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (*(uint *)(uRam0205a6b0 & 0xfffffffc) >> (uRam0205a6b0 & 3) * 8 |
          *(uint *)(uRam0205a6b0 & 0xfffffffc) << (uRam0205a6b0 & 3) * -8 + 0x20) + param_1 * 0x88 +
          0x170;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = func_020efd84((uint)*(byte *)((*(uint *)(uRam0205a6a8 & 0xfffffffc) >>
                                         (uRam0205a6a8 & 3) * 8 |
                                        *(uint *)(uRam0205a6a8 & 0xfffffffc) <<
                                        (uRam0205a6a8 & 3) * -8 + 0x20) + param_1 + 6) * 0x210 +
                        (*(uint *)(uRam0205a6ac & 0xfffffffc) >> (uRam0205a6ac & 3) * 8 |
                        *(uint *)(uRam0205a6ac & 0xfffffffc) << (uRam0205a6ac & 3) * -8 + 0x20),
                        uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (iVar2 != 0) {
    *(undefined4 *)
     ((*(uint *)(uRam0205a6b0 & 0xfffffffc) >> (uRam0205a6b0 & 3) * 8 |
      *(uint *)(uRam0205a6b0 & 0xfffffffc) << (uRam0205a6b0 & 3) * -8 + 0x20) + param_1 * 0x88 +
     0x170) = 0x13;
  }
  return iVar2 != 0;
}

