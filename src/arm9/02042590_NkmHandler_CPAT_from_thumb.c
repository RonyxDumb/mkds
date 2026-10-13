/* Decompiled C draft; module arm9; ROM address 02042590. No matching claim. */
#include "types.h"
#include "deps/02042590_NkmHandler_CPAT_from_thumb.h"

undefined4
NkmHandler_CPAT_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
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
  piVar1 = piRam02042624;
  *(undefined2 *)(*piRam02042624 + 0x50) = uVar2;
  iVar4 = *piVar1;
  if (*(short *)(iVar4 + 0x50) == 0) {
    *(undefined4 *)(iVar4 + 0x4c) = 0;
    *(undefined2 *)(*piVar1 + 0x9a) = 0;
    return 1;
  }
  *(undefined4 *)(iVar4 + 0x4c) = local_10;
  uVar5 = 0;
  iVar4 = *piVar1;
  if (*(short *)(iVar4 + 0x50) != 0) {
    do {
      iVar3 = (uVar5 & 0xffff) * 0xc;
      if (*(short *)(*(int *)(iVar4 + 0x4c) + iVar3) == 0) {
        iVar4 = *(int *)(*piRam02042624 + 0x4c);
        iVar3 = ((int)*(char *)(iVar4 + iVar3 + 7) & 0xffffU) * 0xc;
        *(short *)(*piRam02042624 + 0x9a) =
             *(short *)(iVar4 + iVar3) + *(short *)(iVar4 + iVar3 + 2) + -1;
        return 1;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < (int)(uint)*(ushort *)(iVar4 + 0x50));
  }
  return 1;
}

