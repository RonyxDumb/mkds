/* Decompiled C draft; module arm9; ROM address 0203c018. No matching claim. */
#include "types.h"
#include "deps/0203c018_SceneFn_Title.h"

undefined4 SceneFn_Title(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam0203c05c;
  uStack_2c = puRam0203c05c[1];
  uStack_28 = puRam0203c05c[2];
  uStack_24 = puRam0203c05c[3];
  local_20 = puRam0203c05c[4];
  uStack_1c = puRam0203c05c[5];
  uStack_18 = puRam0203c05c[6];
  uStack_14 = puRam0203c05c[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

