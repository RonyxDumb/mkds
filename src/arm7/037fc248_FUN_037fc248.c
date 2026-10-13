/* Decompiled C draft; module arm7; ROM address 037fc248. No matching claim. */
#include "types.h"
#include "deps/037fc248_FUN_037fc248.h"

void FUN_037fc248(void)

{
  int iVar1;
  
  iVar1 = FUN_037f9854(DAT_037fc288,1,0);
  if (iVar1 == 0) {
    (*(code *)(*(uint *)(DAT_037fc290 & 0xfffffffc) >> (DAT_037fc290 & 3) * 8 |
              *(uint *)(DAT_037fc290 & 0xfffffffc) << (DAT_037fc290 & 3) * -8 + 0x20))(DAT_037fc28c)
    ;
  }
  return;
}

