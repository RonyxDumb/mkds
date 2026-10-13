/* Decompiled C draft; module arm9; ROM address 02118088. No matching claim. */
#include "types.h"
#include "deps/02118088_func_02118088.h"

void func_02118088(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  piVar1 = piRam021180f0;
  *(undefined4 *)(*piRam021180f0 + 0x34) = 8;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  if (*psRam021180f4 == 2) {
    uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0x24),0x5d);
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam021180f0 + 0x24),0x5f);
    func_021277f8(uVar2,uVar3,0);
    return;
  }
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar1 + 0x28),0x14);
  uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam021180f0 + 0x28),0x15);
  func_021277f8(uVar2,uVar3,0);
  return;
}

