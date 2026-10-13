/* Decompiled C draft; module arm9; ROM address 0211d910. No matching claim. */
#include "types.h"
#include "deps/0211d910_func_0211d910.h"

void func_0211d910(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_10c [128];
  undefined1 auStack_8c [132];
  
  piVar1 = piRam0211d9d0;
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (10 < param_1) {
    param_1 = 10;
  }
  *(short *)(*piRam0211d9d0 + 0x88) = (short)param_1;
  func_02124f4c((int)*(short *)(*piVar1 + 0x88),(int)(uintptr_t)(auStack_8c));
  if (*(int *)(*piRam0211d9d4 + 0x20) != 2) {
    iVar3 = *piRam0211d9d0;
    uVar2 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(iVar3 + 0x1c),**(undefined2 **)(iRam0211d9d8 + 0xc));
    func_0212426c(1,9,*(undefined4 *)(*piRam0211d9d0 + 0xc),uVar2,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x14));
    iVar3 = *piRam0211d9d0;
    func_02124248(1,8,*(undefined4 *)(iVar3 + 0xc),auStack_8c,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x14),0xb);
    return;
  }
  func_02124f4c((int)*(short *)(*piRam0211d9d0 + 0x88),(int)(uintptr_t)(auStack_10c));
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0211d9d0 + 0x1c),0x16);
  MaybeHandleBmgFormatting_from_thumb(auStack_10c,uVar2,auStack_8c,0x80);
  iVar3 = *piRam0211d9d0;
  func_0212426c(1,10,*(undefined4 *)(iVar3 + 0xc),auStack_8c,*(undefined4 *)(iVar3 + 4),
                *(undefined4 *)(iVar3 + 0x14));
  return;
}

