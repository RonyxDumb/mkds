/* Decompiled C draft; module arm9; ROM address 020794bc. No matching claim. */
#include "types.h"
#include "deps/020794bc_StructAD00Sub_LoadKartModel_from_thumb.h"

void StructAD00Sub_LoadKartModel_from_thumb(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 4) & 0xffff;
  FormatCharacterKartNsbmdPath(uVar5);
  uVar1 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
  FormatCharacterKartNsbtxPath(uVar5);
  uVar2 = FindFileBuffer_KME_KM1_KM2_KSB_from_thumb();
  uVar3 = Mem_AllocateHeap(param_2,0x6c);
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  iVar4 = Model_CreateFromNsbmdNsbtxMetaCopy(param_2,*(undefined4 *)(param_1 + 0x14),uVar1,uVar2);
  Model_Render(*(undefined4 *)(param_1 + 0x14),3);
  ModelBlock_SomeMatFn(iVar4,0);
  if (param_3 != 0) {
    uVar1 = Dict_SomeFn_0(iVar4 + *(int *)(iVar4 + 8) + 4,uRam02079544);
    func_02013468(iVar4,uVar1,0);
    *(undefined4 *)(*piRam02079548 + 0xc) = uVar1;
  }
  LoadKartBodyPalette_from_thumb
            (*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 4),
             *(undefined4 *)(*piRam02079548 + 0x10));
  return;
}

