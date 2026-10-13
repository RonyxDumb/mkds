/* Decompiled C draft; module arm9; ROM address 020427ac. No matching claim. */
#include "types.h"
#include "deps/020427ac_NkmHandler_KTP2_from_thumb.h"

undefined4
NkmHandler_KTP2_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
  piVar1 = piRam020427d0;
  *(undefined2 *)(*piRam020427d0 + 0x30) = uVar2;
  *(undefined4 *)(*piVar1 + 0x2c) = local_10;
  return 1;
}

