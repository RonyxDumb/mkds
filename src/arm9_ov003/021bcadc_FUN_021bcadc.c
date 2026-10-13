/* Decompiled C draft; module arm9_ov003; ROM address 021bcadc. No matching claim. */
#include "types.h"
#include "deps/021bcadc_FUN_021bcadc.h"

bool FUN_021bcadc(int param_1,undefined1 *param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  longlong lVar10;
  uint local_1bc;
  int local_1b8;
  uint local_178;
  uint local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined1 local_168 [8];
  undefined1 local_160 [8];
  undefined1 auStack_158 [324];
  
  local_170 = DAT_021bccc0;
  local_16c = DAT_021bccc0;
  if (((param_3 & 7) == 0) && ((param_5 & 7) == 0)) {
    uVar2 = param_3 - 1 >> 3;
    if (uVar2 < 2) {
      return false;
    }
    uVar3 = FUN_021bc5e4(auStack_158,param_4,param_5 << 3);
    puVar7 = local_168;
    iVar4 = 8;
    puVar6 = param_2;
    do {
      uVar1 = *puVar6;
      puVar6 = puVar6 + 1;
      *puVar7 = uVar1;
      puVar7 = puVar7 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    func_0x02134eb8((uint *)(uintptr_t)(param_1),(uint)(uintptr_t)(param_2 + 8),param_3 - 1);
    local_1b8 = 5;
    do {
      if (uVar2 != 0) {
        lVar10 = func_0x02133048(uVar2,0,local_1b8,local_1b8 >> 0x1f);
        local_1bc = uVar2;
        do {
          uVar9 = (uint)(lVar10 + (int)local_1bc);
          uVar5 = (uint)((ulonglong)(lVar10 + (int)local_1bc) >> 0x20);
          local_174 = (uVar5 & DAT_021bcccc) >> 0x18 |
                      (uVar9 & DAT_021bccc4) >> 0x18 |
                      (uVar9 & DAT_021bccc8) >> 8 | uVar9 * 0x1000000 | (uVar9 & DAT_021bcccc) << 8;
          local_178 = (uVar5 & DAT_021bccc4) >> 0x18 |
                      (uVar5 & DAT_021bccc8) >> 8 |
                      (uVar5 & DAT_021bcccc) << 8 |
                      uVar5 * 0x1000000 |
                      (uVar9 & DAT_021bccc4) << 8 | (uVar9 & DAT_021bccc8) << 0x18;
          FUN_021bca90(local_168,(byte *)(void *)(&local_178),local_168);
          puVar8 = (undefined1 *)(param_1 + (local_1bc - 1) * 8);
          puVar7 = local_160;
          iVar4 = 8;
          puVar6 = puVar8;
          do {
            uVar1 = *puVar6;
            puVar6 = puVar6 + 1;
            *puVar7 = uVar1;
            puVar7 = puVar7 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          FUN_021bbd9c((uint *)(void *)(auStack_158),uVar3,local_168,local_168);
          puVar7 = local_160;
          iVar4 = 8;
          do {
            uVar1 = *puVar7;
            puVar7 = puVar7 + 1;
            *puVar8 = uVar1;
            puVar8 = puVar8 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          local_1bc = local_1bc - 1;
        } while (0 < (int)local_1bc);
      }
      local_1b8 = local_1b8 + -1;
    } while (-1 < local_1b8);
    iVar4 = func_0x02134d30((uint)(uintptr_t)(&local_170),(uint)(uintptr_t)(local_168),8);
    return iVar4 == 0;
  }
  return false;
}

