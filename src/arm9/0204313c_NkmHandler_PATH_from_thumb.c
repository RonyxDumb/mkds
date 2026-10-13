/* Decompiled C draft; module arm9; ROM address 0204313c. No matching claim. */
#include "types.h"
#include "deps/0204313c_NkmHandler_PATH_from_thumb.h"

undefined4
NkmHandler_PATH_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
  piVar1 = piRam0204316c;
  *(undefined2 *)(*piRam0204316c + 0xc) = uVar2;
  iVar3 = *piVar1;
  if (*(short *)(iVar3 + 0xc) == 0) {
    *(undefined4 *)(iVar3 + 8) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 8) = local_10;
  }
  return 1;
}

