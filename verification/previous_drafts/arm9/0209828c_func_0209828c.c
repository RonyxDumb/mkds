/* Decompiled C draft; module arm9; ROM address 0209828c. No matching claim. */
#include "types.h"
#include "deps/0209828c_func_0209828c.h"

uint func_0209828c(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = func_0209bf48(uRam020982c8,uRam020982cc,0);
  puVar1 = puRam020982d0;
  *puRam020982d0 = uVar2;
  func_020e6f50(puVar1);
  return *(uint *)((uint)puRam020982d0 & 0xfffffffc) >> ((uint)puRam020982d0 & 3) * 8 |
         *(uint *)((uint)puRam020982d0 & 0xfffffffc) << ((uint)puRam020982d0 & 3) * -8 + 0x20;
}

