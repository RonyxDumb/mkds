/* Decompiled C draft; module arm9; ROM address 021295f4. No matching claim. */
#include "types.h"
#include "deps/021295f4_Keyboard_SwitchFn6_from_thumb.h"

void Keyboard_SwitchFn6_from_thumb(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  
  piVar1 = piRam021296a8;
  *(int *)(*piRam021296a8 + 0x28) = *(int *)(*piRam021296a8 + 0x28) + 1;
  uVar2 = ComputeValueInterpolation_from_thumb(1,0xc0,0,*(undefined4 *)(*piVar1 + 0x28),0xf);
  piVar1 = piRam021296a8;
  *(undefined2 *)(*piRam021296a8 + 0x84) = uVar2;
  uVar2 = ComputeValueInterpolation_from_thumb
                    (1,(int)psRam021296ac[3],(int)psRam021296b0[3],*(undefined4 *)(*piVar1 + 0x28),
                     0xf);
  *(undefined2 *)(*piVar1 + 0x8c) = uVar2;
  if (*(int *)(*piVar1 + 0x6c) != 0) {
    uVar2 = ComputeValueInterpolation_from_thumb
                      (1,(int)*psRam021296ac,(int)*psRam021296b0,*(undefined4 *)(*piVar1 + 0x28),0xf
                      );
    *(undefined2 *)(*piRam021296a8 + 0x86) = uVar2;
  }
  if (0xe < *(int *)(*piRam021296a8 + 0x28)) {
    *(undefined4 *)(*piRam021296a8 + 0x28) = 0xf;
  }
  if ((0xe < *(int *)(*piRam021296a8 + 0x28)) &&
     (iVar3 = TextSystem_IsDialogIdle_from_thumb(), piVar1 = piRam021296a8, iVar3 != 0)) {
    *(undefined4 *)(*piRam021296a8 + 0x10) = 7;
    *(undefined4 *)(*piVar1 + 0x24) = 1;
    *(undefined4 *)(*piVar1 + 0x28) = 0;
  }
  func_021296b4();
  func_02128b0c();
  return;
}

