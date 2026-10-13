/* Decompiled C draft; module arm9; ROM address 02079220. No matching claim. */
#include "types.h"
#include "deps/02079220_StructAD00Sub_LoadKartShadowModel_from_thumb.h"

void StructAD00Sub_LoadKartShadowModel_from_thumb(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  FormatKartShadowNsbmdPath(*(uint *)(param_1 + 4) & 0xffff);
  uVar1 = FindFileBufferGeneric_KME_KM1_KM2_KSB_from_thumb();
  uVar2 = Mem_AllocateHeap(param_2,0x74);
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
  LoadedModelTexture_SomeFn(*(int *)(param_1 + 0x1c) + 0x5c,uVar1,uVar1);
  iVar3 = Nsbmd_GetMDL0Block(uVar1);
  StructAD00Sh_SomeFn(*(undefined4 *)(param_1 + 0x1c),
                      iVar3 + *(int *)(iVar3 + (uint)*(ushort *)(iVar3 + 0xe) + 0xc),3);
  return;
}

