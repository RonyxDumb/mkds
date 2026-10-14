/* Decompiled C draft; module arm9; ROM address 020164e8. No matching claim. */
#include "types.h"
#include "deps/020164e8_HandleAllGlobalTEQSubs.h"

void HandleAllGlobalTEQSubs(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  iVar2 = iRam02016550;
  iVar3 = StructTEQ_GetTopUsedTEQSub(iRam02016550);
  iVar4 = StructTEQ_TryPopTEQSub(iVar2);
  if (iVar4 != 0) {
    piVar6 = (int *)(iVar2 + 0x10);
    do {
      StructTEQSub_HandleTEQSub(iVar3);
      uVar1 = iVar3 + 0xcU & 3;
      uVar5 = *(uint *)(iVar3 + 0xcU & 0xfffffffc);
      *piVar6 = (*(uint *)((uint)piVar6 & 0xfffffffc) >> ((uint)piVar6 & 3) * 8 |
                *(uint *)((uint)piVar6 & 0xfffffffc) << ((uint)piVar6 & 3) * -8 + 0x20) -
                (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      iVar3 = StructTEQ_GetTopUsedTEQSub(iVar2);
      iVar4 = StructTEQ_TryPopTEQSub(iVar2);
    } while (iVar4 != 0);
    return;
  }
  return;
}

