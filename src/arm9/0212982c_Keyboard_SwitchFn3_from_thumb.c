/* Decompiled C draft; module arm9; ROM address 0212982c. No matching claim. */
#include "types.h"
#include "deps/0212982c_Keyboard_SwitchFn3_from_thumb.h"

void Keyboard_SwitchFn3_from_thumb(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = piRam02129980;
  *(int *)(*piRam02129980 + 0x28) = *(int *)(*piRam02129980 + 0x28) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0,0xc0,*(undefined4 *)(*piVar1 + 0x28),0xf);
  piVar1 = piRam02129980;
  *(undefined2 *)(*piRam02129980 + 0x84) = uVar2;
  uVar2 = ComputeValueInterpolation_from_thumb
                    (1,(int)*(short *)(iRam02129984 + 2),(int)*(short *)(iRam02129988 + 2),
                     *(undefined4 *)(*piVar1 + 0x28),0xf);
  *(undefined2 *)(*piVar1 + 0x88) = uVar2;
  if (0xe < *(int *)(*piVar1 + 0x28)) {
    *(undefined4 *)(*piVar1 + 0x28) = 0xf;
  }
  if ((0xe < *(int *)(*piRam02129980 + 0x28)) &&
     (iVar3 = TextSystem_IsDialogFinished_from_thumb(), iVar3 != 0)) {
    if (*(int *)(*piRam02129980 + 0x6c) != 0) {
      func_0212a410();
      iVar3 = CheckFriendCode(*piRam02129980 + 0x5c);
      piVar1 = piRam02129980;
      if (iVar3 == 1) {
        *(undefined4 *)(*piRam02129980 + 0x10) = 4;
        Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),10);
        TextSystem_DisplayProgressDialog_Simple_from_thumb();
        *(undefined4 *)(*piRam02129980 + 0x28) = 0;
        return;
      }
      if (iVar3 != 2) {
        *(undefined4 *)(*piRam02129980 + 0x10) = 6;
        uVar4 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),8);
        TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar4,0,0,0,0,0,0);
        piVar1 = piRam02129980;
        *(undefined4 *)(*piRam02129980 + 0x28) = 0;
        *(undefined4 *)(*piVar1 + 4) = 1;
        if (*(int *)*puRam0212998c == 0) {
          *(undefined4 *)(*piVar1 + 8) = 1;
        }
        else {
          *(undefined4 *)(*piVar1 + 8) = 2;
        }
        func_020ab9d0(*(undefined4 *)(*piRam02129980 + 8));
        func_020ab758(*(undefined1 *)(iRam02129990 + 1));
        func_0212a484();
        func_02129e78();
        func_02128b0c();
        return;
      }
      *(undefined4 *)(*piRam02129980 + 0x10) = 4;
      Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0xc0),0xb);
      TextSystem_DisplayProgressDialog_Simple_from_thumb();
      *(undefined4 *)(*piRam02129980 + 0x28) = 0;
      return;
    }
    *(undefined2 *)(*piRam02129980 + 0x72) = 0xc;
  }
  return;
}

