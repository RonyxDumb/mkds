/* Decompiled C draft; module arm9; ROM address 0212da38. No matching claim. */
#include "types.h"
#include "deps/0212da38_Sound_MaybeRestoreHeapState.h"

void Sound_MaybeRestoreHeapState(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  
  bVar3 = false;
  if (param_2 != 0) {
    if (param_2 < (int)(uint)*(ushort *)(param_1 + 0xc)) {
      do {
        uVar4 = IntrusiveListWrapper_GetPrevItem(param_1 + 4,0);
        for (iVar5 = IntrusiveListWrapper_GetPrevItem(uVar4,0); iVar5 != 0;
            iVar5 = IntrusiveListWrapper_GetPrevItem(uVar4,iVar5)) {
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
        IntrusiveListWrapper_RemoveItem(param_1 + 4,uVar4);
      } while (param_2 < (int)(uint)*(ushort *)(param_1 + 0xc));
    }
    Mem_RestoreFrameHeapState
              (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,param_2);
    if (bVar3) {
      func_0212d968();
    }
    Mem_CreateFrameHeapState
              (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
               *(undefined2 *)(param_1 + 0xc));
    Sound_Context_MaybeReset(param_1);
    return;
  }
  Sound_Context_DisposeLoadedStuff();
  return;
}

