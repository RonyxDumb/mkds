/* Decompiled C draft; module arm9_ov000; ROM address 021acda8. No matching claim. */
#include "types.h"
#include "deps/021acda8_FUN_021acda8.h"

void FUN_021acda8(ushort *param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = param_1;
  if (0 < param_2) {
    do {
      *puVar1 = ~*puVar1;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar2 < param_2);
  }
  FUN_021acdd0(param_1,param_1,1);
  return;
}

