/* Decompiled C draft; module arm9; ROM address 0212db7c. No matching claim. */
#include "types.h"
#include "deps/0212db7c_Sound_Context_Allocate.h"

int Sound_Context_Allocate
              (uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Mem_Frame_Allocate(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
                             (param_2 + 0x1fU & 0xffffffe0) + 0x20,0x20);
  if (iVar1 != 0) {
    uVar2 = IntrusiveListWrapper_GetPrevItem(param_1 + 4,0);
    *(int *)(iVar1 + 8) = param_2;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    *(undefined4 *)(iVar1 + 0x10) = param_4;
    *(undefined4 *)(iVar1 + 0x14) = param_5;
    IntrusiveListWrapper_InsertLast(uVar2,iVar1);
    return iVar1 + 0x20;
  }
  return 0;
}

