/* Decompiled C draft; module arm9_ov003; ROM address 021ce6ac. No matching claim. */
#include "types.h"
#include "deps/021ce6ac_FUN_021ce6ac.h"

void FUN_021ce6ac(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  
  local_2c = 0;
  if (*(short *)(param_1 + 0xe) != 0) {
    local_20 = 0;
    local_1c = 0;
    local_28 = param_1;
    do {
      iVar5 = *(int *)(local_28 + 0x10);
      func_0x0200ee3c(iVar5,0xc0);
      iVar1 = func_0x02134d30(iVar5 + 0xc,DAT_021ce7a8,8);
      if (iVar1 == 0) {
        iVar3 = *DAT_021ce7ac;
        iVar4 = iVar3 + DAT_021ce7b0;
        iVar1 = local_20;
        do {
          iVar2 = func_0x02134d30(iVar5 + 4,iVar4,6);
          if (iVar2 == 0) {
            if ((*(char *)(iVar3 + iVar1 * 7 + DAT_021ce7b4) == '\0') &&
               ((*(byte *)(iVar5 + 0x15) & 1) != 0)) {
              if (*(code **)(iVar3 + DAT_021ce7b8) == (code *)0x0) {
                return;
              }
              (**(code **)(iVar3 + DAT_021ce7b8))(1);
              return;
            }
            goto LAB_021ce788;
          }
          iVar4 = iVar4 + 7;
          iVar1 = iVar1 + 1;
        } while (iVar1 < 0x10);
        iVar4 = iVar3 + DAT_021ce7b0;
        iVar1 = local_1c;
        do {
          iVar2 = func_0x02134d30(iVar4,DAT_021ce7bc,6);
          if (iVar2 == 0) {
            func_0x0214d1fc((ushort *)(uintptr_t)(iVar5 + 4),(uint *)(uintptr_t)(iVar3 + DAT_021ce7b0 + iVar1 * 7),6);
            *(bool *)(*DAT_021ce7ac + iVar1 * 7 + DAT_021ce7b4) = (*(byte *)(iVar5 + 0x15) & 1) != 0
            ;
            break;
          }
          iVar4 = iVar4 + 7;
          iVar1 = iVar1 + 1;
        } while (iVar1 < 0x10);
      }
LAB_021ce788:
      local_28 = local_28 + 4;
      local_2c = local_2c + 1;
    } while (local_2c < (int)(uint)*(ushort *)(param_1 + 0xe));
  }
  return;
}

