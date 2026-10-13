/* Decompiled C draft; module arm9; ROM address 0207954c. No matching claim. */
#include "types.h"
#include "deps/0207954c_StructAD00Sub_LoadCharacterEmblem_from_thumb.h"

void StructAD00Sub_LoadCharacterEmblem_from_thumb(uint *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  
  uVar3 = *param_1 & 0xffff;
  FormatCharacterEmblemNsbmdPath(uVar3,param_3);
  uVar4 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
  FormatCharacterEmblemNsbtxPath(uVar3,param_3);
  uVar5 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb();
  uVar6 = Mem_AllocateHeap(param_2,0x6c);
  param_1[4] = uVar6;
  uVar4 = Model_CreateFromNsbmdNsbtxMetaCopy(param_2,param_1[4],uVar4,uVar5);
  Model_Render(param_1[4],3);
  ModelBlock_SomeMatFn(uVar4,0);
  if (param_3 != 0) {
    uVar2 = 0;
    bVar1 = false;
    uVar6 = Mem_AllocateHeap(param_2,0x38);
    param_1[2] = uVar6;
    Animation_CreateFrom(0,param_1[2],param_1[4],4,param_2,0);
    do {
      FormatCharacterEmblemNsbcaPath(uVar3,uVar2);
      iVar7 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
      if (iVar7 != 0) {
        uVar4 = Anim_NSBCA_LoadGetJNT0Block();
        uVar4 = JNT0_LoadJointByIdx(uVar4,0);
        uVar5 = GetRacerAnimationIndex(uVar2);
        Animation_Register(param_1[2],uVar2,uVar4,uVar5,param_2);
        if (uVar2 == 0) {
          bVar1 = true;
        }
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 4);
    if (bVar1) {
      Animation_SetAt(param_1[2],0);
      iVar7 = Animation_GetCurrentLength(param_1[2]);
      uVar3 = _s32_div_f(iVar7 - iRam02079670,2);
      param_1[0xb] = uVar3;
      uVar3 = FX_Div(iRam02079670,param_1[0xb]);
      param_1[0xc] = uVar3;
    }
    else {
      *(undefined2 *)(param_1[2] + 0x18) = 0;
    }
  }
  uVar3 = Mem_AllocateHeap(param_2,0x38);
  param_1[3] = uVar3;
  Animation_CreateFrom(2,param_1[3],param_1[4],1,param_2,0);
  Animation_RegisterAll(param_1[3],*(undefined4 *)(*piRam02079674 + 0x28),param_2);
  Animation_SetAt(param_1[3],0);
  return;
}

