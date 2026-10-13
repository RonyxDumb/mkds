/* Decompiled C draft; module arm9; ROM address 02051528. No matching claim. */
#include "types.h"
#include "deps/02051528_func_02051528.h"

void func_02051528(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  *(undefined4 *)
   ((*(uint *)(uRam020515ac & 0xfffffffc) >> (uRam020515ac & 3) * 8 |
    *(uint *)(uRam020515ac & 0xfffffffc) << (uRam020515ac & 3) * -8 + 0x20) + 0x10) = 0;
  if ((*(short *)(param_1 + 2) != 0) && (*(short *)(param_1 + 2) != 7)) {
    return;
  }
  uVar1 = *(uint *)(uRam020515ac & 0xfffffffc) >> (uRam020515ac & 3) * 8 |
          *(uint *)(uRam020515ac & 0xfffffffc) << (uRam020515ac & 3) * -8 + 0x20;
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  }
  if ((uVar2 == 1) &&
     ((uVar2 = uVar1 + 4 & 3, uVar1 = *(uint *)(uVar1 + 4 & 0xfffffffc),
      uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20, uVar1 == 8 || (uVar1 == 9)))) {
    uVar1 = *(uint *)(uRam020515ac & 0xfffffffc) >> (uRam020515ac & 3) * 8 |
            *(uint *)(uRam020515ac & 0xfffffffc) << (uRam020515ac & 3) * -8 + 0x20;
    *(byte *)(uVar1 + 0x1eac) = *(byte *)(uVar1 + 0x1eac) | *(byte *)(uVar1 + 0x8a);
  }
  *(undefined1 *)
   ((*(uint *)(uRam020515ac & 0xfffffffc) >> (uRam020515ac & 3) * 8 |
    *(uint *)(uRam020515ac & 0xfffffffc) << (uRam020515ac & 3) * -8 + 0x20) + 0x8a) = 0;
  return;
}

