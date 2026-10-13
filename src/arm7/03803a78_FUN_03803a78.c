/* Decompiled C draft; module arm7; ROM address 03803a78. No matching claim. */
#include "types.h"
#include "deps/03803a78_FUN_03803a78.h"

void FUN_03803a78(int *param_1)

{
  ushort *puVar1;
  
  puVar1 = DAT_03803abc;
  *param_1 = (int)(*DAT_03803abc & 0xc) >> 2;
  param_1[1] = (int)(*puVar1 & 0x10) >> 4;
  *puVar1 = *puVar1 & 0xfff3 | 0xc;
  *puVar1 = *puVar1 & 0xffef;
  return;
}

