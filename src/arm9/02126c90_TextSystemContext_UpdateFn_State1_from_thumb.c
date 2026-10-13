/* Decompiled C draft; module arm9; ROM address 02126c90. No matching claim. */
#include "types.h"
#include "deps/02126c90_TextSystemContext_UpdateFn_State1_from_thumb.h"

void TextSystemContext_UpdateFn_State1_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam02126d14;
  *(int *)(*piRam02126d14 + 0xc) = *(int *)(*piRam02126d14 + 0xc) + 1;
  iVar5 = 0;
  iVar4 = 0;
  do {
    iVar3 = *piVar1;
    uVar2 = ComputeValueInterpolation_from_thumb
                      (1,(int)*(short *)(iRam02126d18 + *(int *)(iVar3 + 0x3c) * 2),
                       (int)(short)-(short)*(undefined4 *)(iVar3 + iVar4 + iRam02126d1c),
                       *(undefined4 *)(iVar3 + 0xc),0xf);
    *(undefined4 *)(*piVar1 + iVar4 + iRam02126d20) = uVar2;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  iVar4 = *piVar1;
  uVar2 = _s32_div_f(*(int *)(iVar4 + 0xc) * -10,0xf);
  *(undefined4 *)(iVar4 + iRam02126d24) = uVar2;
  iVar4 = *piRam02126d14;
  if (0xe < *(int *)(iVar4 + 0xc)) {
    if (*(int *)(iVar4 + 0x38) == 0) {
      *(undefined4 *)(iVar4 + 0x34) = 0;
    }
    piVar1 = piRam02126d14;
    *(undefined4 *)(*piRam02126d14 + 4) = 2;
    *(undefined4 *)(*piVar1 + 0xc) = 0;
  }
  return;
}

