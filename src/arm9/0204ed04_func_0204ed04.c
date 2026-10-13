/* Decompiled C draft; module arm9; ROM address 0204ed04. No matching claim. */
#include "types.h"
#include "deps/0204ed04_func_0204ed04.h"

void func_0204ed04(int param_1)

{
  short sVar1;
  int iVar2;
  undefined1 auStack_1a0 [408];
  
  if ((*(short *)(param_1 + 2) == 0) && (*(int *)(param_1 + 0xc) != 0)) {
    if (*(ushort *)(param_1 + 0x10) <= uRam0204ed7c) {
      DC_InvalidateRangeNoClean();
      Mem_CpuCopy8((ushort *)(uintptr_t)(*(undefined4 *)(param_1 + 0xc)),(uint *)(void *)(auStack_1a0),*(undefined2 *)(param_1 + 0x10));
      sVar1 = *(short *)(param_1 + 4);
      if (((sVar1 != 7) && (sVar1 != 9)) && (sVar1 == 0x15)) {
        if ((int *)*piRam0204ed80 == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)*piRam0204ed80;
        }
        if (iVar2 == 1) {
          func_0200692c((int)(uintptr_t)(auStack_1a0),*(undefined2 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0x12))
          ;
          return;
        }
        if (iVar2 != 2) {
          return;
        }
        func_020068f4((int)(uintptr_t)(auStack_1a0),*(undefined2 *)(param_1 + 0x10));
      }
    }
  }
  return;
}

