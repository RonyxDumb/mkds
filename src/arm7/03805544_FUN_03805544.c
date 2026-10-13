/* Decompiled C draft; module arm7; ROM address 03805544. No matching claim. */
#include "types.h"
#include "deps/03805544_FUN_03805544.h"

void FUN_03805544(uint param_1,uint param_2)

{
  int iVar1;
  
  do {
    iVar1 = FUN_037fb5f4(5,(param_1 & 0x7f) << 8 | 0x8000 | param_2 & 0xff,0);
  } while (iVar1 < 0);
  return;
}

