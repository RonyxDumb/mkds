/* Decompiled C draft; module arm9; ROM address 02039eec. No matching claim. */
#include "types.h"
#include "deps/02039eec_SceneFn_Menu.h"

undefined4 SceneFn_Menu(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam02039f30;
  uStack_2c = puRam02039f30[1];
  uStack_28 = puRam02039f30[2];
  uStack_24 = puRam02039f30[3];
  local_20 = puRam02039f30[4];
  uStack_1c = puRam02039f30[5];
  uStack_18 = puRam02039f30[6];
  uStack_14 = puRam02039f30[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

