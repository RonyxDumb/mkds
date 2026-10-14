/* Decompiled C draft; module arm9; ROM address 02035c14. No matching claim. */
#include "types.h"
#include "deps/02035c14_func_02035c14.h"

void func_02035c14(void)

{
  undefined4 uVar1;
  
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02035c4c + 0x88),3);
  TextSystem_SetSomeValues_from_thumb(0xfffffff4,0);
  TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar1,0,0,0,0,0,0);
  return;
}

