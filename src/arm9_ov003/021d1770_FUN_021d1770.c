/* Decompiled C draft; module arm9_ov003; ROM address 021d1770. No matching claim. */
#include "types.h"
#include "deps/021d1770_FUN_021d1770.h"

void FUN_021d1770(int param_1,int param_2,uint *param_3,uint *param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  *param_3 = (*(uint *)(iVar1 + param_2 * 8) & DAT_021d178c) >> 0x10;
  *param_4 = *(uint *)(iVar1 + param_2 * 8) & 0xff;
  return;
}

