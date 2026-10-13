/* Decompiled C draft; module arm7; ROM address 037fd404. No matching claim. */
#include "types.h"
#include "deps/037fd404_FUN_037fd404.h"

bool FUN_037fd404(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  bVar2 = false;
  iVar5 = 0;
  do {
    iVar3 = FUN_037fe2e4(param_1,iVar5);
    if ((iVar3 != 0) &&
       (uVar1 = iVar3 + 0x28U & 3, uVar4 = *(uint *)(iVar3 + 0x28U & 0xfffffffc),
       uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0)) {
      iVar3 = FUN_037fd484((byte *)(uintptr_t)(iVar3),param_1,iVar5,param_2);
      if (iVar3 == 0) {
        bVar2 = true;
      }
      else {
        FUN_037fe270(param_1,iVar5);
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0x10);
  return !bVar2;
}

