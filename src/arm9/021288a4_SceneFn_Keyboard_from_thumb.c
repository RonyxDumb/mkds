/* Decompiled C draft; module arm9; ROM address 021288a4. No matching claim. */
#include "types.h"
#include "deps/021288a4_SceneFn_Keyboard_from_thumb.h"

undefined4 SceneFn_Keyboard_from_thumb(undefined4 param_1)

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
  
  local_30 = *puRam021288d4;
  uStack_2c = puRam021288d4[1];
  local_28 = puRam021288d4[2];
  uStack_24 = puRam021288d4[3];
  local_20 = puRam021288d4[4];
  uStack_1c = puRam021288d4[5];
  local_18 = puRam021288d4[6];
  uStack_14 = puRam021288d4[7];
  OnSceneLoop(param_1,&local_30,&local_30,auStack_10);
  return 0;
}

