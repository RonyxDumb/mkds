/* Decompiled C draft; module arm9_ov000; ROM address 021985ec. No matching claim. */
#include "types.h"
#include "deps/021985ec_FUN_021985ec.h"

undefined4 FUN_021985ec(int param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_02198618 < (uint)(param_2 - *(int *)(param_1 + 0x88))) &&
     (iVar1 = FUN_02198d04(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

