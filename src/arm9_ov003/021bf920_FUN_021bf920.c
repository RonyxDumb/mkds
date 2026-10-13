/* Decompiled C draft; module arm9_ov003; ROM address 021bf920. No matching claim. */
#include "types.h"
#include "deps/021bf920_FUN_021bf920.h"

void FUN_021bf920(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar1 = *DAT_021bf994;
  *DAT_021bf994 = 0;
  iVar3 = func_0x02143280();
  if (iVar3 != DAT_021bf998) {
    iVar4 = func_0x021431d8();
  }
  *DAT_021bf994 = uVar1;
  FUN_021d1c3c(0,*(undefined1 *)
                  (iVar4 + DAT_021bf9a0 + *(char *)((undefined4 *)*DAT_021bf99c + 2) * 4),
               *(undefined4 *)*DAT_021bf99c);
  piVar2 = DAT_021bf99c;
  **(uint **)*DAT_021bf99c =
       (*DAT_021bf9a4 & DAT_021bf9a8) << 0x10 |
       **(uint **)*DAT_021bf99c & DAT_021bf9ac | DAT_021bf9a4[1] & 0xff;
  *(ushort *)(*(int *)*piVar2 + 4) =
       *(ushort *)(*(int *)*piVar2 + 4) & (ushort)DAT_021bf9b0 | (ushort)DAT_021bf9b4;
  return;
}

