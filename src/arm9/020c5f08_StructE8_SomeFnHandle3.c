/* Decompiled C draft; module arm9; ROM address 020c5f08. No matching claim. */
#include "types.h"
#include "deps/020c5f08_StructE8_SomeFnHandle3.h"

void StructE8_SomeFnHandle3(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = uRam020c5f78;
  uVar2 = uRam020c5f74;
  if (*(char *)((*(uint *)(uRam020c5f6c & 0xfffffffc) >> (uRam020c5f6c & 3) * 8 |
                *(uint *)(uRam020c5f6c & 0xfffffffc) << (uRam020c5f6c & 3) * -8 + 0x20) + 0x28) ==
      '\0') {
    uVar5 = *(uint *)(uRam020c5f70 & 0xfffffffc) >> (uRam020c5f70 & 3) * 8 |
            *(uint *)(uRam020c5f70 & 0xfffffffc) << (uRam020c5f70 & 3) * -8 + 0x20;
    uVar4 = uVar5 + 0xc;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
      uVar4 = 0;
    }
    else {
      uVar5 = uVar5 + 0x10;
      uVar4 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    }
  }
  else {
    uVar4 = 1;
  }
  if (uVar4 != 0) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c5f74 & 0xfffffffc) >> (uRam020c5f74 & 3) * 8 |
    *(uint *)(uRam020c5f74 & 0xfffffffc) << (uRam020c5f74 & 3) * -8 + 0x20) + 0x18) = 0;
  *(undefined4 *)
   (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = uVar3;
  *(undefined4 *)
   ((*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
    *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 4) = 0;
  return;
}

