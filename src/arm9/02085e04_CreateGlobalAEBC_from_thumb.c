/* Decompiled C draft; module arm9; ROM address 02085e04. No matching claim. */
#include "types.h"
#include "deps/02085e04_CreateGlobalAEBC_from_thumb.h"

void CreateGlobalAEBC_from_thumb(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  iVar4 = Mem_AllocateHeap(uVar3,uRam02085fa0);
  piVar1 = piRam02085fa4;
  *piRam02085fa4 = iVar4;
  uVar5 = 0;
  do {
    iVar4 = uVar5 * 4;
    *(undefined4 *)(*piVar1 + iVar4) = 0;
    *(undefined4 *)(*piVar1 + iVar4 + 0x20) = 0xffffffff;
    *(undefined4 *)(*piVar1 + iVar4 + 0x40) = 0xffffffff;
    *(undefined4 *)(*piVar1 + iVar4 + 0x60) = 0xffffffff;
    *(undefined4 *)(*piVar1 + iVar4 + 0x90) = 0;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 8);
  *(undefined4 *)(*piVar1 + 0x80) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 0x84) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 0x88) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 0x8c) = 0;
  if (*(int *)(*piRam02085fa8 + 8) == 1) {
    *(int *)(*piVar1 + iRam02085fb4) = *piRam02085fac + iRam02085fb0;
  }
  else {
    *(int *)(*piVar1 + iRam02085fb4) = *piRam02085fac + iRam02085fb8;
  }
  iVar4 = iRam02085fc0;
  piVar2 = piRam02085fa8;
  piVar1 = piRam02085fa4;
  uVar5 = (uint)*(byte *)(*piRam02085fa8 + iRam02085fbc);
  if ((uVar5 < 2) || (uVar5 - *(byte *)(*piRam02085fa8 + iRam02085fc0) != 1)) {
    *(undefined4 *)(*piRam02085fa4 + iRam02085fc4) = 0;
    *(undefined2 *)(*piVar1 + iRam02085fc8) = 0xffff;
  }
  else {
    *(undefined4 *)(*piRam02085fa4 + iRam02085fc4) = 1;
    *(ushort *)(*piVar1 + iRam02085fc8) = (*(byte *)(*piVar2 + iVar4) >> 1) + 1;
  }
  if (*piRam02085fcc != 0) {
    func_02085bec();
    func_02085ad8();
    iVar4 = *piRam02085fa8;
    if (*(int *)(iVar4 + 8) == 0) {
      iVar4 = *(int *)(iVar4 + 0x10);
      if (iVar4 == 0) {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 0;
      }
      else if (iVar4 == 1) {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 1;
      }
      else if (iVar4 == 2) {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 2;
      }
      else {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 1;
      }
    }
    else {
      iVar4 = *(int *)(iVar4 + 0x14);
      if (iVar4 == 1) {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 0;
      }
      else if (iVar4 == 2) {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 1;
      }
      else if (iVar4 == 3) {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 2;
      }
      else {
        *(undefined4 *)(*piRam02085fa4 + iRam02085fd0) = 1;
      }
    }
    uVar3 = FX_Div(*(undefined4 *)(*piRam02085fcc + 4),uRam02085fd4);
    *(undefined4 *)(*piRam02085fcc + 4) = uVar3;
  }
  func_02085d1c();
  func_0207fba0();
  func_0207e268();
  func_0207c78c();
  if (*(int *)(*piRam02085fa8 + 8) == 2) {
    func_02089974();
    func_02090354();
  }
  return;
}

