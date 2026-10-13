/* Decompiled C draft; module arm9; ROM address 0212ecc0. No matching claim. */
#include "types.h"
#include "deps/0212ecc0_NNSi_MaybeSndPlayerStartSeq.h"

void NNSi_MaybeSndPlayerStartSeq(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Sound_GetSarcInfoEntry(param_2);
  if (uVar1 == 0) {
    return;
  }
  iVar2 = Sound_MaybeGetRawFilePointer
                    (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
  if (iVar2 != 0) {
    iVar2 = func_0212f788(iVar2,param_3);
    if (iVar2 != 0) {
      func_0212ea28(param_1,*(undefined1 *)(iVar2 + 9),*(undefined2 *)(iVar2 + 4),
                    *(undefined1 *)(iVar2 + 8));
      return;
    }
    return;
  }
  return;
}

