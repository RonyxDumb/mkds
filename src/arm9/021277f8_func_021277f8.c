/* Decompiled C draft; module arm9; ROM address 021277f8. No matching claim. */
#include "types.h"
#include "deps/021277f8_func_021277f8.h"

void func_021277f8(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  (**(code **)(*piRam021278ac + iRam021278b0 + 0x18))(*piRam021278ac + iRam021278b0,5);
  (**(code **)(*piRam021278ac + iRam021278b4 + 0x18))(*piRam021278ac + iRam021278b4,5);
  G2d_Text_SomeFn_from_thumb
            (*piRam021278ac + iRam021278bc,0x28,0,0xd8,0x10,0xc,uRam021278b8,1,param_1);
  G2d_Text_SomeFn_from_thumb
            (*piRam021278ac + iRam021278c0,0x28,0,0xd8,0x10,0xc,uRam021278b8,1,param_2);
  func_021281b4();
  *(undefined4 *)(*piRam021278ac + iRam021278c4) = 1;
  func_021278c8();
  if (param_3 == 0) {
    *(undefined4 *)(*piRam021278ac + 0x18) = 0;
  }
  else {
    *(undefined4 *)(*piRam021278ac + 0x18) = 1;
  }
  SelectChoisesContext_UpdateGraphics_from_thumb();
  piVar1 = piRam021278ac;
  *(undefined4 *)(*piRam021278ac + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 1;
  return;
}

