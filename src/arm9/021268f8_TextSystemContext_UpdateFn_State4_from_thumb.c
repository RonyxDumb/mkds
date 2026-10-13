/* Decompiled C draft; module arm9; ROM address 021268f8. No matching claim. */
#include "types.h"
#include "deps/021268f8_TextSystemContext_UpdateFn_State4_from_thumb.h"

void TextSystemContext_UpdateFn_State4_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam021269a4;
  *(int *)(*piRam021269a4 + 0xc) = *(int *)(*piRam021269a4 + 0xc) + 1;
  iVar5 = 0;
  iVar4 = 0;
  do {
    iVar3 = *piVar1;
    uVar2 = ComputeValueInterpolation_from_thumb
                      (1,(int)(short)-(short)*(undefined4 *)(iVar3 + iVar4 + iRam021269a8),
                       (int)*(short *)(iRam021269ac + *(int *)(iVar3 + 0x40) * 2),
                       *(undefined4 *)(iVar3 + 0xc),0xf);
    *(undefined4 *)(*piVar1 + iVar4 + iRam021269b0) = uVar2;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  iVar5 = *piVar1;
  iVar4 = _s32_div_f(*(int *)(iVar5 + 0xc) * -10,0xf);
  *(int *)(iVar5 + iRam021269b4) = -10 - iVar4;
  iVar4 = iRam021269b0;
  piVar1 = piRam021269a4;
  if (0xe < *(int *)(*piRam021269a4 + 0xc)) {
    iVar5 = 0;
    iVar3 = 0;
    do {
      *(undefined4 *)(*piVar1 + iVar3 + iVar4) = 0xffffff40;
      iVar3 = iVar3 + 4;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    *(undefined4 *)(*piVar1 + 4) = 0;
    TextSystemContext_ReloadButtonGraphics2_from_thumb();
    piVar1 = piRam021269a4;
    *(undefined4 *)(*piRam021269a4 + 0xc) = 0;
    *(undefined4 *)(*piVar1 + 0x38) = 0;
    *(undefined4 *)(*piVar1 + 0x30) = 0;
    *(undefined4 *)(*piVar1 + 0x18) = 0;
    *(undefined4 *)(*piVar1 + 0x1c) = 0;
  }
  return;
}

