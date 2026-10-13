/* Decompiled C draft; module arm9; ROM address 02057524. No matching claim. */
#include "types.h"
#include "deps/02057524_InitializeSaveDataHolder_from_thumb.h"

void InitializeSaveDataHolder_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Mem_AllocateHeap(param_1,0x48);
  *piRam02057600 = iVar2;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057604,0x20);
  *(undefined4 *)*piRam02057600 = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057608,0x20);
  *(undefined4 *)(*piRam02057600 + 4) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam0205760c,0x20);
  *(undefined4 *)(*piRam02057600 + 8) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057610,0x20);
  *(undefined4 *)(*piRam02057600 + 0xc) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057604,0x20);
  *(undefined4 *)(*piRam02057600 + 0x10) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057614,0x20);
  *(undefined4 *)(*piRam02057600 + 0x14) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057618,0x20);
  *(undefined4 *)(*piRam02057600 + 0x18) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057618,0x20);
  *(undefined4 *)(*piRam02057600 + 0x1c) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam0205761c,0x20);
  *(undefined4 *)(*piRam02057600 + 0x20) = uVar3;
  uVar3 = Mem_AllocateHeapAligned(param_1,uRam02057620,0x20);
  piVar1 = piRam02057600;
  *(undefined4 *)(*piRam02057600 + 0x24) = uVar3;
  *(undefined4 *)(*piVar1 + 0x40) = 0;
  ClearAllSaveDataSections_from_thumb(1);
  piVar1 = piRam02057600;
  *(undefined2 *)(*piRam02057600 + 0x2a) = 0;
  *(undefined4 *)(*piVar1 + 0x2c) = 0;
  *(uint *)(*piVar1 + 0x44) = *(uint *)(*piVar1 + 0x44) & 0xfffffffe;
  *(undefined1 *)(*piVar1 + 0x28) = 0;
  return;
}

