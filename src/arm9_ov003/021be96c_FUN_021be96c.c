/* Decompiled C draft; module arm9_ov003; ROM address 021be96c. No matching claim. */
#include "types.h"
#include "deps/021be96c_FUN_021be96c.h"

int FUN_021be96c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  func_0x021a67dc(1);
  iVar1 = func_0x021a6844();
  if ((0 < iVar1) && (uVar3 = 0, 0 < iVar1)) {
    do {
      if (param_2 <= (int)uVar3) break;
      uVar2 = func_0x021a6788(uVar3 & 0xffff);
      func_0x0214d02c((undefined4 *)(uintptr_t)(uVar2),(undefined4 *)(uintptr_t)(param_1),0xc0);
      uVar3 = uVar3 + 1;
      param_1 = param_1 + 0xc0;
    } while ((int)uVar3 < iVar1);
  }
  func_0x021a67dc(0);
  return iVar1;
}

