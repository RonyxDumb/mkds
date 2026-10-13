/* Decompiled C draft; module arm9; ROM address 02043170. No matching claim. */
#include "types.h"
#include "deps/02043170_NkmHandler_OBJI_from_thumb.h"

undefined4
NkmHandler_OBJI_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
  piVar1 = piRam020431a0;
  *(undefined2 *)(*piRam020431a0 + 4) = uVar2;
  puVar3 = (undefined4 *)*piVar1;
  if (*(short *)(puVar3 + 1) == 0) {
    *puVar3 = 0;
  }
  else {
    *puVar3 = local_10;
  }
  return 1;
}

