/* Decompiled C draft; module arm9; ROM address 021291d4. No matching claim. */
#include "types.h"
#include "deps/021291d4_Keyboard_SwitchFn8_from_thumb.h"

void Keyboard_SwitchFn8_from_thumb(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 auStack_220 [11];
  undefined1 auStack_20a [506];
  
  piVar1 = piRam021293a0;
  *(int *)(*piRam021293a0 + 0x28) = *(int *)(*piRam021293a0 + 0x28) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0,0xc0,*(undefined4 *)(*piVar1 + 0x28),0xf);
  piVar1 = piRam021293a0;
  *(undefined2 *)(*piRam021293a0 + 0x84) = uVar2;
  uVar2 = ComputeValueInterpolation_from_thumb
                    (1,(int)psRam021293a4[3],(int)psRam021293a8[3],*(undefined4 *)(*piVar1 + 0x28),
                     0xf);
  *(undefined2 *)(*piVar1 + 0x8c) = uVar2;
  if (*(int *)(*piVar1 + 0x6c) == 0) {
    uVar2 = ComputeValueInterpolation_from_thumb
                      (1,(int)*psRam021293a4,(int)*psRam021293a8,*(undefined4 *)(*piVar1 + 0x28),0xf
                      );
    *(undefined2 *)(*piRam021293a0 + 0x86) = uVar2;
  }
  if (0xe < *(int *)(*piRam021293a0 + 0x28)) {
    *(undefined4 *)(*piRam021293a0 + 0x28) = 0xf;
  }
  if ((0xe < *(int *)(*piRam021293a0 + 0x28)) &&
     (iVar3 = TextSystem_IsDialogFinished_from_thumb(), piVar1 = piRam021293a0, iVar3 != 0)) {
    iVar3 = *piRam021293a0;
    if (*(int *)(iVar3 + 0x6c) != 0) {
      if (*(short *)(iVar3 + 0x70) == 0xc) {
        uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar3 + 0xc0),0x11);
        uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam021293a0 + 0xc0),0);
        uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar3 + 0xc0),1);
        TextSystem_DisplayDoubleButtonDialog_from_thumb(uVar4,uVar5,uVar6,0,0,1,1,0);
      }
      else {
        uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar3 + 0xc0),0xe);
        iVar3 = GetClampedString10LengthForFontIndex0_from_thumb(*piRam021293a0 + 0x44,auStack_220);
        auStack_220[iVar3] = 0;
        MaybeHandleBmgFormatting_from_thumb(auStack_220,uVar4,auStack_20a,uRam021293ac);
        uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam021293a0 + 0xc0),0);
        uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam021293a0 + 0xc0),1);
        TextSystem_DisplayDoubleButtonDialog_from_thumb(auStack_20a,uVar4,uVar5,0,0,1,1,0);
      }
      piVar1 = piRam021293a0;
      *(undefined4 *)(*piRam021293a0 + 0x10) = 9;
      *(undefined4 *)(*piVar1 + 0x28) = 0;
      return;
    }
    if (*(short *)(iVar3 + 0x70) == 0xc) {
      *(undefined4 *)(iVar3 + 4) = 0;
      *(undefined4 *)(*piVar1 + 8) = 0;
      func_020ab9d0(*(undefined4 *)(*piVar1 + 8));
      func_020ab758(*puRam021293b0);
      func_02129e78();
      func_0212a4bc();
      piVar1 = piRam021293a0;
      *(undefined4 *)(*piRam021293a0 + 0x10) = 1;
      *(undefined4 *)(*piVar1 + 0x28) = 0;
      uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),7);
      TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar4,0,0,0,0,0,0);
      return;
    }
    *(undefined2 *)(iVar3 + 0x72) = 7;
  }
  return;
}

