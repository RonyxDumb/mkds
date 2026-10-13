/* Decompiled C draft; module arm9; ROM address 0200c534. No matching claim. */
#include "types.h"
#include "deps/0200c534_ReadSomeExmemcntData_from_thumb.h"

void ReadSomeExmemcntData_from_thumb(int *param_1)

{
  ushort *puVar1;
  
  puVar1 = puRam0200c564;
  *param_1 = (int)(*puRam0200c564 & 0xc) >> 2;
  param_1[1] = (int)(*puVar1 & 0x10) >> 4;
  *puVar1 = *puVar1 & 0xfff3 | 0xc;
  *puVar1 = *puVar1 & 0xffef;
  return;
}

