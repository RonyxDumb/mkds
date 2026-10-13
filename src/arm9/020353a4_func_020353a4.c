/* Decompiled C draft; module arm9; ROM address 020353a4. No matching claim. */
#include "types.h"
#include "deps/020353a4_func_020353a4.h"

void func_020353a4(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam020353f4 + 0x88),0x11);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam020353f4 + 0x84),4);
  TextSystem_SetButtonPressSseqId_from_thumb(0,5);
  TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar2,uVar3);
  piVar1 = piRam020353f4;
  *(undefined4 *)(*piRam020353f4 + 0x90) = 0;
  *(undefined4 *)(*piVar1 + 0x94) = 0xf;
  return;
}

