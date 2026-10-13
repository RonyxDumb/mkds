/* Decompiled C draft; module arm9; ROM address 02126f78. No matching claim. */
#include "types.h"
#include "deps/02126f78_TextSystemContext_LoadEnabledSpritesAndAnimations_from_thumb.h"

void TextSystemContext_LoadEnabledSpritesAndAnimations_from_thumb(int *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  short *psVar6;
  byte *pbVar7;
  uint uVar8;
  int *local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  byte *local_40;
  int local_3c;
  int local_38;
  byte local_20 [12];
  
  pbVar5 = local_20;
  iVar4 = 9;
  pbVar7 = pbRam0212709c;
  do {
    bVar1 = *pbVar7;
    pbVar7 = pbVar7 + 1;
    *pbVar5 = bVar1;
    pbVar5 = pbVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  Mem_CpuFastMemorySet(0,*piRam021270a0 + 0x54,uRam021270a4);
  Mem_CpuFill16(*(uint *)(*piRam021270a0 + iRam021270a8) & 0xffff,*piRam021270a0 + iRam021270ac,
                uRam021270a4);
  local_4c = 0;
  local_40 = local_20;
  local_3c = 0;
  local_50 = param_1;
  do {
    if (*local_50 != 0) {
      if (local_4c - 7 < 2) {
        TextSystemContext_UpdateAnimationGraphics_from_thumb();
      }
      else if (local_4c != 6) {
        bVar1 = *local_40;
        local_44 = *piRam021270a0 + iRam021270ac;
        if (local_4c < 2) {
          local_44 = *piRam021270a0 + 0x54;
        }
        pbVar5 = (byte *)(iRam021270b0 + (uint)bVar1 * 4);
        local_48 = (uint)pbVar5[2];
        if (local_48 <= pbVar5[3]) {
          local_38 = local_48 << 5;
          uVar3 = (uint)*pbVar5;
          bVar2 = pbVar5[1];
          do {
            if (uVar3 <= bVar2) {
              iVar4 = uVar3 * 2;
              psVar6 = (short *)(local_44 + local_38 * 2 + iVar4);
              uVar8 = uVar3;
              do {
                *psVar6 = (short)*(undefined4 *)(local_3c + *piRam021270a0 + iRam021270b4) +
                          *(short *)(local_38 * 2 +
                                     *(int *)((uint)bVar1 * 4 + *piRam021270a0 + iRam021270b8) +
                                     iVar4 + 0xc);
                iVar4 = iVar4 + 2;
                psVar6 = psVar6 + 1;
                uVar8 = uVar8 + 1;
              } while ((int)uVar8 <= (int)(uint)bVar2);
            }
            local_38 = local_38 + 0x20;
            local_48 = local_48 + 1;
          } while ((int)local_48 <= (int)(uint)pbVar5[3]);
        }
      }
    }
    local_50 = local_50 + 1;
    local_40 = local_40 + 1;
    local_3c = local_3c + 4;
    local_4c = local_4c + 1;
  } while ((int)local_4c < 9);
  return;
}

