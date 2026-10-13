/* Decompiled C draft; module arm9; ROM address 020d6f20. No matching claim. */
#include "types.h"
#include "deps/020d6f20_func_020d6f20.h"

void func_020d6f20(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined1 auStack_30 [36];
  
  MTX_RotY33__from_thumb
            (auStack_30,(int)*(short *)(iRam020d6f74 + (param_2 >> 4) * 4),
             (int)*(short *)(iRam020d6f74 + ((param_2 >> 4) * 2 + 1) * 2));
  MTX_MultVec33(param_1,auStack_30,param_3);
  return;
}

