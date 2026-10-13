/* Decompiled C draft; module arm9; ROM address 0212ee8c. No matching claim. */
#include "types.h"
#include "deps/0212ee8c_func_0212ee8c.h"

void func_0212ee8c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = Os_DisableIrq();
  iVar4 = IntrusiveListWrapper_NextItem(param_1,0);
  while (iVar2 = iVar4, iVar2 != 0) {
    iVar4 = IntrusiveListWrapper_NextItem(param_1,iVar2);
    uVar1 = iVar2 + 8U & 3;
    uVar5 = *(uint *)(iVar2 + 8U & 0xfffffffc);
    if ((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) == param_2) {
      IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(param_1),iVar2);
      func_0212ee54(iVar2);
    }
  }
  Os_RestoreIrq(uVar3);
  return;
}

