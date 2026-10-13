/* Decompiled C draft; module arm9; ROM address 02051400. No matching claim. */
#include "types.h"
#include "deps/02051400_func_02051400.h"

void func_02051400(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = uRam02051468;
  *(undefined4 *)
   ((*(uint *)(uRam02051468 & 0xfffffffc) >> (uRam02051468 & 3) * 8 |
    *(uint *)(uRam02051468 & 0xfffffffc) << (uRam02051468 & 3) * -8 + 0x20) + 0x10) = 0;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x454) = *(ushort *)(uVar2 + 0x454) & 0xfffe;
  if (*(short *)(param_1 + 2) == 0) {
    uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar1 = uVar3 + 4;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 0xb) {
      *(undefined4 *)(uVar3 + 4) = 0xc;
    }
    return;
  }
  func_020533a0();
  return;
}

