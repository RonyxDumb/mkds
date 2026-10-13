/* Decompiled C draft; module arm9; ROM address 02129acc. No matching claim. */
#include "types.h"
#include "deps/02129acc_Keyboard_SwitchFn1_from_thumb.h"

void Keyboard_SwitchFn1_from_thumb(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = piRam02129b54;
  *(int *)(*piRam02129b54 + 0x28) = *(int *)(*piRam02129b54 + 0x28) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0xc0,0,*(undefined4 *)(*piVar1 + 0x28),0xf);
  piVar1 = piRam02129b54;
  *(undefined2 *)(*piRam02129b54 + 0x84) = uVar2;
  uVar2 = ComputeValueInterpolation_from_thumb
                    (1,(int)*(short *)(iRam02129b58 + 2),(int)*(short *)(iRam02129b5c + 2),
                     *(undefined4 *)(*piVar1 + 0x28),0xf);
  *(undefined2 *)(*piVar1 + 0x88) = uVar2;
  if (0xe < *(int *)(*piVar1 + 0x28)) {
    *(undefined4 *)(*piVar1 + 0x28) = 0xf;
  }
  if ((0xe < *(int *)(*piRam02129b54 + 0x28)) &&
     (iVar3 = TextSystem_IsDialogIdle_from_thumb(), piVar1 = piRam02129b54, iVar3 != 0)) {
    *(undefined4 *)(*piRam02129b54 + 0x10) = 2;
    *(undefined4 *)(*piVar1 + 0x24) = 1;
    *(undefined4 *)(*piVar1 + 0x28) = 0;
  }
  func_02129b60();
  return;
}

