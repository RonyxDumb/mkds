/* Decompiled C draft; module arm9; ROM address 020c0f48. No matching claim. */
#include "types.h"
#include "deps/020c0f48_func_020c0f48.h"

void func_020c0f48(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = uRam020c0fc8;
  uVar4 = *(uint *)(uRam020c0fc8 & 0xfffffffc) >> (uRam020c0fc8 & 3) * 8 |
          *(uint *)(uRam020c0fc8 & 0xfffffffc) << (uRam020c0fc8 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 0xb0;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  *(uint *)(uVar4 + 0xb0) = uVar5 + 1;
  if ((int)uVar5 < 0x14) {
    uVar3 = ComputeValueInterpolation_from_thumb(1,0x80,0,uVar5,0x14);
    *(undefined4 *)
     ((*(uint *)(uRam020c0fc8 & 0xfffffffc) >> (uRam020c0fc8 & 3) * 8 |
      *(uint *)(uRam020c0fc8 & 0xfffffffc) << (uRam020c0fc8 & 3) * -8 + 0x20) + 0xa0) = uVar3;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xa0) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xac) = uRam020c0fcc;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xb0) = 0;
  return;
}

