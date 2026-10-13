/* Decompiled C draft; module arm9; ROM address 02042170. No matching claim. */
#include "types.h"
#include "deps/02042170_NkmHandler_CAME_from_thumb.h"

undefined4
NkmHandler_CAME_from_thumb
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar3 = NkmSection_AdvanceHeaderGetEntryCount_from_thumb(&local_10);
  piVar1 = piRam02042278;
  *(undefined2 *)(*piRam02042278 + 0x80) = uVar3;
  iVar5 = *piVar1;
  if (*(short *)(iVar5 + 0x80) != 0) {
    *(undefined4 *)(iVar5 + 0x7c) = local_10;
    uVar6 = 0;
    *(undefined4 *)(*piVar1 + 0xc4) = 0;
    *(undefined4 *)(*piVar1 + 200) = 0;
    *(undefined4 *)(*piVar1 + 0xcc) = 0;
    *(undefined4 *)(*piVar1 + 0xd0) = 0;
    piVar2 = piRam0204227c;
    iVar5 = *piVar1;
    if (*(short *)(iVar5 + 0x80) != 0) {
      do {
        iVar4 = *(int *)(*piVar1 + 0x7c) + uVar6 * 0x4c;
        if ((*(int *)(*piVar1 + 0xc4) == 0) && (*(char *)(iVar4 + 0x4a) == '\x01')) {
          *(int *)(iVar5 + 0xc4) = iVar4;
        }
        if ((*(int *)(*piVar1 + 200) == 0) && (*(char *)(iVar4 + 0x4a) == '\x02')) {
          *(int *)(*piVar1 + 200) = iVar4;
        }
        if ((*(int *)(*piVar1 + 0xcc) == 0) && (*(short *)(iVar4 + 0x3e) == 6)) {
          *(int *)(*piVar1 + 0xcc) = iVar4;
        }
        if (((*(int *)(*piVar2 + 8) == 2) && (*(int *)(*piVar1 + 0xd0) == 0)) &&
           (*(short *)(iVar4 + 0x3e) == 7)) {
          *(int *)(*piVar1 + 0xd0) = iVar4;
        }
        if (((*(int *)(*piVar2 + 8) == 4) && (*(int *)(*piVar1 + 0xd4) == 0)) &&
           (*(short *)(iVar4 + 0x3e) == 8)) {
          *(int *)(*piVar1 + 0xd4) = iVar4;
        }
        uVar6 = uVar6 + 1 & 0xffff;
        iVar5 = *piVar1;
      } while (uVar6 < *(ushort *)(iVar5 + 0x80));
    }
    return 1;
  }
  *(undefined4 *)(iVar5 + 0x7c) = 0;
  return 1;
}

