/* Decompiled C draft; module arm9; ROM address 02042498. No matching claim. */
#include "types.h"
#include "deps/02042498_NkmHandler_EPOI_from_thumb.h"

undefined4
NkmHandler_EPOI_from_thumb
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
  if (*(ushort *)(*piRam0204251c + 0x20) < 2) {
    uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
    piVar1 = piRam0204251c;
    *(undefined2 *)(*piRam0204251c + 0x68) = uVar2;
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 0x68) == 0) {
      *(undefined4 *)(iVar3 + 100) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 100) = local_10;
      *(undefined4 *)(*piVar1 + 0x84) = 0;
      *(undefined2 *)(*piVar1 + 0x88) = 0;
    }
  }
  else {
    uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
    piVar1 = piRam0204251c;
    *(undefined2 *)(*piRam0204251c + 0x88) = uVar2;
    iVar3 = *piVar1;
    if (*(short *)(iVar3 + 0x88) == 0) {
      *(undefined4 *)(iVar3 + 0x84) = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 0x84) = local_10;
      *(undefined4 *)(*piVar1 + 100) = 0;
      *(undefined2 *)(*piVar1 + 0x68) = 0;
    }
  }
  return 1;
}

