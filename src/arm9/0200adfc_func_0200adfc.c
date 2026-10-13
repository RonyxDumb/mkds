/* Decompiled C draft; module arm9; ROM address 0200adfc. No matching claim. */
#include "types.h"
#include "deps/0200adfc_func_0200adfc.h"

undefined4 func_0200adfc(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar1 = Os_DisableIrq();
  piVar3 = param_1 + 0xc;
  if (piVar3 < param_1 + 0x1c) {
    do {
      if (((1 < (uint)piVar3[3]) && (iVar2 = param_2 - *piVar3, -1 < iVar2)) &&
         ((uint)(iVar2 + param_4) <= (uint)piVar3[1])) {
        Mem_CpuCopy8((ushort *)(uintptr_t)(piVar3[2] + iVar2),(uint *)(uintptr_t)(param_3),param_4);
        uVar4 = 1;
        *param_1 = 1;
        break;
      }
      piVar3 = piVar3 + 4;
    } while (piVar3 < param_1 + 0x1c);
  }
  Os_RestoreIrq(uVar1);
  return uVar4;
}

