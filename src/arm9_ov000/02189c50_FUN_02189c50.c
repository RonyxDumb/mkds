/* Decompiled C draft; module arm9_ov000; ROM address 02189c50. No matching claim. */
#include "types.h"
#include "deps/02189c50_FUN_02189c50.h"

undefined4 FUN_02189c50(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar4 = func_0x0200f5ac();
  lVar4 = lVar4 - CONCAT44(*(undefined4 *)(param_1 + DAT_02189cc0),
                           *(undefined4 *)(param_1 + DAT_02189cbc));
  uVar3 = (uint)lVar4;
  uVar5 = func_0x02132e40(uVar3 * 0x40,(int)((ulonglong)lVar4 >> 0x20) * 0x40 | uVar3 >> 0x1a,
                          DAT_02189cc4,0);
  iVar1 = DAT_02189ccc;
  uVar3 = (uint)((ulonglong)uVar5 >> 0x20);
  if (uVar3 != 0 || uVar3 < (DAT_02189cc8 <= (uint)uVar5)) {
    *(char *)(param_1 + DAT_02189ccc) = *(char *)(param_1 + DAT_02189ccc) + '\x02';
    if ('\f' < *(char *)(param_1 + iVar1)) {
      uVar2 = FUN_02189998(param_1,3);
      return uVar2;
    }
    uVar5 = func_0x0200f5ac();
    *(int *)(param_1 + DAT_02189cbc) = (int)uVar5;
    *(int *)(param_1 + DAT_02189cc0) = (int)((ulonglong)uVar5 >> 0x20);
    FUN_02189868(DAT_02189cd0,DAT_02189cd4,(int)*(char *)(param_1 + DAT_02189ccc),DAT_02189cd8);
  }
  return 3;
}

