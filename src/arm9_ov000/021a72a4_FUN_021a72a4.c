/* Decompiled C draft; module arm9_ov000; ROM address 021a72a4. No matching claim. */
#include "types.h"
#include "deps/021a72a4_FUN_021a72a4.h"

int FUN_021a72a4(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021a8a54((uint)*(byte *)((int)param_1 + 3) << 2);
  iVar2 = FUN_021a8a54(*param_1);
  return iVar1 + iVar2;
}

