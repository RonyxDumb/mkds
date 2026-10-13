/* Decompiled C draft; module arm9; ROM address 0210b198. No matching claim. */
#include "types.h"
#include "deps/0210b198_func_0210b198.h"

void func_0210b198(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  int iVar1;
  int iStack_18;
  
  iVar1 = IsInRaceSceneNormalOrReplay();
  if (iVar1 != 0) {
    func_0212c6a0(&iStack_18);
    if (iStack_18 != 0) {
      func_0212c6f0(&iStack_18,0);
    }
    func_0212ec04(&iStack_18,param_4,0xffffffff,param_5);
    func_02105b28((undefined4)(uintptr_t)(&iStack_18),param_3);
    func_0212c688(&iStack_18);
    return;
  }
  return;
}

