/* Decompiled C draft; module arm9; ROM address 0212913c. No matching claim. */
#include "types.h"
#include "deps/0212913c_Keyboard_SwitchFn9_from_thumb.h"

void Keyboard_SwitchFn9_from_thumb(void)

{
  short sVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  
  piVar2 = piRam021291c8;
  *(int *)(*piRam021291c8 + 0x28) = *(int *)(*piRam021291c8 + 0x28) + 1;
  sVar1 = psRam021291cc[2];
  uVar3 = ComputeValueInterpolation_from_thumb
                    (1,(int)*psRam021291cc,((int)*psRam021291cc - (0xc0 - sVar1)) * 0x10000 >> 0x10,
                     *(undefined4 *)(*piVar2 + 0x28),0xf);
  piVar2 = piRam021291c8;
  *(undefined2 *)(*piRam021291c8 + 0x86) = uVar3;
  uVar3 = ComputeValueInterpolation_from_thumb
                    (1,(int)*(short *)(iRam021291d0 + 4),(int)sVar1,*(undefined4 *)(*piVar2 + 0x28),
                     0xf);
  piVar2 = piRam021291c8;
  *(undefined2 *)(*piRam021291c8 + 0x8a) = uVar3;
  if (0xe < *(int *)(*piVar2 + 0x28)) {
    *(undefined4 *)(*piVar2 + 0x28) = 0xf;
  }
  if ((0xe < *(int *)(*piRam021291c8 + 0x28)) &&
     (iVar4 = TextSystem_IsDialogIdle_from_thumb(), piVar2 = piRam021291c8, iVar4 != 0)) {
    *(undefined4 *)(*piRam021291c8 + 0x10) = 10;
    *(undefined4 *)(*piVar2 + 0x28) = 0;
  }
  return;
}

