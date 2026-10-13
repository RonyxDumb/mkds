/* Decompiled C draft; module arm9; ROM address 02046a88. No matching claim. */
#include "types.h"
#include "deps/02046a88_SceneFn_Menu2.h"

undefined4 SceneFn_Menu2(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam02046acc;
  uStack_2c = puRam02046acc[1];
  uStack_28 = puRam02046acc[2];
  uStack_24 = puRam02046acc[3];
  local_20 = puRam02046acc[4];
  uStack_1c = puRam02046acc[5];
  uStack_18 = puRam02046acc[6];
  uStack_14 = puRam02046acc[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

