/* Decompiled C draft; module arm9; ROM address 02017640. No matching claim. */
#include "types.h"
#include "deps/02017640_Mem_FindTopParentHeapHead.h"

int Mem_FindTopParentHeapHead(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = IntrusiveListWrapper_NextItem(param_1,0);
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    uVar1 = iVar2 + 0x18U & 3;
    uVar3 = *(uint *)(iVar2 + 0x18U & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) <= param_2) &&
       (uVar1 = iVar2 + 0x1cU & 3, uVar3 = *(uint *)(iVar2 + 0x1cU & 0xfffffffc),
       param_2 < (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20))) break;
    iVar2 = IntrusiveListWrapper_NextItem(param_1,iVar2);
  }
  iVar4 = Mem_FindTopParentHeapHead(iVar2 + 0xc,param_2);
  if (iVar4 == 0) {
    iVar4 = iVar2;
  }
  return iVar4;
}

