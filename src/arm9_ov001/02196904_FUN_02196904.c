/* Decompiled C draft; module arm9_ov001; ROM address 02196904. No matching claim. */
#include "types.h"
#include "deps/02196904_FUN_02196904.h"

void FUN_02196904(void)

{
  uint uVar1;
  uint uVar2;
  
  func_0x02117218();
  *DAT_0219694c = 0;
  uVar2 = DAT_02196958;
  uVar1 = DAT_02196954;
  *DAT_02196950 =
       *DAT_02196950 & DAT_02196958 | ((*DAT_02196950 & DAT_02196954) >> 8 & 0xffffffec) << 8;
  *DAT_0219695c = *DAT_0219695c & uVar2 | ((*DAT_0219695c & uVar1) >> 8 & 0xfffffff6) << 8;
  return;
}

