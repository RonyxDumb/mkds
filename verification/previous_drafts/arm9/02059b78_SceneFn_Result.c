/* Decompiled C draft; module arm9; ROM address 02059b78. No matching claim. */
#include "types.h"
#include "deps/02059b78_SceneFn_Result.h"

undefined4 SceneFn_Result(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam02059bbc;
  uStack_2c = puRam02059bbc[1];
  uStack_28 = puRam02059bbc[2];
  uStack_24 = puRam02059bbc[3];
  local_20 = puRam02059bbc[4];
  uStack_1c = puRam02059bbc[5];
  uStack_18 = puRam02059bbc[6];
  uStack_14 = puRam02059bbc[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

