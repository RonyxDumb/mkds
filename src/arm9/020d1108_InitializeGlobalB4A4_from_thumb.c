/* Decompiled C draft; module arm9; ROM address 020d1108. No matching claim. */
#include "types.h"
#include "deps/020d1108_InitializeGlobalB4A4_from_thumb.h"

void InitializeGlobalB4A4_from_thumb(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = func_020d1158();
  if (iVar1 == 0) {
    uVar2 = GetActiveExecutionContextHeapHandle_0();
    iVar1 = Mem_AllocateHeap(uVar2,uRam020d1134);
    *piRam020d1138 = iVar1;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    func_020d0efc(0x14);
  }
  return;
}

