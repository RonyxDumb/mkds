/* Decompiled C draft; module arm9_ov000; ROM address 02180500. No matching claim. */
#include "types.h"
#include "deps/02180500_func_ov000_02180500.h"

undefined4 func_ov000_02180500(undefined4 param_1)

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
  
  local_30 = *puRam02180530;
  uStack_2c = puRam02180530[1];
  local_28 = puRam02180530[2];
  uStack_24 = puRam02180530[3];
  local_20 = puRam02180530[4];
  uStack_1c = puRam02180530[5];
  local_18 = puRam02180530[6];
  uStack_14 = puRam02180530[7];
  func_0x020487fc(param_1,&local_30,&local_30,auStack_10);
  return 0;
}

