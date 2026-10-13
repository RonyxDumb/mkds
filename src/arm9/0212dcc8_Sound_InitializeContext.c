/* Decompiled C draft; module arm9; ROM address 0212dcc8. No matching claim. */
#include "types.h"
#include "deps/0212dcc8_Sound_InitializeContext.h"

uint Sound_InitializeContext(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 3U & 0xfffffffc;
  if ((uint)(param_1 + param_2) < uVar4) {
    return 0;
  }
  uVar3 = (param_1 + param_2) - uVar4;
  if (uVar3 < 0x10) {
    return 0;
  }
  iVar1 = Mem_Frame_Create(uVar4 + 0x10,uVar3 - 0x10,0);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = Sound_Context_SetHeap((undefined4 *)(uintptr_t)(uVar4),iVar1);
  if (iVar2 == 0) {
    Mem_Frame_Finalize(iVar1);
    return 0;
  }
  return uVar4;
}

