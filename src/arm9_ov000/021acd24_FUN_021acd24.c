/* Decompiled C draft; module arm9_ov000; ROM address 021acd24. No matching claim. */
#include "types.h"
#include "deps/021acd24_FUN_021acd24.h"

void FUN_021acd24(ushort *param_1,ushort *param_2,ushort *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  
  iVar1 = thunk_FUN_021acecc((int)(uintptr_t)(param_2),param_4);
  iVar2 = thunk_FUN_021acecc((int)(uintptr_t)(param_3),param_4);
  if (iVar1 < iVar2) {
    iVar1 = iVar2;
  }
  if (iVar1 != param_4) {
    iVar1 = iVar1 + 1;
  }
  iVar3 = 0;
  puVar4 = param_1;
  puVar5 = param_2;
  puVar6 = param_3;
  for (iVar2 = 0; (iVar3 < iVar1 || ((iVar3 < param_4 && (iVar2 != 0)))); iVar2 = iVar2 >> 0x10) {
    iVar2 = iVar2 + ((uint)*puVar5 - (uint)*puVar6);
    *puVar4 = (ushort)iVar2;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + 1;
  }
  if ((param_1 != param_2) && (param_1 != param_3)) {
    func_0x0214d168((uint *)(void *)(param_1 + iVar3),0,(param_4 - iVar3) * 2);
  }
  return;
}

