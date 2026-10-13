/* Decompiled C draft; module arm9; ROM address 02079678. No matching claim. */
#include "types.h"
#include "deps/02079678_func_02079678.h"

void func_02079678(undefined4 param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_r1;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  if (param_2 == 0) {
    local_28 = 7;
    local_24 = 0xd;
    local_20 = 0x15;
    local_1c = 0x25;
  }
  else {
    local_28 = 0;
    local_24 = 7;
    local_20 = 0;
    local_1c = 0x15;
  }
  local_2c = 0;
  piVar3 = (int *)*piRam020797d4;
  if ((short)piVar3[2] != 0) {
    if (param_2 == 0) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    do {
      piVar3 = (int *)(*piVar3 + local_2c * 0xb4);
      iVar4 = DetermineIsP_from_thumb(local_2c);
      _s32_div_f(piVar3[1] & 0xffff,3);
      if ((extraout_r1 != 0) || (!bVar2)) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
      if ((local_28 <= *piVar3) && (*piVar3 < local_24)) {
        StructAD00Sub_LoadCharacterEmblem_from_thumb(piVar3,param_1,iVar4);
      }
      if ((!bVar1) &&
         (((extraout_r1 == 0 && (param_2 != 0)) ||
          ((local_20 <= piVar3[1] && (piVar3[1] < local_1c)))))) {
        StructAD00Sub_LoadKartModel_from_thumb((int)(uintptr_t)(piVar3),param_1,iVar4);
      }
      if (param_2 != 0) {
        if (iVar4 != 0) {
          uVar8 = 0;
          iVar4 = Mem_AllocateHeap(param_1,0x30);
          piVar3[0x15] = iVar4;
          do {
            iVar7 = uVar8 * 0xc;
            iVar6 = piVar3[0x15] + iVar7;
            iVar4 = piVar3[8] + 0x14 + iVar7;
            *(int *)(piVar3[0x15] + iVar7) = *(int *)(piVar3[8] + 0x14 + iVar7) >> 4;
            *(int *)(iVar6 + 4) = *(int *)(iVar4 + 4) >> 4;
            *(int *)(iVar6 + 8) = *(int *)(iVar4 + 8) >> 4;
            uVar8 = uVar8 + 1 & 0xffff;
          } while (uVar8 < 4);
          uVar5 = FX_Div(*(int *)piVar3[0x15] * -2,*(undefined4 *)(piVar3[8] + 0x10));
          *(undefined4 *)(piVar3[0x15] + 0xc) = uVar5;
          *(int *)(piVar3[0x15] + 0x24) = *(int *)(piVar3[0x15] + 0x18) * -2;
          CharacterKart_LoadKartTireModel_from_thumb((int)(uintptr_t)(piVar3),param_1);
        }
        StructAD00Sub_LoadKartShadowModel_from_thumb((int)(uintptr_t)(piVar3),param_1);
      }
      local_2c = local_2c + 1 & 0xffff;
      piVar3 = (int *)*piRam020797d4;
    } while (local_2c < *(ushort *)(piVar3 + 2));
  }
  return;
}

