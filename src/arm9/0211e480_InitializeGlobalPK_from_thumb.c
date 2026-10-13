/* Decompiled C draft; module arm9; ROM address 0211e480. No matching claim. */
#include "types.h"
#include "deps/0211e480_InitializeGlobalPK_from_thumb.h"

void InitializeGlobalPK_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Mem_AllocateHeap(param_1,0x14);
  *piRam0211e4e4 = iVar2;
  uVar3 = AllocateStructYE(param_1);
  piVar1 = piRam0211e4e4;
  *(undefined4 *)*piRam0211e4e4 = uVar3;
  SetStructYE_RunATFunction(*(undefined4 *)*piVar1);
  WaitForWorkerTask();
  uVar3 = AllocateFX(param_1);
  piVar1 = piRam0211e4e4;
  *(undefined4 *)(*piRam0211e4e4 + 4) = uVar3;
  RunSomeATFunction(*(undefined4 *)(*piVar1 + 4));
  WaitForWorkerTask();
  uVar3 = AllocateGhostHolder(param_1);
  piVar1 = piRam0211e4e4;
  *(undefined4 *)(*piRam0211e4e4 + 8) = uVar3;
  RunReadGhostBinsFn(*(undefined4 *)(*piVar1 + 8));
  WaitForWorkerTask();
  ReadStaffGhostTimeBin(param_1);
  return;
}

