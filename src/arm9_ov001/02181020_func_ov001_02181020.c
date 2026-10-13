/* Decompiled C draft; module arm9_ov001; ROM address 02181020. No matching claim. */
#include "types.h"
#include "deps/02181020_func_ov001_02181020.h"

undefined4 func_ov001_02181020(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  pbVar1 = (byte *)func_ov001_02181200();
  if ((pbVar1 != (byte *)0x0) && (*pbVar1 != param_3)) {
    uVar2 = 1;
    func_ov001_021811c8();
    *pbVar1 = (byte)param_3;
  }
  return uVar2;
}

