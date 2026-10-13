/* Decompiled C draft; module arm9; ROM address 02022dd8. No matching claim. */
#include "types.h"
#include "deps/02022dd8_NFTR_CharacterMap_GetTileIndexForCharacter.h"

uint NFTR_CharacterMap_GetTileIndexForCharacter(ushort *param_1,uint param_2)

{
  int iVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  ushort *puVar5;
  
  uVar2 = param_1[2];
  if (uVar2 == 0) {
    uVar4 = (uint)param_1[6] + (param_2 - *param_1) & 0xffff;
  }
  else if (uVar2 == 1) {
    uVar4 = (uint)param_1[(param_2 - *param_1) + 6];
  }
  else {
    uVar4 = uRam02022eac;
    if (uVar2 == 2) {
      puVar3 = param_1 + 7;
      puVar5 = puVar3 + (param_1[6] - 1) * 2;
      if (puVar3 <= puVar5) {
        do {
          iVar1 = ((int)(((int)puVar5 - (int)puVar3) +
                        ((uint)((int)puVar5 - (int)puVar3 >> 1) >> 0x1e)) >> 2) / 2;
          if (puVar3[iVar1 * 2] < param_2) {
            puVar3 = puVar3 + iVar1 * 2 + 2;
          }
          else {
            if (puVar3[iVar1 * 2] <= param_2) {
              return (uint)puVar3[iVar1 * 2 + 1];
            }
            puVar5 = puVar3 + iVar1 * 2 + -2;
          }
        } while (puVar3 <= puVar5);
      }
    }
  }
  return uVar4;
}

