/* Decompiled C draft; module arm9_ov003; ROM address 021d0acc. No matching claim. */
#include "types.h"
#include "deps/021d0acc_FUN_021d0acc.h"

void FUN_021d0acc(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int extraout_r1;
  char *pcVar3;
  int iVar4;
  
  uVar2 = FUN_021d010c();
  switch(uVar2) {
  case 1:
    FUN_021cfc4c(4,*(short *)(*DAT_021d0c38 + DAT_021d0c3c) + 1,
                 *(undefined2 *)(*DAT_021d0c38 + DAT_021d0c40));
    return;
  case 4:
  case 5:
  case 6:
    iVar4 = *DAT_021d0c38;
    uVar1 = *(undefined2 *)(iVar4 + DAT_021d0c44);
    func_0x02133068(uVar1,0x10);
    FUN_021d0900(0,uVar1,*(int *)(iVar4 + DAT_021d0c48) + extraout_r1 * 0x40);
    FUN_021d0850();
    pcVar3 = (char *)(*DAT_021d0c38 + DAT_021d0c4c);
    if (*pcVar3 != '\x1b') {
      if (DAT_021d0c54 < *(uint *)(*DAT_021d0c38 + DAT_021d0c50)) {
        *pcVar3 = '\x1b';
        return;
      }
      iVar4 = FUN_021d083c();
      if ((iVar4 == 0x10) || (iVar4 = FUN_021d083c(), iVar4 == 0x20)) {
        FUN_021d083c();
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 10;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0x40) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 0xb;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0xff) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 0x1b;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0x50) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 0x15;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0x60) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 0x18;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0x70) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 0x1b;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 8;
        return;
      }
      iVar4 = FUN_021d083c();
      if (iVar4 == 0xbd) {
        *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 9;
        return;
      }
      *(undefined1 *)(*DAT_021d0c38 + DAT_021d0c4c) = 0x1f;
    }
  }
  return;
}

