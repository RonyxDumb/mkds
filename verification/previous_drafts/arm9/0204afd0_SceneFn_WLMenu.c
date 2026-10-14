/* Decompiled C draft; module arm9; ROM address 0204afd0. No matching claim. */
#include "types.h"
#include "deps/0204afd0_SceneFn_WLMenu.h"

undefined4 SceneFn_WLMenu(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam0204b014;
  uStack_2c = puRam0204b014[1];
  uStack_28 = puRam0204b014[2];
  uStack_24 = puRam0204b014[3];
  local_20 = puRam0204b014[4];
  uStack_1c = puRam0204b014[5];
  uStack_18 = puRam0204b014[6];
  uStack_14 = puRam0204b014[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

