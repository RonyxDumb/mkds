/* Decompiled C draft; module arm9_ov000; ROM address 0219d81c. No matching claim. */
#include "types.h"
#include "deps/0219d81c_FUN_0219d81c.h"

void FUN_0219d81c(void)

{
  int *piVar1;
  int iVar2;
  
  if (((*DAT_0219d8c0 != 0) && (*(int *)(*DAT_0219d8c0 + 0x18) != 0)) &&
     (iVar2 = FUN_0219c39c(), iVar2 == 0)) {
    iVar2 = FUN_0219caf4();
    if ((iVar2 != 0) && (iVar2 = FUN_0219746c(), iVar2 == 0)) {
      FUN_0219d734(6,DAT_0219d8c4);
      return;
    }
    if ((*(int **)(*DAT_0219d8c0 + 4) != (int *)0x0) && (**(int **)(*DAT_0219d8c0 + 4) != 0)) {
      FUN_0219d49c();
      iVar2 = FUN_0219d034();
      if (iVar2 != 0) {
        return;
      }
      iVar2 = *DAT_0219d8c0;
      if (((*(int *)(iVar2 + 0x18) != 0) && (*(byte *)(iVar2 + 0x1e) != 3)) &&
         (7 < *(uint *)(iVar2 + 8))) {
        if (*(byte *)(iVar2 + 0x1e) < 2) {
          FUN_0219d2e8(*(int *)(iVar2 + 0x18),*(undefined4 *)(iVar2 + 0x14));
        }
        piVar1 = DAT_0219d8c0;
        iVar2 = *DAT_0219d8c0;
        if (*(int *)(iVar2 + 0x14) <= (int)(uint)*(byte *)(iVar2 + 0x1c)) {
          *(undefined1 *)(iVar2 + 0x1e) = 3;
          *(char *)(*piVar1 + 0x1f) = *(char *)(*piVar1 + 0x1f) + '\x01';
        }
      }
    }
    if (1 < *(byte *)(*DAT_0219d8c0 + 0x1f)) {
      *(undefined1 *)(*DAT_0219d8c0 + 0x1f) = 0;
      FUN_0219d2c4();
    }
  }
  return;
}

