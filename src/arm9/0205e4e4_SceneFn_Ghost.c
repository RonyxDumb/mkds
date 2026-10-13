/* Decompiled C draft; module arm9; ROM address 0205e4e4. No matching claim. */
#include "types.h"
#include "deps/0205e4e4_SceneFn_Ghost.h"

undefined4 SceneFn_Ghost(undefined4 param_1)

{
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined1 auStack_10 [4];
  
  local_30 = *puRam0205e514;
  uStack_2c = puRam0205e514[1];
  local_28 = puRam0205e514[2];
  uStack_24 = puRam0205e514[3];
  local_20 = puRam0205e514[4];
  uStack_1c = puRam0205e514[5];
  local_18 = puRam0205e514[6];
  uStack_14 = puRam0205e514[7];
  OnSceneLoop(param_1,&local_30,&local_30,auStack_10);
  return 0;
}

