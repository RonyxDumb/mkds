/* Decompiled C draft; module arm9; ROM address 020c5e30. No matching claim. */
#include "types.h"
#include "deps/020c5e30_StructE8_SomeFnHandle2.h"

void StructE8_SomeFnHandle2(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = uRam020c5eb0;
  uVar4 = *(uint *)(uRam020c5eb0 & 0xfffffffc) >> (uRam020c5eb0 & 3) * 8 |
          *(uint *)(uRam020c5eb0 & 0xfffffffc) << (uRam020c5eb0 & 3) * -8 + 0x20;
  uVar5 = uVar4 + 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  *(uint *)(uVar4 + 4) = uVar5 + 1;
  if ((int)uVar5 < 0x14) {
    uVar3 = ComputeValueInterpolation_from_thumb(1,0xffffff00,0,uVar5,0x14);
    *(undefined4 *)
     ((*(uint *)(uRam020c5eb0 & 0xfffffffc) >> (uRam020c5eb0 & 3) * 8 |
      *(uint *)(uRam020c5eb0 & 0xfffffffc) << (uRam020c5eb0 & 3) * -8 + 0x20) + 0xe0) = uVar3;
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xe0) = 0;
  *(undefined4 *)
   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = uRam020c5eb4;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4) = 0;
  return;
}

