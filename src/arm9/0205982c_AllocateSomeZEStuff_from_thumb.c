/* Decompiled C draft; module arm9; ROM address 0205982c. No matching claim. */
#include "types.h"
#include "deps/0205982c_AllocateSomeZEStuff_from_thumb.h"

void AllocateSomeZEStuff_from_thumb(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = Mem_AllocateHeapAligned(param_1,uRam02059868,0x20);
  piVar1 = piRam0205986c;
  *(undefined4 *)(*piRam0205986c + iRam02059870) = uVar2;
  iVar4 = 0;
  iVar3 = 0;
  do {
    uVar2 = Mem_AllocateHeap(param_1,0x12);
    *(undefined4 *)(*piVar1 + iVar3 + iRam02059874) = uVar2;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  return;
}

