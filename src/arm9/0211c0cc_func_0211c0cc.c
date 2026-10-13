/* Decompiled C draft; module arm9; ROM address 0211c0cc. No matching claim. */
#include "types.h"
#include "deps/0211c0cc_func_0211c0cc.h"

void func_0211c0cc(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = piRam0211c148;
  if (*(int *)(*piRam0211c144 + 0x20) == 2) {
    *(undefined4 *)
     (*(int *)(*piRam0211c148 + 0x14) + (*(ushort *)(*(int *)(*piRam0211c148 + 4) + 6) + 0xe) * 0x40
     ) = 1;
    iVar3 = *piVar1;
    if (*(int *)(iVar3 + 0x78) == 2) {
      uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar3 + 0x1c),0x15);
      func_0212426c(1,0xe,*(undefined4 *)(*piRam0211c148 + 0xc),uVar2,*(undefined4 *)(iVar3 + 4),
                    *(undefined4 *)(iVar3 + 0x14));
      return;
    }
    uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar3 + 0x1c),0x14);
    func_0212426c(1,0xe,*(undefined4 *)(*piRam0211c148 + 0xc),uVar2,*(undefined4 *)(iVar3 + 4),
                  *(undefined4 *)(iVar3 + 0x14));
  }
  return;
}

