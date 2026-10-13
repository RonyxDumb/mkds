/* Decompiled C draft; module arm9; ROM address 020351c8. No matching claim. */
#include "types.h"
#include "deps/020351c8_func_020351c8.h"

void func_020351c8(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035224 + 0x88),8);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035224 + 0x84),0);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035224 + 0x84),1);
  TextSystem_SetButtonPressSseqId_from_thumb(0,5);
  TextSystem_DisplayDoubleButtonDialog_from_thumb(uVar1,uVar2,uVar3,0,0,1,1,0);
  return;
}

