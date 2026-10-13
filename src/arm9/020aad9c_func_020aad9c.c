/* Decompiled C draft; module arm9; ROM address 020aad9c. No matching claim. */
#include "types.h"
#include "deps/020aad9c_func_020aad9c.h"

void func_020aad9c(int param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  int iVar9;
  int local_4c;
  int local_48;
  int local_3c;
  int local_38;
  undefined1 auStack_34 [20];
  code *local_20;
  
  piVar8 = (int *)*puRam020aae98;
  bVar1 = *(byte *)(*(int *)(*piVar8 + 8) + 1);
  piVar2 = *(int **)(param_1 + 0x2c);
  MIi_CpuCopyFast((undefined4 *)(uintptr_t)(*(undefined4 *)(piVar2[1] + 0x14)),(undefined4 *)(uintptr_t)(puRam020aae98[1]),
                  *(undefined4 *)(piVar2[1] + 0x10));
  G2d_Sprite_CreateFromTiles
            (auStack_34,puRam020aae98[1],((undefined2 *)piVar2[1])[1],*(undefined2 *)piVar2[1],4);
  iVar3 = func_020aaf70(piVar2);
  iVar9 = 0;
  if (0 < (int)((uint)*(ushort *)((int)piVar2 + 0xe) - iVar3)) {
    local_48 = 0;
    local_4c = iVar3;
    do {
      pbVar7 = (byte *)(*piVar2 + local_4c * 8);
      if ((1 < pbVar7[2]) && (1 < pbVar7[3])) {
        uVar4 = NFTR_GetTileIndexForCharacter
                          ((uint)(uintptr_t)(piVar8),*(undefined2 *)(*(int *)(param_1 + 0x30) + local_48));
        if (uVar4 == uRam020aae9c) {
          uVar4 = (uint)*(ushort *)(*piVar8 + 2);
        }
        local_3c = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar8),uVar4);
        local_38 = *(int *)(*piVar8 + 8) + 8 + *(ushort *)(*(int *)(*piVar8 + 8) + 2) * uVar4;
        iVar5 = _s32_div_f((uint)pbVar7[2] - (uint)*(byte *)(local_3c + 1),2);
        iVar6 = _s32_div_f((uint)pbVar7[3] - (uint)bVar1,2);
        (*local_20)(auStack_34,piVar8,(uint)*pbVar7 + iVar5,(uint)pbVar7[1] + iVar6,puRam020aae98[8]
                    ,&local_3c);
      }
      local_4c = local_4c + 1;
      local_48 = local_48 + 2;
      iVar9 = iVar9 + 1;
    } while (iVar9 < (int)((uint)*(ushort *)((int)piVar2 + 0xe) - iVar3));
  }
  return;
}

