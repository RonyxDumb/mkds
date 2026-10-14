/* Decompiled C draft; module arm9; ROM address 02098328. No matching claim. */
#include "types.h"
#include "deps/02098328_func_02098328.h"

uint func_02098328(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = CreateAllocateMapObject_from_thumb(uRam02098364,uRam02098368,uRam0209836c);
  puVar1 = puRam02098370;
  *puRam02098370 = uVar2;
  func_020d49d8(puVar1);
  return *(uint *)((uint)puRam02098370 & 0xfffffffc) >> ((uint)puRam02098370 & 3) * 8 |
         *(uint *)((uint)puRam02098370 & 0xfffffffc) << ((uint)puRam02098370 & 3) * -8 + 0x20;
}

