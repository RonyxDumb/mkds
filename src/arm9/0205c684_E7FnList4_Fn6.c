/* Decompiled C draft; module arm9; ROM address 0205c684. No matching claim. */
#include "types.h"
#include "deps/0205c684_E7FnList4_Fn6.h"

void E7FnList4_Fn6(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = uRam0205c6ac;
  *(undefined2 *)
   ((*(uint *)(uRam0205c6ac & 0xfffffffc) >> (uRam0205c6ac & 3) * 8 |
    *(uint *)(uRam0205c6ac & 0xfffffffc) << (uRam0205c6ac & 3) * -8 + 0x20) + 0x736) = 0xf0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x734) = 0;
  return;
}

