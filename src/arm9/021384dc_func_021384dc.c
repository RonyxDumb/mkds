/* Decompiled C draft; module arm9; ROM address 021384dc. No matching claim. */
#include "types.h"
#include "deps/021384dc_func_021384dc.h"

uint func_021384dc(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam0213850c;
  uVar2 = (*(uint *)((uint)puRam02138500 & 0xfffffffc) >> ((uint)puRam02138500 & 3) * 8 |
          *(uint *)((uint)puRam02138500 & 0xfffffffc) << ((uint)puRam02138500 & 3) * -8 + 0x20) *
          iRam02138504 + iRam02138508;
  *puRam02138500 = uVar2;
  return uVar1 & uVar2 >> 0x10;
}

