/* Decompiled C draft; module arm9_ov000; ROM address 02189b28. No matching claim. */
#include "types.h"
#include "deps/02189b28_FUN_02189b28.h"

undefined4 FUN_02189b28(int param_1)

{
  undefined4 uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  lVar5 = func_0x0200f5ac();
  lVar5 = lVar5 - CONCAT44(*(undefined4 *)(param_1 + DAT_02189be0),
                           *(undefined4 *)(param_1 + DAT_02189bdc));
  uVar4 = (uint)lVar5;
  uVar6 = func_0x02132e40(uVar4 * 0x40,(int)((ulonglong)lVar5 >> 0x20) * 0x40 | uVar4 >> 0x1a,
                          DAT_02189be4,0);
  uVar4 = (uint)((ulonglong)uVar6 >> 0x20);
  if ((uVar4 != 0 || uVar4 < (0x95 < (uint)uVar6)) ||
     ((*(byte *)(param_1 + (uint)*(byte *)(param_1 + DAT_02189be8) * 0x24 + DAT_02189bec) & 0xf) ==
      1)) {
    pbVar2 = (byte *)(param_1 + DAT_02189be8);
    *(byte *)(param_1 + DAT_02189bec + (uint)*pbVar2 * 0x24) =
         *(byte *)(param_1 + DAT_02189bec + (uint)*pbVar2 * 0x24) & 0xf0;
    *pbVar2 = *pbVar2 + 1;
    if (*(byte *)(param_1 + DAT_02189bf0) <= *pbVar2) {
      *pbVar2 = 0;
      uVar1 = FUN_02189998(param_1,4);
      return uVar1;
    }
    uVar6 = func_0x0200f5ac();
    *(int *)(param_1 + DAT_02189bdc) = (int)uVar6;
    *(int *)(param_1 + DAT_02189be0) = (int)((ulonglong)uVar6 >> 0x20);
    iVar3 = (uint)*(byte *)(param_1 + DAT_02189be8) * 0x24;
    FUN_02189868(data_ov000_02189bf4,param_1 + DAT_02189bf8 + iVar3,
                 *(undefined1 *)(param_1 + iVar3 + DAT_02189bfc),DAT_02189c00);
  }
  return 4;
}

