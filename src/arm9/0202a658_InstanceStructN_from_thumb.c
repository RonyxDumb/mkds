/* Decompiled C draft; module arm9; ROM address 0202a658. No matching claim. */
#include "types.h"
#include "deps/0202a658_InstanceStructN_from_thumb.h"

void InstanceStructN_from_thumb(undefined4 param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = Mem_AllocateHeap(param_1,uRam0202a708);
  *piRam0202a70c = iVar3;
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(iVar3),uRam0202a708);
  OamBuffer_SomeFn_from_thumb(*piRam0202a70c,*piRam0202a70c + iRam0202a710);
  iVar3 = iRam0202a718;
  piVar1 = piRam0202a70c;
  *(undefined4 *)(*piRam0202a70c + iRam0202a718) = *(undefined4 *)(*piRam0202a714 + 8);
  iVar4 = *piVar1;
  if (*(int *)(iVar4 + iVar3) == 0) {
    InstanceStructM_from_thumb(param_1,iVar4,iVar4 + iRam0202a710);
  }
  else {
    InstanceStructV_from_thumb(param_1,iVar4,iVar4 + iRam0202a710);
  }
  CreateGlobalNN_from_thumb(param_1,*piRam0202a70c);
  uVar2 = uRam0202a720;
  *puRam0202a71c = *puRam0202a71c & uRam0202a720 | 0x10;
  *puRam0202a724 = *puRam0202a724 & uVar2 | 0x10;
  G2x_SetBlendAlpha_((uint *)(uintptr_t)(uRam0202a728),1,0x3f,8,8);
  G2x_SetBlendAlpha_((uint *)(uintptr_t)(uRam0202a72c),0,0x2f,8,8);
  uVar2 = uRam0202a730;
  *puRam0202a71c = *puRam0202a71c & uRam0202a730;
  *puRam0202a724 = *puRam0202a724 & uVar2;
  return;
}

