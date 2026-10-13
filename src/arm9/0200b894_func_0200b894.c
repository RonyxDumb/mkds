/* Decompiled C draft; module arm9; ROM address 0200b894. No matching claim. */
#include "types.h"
#include "deps/0200b894_func_0200b894.h"

void func_0200b894(int param_1)

{
  short sVar1;
  
  if (*(short *)(param_1 + 2) != 0) {
    func_0200b820(10);
    return;
  }
  sVar1 = *(short *)(param_1 + 8);
  if (sVar1 == 3) {
    return;
  }
  if (sVar1 != 4) {
    if (sVar1 != 5) {
      func_0200b820(10,1);
      return;
    }
    if (*(int *)(param_1 + 0x3c) == *(int *)(*piRam0200b920 + iRam0200b924)) {
      DC_InvalidateRangeNoClean(*piRam0200b920 + iRam0200b928,0xc0);
      func_0200921c(uRam0200b92c,*(undefined2 *)(param_1 + 0x12),*piRam0200b920 + iRam0200b928);
      func_02008f00(uRam0200b92c,1);
    }
  }
  func_02008f00(uRam0200b92c,0);
  if (*(int *)(*piRam0200b920 + iRam0200b930) == 0) {
    func_0200b6e8();
    return;
  }
  func_0200b934();
  return;
}

