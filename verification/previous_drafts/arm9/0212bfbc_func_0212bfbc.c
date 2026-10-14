/* Decompiled C draft; module arm9; ROM address 0212bfbc. No matching claim. */
#include "types.h"
#include "deps/0212bfbc_func_0212bfbc.h"

uint func_0212bfbc(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1 * 0x24 + iRam0212c014;
  iVar2 = IntrusiveListWrapper_NextItem(iVar4 + 0xc,0);
  if (iVar2 != 0) {
    IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(iVar4 + 0xc),iVar2);
    *(int *)(iVar2 + 0xc) = param_2;
    *(int *)(param_2 + 8) = iVar2;
    uVar1 = iVar2 + 8U & 3;
    uVar3 = *(uint *)(iVar2 + 8U & 0xfffffffc);
    Sound_Context_DisposeLoadedStuff(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    uVar1 = iVar2 + 8U & 3;
    uVar3 = *(uint *)(iVar2 + 8U & 0xfffffffc);
    return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  }
  return 0;
}

