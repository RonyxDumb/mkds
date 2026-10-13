/* Decompiled C draft; module arm9_ov003; ROM address 021bccd0. No matching claim. */
#include "types.h"
#include "deps/021bccd0_FUN_021bccd0.h"

undefined4
FUN_021bccd0(undefined1 *param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  longlong lVar10;
  undefined1 *local_1e8;
  int local_1dc;
  int local_1d8;
  undefined1 *local_1bc;
  uint local_178;
  uint local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined1 local_168 [8];
  undefined1 local_160 [8];
  undefined1 auStack_158 [324];
  
  local_170 = DAT_021bcecc;
  local_16c = DAT_021bcecc;
  if (((param_3 & 7) == 0) && ((param_5 & 7) == 0)) {
    uVar2 = param_3 >> 3;
    if (1 < uVar2) {
      uVar3 = FUN_021bc7a8(auStack_158,param_4,param_5 << 3);
      func_0x02134eb8(param_1 + 8,param_2,param_3);
      puVar7 = local_168;
      puVar6 = &local_170;
      iVar4 = 8;
      do {
        uVar1 = *(undefined1 *)puVar6;
        puVar6 = (undefined4 *)((int)puVar6 + 1);
        *puVar7 = uVar1;
        puVar7 = puVar7 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      local_1d8 = 0;
      do {
        local_1dc = 1;
        if (uVar2 != 0) {
          lVar10 = func_0x02133048(uVar2,0,local_1d8,local_1d8 >> 0x1f);
          do {
            local_1bc = param_1 + local_1dc * 8;
            puVar7 = local_160;
            iVar4 = 8;
            puVar8 = local_1bc;
            do {
              uVar1 = *puVar8;
              puVar8 = puVar8 + 1;
              *puVar7 = uVar1;
              puVar7 = puVar7 + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            FUN_021bc1c4(auStack_158,uVar3,local_168,local_168);
            uVar9 = (uint)(lVar10 + local_1dc);
            uVar5 = (uint)((ulonglong)(lVar10 + local_1dc) >> 0x20);
            local_174 = (uVar5 & DAT_021bced8) >> 0x18 |
                        (uVar9 & DAT_021bced0) >> 0x18 |
                        (uVar9 & DAT_021bced4) >> 8 |
                        uVar9 * 0x1000000 | (uVar9 & DAT_021bced8) << 8;
            local_178 = (uVar5 & DAT_021bced0) >> 0x18 |
                        (uVar5 & DAT_021bced4) >> 8 |
                        (uVar5 & DAT_021bced8) << 8 |
                        uVar5 * 0x1000000 |
                        (uVar9 & DAT_021bced0) << 8 | (uVar9 & DAT_021bced4) << 0x18;
            FUN_021bca90(local_168,&local_178,local_168);
            puVar7 = local_160;
            iVar4 = 8;
            do {
              uVar1 = *puVar7;
              puVar7 = puVar7 + 1;
              *local_1bc = uVar1;
              local_1bc = local_1bc + 1;
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            local_1dc = local_1dc + 1;
          } while (local_1dc <= (int)uVar2);
        }
        local_1d8 = local_1d8 + 1;
      } while (local_1d8 < 6);
      puVar7 = local_168;
      iVar4 = 8;
      local_1e8 = param_1;
      do {
        uVar1 = *puVar7;
        puVar7 = puVar7 + 1;
        *local_1e8 = uVar1;
        local_1e8 = local_1e8 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      return 1;
    }
    return 0;
  }
  return 0;
}

