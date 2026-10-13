/* Decompiled C draft; module arm9; ROM address 021270bc. No matching claim. */
#include "types.h"
#include "deps/021270bc_TextSystemContext_UpdateAnimationGraphics_from_thumb.h"

void TextSystemContext_UpdateAnimationGraphics_from_thumb(void)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  iVar4 = 0;
  local_24 = 0;
  iVar1 = (*(int *)(*piRam02127168 + 0x14) + 4) * 4;
  pbVar6 = (byte *)(iRam0212716c + iVar1);
  do {
    iVar2 = *piRam02127168;
    if (*(int *)(iVar2 + iVar4 + 0x18) != 0) {
      local_20 = iVar2 + 0x54;
      if (local_24 == 1) {
        local_20 = iVar2 + iRam02127170;
      }
      local_28 = (uint)pbVar6[2];
      if (local_28 <= pbVar6[3]) {
        local_1c = local_28 << 5;
        do {
          uVar5 = (uint)*pbVar6;
          if (uVar5 <= pbVar6[1]) {
            iVar2 = uVar5 * 2;
            psVar3 = (short *)(local_20 + local_1c * 2 + iVar2);
            do {
              *psVar3 = (short)*(undefined4 *)(iVar4 + *piRam02127168 + iRam02127174) +
                        *(short *)(local_1c * 2 + *(int *)(iVar1 + *piRam02127168 + iRam02127178) +
                                   iVar2 + 0xc);
              iVar2 = iVar2 + 2;
              psVar3 = psVar3 + 1;
              uVar5 = uVar5 + 1;
            } while ((int)uVar5 <= (int)(uint)pbVar6[1]);
          }
          local_1c = local_1c + 0x20;
          local_28 = local_28 + 1;
        } while ((int)local_28 <= (int)(uint)pbVar6[3]);
      }
    }
    iVar4 = iVar4 + 4;
    local_24 = local_24 + 1;
  } while (local_24 < 2);
  return;
}

