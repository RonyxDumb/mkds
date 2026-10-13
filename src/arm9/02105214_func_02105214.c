/* Decompiled C draft; module arm9; ROM address 02105214. No matching claim. */
#include "types.h"
#include "deps/02105214_func_02105214.h"

void func_02105214(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  
  iVar4 = *(int *)(*piRam021052cc + 8);
  if (iVar4 == 2) {
    *piRam021052d0 = 0xb;
  }
  else if (iVar4 == 4) {
    *piRam021052d0 = 0x20;
  }
  else if (iVar4 == 5) {
    *piRam021052d0 = 6;
  }
  else {
    *piRam021052d0 = 3;
  }
  GetActiveExecutionContext();
  uVar5 = ExecutionContext_GetHeapHandle();
  iVar4 = Mem_AllocateHeap(uVar5,*piRam021052d0 << 2);
  piVar1 = piRam021052d4;
  *piRam021052d4 = iVar4;
  puVar2 = puRam021052dc;
  uVar5 = *puRam021052d8;
  uVar7 = puRam021052d8[1];
  uVar6 = puRam021052d8[2];
  *puRam021052dc = uVar5;
  puVar2[1] = uVar7;
  puVar2[2] = uVar6;
  puVar3 = puRam021052e0;
  *puRam021052e0 = uVar5;
  puVar3[1] = uVar7;
  puVar3[2] = uVar6;
  puVar3 = puRam021052e8;
  uVar5 = puRam021052e4[1];
  puVar9 = puRam021052e4 + 2;
  *puRam021052e8 = *puRam021052e4;
  puVar3[1] = uVar5;
  puVar3[2] = *puVar9;
  *(undefined2 *)(puVar2 + 9) = 0x6f;
  *(undefined2 *)((int)puVar2 + 0x2e) = 1;
  iVar4 = 0;
  if (0 < *piRam021052d0) {
    iVar8 = 0;
    do {
      uVar5 = func_020d34c4((undefined4)(uintptr_t)(puVar2),0x6f);
      *(undefined4 *)(*piVar1 + iVar8) = uVar5;
      iVar8 = iVar8 + 4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piRam021052d0);
  }
  *puRam021052ec = 0;
  return;
}

