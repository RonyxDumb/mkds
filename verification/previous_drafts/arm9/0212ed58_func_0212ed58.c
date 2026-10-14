/* Decompiled C draft; module arm9; ROM address 0212ed58. No matching claim. */
#include "types.h"
#include "deps/0212ed58_func_0212ed58.h"

void func_0212ed58(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = NNS_SndArcGetSeqInfo(param_2);
  if (iVar1 != 0) {
    MaybeStartSeq(param_1,*(undefined1 *)(iVar1 + 9),*(undefined2 *)(iVar1 + 4),
                  *(undefined1 *)(iVar1 + 8));
    return;
  }
  return;
}

