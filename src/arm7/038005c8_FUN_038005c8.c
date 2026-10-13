/* Decompiled C draft; module arm7; ROM address 038005c8. No matching claim. */
#include "types.h"
#include "deps/038005c8_FUN_038005c8.h"

bool FUN_038005c8(void)

{
  undefined4 *puVar1;
  bool bVar2;
  
  FUN_03800610(0,DAT_03800608);
  puVar1 = (undefined4 *)
           (*(uint *)(DAT_0380060c & 0xfffffffc) >> (DAT_0380060c & 3) * 8 |
           *(uint *)(DAT_0380060c & 0xfffffffc) << (DAT_0380060c & 3) * -8 + 0x20);
  bVar2 = (*(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20) == 4;
  if (bVar2) {
    *puVar1 = 6;
  }
  return !bVar2;
}

