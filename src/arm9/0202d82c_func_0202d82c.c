/* Decompiled C draft; module arm9; ROM address 0202d82c. No matching claim. */
#include "types.h"
#include "deps/0202d82c_func_0202d82c.h"

void func_0202d82c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202d864 + 0xac),0xd);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0202d864 + 0xa8),4);
  *(undefined4 *)(*piRam0202d864 + 0xb0) = 8;
  TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar1,uVar2);
  return;
}

