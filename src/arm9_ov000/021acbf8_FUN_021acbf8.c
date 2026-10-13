/* Decompiled C draft; module arm9_ov000; ROM address 021acbf8. No matching claim. */
#include "types.h"
#include "deps/021acbf8_FUN_021acbf8.h"

void FUN_021acbf8(undefined4 param_1,ushort *param_2,ushort *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int local_18;
  
  func_0x0214d168((uint *)(uintptr_t)(param_1),0,param_4 << 1);
  iVar1 = thunk_FUN_021acecc((int)(uintptr_t)(param_2),param_4);
  iVar2 = thunk_FUN_021acecc((int)(uintptr_t)(param_3),param_4);
  iVar5 = 0;
  if (0 < iVar2) {
    local_18 = 0;
    do {
      puVar3 = param_2;
      for (iVar4 = local_18; (iVar4 < iVar1 && (iVar4 < param_4 - iVar5)); iVar4 = iVar4 + 1) {
        FUN_021acc68(param_1,(uint)*param_3 * (uint)*puVar3,iVar5 + iVar4,param_4);
        puVar3 = puVar3 + 1;
      }
      param_3 = param_3 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  return;
}

