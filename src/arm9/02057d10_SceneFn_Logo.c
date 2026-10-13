/* Decompiled C draft; module arm9; ROM address 02057d10. No matching claim. */
#include "types.h"
#include "deps/02057d10_SceneFn_Logo.h"

undefined4 SceneFn_Logo(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam02057d54;
  uStack_2c = puRam02057d54[1];
  uStack_28 = puRam02057d54[2];
  uStack_24 = puRam02057d54[3];
  local_20 = puRam02057d54[4];
  uStack_1c = puRam02057d54[5];
  uStack_18 = puRam02057d54[6];
  uStack_14 = puRam02057d54[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

