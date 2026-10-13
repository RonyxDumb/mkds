/* Decompiled C draft; module arm9_ov003; ROM address 021ce5b8. No matching claim. */
#include "types.h"
#include "deps/021ce5b8_FUN_021ce5b8.h"

void FUN_021ce5b8(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_18;
  
  iVar4 = *DAT_021ce68c;
  if (*(char *)(iVar4 + DAT_021ce690) == '\0') {
    func_0x0200ee3c(iVar4 + DAT_021ce698,DAT_021ce69c);
    local_24 = 0;
    uVar1 = *(ushort *)(param_1 + 0xe);
    if (uVar1 != 0) {
      iVar4 = *DAT_021ce68c;
      local_18 = 0;
      local_28 = param_1;
      do {
        iVar6 = *(int *)(local_28 + 0x10);
        iVar2 = func_0x02134d30(iVar6 + 0xc,DAT_021ce6a0,8);
        if ((iVar2 == 0) && ((*(byte *)(iVar6 + 0x15) & 1) != 0)) {
          iVar5 = iVar4 + DAT_021ce6a4;
          iVar2 = local_18;
          do {
            iVar3 = func_0x02134d30(iVar6 + 4,iVar5,6);
            if (iVar3 == 0) {
              if (*(char *)(iVar4 + iVar2 * 7 + DAT_021ce6a8) == '\0') {
                if (*(code **)(iVar4 + DAT_021ce694) != (code *)0x0) {
                  (**(code **)(iVar4 + DAT_021ce694))(1);
                  return;
                }
                *(undefined1 *)(iVar4 + DAT_021ce690) = 1;
                return;
              }
              break;
            }
            iVar5 = iVar5 + 7;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 0x10);
        }
        local_28 = local_28 + 4;
        local_24 = local_24 + 1;
      } while (local_24 < (int)(uint)uVar1);
    }
  }
  else if (*(code **)(iVar4 + DAT_021ce694) != (code *)0x0) {
    (**(code **)(iVar4 + DAT_021ce694))();
    return;
  }
  return;
}

