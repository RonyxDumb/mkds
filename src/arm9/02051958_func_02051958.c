/* Decompiled C draft; module arm9; ROM address 02051958. No matching claim. */
#include "types.h"
#include "deps/02051958_func_02051958.h"

/* WARNING: Removing unreachable block (ram,0x0205196c) */

void func_02051958(int param_1)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam02051a20;
  uVar1 = *(ushort *)(param_1 + 2);
  if (uVar1 != 0) {
    if ((uVar1 < 0x10) && (8 < uVar1)) {
      if (uVar1 == 9) {
        return;
      }
      if (uVar1 == 0xd) {
        return;
      }
      if (uVar1 == 0xf) {
        return;
      }
    }
    uVar3 = *(uint *)(uRam02051a20 & 0xfffffffc) >> (uRam02051a20 & 3) * 8 |
            *(uint *)(uRam02051a20 & 0xfffffffc) << (uRam02051a20 & 3) * -8 + 0x20;
    *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) | 1;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 8) = 2;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if (*(short *)(param_1 + 4) == 10) {
    uVar3 = *(uint *)(uRam02051a20 & 0xfffffffc) >> (uRam02051a20 & 3) * 8 |
            *(uint *)(uRam02051a20 & 0xfffffffc) << (uRam02051a20 & 3) * -8 + 0x20;
    *(ushort *)(uVar3 + 0x454) = *(ushort *)(uVar3 + 0x454) | 1;
    *(undefined1 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x1d54) = 0;
    *(undefined4 *)
     ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
      *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if (*(short *)(param_1 + 4) == 0xb) {
    return;
  }
  return;
}

