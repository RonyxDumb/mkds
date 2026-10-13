/* Decompiled C draft; module arm9; ROM address 0210ab48. No matching claim. */
#include "types.h"
#include "deps/0210ab48_func_0210ab48.h"

void func_0210ab48(void)

{
  int iVar1;
  int iStack_10;
  
  *(undefined4 *)(iRam0210abf0 + 100) = 1;
  iVar1 = IsInRaceSceneNormalOrReplay();
  if (iVar1 == 0) {
    return;
  }
  func_0212c6a0(&iStack_10);
  if (iStack_10 != 0) {
    func_0212c6f0(&iStack_10,0);
  }
  func_0212ec04(&iStack_10,7,0xffffffff,0xffffffff);
  func_02105b28(&iStack_10,0x6e);
  func_0212c688(&iStack_10);
  return;
}

