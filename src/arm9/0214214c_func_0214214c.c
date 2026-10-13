/* Decompiled C draft; module arm9; ROM address 0214214c. No matching claim. */
#include "types.h"
#include "deps/0214214c_func_0214214c.h"

void func_0214214c(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = (uint *)(param_1 + 5 + param_2);
  while( true ) {
    puVar2 = (uint *)((int)puVar2 + -1);
    uVar3 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xff;
    if (uVar3 < 9) {
      uVar1 = uVar3 + 1 & 0xff |
              (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00;
      uVar3 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
      *puVar2 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
      return;
    }
    if (puVar2 == (uint *)(param_1 + 5)) break;
    uVar1 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00;
    uVar3 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
    *puVar2 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
  }
  uVar1 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00 | 1;
  uVar3 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
  *puVar2 = uVar1 >> uVar3 | uVar1 << 0x20 - uVar3;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  return;
}

