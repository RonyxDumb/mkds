/* Decompiled C draft; module arm9_ov000; ROM address 021aaa58. No matching claim. */
#include "types.h"
#include "deps/021aaa58_FUN_021aaa58.h"

void FUN_021aaa58(undefined4 *param_1,undefined1 *param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  iVar4 = FUN_021aaaec(*param_2,param_2[1]);
  if (iVar4 != 0) {
    iVar4 = (uint)(byte)param_2[2] * 0x100 + (uint)(byte)param_2[3];
    uVar5 = func_0x02133068(iVar4,3);
    sVar3 = FUN_021aaaf8(param_2 + 8,uVar5,3);
    if (sVar3 != 0) {
      *(short *)((int)param_1 + 6) = sVar3;
      bVar1 = param_2[4];
      bVar2 = param_2[5];
      uVar6 = (uint)(byte)param_2[6] * 0x100 + (uint)(byte)param_2[7];
      *param_1 = 0;
      if (uVar6 < 0x20) {
        func_0x0214d168(param_1 + 2,0,0x20 - uVar6);
        func_0x0214d1fc(param_2 + iVar4 + 8 + (uint)bVar1 * 0x100 + (uint)bVar2,
                        (int)param_1 + (0x28 - uVar6),uVar6);
      }
      else {
        func_0x0214d1fc(param_2 + iVar4 + 8 + (uint)bVar1 * 0x100 + (uint)bVar2,param_1 + 2,0x20);
      }
      *(undefined1 *)((int)param_1 + DAT_021aaae8) = 1;
    }
  }
  return;
}

