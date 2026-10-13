/* Decompiled C draft; module arm9; ROM address 02042410. No matching claim. */
#include "types.h"
#include "deps/02042410_NkmHandler_EPAT_from_thumb.h"

undefined4
NkmHandler_EPAT_from_thumb
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
  if (*(ushort *)(*piRam02042494 + 0x20) < 2) {
    uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
    piVar1 = piRam02042494;
    *(undefined2 *)(*piRam02042494 + 0x70) = uVar2;
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 0x70) == 0) {
      *(undefined4 *)(iVar3 + 0x6c) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 0x6c) = local_10;
      *(undefined4 *)(*piVar1 + 0x8c) = 0;
      *(undefined2 *)(*piVar1 + 0x90) = 0;
    }
  }
  else {
    uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
    piVar1 = piRam02042494;
    *(undefined2 *)(*piRam02042494 + 0x90) = uVar2;
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 0x90) == 0) {
      *(undefined4 *)(iVar3 + 0x8c) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 0x8c) = local_10;
      *(undefined4 *)(*piVar1 + 0x6c) = 0;
      *(undefined2 *)(*piVar1 + 0x70) = 0;
    }
  }
  return 1;
}

