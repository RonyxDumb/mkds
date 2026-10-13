/* Decompiled C draft; module arm9; ROM address 020d41e0. No matching claim. */
#include "types.h"
#include "deps/020d41e0_func_020d41e0.h"

int func_020d41e0(int param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int unaff_r9;
  uint uVar12;
  bool bVar13;
  int local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  local_64 = *param_2;
  uStack_60 = param_2[1];
  uStack_5c = param_2[2];
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  iVar8 = 0;
  bVar13 = ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) != 0;
  uVar1 = param_1 + 0x1d0U & 3;
  uVar11 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc);
  uVar2 = param_1 + 0x29cU & 3;
  uVar12 = *(uint *)(param_1 + 0x29cU & 0xfffffffc);
  uVar7 = *(uint *)(uRam020d4404 & 0xfffffffc) >> (uRam020d4404 & 3) * 8 |
          *(uint *)(uRam020d4404 & 0xfffffffc) << (uRam020d4404 & 3) * -8 + 0x20;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (bVar13) {
    unaff_r9 = 1;
  }
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  param_3[2] = 0;
  uVar9 = (uint)(param_3 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  if (!bVar13) {
    unaff_r9 = 0;
  }
  param_3[1] = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  uVar9 = (uint)(param_3 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
  iVar10 = 0;
  *param_3 = uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20;
  if (0 < *psRam020d4408) {
    local_68 = 0x1f;
    do {
      if (((*(ushort *)
             ((*(uint *)(uRam020d440c & 0xfffffffc) >> (uRam020d440c & 3) * 8 |
              *(uint *)(uRam020d440c & 0xfffffffc) << (uRam020d440c & 3) * -8 + 0x20) + iVar10 * 2)
           & 0x2000) != 0) &&
         (((uVar9 = (*(uint *)(uRam020d4410 & 0xfffffffc) >> (uRam020d4410 & 3) * 8 |
                    *(uint *)(uRam020d4410 & 0xfffffffc) << (uRam020d4410 & 3) * -8 + 0x20) +
                    iVar10 * 4, uVar3 = uVar9 & 3, uVar9 = *(uint *)(uVar9 & 0xfffffffc),
           uVar9 = uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20, unaff_r9 == 0 ||
           (uVar3 = uVar9 + 0x78 & 3, uVar4 = *(uint *)(uVar9 + 0x78 & 0xfffffffc),
           ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) & 0x10) != 0)) &&
          (iVar5 = func_020d3e34(&local_64,uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20,uVar9,
                                 uVar7), iVar5 != 0)))) {
        uVar3 = local_44;
        if (((*(ushort *)(uVar9 + 2) & 0x40) == 0) &&
           (iVar5 = func_020d69e4(uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20,(ushort *)(uintptr_t)(uVar9)),
           uVar3 = local_44, iVar5 != 0)) {
          uVar4 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                  *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
          if ((int)uVar4 < (int)local_58) {
            local_58 = uVar4;
          }
          uVar3 = uVar7 + 4 & 3;
          uVar6 = *(uint *)(uVar7 + 4 & 0xfffffffc);
          uVar6 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
          if ((int)uVar6 < (int)local_54) {
            local_54 = uVar6;
          }
          uVar3 = uVar7 + 8 & 3;
          uVar7 = *(uint *)(uVar7 + 8 & 0xfffffffc);
          uVar3 = uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20;
          if ((int)uVar3 < (int)local_50) {
            local_50 = uVar3;
          }
          if ((int)uVar4 <= (int)local_4c) {
            uVar4 = local_4c;
          }
          if ((int)uVar6 <= (int)local_48) {
            uVar6 = local_48;
          }
          local_4c = uVar4;
          local_48 = uVar6;
          if ((int)uVar3 <= (int)local_44) {
            uVar3 = local_44;
          }
        }
        local_44 = uVar3;
        *(uint *)((*(uint *)(uRam020d4414 & 0xfffffffc) >> (uRam020d4414 & 3) * 8 |
                  *(uint *)(uRam020d4414 & 0xfffffffc) << (uRam020d4414 & 3) * -8 + 0x20) +
                 iVar8 * 4) = uVar9;
        iVar8 = iVar8 + 1;
        uVar7 = iVar8 * 0xc +
                (*(uint *)(uRam020d4404 & 0xfffffffc) >> (uRam020d4404 & 3) * 8 |
                *(uint *)(uRam020d4404 & 0xfffffffc) << (uRam020d4404 & 3) * -8 + 0x20);
        if (0x1f < iVar8) {
          iVar8 = local_68;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < *psRam020d4408);
  }
  if ((iVar8 != 0) && (param_3 != (uint *)0x0)) {
    *param_3 = local_4c + local_58;
    param_3[1] = local_48 + local_54;
    uVar1 = (uint)(param_3 + 1) & 3;
    uVar2 = *(uint *)((uint)(param_3 + 1) & 0xfffffffc);
    if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0) {
      param_3[1] = 0;
    }
    param_3[2] = local_44 + local_50;
  }
  return iVar8;
}

