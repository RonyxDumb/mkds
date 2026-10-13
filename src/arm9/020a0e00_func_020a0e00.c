/* Decompiled C draft; module arm9; ROM address 020a0e00. No matching claim. */
#include "types.h"
#include "deps/020a0e00_func_020a0e00.h"

void func_020a0e00(void)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar4,0x3c0);
  uVar8 = 0;
  iVar6 = 0;
  *puRam020a0f04 = uVar4;
  uVar3 = uRam020a0f08;
  do {
    iVar7 = (*(uint *)((uint)puRam020a0f04 & 0xfffffffc) >> ((uint)puRam020a0f04 & 3) * 8 |
            *(uint *)((uint)puRam020a0f04 & 0xfffffffc) << ((uint)puRam020a0f04 & 3) * -8 + 0x20) +
            iVar6;
    *(undefined4 *)(iVar7 + 0x1c) = 0xfffffffe;
    *(undefined4 *)(iVar7 + 0x18) = 0xfffffffe;
    uVar2 = (undefined2)uVar8;
    *(undefined2 *)(iVar7 + 0x44) = uVar2;
    *(undefined2 *)(iVar7 + 0x48) = uVar2;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    if ((int)uVar8 < (int)(uint)*(byte *)(uVar5 + 0x3d0)) {
      uVar5 = (uVar8 & 0xffff) * 0x30 + uVar5 + 0x74;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      if (uVar5 == 0) {
        *(undefined2 *)(iVar7 + 0x46) = 1;
      }
      else if (uVar5 == 1) {
        *(undefined2 *)(iVar7 + 0x46) = 3;
      }
      else {
        *(undefined2 *)(iVar7 + 0x46) = uVar2;
      }
      *(undefined4 *)(iVar7 + 8) = 0;
      *(undefined4 *)(iVar7 + 0x4c) = 0;
      *(undefined2 *)(iVar7 + 0x50) = 0;
    }
    else {
      *(undefined4 *)(iVar7 + 8) = 2;
      *(undefined4 *)(iVar7 + 0x4c) = 0xffffffff;
      *(undefined2 *)(iVar7 + 0x50) = 0;
      *(ushort *)(iVar7 + 0x46) =
           (ushort)*(byte *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                             *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0x3d0);
    }
    uVar8 = uVar8 + 1;
    iVar6 = iVar6 + 0x70;
  } while ((int)uVar8 < 8);
  *(undefined4 *)
   ((*(uint *)((uint)puRam020a0f04 & 0xfffffffc) >> ((uint)puRam020a0f04 & 3) * 8 |
    *(uint *)((uint)puRam020a0f04 & 0xfffffffc) << ((uint)puRam020a0f04 & 3) * -8 + 0x20) + 0x3b4) =
       0xffffffff;
  return;
}

