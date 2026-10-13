/* Decompiled C draft; module arm9; ROM address 0212a670. No matching claim. */
#include "types.h"
#include "deps/0212a670_func_0212a670.h"

void func_0212a670(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int local_18;
  
  iVar3 = 0;
  local_18 = 0;
  iVar2 = 0;
  puVar4 = puRam0212a6f8;
  do {
    iVar5 = *piRam0212a6fc;
    uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar5 + 0xc0),4);
    func_0212426c(1,*puVar4,*(undefined4 *)(*piRam0212a6fc + iVar2 + 0xac),uVar1,
                  *(undefined4 *)(iVar5 + iVar2 + 0x9c),*(undefined4 *)(iVar5 + iVar3 + 0x78));
    iVar5 = *piRam0212a6fc;
    uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar5 + 0xc0),5);
    func_0212426c(1,puVar4[1],*(undefined4 *)(*piRam0212a6fc + iVar2 + 0xac),uVar1,
                  *(undefined4 *)(iVar5 + iVar2 + 0x9c),*(undefined4 *)(iVar5 + iVar3 + 0x78));
    iVar3 = iVar3 + 8;
    iVar2 = iVar2 + 4;
    puVar4 = puVar4 + 2;
    local_18 = local_18 + 1;
  } while (local_18 < 2);
  return;
}

