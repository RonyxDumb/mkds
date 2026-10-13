/* Decompiled C draft; module arm9; ROM address 02064180. No matching claim. */
#include "types.h"
#include "deps/02064180_DriverContext_Fn2_Replay_NonPlayer.h"

void DriverContext_Fn2_Replay_NonPlayer(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x40) = uVar1;
  uVar1 = GetAED0PlayerUnk(*(undefined2 *)(param_1 + 0x74));
  func_0210b7ec(param_1 + iRam020641b4,uVar1);
  return;
}

