/* Decompiled C draft; module arm9; ROM address 02079078. No matching claim. */
#include "types.h"
#include "deps/02079078_MaybeLoadWinModelTextureAnimationHelper_from_thumb.h"

void MaybeLoadWinModelTextureAnimationHelper_from_thumb
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Model_CreateFromNsbmdNsbtx(param_2,param_4,param_5);
  Model_Render(param_2,3);
  ModelBlock_SomeMatFn(uVar1,1);
  Animation_CreateFrom(0,param_3,param_2,1,param_1,0);
  uVar1 = Anim_NSBCA_LoadGetJNT0Block(param_6);
  uVar1 = JNT0_LoadJointByIdx(uVar1,0);
  uVar2 = GetRacerAnimationIndex(2);
  Animation_Register(param_3,0,uVar1,uVar2,param_1);
  Animation_SetAt(param_3,0);
  return;
}

