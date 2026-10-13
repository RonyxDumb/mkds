/* Decompiled C draft; module arm9_ov003; ROM address 021ccf30. No matching claim. */
#include "types.h"
#include "deps/021ccf30_FUN_021ccf30.h"

void FUN_021ccf30(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a0;
  byte local_9c [4];
  byte local_98 [4];
  undefined4 local_94 [32];
  
  iVar1 = *DAT_021cd068 + DAT_021cd06c;
  func_0x0200ee3c(*DAT_021cd068 + DAT_021cd070,DAT_021cd074);
  local_b8 = 0;
  if (*(short *)(param_1 + 0xe) != 0) {
    local_ac = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_b4 = param_1;
    local_b0 = param_1;
    do {
      iVar6 = *(int *)(local_b4 + 0x10);
      if ((*(char *)(iVar6 + 0xc) != '\0') &&
         (iVar3 = local_ac, iVar4 = iVar1, *(short *)(iVar6 + 0x3c) == 0)) {
        do {
          iVar2 = func_0x02134d30(iVar6 + 4,iVar4 + 0x20,6);
          if (iVar2 == 0) break;
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 0x2a;
        } while (iVar3 < 0x14);
        iVar4 = local_a8;
        iVar2 = iVar1;
        if (iVar3 == 0x14) {
          do {
            iVar3 = func_0x02134d30(iVar2 + 0x20,DAT_021cd078,6);
            if (iVar3 == 0) break;
            iVar4 = iVar4 + 1;
            iVar2 = iVar2 + 0x2a;
          } while (iVar4 < 0x14);
          iVar3 = iVar4;
          if (iVar4 == 0x14) {
            return;
          }
        }
        iVar3 = iVar1 + iVar3 * 0x2a;
        func_0x0214d1fc((ushort *)(uintptr_t)(iVar6 + 4),(uint *)(uintptr_t)(iVar3 + 0x20),6);
        func_0x0214d1fc((ushort *)(uintptr_t)(iVar6 + 0xc),(uint *)(uintptr_t)(iVar3),0x20);
        *(undefined2 *)(iVar3 + 0x26) = *(undefined2 *)(local_b0 + 0x50);
        if ((*(ushort *)(iVar6 + 0x2c) & 0x10) == 0) {
          *(undefined1 *)(iVar3 + 0x28) = 0;
        }
        else {
          *(undefined1 *)(iVar3 + 0x28) = 1;
          func_0x02142f24((undefined4 *)(void *)(local_9c),(ushort *)(uintptr_t)(iVar6));
          uVar7 = (uint)local_9c[0];
          if (uVar7 != 0) {
            pbVar5 = local_9c;
            iVar6 = local_a0;
            do {
              if (pbVar5[4] == 0x30) {
                *(undefined1 *)(iVar3 + 0x28) = 2;
                break;
              }
              if (((pbVar5[4] == 0xdd) && (3 < pbVar5[5])) &&
                 (iVar4 = func_0x02134d30(*(undefined4 *)(pbVar5 + 8),DAT_021cd07c,4), iVar4 == 0))
              {
                *(undefined1 *)(iVar3 + 0x28) = 2;
                break;
              }
              pbVar5 = pbVar5 + 8;
              iVar6 = iVar6 + 1;
            } while (iVar6 < (int)uVar7);
          }
        }
      }
      local_b4 = local_b4 + 4;
      local_b0 = local_b0 + 2;
      local_b8 = local_b8 + 1;
    } while (local_b8 < (int)(uint)*(ushort *)(param_1 + 0xe));
  }
  return;
}

