/* Decompiled C draft; module arm9; ROM address 0211d844. No matching claim. */
#include "types.h"
#include "deps/0211d844_func_0211d844.h"

void func_0211d844(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_10c [128];
  undefined1 auStack_8c [132];
  
  piVar1 = piRam0211d904;
  if (param_1 < 1) {
    param_1 = 1;
  }
  if (0x20 < param_1) {
    param_1 = 0x20;
  }
  *(short *)(*piRam0211d904 + 0x8a) = (short)param_1;
  func_02124f4c((int)*(short *)(*piVar1 + 0x8a),auStack_8c);
  if (*(int *)(*piRam0211d908 + 0x20) != 2) {
    iVar3 = *piRam0211d904;
    uVar2 = Bmg_GetRawStringPointer_from_thumb
                      (*(undefined4 *)(iVar3 + 0x1c),
                       *(undefined2 *)(*(int *)(iRam0211d90c + 0xc) + 2));
    func_0212426c(1,9,*(undefined4 *)(*piRam0211d904 + 0xc),uVar2,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x14));
    iVar3 = *piRam0211d904;
    func_02124248(1,8,*(undefined4 *)(iVar3 + 0xc),auStack_8c,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x14),0xb);
    return;
  }
  func_02124f4c((int)*(short *)(*piRam0211d904 + 0x8a),auStack_10c);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam0211d904 + 0x1c),0x17);
  MaybeHandleBmgFormatting_from_thumb(auStack_10c,uVar2,auStack_8c,0x80);
  iVar3 = *piRam0211d904;
  func_0212426c(1,10,*(undefined4 *)(iVar3 + 0xc),auStack_8c,*(undefined4 *)(iVar3 + 4),
                *(undefined4 *)(iVar3 + 0x14));
  return;
}

