/* Decompiled C draft; module arm9; ROM address 0207916c. No matching claim. */
#include "types.h"
#include "deps/0207916c_LoadAD00KillerItemModel_from_thumb.h"

void LoadAD00KillerItemModel_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam02079208);
  uVar2 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb(uRam0207920c);
  uVar3 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam02079210);
  uVar2 = Model_CreateFromNsbmdNsbtxMetaCopy(param_1,*piRam02079214 + 0x2c,uVar1,uVar2);
  ModelBlock_SomeMatFn(uVar2,0);
  Model_Render(*piRam02079214 + 0x2c,3);
  uVar2 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb(uRam02079218);
  Animation_CreateFrom(0,*piRam02079214 + iRam0207921c,*piRam02079214 + 0x2c,1,param_1,uVar1);
  Animation_RegisterAll(*piRam02079214 + iRam0207921c,uVar2,param_1);
  Animation_SetAt(*piRam02079214 + iRam0207921c,0);
  StructAD00Sh_SomeFn_2(*piRam02079214 + 0x98,uVar3,3);
  StructML_SetSomeDefaultFields(*piRam02079214 + 0x2c);
  return;
}

