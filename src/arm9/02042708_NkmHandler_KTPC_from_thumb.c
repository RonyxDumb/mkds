/* Decompiled C draft; module arm9; ROM address 02042708. No matching claim. */
#include "types.h"
#include "deps/02042708_NkmHandler_KTPC_from_thumb.h"

bool NkmHandler_KTPC_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  bool bVar3;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = piRam02042744;
  bVar3 = 0x1e < *(ushort *)(*piRam02042744 + iRam02042748);
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  if (bVar3) {
    uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
    piVar1 = piRam02042744;
    *(undefined2 *)(*piRam02042744 + 0x38) = uVar2;
    *(undefined4 *)(*piVar1 + 0x34) = local_10;
  }
  else {
    *(undefined2 *)(*piRam02042744 + 0x38) = 0;
    *(undefined4 *)(*piVar1 + 0x34) = 0;
  }
  InitializePECannonTable_from_thumb();
  return bVar3;
}

