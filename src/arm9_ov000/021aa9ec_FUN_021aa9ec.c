/* Decompiled C draft; module arm9_ov000; ROM address 021aa9ec. No matching claim. */
#include "types.h"
#include "deps/021aa9ec_FUN_021aa9ec.h"

void FUN_021aa9ec(undefined4 *param_1,undefined1 *param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  iVar3 = FUN_021aaaec(*param_2,param_2[1]);
  if (iVar3 != 0) {
    func_0x0214d1fc((ushort *)(void *)(param_2 + 2),param_1 + 2,0x20);
    bVar1 = param_2[0x22];
    if (bVar1 == 0x20) {
      uVar4 = FUN_021ab684((undefined4)(uintptr_t)(param_2 + 0x23));
      *param_1 = uVar4;
    }
    else {
      *param_1 = 0;
    }
    pbVar5 = param_2 + 0x23 + bVar1;
    uVar4 = func_0x02133068((uint)*pbVar5 * 0x100 + (uint)pbVar5[1],2);
    sVar2 = FUN_021aaaf8((undefined4)(uintptr_t)(pbVar5 + 2),uVar4,2);
    *(short *)((int)param_1 + 6) = sVar2;
    if (sVar2 != 0) {
      *(undefined1 *)((int)param_1 + DAT_021aaa54) = 1;
    }
  }
  return;
}

