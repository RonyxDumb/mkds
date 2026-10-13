/* Decompiled C draft; module arm9; ROM address 0205cfd4. No matching claim. */
#include "types.h"
#include "deps/0205cfd4_func_0205cfd4.h"

void func_0205cfd4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam0205d078;
  uVar4 = 0;
  uVar3 = 0;
  do {
    *(undefined1 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar4 + 6) = 0xff;
    if ((param_1 & 1 << uVar4) != 0) {
      *(char *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar3) = (char)uVar4;
      *(char *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + uVar4 + 6) = (char)uVar3
      ;
      uVar3 = uVar3 + 1 & 0xff;
    }
    uVar2 = uRam0205d078;
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  *(char *)((*(uint *)(uRam0205d078 & 0xfffffffc) >> (uRam0205d078 & 3) * 8 |
            *(uint *)(uRam0205d078 & 0xfffffffc) << (uRam0205d078 & 3) * -8 + 0x20) + 4) =
       (char)param_1;
  if (uVar3 < 4) {
    do {
      uVar1 = uVar2 & 3;
      uVar4 = *(uint *)(uVar2 & 0xfffffffc);
      *(undefined1 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + uVar3) = 0xff;
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 4);
    return;
  }
  return;
}

