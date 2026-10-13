/* Decompiled C draft; module arm9; ROM address 020848fc. No matching claim. */
#include "types.h"
#include "deps/020848fc_DisposeAllModelResources.h"

void DisposeAllModelResources(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = IntrusiveListWrapper_NextItem(uRam02084954,0);
  uVar2 = uRam02084954;
  if (iVar3 == 0) {
    return;
  }
  do {
    uVar1 = iVar3 + 8U & 3;
    uVar4 = *(uint *)(iVar3 + 8U & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) {
      MaybeDisposeCommonHeaderFileData();
    }
    iVar3 = IntrusiveListWrapper_NextItem(uVar2,iVar3);
  } while (iVar3 != 0);
  return;
}

