/* Decompiled C draft; module arm9; ROM address 021251c4. No matching claim. */
#include "types.h"
#include "deps/021251c4_G2d_Text_SomeFn_4_from_thumb.h"

void G2d_Text_SomeFn_4_from_thumb
               (undefined4 *param_1,undefined4 param_2,undefined4 *param_3,int param_4,int param_5,
               int param_6,int param_7,int param_8,int param_9,uint param_10,undefined4 param_11,
               byte *param_12,int param_13,int param_14,int param_15)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 *local_34;
  byte *local_18;
  
  iVar3 = param_1[2];
  piVar4 = (int *)param_1[1];
  iVar5 = param_1[3];
  cVar1 = *(char *)(*piVar4 + 1);
  local_18 = param_12;
  iVar6 = func_021253ac(param_10,param_11,param_7,param_2,*param_3);
  iVar6 = param_5 + iVar6;
  if (-1 < iVar6) {
    if ((param_10 & 0x80) == 0) {
      iVar10 = param_6;
      if ((param_10 & uRam0212539c) != 0) {
        iVar10 = param_6 + (param_8 - param_4);
      }
    }
    else {
      iVar10 = param_6 + (param_8 - param_4 >> 1);
    }
    if ((-1 < iVar10) && (uVar7 = (*(code *)piVar4[1])(&local_18), uVar7 != 0)) {
      local_34 = param_3;
      do {
        if (uVar7 == 0x1a) {
          if ((local_18[1] == 0xff) && (*(short *)(local_18 + 2) == 0)) {
            uVar7 = (uint)local_18[4];
            if (param_15 == 0) {
              param_9 = uVar7 * 2 + 1;
            }
            else if (uVar7 == 0) {
              param_9 = 2;
            }
            else {
              param_9 = uVar7 * 2 + 1;
            }
          }
          local_18 = local_18 + (*local_18 - 2);
        }
        else if (uVar7 == 10) {
          iVar10 = iVar10 + iVar5 + cVar1;
          local_34 = local_34 + 1;
          if (param_6 + param_8 <= iVar10) {
            return;
          }
          iVar6 = func_021253ac(param_10,param_11,param_7,param_2,*local_34);
          iVar6 = param_5 + iVar6;
          if (iVar6 < 0) {
            return;
          }
        }
        else {
          if (param_14 == -1) {
LAB_02125316:
            iVar8 = G2d_Sprite_PutChar(*param_1,param_1[1],iVar6,iVar10,param_9,uVar7);
            iVar6 = iVar6 + iVar8;
          }
          else {
            if (param_13 != 0) {
              if ((((uVar7 < 0x30) || (0x39 < uVar7)) &&
                  ((uVar7 < uRam021253a0 || (uRam021253a4 < uVar7)))) && (uVar7 != 0x2d)) {
                bVar2 = false;
              }
              else {
                bVar2 = true;
              }
              if (!bVar2) goto LAB_02125316;
            }
            uVar9 = NFTR_GetTileIndexForCharacter((uint)(uintptr_t)(piVar4),uVar7);
            if (uVar9 == uRam021253a8) {
              uVar9 = (uint)*(ushort *)(*piVar4 + 2);
            }
            iVar8 = NFTR_GetCharacterWidthTileEntry((uint)(uintptr_t)(piVar4),uVar9);
            iVar6 = iVar6 + (param_14 - *(char *)(iVar8 + 2) >> 1);
            G2d_Sprite_PutChar(*param_1,param_1[1],iVar6,iVar10,param_9,uVar7);
            iVar6 = iVar6 + (param_14 - (param_14 - *(char *)(iVar8 + 2) >> 1));
          }
          if (param_5 + param_7 < iVar6) {
            return;
          }
          iVar6 = iVar6 + iVar3;
        }
        uVar7 = (*(code *)piVar4[1])(&local_18);
      } while (uVar7 != 0);
    }
  }
  return;
}

