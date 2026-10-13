/* Decompiled C draft; module arm9_ov000; ROM address 02189a28. No matching claim. */
#include "types.h"
#include "deps/02189a28_FUN_02189a28.h"

undefined4 FUN_02189a28(int param_1)

{
  undefined1 uVar1;
  byte *pbVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  lVar6 = func_0x0200f5ac();
  lVar6 = lVar6 - CONCAT44(*(undefined4 *)(param_1 + DAT_02189b00),
                           *(undefined4 *)(param_1 + DAT_02189afc));
  uVar5 = (uint)lVar6;
  uVar7 = func_0x02132e40(uVar5 * 0x40,(int)((ulonglong)lVar6 >> 0x20) * 0x40 | uVar5 >> 0x1a,
                          DAT_02189b04,0);
  uVar5 = (uint)((ulonglong)uVar7 >> 0x20);
  if ((uVar5 != 0 || uVar5 < (0x95 < (uint)uVar7)) ||
     ((*(byte *)(param_1 + (uint)*(byte *)(param_1 + DAT_02189b08) * 0x24 + DAT_02189b0c) & 0xf) ==
      1)) {
    pbVar2 = (byte *)(param_1 + DAT_02189b08);
    *(byte *)(param_1 + DAT_02189b0c + (uint)*pbVar2 * 0x24) =
         *(byte *)(param_1 + DAT_02189b0c + (uint)*pbVar2 * 0x24) & 0xf0;
    *pbVar2 = *pbVar2 + 1;
    if (*(byte *)(param_1 + DAT_02189b10) == *pbVar2) {
      pcVar4 = (char *)(param_1 + DAT_02189b14);
      *pcVar4 = *pcVar4 + '\x01';
      *pbVar2 = 0;
      uVar1 = FUN_02189df8(*pcVar4);
      *(undefined1 *)(param_1 + DAT_02189b18) = uVar1;
    }
    if (*(char *)(param_1 + DAT_02189b18) < '\0') {
      *(undefined1 *)(param_1 + DAT_02189b14) = 0;
      uVar3 = FUN_02189998(param_1,5);
      return uVar3;
    }
    uVar7 = func_0x0200f5ac();
    *(int *)(param_1 + DAT_02189afc) = (int)uVar7;
    *(int *)(param_1 + DAT_02189b00) = (int)((ulonglong)uVar7 >> 0x20);
    FUN_02189868(DAT_02189b1c,
                 param_1 + DAT_02189b20 + (uint)*(byte *)(param_1 + DAT_02189b08) * 0x24,
                 (int)*(char *)(param_1 + DAT_02189b18),DAT_02189b24);
  }
  return 5;
}

