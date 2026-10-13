/* Decompiled C draft; module arm9; ROM address 0214c4d4. No matching claim. */
#include "types.h"
#include "deps/0214c4d4_func_0214c4d4.h"

void func_0214c4d4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(uint *)(uRam0214c530 & 0xfffffffc) >> (uRam0214c530 & 3) * 8 |
      *(uint *)(uRam0214c530 & 0xfffffffc) << (uRam0214c530 & 3) * -8 + 0x20) != 0xffffffff) {
    MI_WaitDma();
  }
  func_021495e4(*(uint *)((uint)puRam0214c534 & 0xfffffffc) >> ((uint)puRam0214c534 & 3) * 8 |
                *(uint *)((uint)puRam0214c534 & 0xfffffffc) << ((uint)puRam0214c534 & 3) * -8 + 0x20
               );
  puVar3 = puRam0214c540;
  puVar2 = puRam0214c53c;
  puVar1 = puRam0214c534;
  *puRam0214c538 = 0;
  *puVar2 = 0;
  *puVar3 = 0;
  *puVar1 = 0;
  return;
}

