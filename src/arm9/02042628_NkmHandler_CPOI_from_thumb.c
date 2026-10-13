/* Decompiled C draft; module arm9; ROM address 02042628. No matching claim. */
#include "types.h"
#include "deps/02042628_NkmHandler_CPOI_from_thumb.h"

undefined4
NkmHandler_CPOI_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar2 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
  piVar1 = piRam020426a8;
  *(undefined2 *)(*piRam020426a8 + 0x48) = uVar2;
  iVar3 = *piVar1;
  if (*(short *)(iVar3 + 0x48) == 0) {
    *(undefined4 *)(iVar3 + 0x44) = 0;
    return 1;
  }
  *(undefined4 *)(iVar3 + 0x44) = local_10;
  sVar4 = 0;
  uVar5 = 0;
  iVar3 = *piVar1;
  if (*(short *)(iVar3 + 0x48) != 0) {
    do {
      if (*(short *)(*(int *)(iVar3 + 0x44) + uVar5 * 0x24 + 0x20) != -1) {
        sVar4 = sVar4 + 1;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < *(ushort *)(iVar3 + 0x48));
  }
  *(short *)(iVar3 + 0x98) = sVar4;
  return 1;
}

