/* Decompiled C draft; module arm9_ov003; ROM address 021d0900. No matching claim. */
#include "types.h"
#include "deps/021d0900_FUN_021d0900.h"

void FUN_021d0900(undefined2 param_1,undefined2 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = DAT_021d0a00;
  piVar1 = DAT_021d09f8;
  iVar3 = *DAT_021d09f8;
  if (*(char *)(iVar3 + DAT_021d09fc) == '\x01') {
    **(undefined2 **)(iVar3 + DAT_021d0a00) = param_1;
    *(undefined2 *)(*(int *)(*piVar1 + iVar2) + 2) = param_2;
    func_0x0214d1fc(param_3,*(int *)(*piVar1 + iVar2) + 4,0x40);
  }
  else {
    *(int *)(iVar3 + DAT_021d0a04) = *(int *)(iVar3 + DAT_021d0a04) + 1;
    iVar2 = DAT_021d0a00;
    **(undefined2 **)(*piVar1 + DAT_021d0a00) = 0xbc;
    *(undefined1 *)(*(int *)(*piVar1 + iVar2) + 4) = *(undefined1 *)(*piVar1 + DAT_021d0a08);
  }
  iVar2 = FUN_021d010c();
  if (iVar2 == 5) {
    iVar2 = FUN_021cfb98(*DAT_021d09f8);
    if (iVar2 == 0) {
      *(int *)(*DAT_021d09f8 + DAT_021d0a04) = *(int *)(*DAT_021d09f8 + DAT_021d0a04) + 4;
      return;
    }
    iVar2 = *DAT_021d09f8;
    if (*(char *)(iVar2 + DAT_021d09fc) == '\0') {
      *(int *)(iVar2 + DAT_021d0a04) = *(int *)(iVar2 + DAT_021d0a04) + 1;
    }
    else {
      *(undefined4 *)(iVar2 + DAT_021d0a04) = 0;
      iVar2 = FUN_021d0118();
      if (iVar2 != 3) {
        *(undefined1 *)(*DAT_021d09f8 + DAT_021d0a0c) = 0x1b;
        return;
      }
    }
    iVar2 = DAT_021d0a10;
    piVar1 = DAT_021d09f8;
    uVar4 = 0;
    do {
      iVar3 = FUN_021cfc1c(uVar4);
      if (iVar3 == 0) {
        *(undefined4 *)(*piVar1 + uVar4 * 4 + iVar2) = 0;
      }
      else {
        func_0x0214d1fc(iVar3,*piVar1 + DAT_021d0a14 + uVar4 * 0x44,0x44);
        *(undefined4 *)(*piVar1 + uVar4 * 4 + iVar2) = 1;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 2);
  }
  return;
}

