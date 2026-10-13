/* Decompiled C draft; module arm9; ROM address 0207926c. No matching claim. */
#include "types.h"
#include "deps/0207926c_CharacterKart_LoadKartTireModel_from_thumb.h"

void CharacterKart_LoadKartTireModel_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 4) & 0xffff;
  FormatKartTireNsbmdPath(uVar4,*(undefined4 *)(param_1 + 0x20));
  uVar1 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
  FormatKartTireNsbtxPath(uVar4,*(undefined4 *)(param_1 + 0x20));
  uVar2 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb();
  uVar3 = Mem_AllocateHeap(param_2,0x6c);
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  uVar1 = Model_CreateFromNsbmdNsbtxMetaCopy(param_2,*(undefined4 *)(param_1 + 0x18),uVar1,uVar2);
  Model_Render(*(undefined4 *)(param_1 + 0x18),3);
  ModelBlock_SomeMatFn(uVar1,0);
  return;
}

