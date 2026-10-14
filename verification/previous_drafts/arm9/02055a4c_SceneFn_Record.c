/* Decompiled C draft; module arm9; ROM address 02055a4c. No matching claim. */
#include "types.h"
#include "deps/02055a4c_SceneFn_Record.h"

undefined4 SceneFn_Record(undefined4 param_1)

{
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_30 = *puRam02055a90;
  uStack_2c = puRam02055a90[1];
  uStack_28 = puRam02055a90[2];
  uStack_24 = puRam02055a90[3];
  local_20 = puRam02055a90[4];
  uStack_1c = puRam02055a90[5];
  uStack_18 = puRam02055a90[6];
  uStack_14 = puRam02055a90[7];
  OnSceneLoop(param_1,&uStack_30);
  return 0;
}

