/* Decompiled C draft; module arm7; ROM address 060095d0. No matching claim. */
#include "types.h"
#include "deps/060095d0_FUN_060095d0.h"

uint FUN_060095d0(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)(DAT_06009640 + (param_2 & 0xf) * 2) ^
          DAT_06009644 & (int)param_2 >> 4 & 0xffff ^
          (uint)*(ushort *)(DAT_06009640 + (param_1 & 0xf) * 2);
  return (uint)*(ushort *)(DAT_06009640 + (uVar1 & 0xf) * 2) ^ DAT_06009644 & (int)uVar1 >> 4 ^
         (uint)*(ushort *)(DAT_06009640 + ((int)param_1 >> 4 & 0xfU) * 2);
}

