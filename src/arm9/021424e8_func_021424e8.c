/* Decompiled C draft; module arm9; ROM address 021424e8. No matching claim. */
#include "types.h"
#include "deps/021424e8_func_021424e8.h"

void func_021424e8(void)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  puVar3 = puRam0214253c;
  uVar5 = *(uint *)((uint)puRam0214253c & 0xfffffffc) >> ((uint)puRam0214253c & 3) * 8 |
          *(uint *)((uint)puRam0214253c & 0xfffffffc) << ((uint)puRam0214253c & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    return;
  }
  do {
    *puVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    uVar1 = uVar5 + 8 & 3;
    uVar4 = *(uint *)(uVar5 + 8 & 0xfffffffc);
    uVar2 = uVar5 + 4 & 3;
    uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc);
    (*(code *)(uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20))
              (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,0xffffffff);
    uVar5 = *(uint *)((uint)puVar3 & 0xfffffffc) >> ((uint)puVar3 & 3) * 8 |
            *(uint *)((uint)puVar3 & 0xfffffffc) << ((uint)puVar3 & 3) * -8 + 0x20;
  } while (uVar5 != 0);
  return;
}

