/* Decompiled C draft; module arm9; ROM address 0211ba1c. No matching claim. */
#include "types.h"
#include "deps/0211ba1c_func_0211ba1c.h"

void func_0211ba1c(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  piVar1 = piRam0211ba54;
  *(undefined4 *)(*piRam0211ba54 + 0x34) = 5;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0x18),4);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0211ba54 + 0x18),2);
  func_021277f8(uVar2,uVar3,0);
  return;
}

