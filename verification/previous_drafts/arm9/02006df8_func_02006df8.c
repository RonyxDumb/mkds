/* Decompiled C draft; module arm9; ROM address 02006df8. No matching claim. */
#include "types.h"
#include "deps/02006df8_func_02006df8.h"

int * func_02006df8(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  
  uVar3 = Os_DisableIrq();
  piVar4 = (int *)GetGlobalGO_from_thumb();
  if (piVar4 == (int *)0x0) {
    Os_RestoreIrq(uVar3);
    return (int *)0x0;
  }
  if (*piVar4 != param_1) {
    piVar2 = (int *)piVar4[10];
    while( true ) {
      piVar1 = piVar2;
      if (piVar1 == (int *)0x0) {
        Os_RestoreIrq(uVar3);
        return (int *)0x0;
      }
      if (*piVar1 == param_1) break;
      piVar2 = (int *)piVar1[10];
      piVar4 = piVar1;
    }
    piVar4[10] = piVar1[10];
    Os_RestoreIrq(uVar3);
    return piVar1;
  }
  SetGlobalGO_from_thumb(piVar4[10]);
  Os_RestoreIrq(uVar3);
  return piVar4;
}

