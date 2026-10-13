/* Decompiled C draft; module arm9; ROM address 02006e74. No matching claim. */
#include "types.h"
#include "deps/02006e74_StructGO_SomeFn_from_thumb.h"

undefined4
StructGO_SomeFn_from_thumb
          (undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
          undefined2 param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = Os_DisableIrq();
  iVar4 = GetGlobalGO_from_thumb();
  if (iVar4 == 0) {
    SetGlobalGO_from_thumb((undefined4)(uintptr_t)(param_1));
  }
  else {
    iVar4 = GetGlobalGO_from_thumb();
    iVar2 = *(int *)(iVar4 + 0x28);
    while (iVar1 = iVar2, iVar1 != 0) {
      iVar4 = iVar1;
      iVar2 = *(int *)(iVar1 + 0x28);
    }
    *(undefined4 **)(iVar4 + 0x28) = param_1;
  }
  if (param_4 == 0) {
    *(undefined2 *)((int)param_1 + 0x32) = 1;
  }
  else {
    param_1[0xb] = param_4;
    *(undefined2 *)((int)param_1 + 0x32) = 0;
  }
  param_1[10] = 0;
  *param_1 = param_2;
  param_1[1] = param_5;
  *(undefined2 *)(param_1 + 0xc) = param_6;
  if (param_3 == 0) {
    Mem_CpuFill8(param_1 + 2,0,0x20);
  }
  else {
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_3),param_1 + 2,0x20);
  }
  Os_RestoreIrq(uVar3);
  return 1;
}

