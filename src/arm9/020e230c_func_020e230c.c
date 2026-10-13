/* Decompiled C draft; module arm9; ROM address 020e230c. No matching claim. */
#include "types.h"
#include "deps/020e230c_func_020e230c.h"

void func_020e230c(undefined4 *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int extraout_r1;
  ushort uVar8;
  uint uVar9;
  int local_30;
  uint local_28;
  int *local_24;
  
  uVar1 = *(ushort *)(param_1 + 1);
  local_24 = (int *)*param_1;
  local_28 = 0;
  local_30 = 0;
  if (uVar1 != 0) {
    do {
      uVar9 = (uint)*(ushort *)(*(int *)(*local_24 + 0x9c) + 0x26);
      *(int *)(*local_24 + 0xd4) = local_30;
      uVar4 = 1 << (uVar9 & 0xff);
      if ((local_28 & uVar4) == 0) {
        uVar2 = *(ushort *)(*(int *)(*piRam020e23e8 + 8) + uVar9 * 4 + 2);
        local_28 = local_28 | uVar4;
        uVar8 = 0;
        if (uVar2 != 0) {
          do {
            iVar5 = GetLoadedNkmPathEntryPOIT(uVar9,uVar8);
            iVar6 = (int)*(short *)(iVar5 + 0xe);
            if (iVar6 == 0) {
              uVar3 = (undefined2)uRam020e23fc;
            }
            else {
              if (iVar6 < 1) {
                uVar7 = FUN_02132440(iVar6 << 0xc);
                func_021329f8(uVar7,uRam020e23ec);
              }
              else {
                uVar7 = FUN_02132440(iVar6 << 0xc);
                func_02131234(uRam020e23ec,uVar7);
              }
              iVar6 = func_021322c8();
              Multiply64(iVar6,iVar6 >> 0x1f,uRam020e23f0,0xb6);
              uVar3 = *(undefined2 *)
                       (iRam020e23f8 +
                       (((int)((uint)((extraout_r1 + iRam020e23f4) * 0x10) >> 0x10) >> 4) * 2 + 1) *
                       2);
            }
            *(undefined2 *)(iVar5 + 0x12) = uVar3;
            *(undefined2 *)(iVar5 + 0xe) = 0;
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar2);
        }
      }
      local_24 = local_24 + 1;
      local_30 = local_30 + 1;
    } while (local_30 < (int)(uint)uVar1);
  }
  return;
}

