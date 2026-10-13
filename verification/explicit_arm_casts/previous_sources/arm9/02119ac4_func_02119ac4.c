/* Decompiled C draft; module arm9; ROM address 02119ac4. No matching claim. */
#include "types.h"
#include "deps/02119ac4_func_02119ac4.h"

void func_02119ac4(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_210 [516];
  
  piVar1 = DAT_02119b94;
  *(undefined4 *)(*DAT_02119b94 + 0x38) = 5;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  iVar4 = *piVar1;
  switch(*(undefined4 *)(iVar4 + 0x40)) {
  case 0:
  case 1:
  case 3:
    uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar4 + 0x28),4);
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar4 + 0x28),2);
    func_021277f8(uVar2,uVar3,0);
    return;
  case 2:
    uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar4 + 0x28),4);
    uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar4 + 0x28),2);
    func_021277f8(uVar2,uVar3,0);
    if (*DAT_02119b98 == 2) {
      iVar4 = GetSelectedCup_from_thumb();
      uVar2 = Bmg_GetRawStringPointer_from_thumb
                        (*(undefined4 *)(*DAT_02119b94 + 0x2c),
                         *(undefined2 *)
                          (*(short *)(*DAT_02119b94 + 0x50) * 2 +
                          DAT_02119ba0 + *(int *)(DAT_02119b9c + iVar4 * 4) * 8));
      uVar3 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02119b94 + 0x28),0x8b);
      MaybeHandleBmgFormatting_from_thumb(uVar2,uVar3,auStack_210,DAT_02119ba4);
      TextSystem_SetFadeInSseqId_from_thumb(0x23);
      func_021266e4(auStack_210);
    }
  }
  return;
}

