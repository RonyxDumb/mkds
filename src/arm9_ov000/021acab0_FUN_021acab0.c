/* Decompiled C draft; module arm9_ov000; ROM address 021acab0. No matching claim. */
#include "types.h"
#include "deps/021acab0_FUN_021acab0.h"

void FUN_021acab0(int param_1,ushort *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ushort *local_24;
  ushort *local_20;
  int local_1c;
  
  iVar1 = thunk_FUN_021acecc((int)(uintptr_t)(param_2),param_3);
  if (iVar1 * 2 < param_3) {
    func_0x0214d168((uint *)(uintptr_t)(param_1 + iVar1 * 4),0,(param_3 + iVar1 * -2) * 2);
  }
  iVar5 = 0;
  if (0 < iVar1) {
    iVar4 = 0;
    puVar3 = param_2;
    do {
      if (param_3 <= iVar4) break;
      iVar2 = (uint)*puVar3 * (uint)*puVar3;
      *(short *)(param_1 + iVar4 * 2) = (short)iVar2;
      if (iVar4 == param_3 + -1) break;
      *(short *)(param_1 + (iVar4 + 1) * 2) = (short)((uint)iVar2 >> 0x10);
      iVar4 = iVar4 + 2;
      puVar3 = puVar3 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  local_1c = 0;
  local_24 = param_2;
  if (0 < iVar1) {
    do {
      iVar5 = local_1c + 1;
      local_20 = param_2 + iVar5;
      for (; (iVar5 < iVar1 && (iVar4 = local_1c + iVar5, iVar4 < param_3)); iVar5 = iVar5 + 1) {
        uVar6 = (uint)*local_24 * (uint)*local_20;
        if (uVar6 < DAT_021acb94 || uVar6 - DAT_021acb94 == 0) {
          FUN_021acc68(param_1,uVar6 * 2,iVar4,param_3);
        }
        else {
          FUN_021acc68(param_1,uVar6,iVar4,param_3);
          FUN_021acc68(param_1,uVar6,iVar4,param_3);
        }
        local_20 = local_20 + 1;
      }
      local_24 = local_24 + 1;
      local_1c = local_1c + 1;
    } while (local_1c < iVar1);
  }
  return;
}

