/* Decompiled C draft; module arm9; ROM address 02042520. No matching claim. */
#include "types.h"
#include "deps/02042520_NkmHandler_IPAT_from_thumb.h"

undefined4
NkmHandler_IPAT_from_thumb
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
  piVar1 = piRam02042554;
  *(undefined2 *)(*piRam02042554 + 0x60) = uVar2;
  iVar3 = *piVar1;
  if (*(short *)(iVar3 + 0x60) == 0) {
    *(undefined4 *)(iVar3 + 0x5c) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 0x5c) = local_10;
  }
  return 1;
}

