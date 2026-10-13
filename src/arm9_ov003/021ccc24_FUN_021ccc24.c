/* Decompiled C draft; module arm9_ov003; ROM address 021ccc24. No matching claim. */
#include "types.h"
#include "deps/021ccc24_FUN_021ccc24.h"

void FUN_021ccc24(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  param_1 = (uint)*(byte *)(*DAT_021ccc80 + 0x1a) - param_1;
  if (param_1 < 0) {
    param_1 = -param_1;
  }
  if (param_1 < 2) {
    uVar1 = 0;
  }
  else if (param_1 < 6) {
    uVar1 = func_0x02147d30(0x7f,6 - param_1);
  }
  else {
    uVar1 = 0x7f;
  }
  FUN_021cdbfc(uVar1);
  if (param_1 < 2) {
    iVar2 = -0x100;
  }
  else {
    iVar2 = DAT_021ccc88;
    if (param_1 < 6) {
      iVar2 = func_0x02147d30(DAT_021ccc84,6 - param_1);
      iVar2 = iVar2 - DAT_021ccc88;
    }
  }
  FUN_021cdbe4(DAT_021ccc8c,iVar2);
  return;
}

