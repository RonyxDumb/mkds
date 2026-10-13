/* Decompiled C draft; module arm9_ov001; ROM address 0219c80c. No matching claim. */
#include "types.h"
#include "deps/0219c80c_FUN_0219c80c.h"

undefined4 FUN_0219c80c(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = DAT_0219c8b0;
  *(undefined4 *)*DAT_0219c8b0 = ((undefined4 *)*DAT_0219c8b0)[1];
  switch(*(undefined4 *)*piVar1) {
  case 0:
    FUN_0219cdd4();
    break;
  case 1:
    FUN_0219cdb4();
    break;
  case 2:
    FUN_0219cba0();
    break;
  case 3:
    FUN_0219caf4();
    break;
  case 4:
    FUN_0219ca94();
    break;
  case 5:
    FUN_0219ca2c();
    break;
  case 6:
    FUN_0219c950();
  }
  FUN_0219c8c8();
  FUN_0219c8ec();
  FUN_0219cec4();
  FUN_0219cf60();
  iVar2 = DAT_0219c8b4;
  piVar1 = DAT_0219c8b0;
  iVar5 = 0;
  iVar4 = 0;
  do {
    iVar3 = *piVar1 + iVar4;
    func_0x02124c30(*(undefined4 *)(iVar3 + DAT_0219c8bc),*(undefined4 *)(iVar3 + DAT_0219c8c0),
                    *(undefined4 *)(iVar3 + DAT_0219c8c4),*(undefined4 *)(iVar3 + iVar2),
                    *(undefined4 *)(iVar3 + DAT_0219c8b8));
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return *(undefined4 *)(*DAT_0219c8b0 + 0x24);
}

