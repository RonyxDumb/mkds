/* Decompiled C draft; module arm9; ROM address 0202d5f8. No matching claim. */
#include "types.h"
#include "deps/0202d5f8_func_0202d5f8.h"

void func_0202d5f8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined1 auStack_228 [20];
  undefined2 local_214;
  undefined1 auStack_212 [518];
  
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202d66c + 0xac),param_1);
  CopyMemory16(*piRam0202d66c + 0xb8,auStack_228,0x14);
  local_214 = 0;
  MaybeHandleBmgFormatting_from_thumb(auStack_228,uVar1,auStack_212,uRam0202d670);
  if (param_2 != 0) {
    uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202d66c + 0xa8),4);
    TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(auStack_212,uVar1);
    return;
  }
  TextSystem_DisplayProgressDialog_Simple_from_thumb(auStack_212);
  return;
}

