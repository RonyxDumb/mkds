/* Decompiled C draft; module arm9_ov000; ROM address 021acc68. No matching claim. */
#include "types.h"
#include "deps/021acc68_FUN_021acc68.h"

void FUN_021acc68(int param_1,uint param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort *puVar2;
  
  puVar2 = (ushort *)(param_1 + param_3 * 2);
  for (; (param_2 != 0 && (param_3 < param_4)); param_3 = param_3 + 1) {
    uVar1 = *puVar2;
    *puVar2 = (ushort)(param_2 + uVar1);
    param_2 = param_2 + uVar1 >> 0x10;
    puVar2 = puVar2 + 1;
  }
  return;
}

