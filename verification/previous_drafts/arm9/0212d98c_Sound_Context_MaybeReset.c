/* Decompiled C draft; module arm9; ROM address 0212d98c. No matching claim. */
#include "types.h"
#include "deps/0212d98c_Sound_Context_MaybeReset.h"

undefined4 Sound_Context_MaybeReset(uint param_1)

{
  int iVar1;
  
  iVar1 = Mem_Frame_Allocate(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,0x14,4);
  if (iVar1 != 0) {
    func_0212da1c(iVar1);
    IntrusiveListWrapper_InsertLast(param_1 + 4,iVar1);
    return 1;
  }
  return 0;
}

