/* Decompiled C draft; module arm9_ov000; ROM address 021a1b2c. No matching claim. */
#include "types.h"
#include "deps/021a1b2c_FUN_021a1b2c.h"

void FUN_021a1b2c(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 auStack_20 [16];
  
  iVar5 = *DAT_021a1c84;
  if ((iVar5 != 0) &&
     ((*(int *)(iVar5 + DAT_021a1c88) == 7 || (*(int *)(iVar5 + DAT_021a1c88) == 0xc)))) {
    if (param_2 == 0) {
      iVar5 = FUN_0219b998();
      if (iVar5 == -1) {
        FUN_021a1a38(6,DAT_021a1ca0);
      }
      puVar3 = (undefined4 *)FUN_0219b958(iVar5);
      puVar4 = (undefined1 *)FUN_0219b8f0(iVar5);
      *puVar3 = param_1;
      piVar1 = DAT_021a1c84;
      *(char *)(*DAT_021a1c84 + 0xd) = *(char *)(*DAT_021a1c84 + 0xd) + '\x01';
      *puVar4 = (char)iVar5;
      *(undefined2 *)(puVar4 + 2) = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
      puVar4[1] = *(undefined1 *)(*piVar1 + (uint)*(byte *)(*piVar1 + 0xd) + DAT_021a1ca4);
      FUN_021988a4(param_1);
      if (*(int *)(*DAT_021a1c84 + DAT_021a1c88) == 0xc) {
        FUN_0219f544(0);
        return;
      }
      FUN_0219f544(1);
    }
    else if (param_2 != 5) {
      if (param_2 != 6) {
        if (param_2 != 2) {
          FUN_0219e3e4(param_2);
          return;
        }
        FUN_0219f9bc(*(undefined4 *)
                      (*DAT_021a1c84 + (*(byte *)(*DAT_021a1c84 + 0xd) + 1) * 4 + 0xf4));
        return;
      }
      *(char *)(iVar5 + 0xc) = *(char *)(iVar5 + 0xc) + '\x01';
      piVar1 = DAT_021a1c84;
      iVar5 = *DAT_021a1c84;
      if (*(byte *)(iVar5 + 0xc) < 6) {
        func_0x0200d9e0((undefined4)(uintptr_t)(auStack_20),0xc,DAT_021a1c8c,*(undefined4 *)(iVar5 + DAT_021a1c90));
        iVar5 = *DAT_021a1c84;
        uVar2 = FUN_0219a760(*(undefined4 *)
                              (iVar5 + (uint)*(byte *)(iVar5 + 0x14) * 4 + DAT_021a1c94),
                             *(undefined2 *)
                              (iVar5 + (uint)*(byte *)(iVar5 + 0x14) * 2 + DAT_021a1c98),0);
        FUN_02198968(**(undefined4 **)(*DAT_021a1c84 + 4),0,uVar2,(undefined4)(uintptr_t)(auStack_20),0xffffffff,DAT_021a1c9c
                     ,*(undefined4 *)(iVar5 + 8),0);
        FUN_0219e3e4();
        return;
      }
      *(undefined1 *)(iVar5 + 0xc) = 0;
      FUN_0219f9bc(*(undefined4 *)(*piVar1 + (*(byte *)(*piVar1 + 0xd) + 1) * 4 + 0xf4));
      return;
    }
  }
  return;
}

