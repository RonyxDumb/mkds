/* Decompiled C draft; module arm9; ROM address 0204a550. No matching claim. */
#include "types.h"
#include "deps/0204a550_SceneFn_Emblem.h"

undefined4 SceneFn_Emblem(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam0204a594;
  uStack_2c = puRam0204a594[1];
  uStack_28 = puRam0204a594[2];
  uStack_24 = puRam0204a594[3];
  local_20 = puRam0204a594[4];
  uStack_1c = puRam0204a594[5];
  uStack_18 = puRam0204a594[6];
  uStack_14 = puRam0204a594[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

