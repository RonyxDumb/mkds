/* Decompiled C draft; module arm9; ROM address 0212db24. No matching claim. */
#include "types.h"
#include "deps/0212db24_Sound_Context_BackupFrameState.h"

int Sound_Context_BackupFrameState(uint param_1)

{
  int iVar1;
  
  iVar1 = Mem_CreateFrameHeapState
                    (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
                     *(undefined2 *)(param_1 + 0xc));
  if (iVar1 == 0) {
    return -1;
  }
  iVar1 = Sound_Context_MaybeReset(param_1);
  if (iVar1 == 0) {
    Mem_RestoreFrameHeapState
              (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,0);
    return -1;
  }
  return *(ushort *)(param_1 + 0xc) - 1;
}

