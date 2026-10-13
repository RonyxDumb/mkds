/* Decompiled C draft; module arm9; ROM address 02118148. No matching claim. */
#include "types.h"
#include "deps/02118148_func_02118148.h"

void func_02118148(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  piVar1 = piRam02118180;
  *(undefined4 *)(*piRam02118180 + 0x34) = 5;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0x24),4);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02118180 + 0x24),2);
  func_021277f8(uVar2,uVar3,0);
  return;
}

