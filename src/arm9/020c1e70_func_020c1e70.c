/* Decompiled C draft; module arm9; ROM address 020c1e70. No matching claim. */
#include "types.h"
#include "deps/020c1e70_func_020c1e70.h"

void func_020c1e70(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = uRam020c1ef0;
  uVar4 = *(uint *)(uRam020c1ef0 & 0xfffffffc) >> (uRam020c1ef0 & 3) * 8 |
          *(uint *)(uRam020c1ef0 & 0xfffffffc) << (uRam020c1ef0 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 0xb0;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  *(uint *)(uVar4 + 0xb0) = uVar5 + 1;
  if ((int)uVar5 < 0x14) {
    uVar3 = ComputeValueInterpolation_from_thumb(1,0xffffff00,0,uVar5,0x14);
    *(undefined4 *)
     ((*(uint *)(uRam020c1ef0 & 0xfffffffc) >> (uRam020c1ef0 & 3) * 8 |
      *(uint *)(uRam020c1ef0 & 0xfffffffc) << (uRam020c1ef0 & 3) * -8 + 0x20) + 0xa0) = uVar3;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xa0) = 0;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xac) = uRam020c1ef4;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xb0) = 0;
  return;
}

