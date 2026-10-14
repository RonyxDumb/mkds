/* Decompiled C draft; module arm9; ROM address 0212dbec. No matching claim. */
#include "types.h"
#include "deps/0212dbec_Sound_Context_DisposeLoadedStuff.h"

void Sound_Context_DisposeLoadedStuff(uint param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  
  bVar3 = false;
  iVar4 = IntrusiveListWrapper_GetPrevItem(param_1 + 4,0);
  if (iVar4 != 0) {
    do {
      for (iVar5 = IntrusiveListWrapper_GetPrevItem(iVar4,0); iVar5 != 0;
          iVar5 = IntrusiveListWrapper_GetPrevItem(iVar4,iVar5)) {
        uVar1 = iVar5 + 0xcU & 3;
        uVar9 = *(uint *)(iVar5 + 0xcU & 0xfffffffc);
        pcVar10 = (code *)(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20);
        if (pcVar10 != (code *)0x0) {
          uVar1 = iVar5 + 8U & 3;
          uVar6 = *(uint *)(iVar5 + 8U & 0xfffffffc);
          uVar9 = iVar5 + 0x10U & 3;
          uVar7 = *(uint *)(iVar5 + 0x10U & 0xfffffffc);
          uVar2 = iVar5 + 0x14U & 3;
          uVar8 = *(uint *)(iVar5 + 0x14U & 0xfffffffc);
          (*pcVar10)(iVar5 + 0x20,uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,
                     uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20,
                     uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
          bVar3 = true;
        }
      }
      IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(param_1 + 4),iVar4);
      iVar4 = IntrusiveListWrapper_GetPrevItem(param_1 + 4,0);
    } while (iVar4 != 0);
  }
  Mem_ResetFrameHeap(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,3);
  if (bVar3) {
    func_0212d968();
  }
  Sound_Context_MaybeReset(param_1);
  return;
}

