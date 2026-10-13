/* Decompiled C draft; module arm9; ROM address 0210e5e4. No matching claim. */
#include "types.h"
#include "deps/0210e5e4_func_0210e5e4.h"

void func_0210e5e4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  undefined1 local_1c;
  byte local_1b;
  byte local_1a;
  byte local_19;
  uint local_18;
  uint local_14;
  uint local_10;
  
  GetCourseBgmInfo(param_2,&local_20);
  local_1b = local_1f;
  local_1a = local_1e;
  local_19 = local_1d;
  local_18 = (uint)local_1f;
  local_14 = (uint)local_1e;
  local_10 = (uint)local_1d;
  local_1c = local_20;
  Sound_MaybeSetActiveSdat(uRam0210e67c);
  iVar1 = func_0210e98c(local_18,local_14,local_10,1);
  if (iVar1 == 0) {
    return;
  }
  LoadPerRaceModeResultSseqs(param_1);
  return;
}

