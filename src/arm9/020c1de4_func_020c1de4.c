/* Decompiled C draft; module arm9; ROM address 020c1de4. No matching claim. */
#include "types.h"
#include "deps/020c1de4_func_020c1de4.h"

void func_020c1de4(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = uRam020c1e64;
  uVar4 = *(uint *)(uRam020c1e64 & 0xfffffffc) >> (uRam020c1e64 & 3) * 8 |
          *(uint *)(uRam020c1e64 & 0xfffffffc) << (uRam020c1e64 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0xb0;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(uVar4 + 0xb0) = uVar2 + 1;
  if (0x59 < (int)uVar2) {
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xac) = uRam020c1e68;
    *(undefined4 *)
     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xb0) = 0;
  }
  uVar3 = uRam020c1e64;
  if ((*(ushort *)(iRam020c1e6c + 0x2e0) & 1) == 0) {
    return;
  }
  if ((int)uVar2 < 0x2d) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c1e64 & 0xfffffffc) >> (uRam020c1e64 & 3) * 8 |
    *(uint *)(uRam020c1e64 & 0xfffffffc) << (uRam020c1e64 & 3) * -8 + 0x20) + 0xac) = uRam020c1e68;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0xb0) = 0;
  return;
}

