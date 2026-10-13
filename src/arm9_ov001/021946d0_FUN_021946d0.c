/* Decompiled C draft; module arm9_ov001; ROM address 021946d0. No matching claim. */
#include "types.h"
#include "deps/021946d0_FUN_021946d0.h"

void FUN_021946d0(void)

{
  uint uVar1;
  uint uVar2;
  
  func_0x02117218();
  func_0x0211df38();
  *DAT_0219471c = 0;
  uVar2 = DAT_02194728;
  uVar1 = DAT_02194724;
  *DAT_02194720 =
       *DAT_02194720 & DAT_02194728 | ((*DAT_02194720 & DAT_02194724) >> 8 & 0xffffffee) << 8;
  *DAT_0219472c = *DAT_0219472c & uVar2 | ((*DAT_0219472c & uVar1) >> 8 & 0xfffffff7) << 8;
  return;
}

