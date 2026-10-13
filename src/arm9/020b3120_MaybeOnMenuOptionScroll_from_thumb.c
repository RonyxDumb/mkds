/* Decompiled C draft; module arm9; ROM address 020b3120. No matching claim. */
#include "types.h"
#include "deps/020b3120_MaybeOnMenuOptionScroll_from_thumb.h"

int MaybeOnMenuOptionScroll_from_thumb(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int extraout_r1;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar1 = func_020b2e98();
  if (iVar1 != 0) {
    iVar1 = GetCurrentOptionMenuKind_from_thumb();
    iVar3 = *piRam020b31b4;
    iVar2 = iVar3 + iVar1 * 0x1c;
    iVar4 = *(int *)(iVar2 + 0x50);
    while ((iVar5 < iVar4 && (*(int *)(iVar3 + 0x28) != *(int *)(iVar2 + iVar5 * 4 + 0x38)))) {
      iVar5 = iVar5 + 1;
    }
    if (iVar4 == 1) {
      param_1 = 0;
    }
    else if (iVar4 == 2) {
      if (((param_1 == 0) || (iVar5 + param_1 < 0)) || (1 < iVar5 + param_1)) {
        param_1 = 0;
      }
      else {
        *(undefined4 *)(iVar3 + 0x34) = 0;
        MaybePlaySomeSseqFromSarc0();
      }
    }
    else if (param_1 != 0) {
      *(undefined4 *)(iVar3 + 0x34) = 0;
      MaybePlaySomeSseqFromSarc0();
    }
    iVar2 = *piRam020b31b4;
    _s32_div_f(iVar4 + iVar5 + param_1,iVar4);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar2 + iVar1 * 0x1c + extraout_r1 * 4 + 0x38);
  }
  return iVar5;
}

