/* Decompiled C draft; module arm9; ROM address 02033d9c. No matching claim. */
#include "types.h"
#include "deps/02033d9c_func_02033d9c.h"

void func_02033d9c(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02033dcc + 200),0x5d);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02033dcc + 200),0x5f);
  func_021277f8(uVar1,uVar2,0);
  return;
}

