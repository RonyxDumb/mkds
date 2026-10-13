/* Decompiled C draft; module arm9_ov001; ROM address 0219ea48. No matching claim. */
#include "types.h"
#include "deps/0219ea48_FUN_0219ea48.h"

void FUN_0219ea48(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  
  FUN_0219e118();
  if ((param_1 != 0) && (iVar2 = FUN_0219e0a8(), iVar2 != -1)) {
    uVar1 = FUN_0219e0a8();
    *(undefined2 *)(param_1 + 4) = uVar1;
  }
  return;
}

