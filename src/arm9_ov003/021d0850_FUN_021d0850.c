/* Decompiled C draft; module arm9_ov003; ROM address 021d0850. No matching claim. */
#include "types.h"
#include "deps/021d0850_FUN_021d0850.h"

void FUN_021d0850(void)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = DAT_021d08e8;
  piVar1 = DAT_021d08e4;
  iVar6 = 0;
  iVar5 = 0;
  do {
    iVar4 = *piVar1;
    if ((*(int *)(iVar4 + iVar5 + DAT_021d08ec) != 0) &&
       (psVar3 = (short *)(iVar4 + DAT_021d08f0 + iVar6 * 0x44), iVar6 == 1)) {
      if (*(char *)(iVar4 + DAT_021d08f4) == '\x01') {
        if (*psVar3 != 0x10) {
          return;
        }
        *(int *)(iVar4 + DAT_021d08f8) = *(int *)(iVar4 + DAT_021d08f8) + 1;
        iVar4 = *piVar1;
        if ((*(uint *)(iVar4 + DAT_021d08f8) & 1) == 0) {
          *(short *)(iVar4 + iVar2) = *(short *)(iVar4 + iVar2) + 1;
          if (0x23 < *(ushort *)(*piVar1 + iVar2)) {
            *(undefined2 *)(*piVar1 + iVar2) = 0;
          }
        }
      }
      else {
        *(undefined2 *)(iVar4 + DAT_021d08fc) = 0xbc;
        if (*psVar3 == 0xbd) {
          *(undefined1 *)(*piVar1 + DAT_021d08f4) = 1;
          *(undefined2 *)(*piVar1 + iVar2) = 0;
          *(undefined4 *)(*piVar1 + DAT_021d08f8) = 0;
        }
      }
    }
    iVar5 = iVar5 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  return;
}

