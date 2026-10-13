/* Decompiled C draft; module arm9; ROM address 0210b564. No matching claim. */
#include "types.h"
#include "deps/0210b564_func_0210b564.h"

void func_0210b564(int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  
  if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
    return;
  }
  if (param_2 == 2) {
    if (uRam0210b608 < param_5) {
      DriverContext_MaybeQueuePlaySfx(param_1,0x70,0x7f,0);
      return;
    }
    if (param_5 != 0) {
      DriverContext_MaybeQueuePlaySfx(param_1,0x6f,0x7f,0);
      return;
    }
  }
  iVar1 = func_0210bb74(param_2,param_3,param_4);
  if (iVar1 != iRam0210b60c) {
    DriverContext_MaybeQueuePlaySfx(param_1,iVar1,0x7f,0);
    return;
  }
  return;
}

