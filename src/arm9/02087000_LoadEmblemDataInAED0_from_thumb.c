/* Decompiled C draft; module arm9; ROM address 02087000. No matching claim. */
#include "types.h"
#include "deps/02087000_LoadEmblemDataInAED0_from_thumb.h"

void LoadEmblemDataInAED0_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int local_1c [2];
  
  piVar1 = piRam020870dc;
  uVar5 = 0;
  if (*(char *)(*piRam020870d4 + iRam020870d8) != '\0') {
    do {
      *(undefined4 *)(*piVar1 + uVar5 * 4 + iRam020870e0) = 0;
      *(undefined4 *)(*piVar1 + uVar5 * 4 + iRam020870e4) = 0;
      iVar2 = *piRam020870d4;
      iVar4 = iVar2 + uVar5 * 0x30;
      if ((*(char *)(iVar4 + 0x94) == '\0') || (*(char *)(iVar2 + 0x58) != '\0')) {
        if (*(char *)(iVar2 + 0x58) == '\0') {
          FormatEmblemNsbtx(*(uint *)(iVar4 + 0x68) & 0xffff);
        }
        else {
          FormatTeamEmblemNsbtx(*(int *)(iVar4 + 0x74) == 1);
        }
        FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
        iVar2 = Nsbtx_GetTEX0Block();
        iVar4 = *(int *)(iVar2 + 0x38);
        *(int *)(*piVar1 + uVar5 * 4 + iRam020870e0) = iVar2 + *(int *)(iVar2 + 0x14);
        *(int *)(*piVar1 + uVar5 * 4 + iRam020870e4) = iVar2 + iVar4;
      }
      else {
        uVar6 = *(undefined4 *)(iVar4 + 0x8c);
        uVar3 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam020870e8);
        Gfx_ReadPalette(local_1c,uVar3);
        uVar3 = *(undefined4 *)(local_1c[0] + 0xc);
        *(undefined4 *)(*piVar1 + uVar5 * 4 + iRam020870e0) = uVar6;
        *(undefined4 *)(*piVar1 + uVar5 * 4 + iRam020870e4) = uVar3;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < *(byte *)(*piRam020870d4 + iRam020870d8));
  }
  return;
}

