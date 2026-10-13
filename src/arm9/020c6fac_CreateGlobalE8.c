/* Decompiled C draft; module arm9; ROM address 020c6fac. No matching claim. */
#include "types.h"
#include "deps/020c6fac_CreateGlobalE8.h"

void CreateGlobalE8(void)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  uVar3 = (*(uint *)(uRam020c7094 & 0xfffffffc) >> (uRam020c7094 & 3) * 8 |
          *(uint *)(uRam020c7094 & 0xfffffffc) << (uRam020c7094 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1) {
    GetActiveExecutionContext();
    uVar4 = ExecutionContext_GetHeapHandle();
    puVar5 = (undefined4 *)Mem_AllocateHeap(uVar4,0xe8);
    uVar4 = uRam020c709c;
    puVar2 = puRam020c7098;
    iVar8 = 0;
    *puRam020c7098 = puVar5;
    *puVar5 = uVar4;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 4) = 0;
    iVar7 = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 8) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0xc) = 0xffffffff;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x10) = 0;
    *(undefined2 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x14) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
      *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x18) = 0;
    uVar3 = uRam020c7094;
    do {
      uVar1 = uVar3 & 3;
      uVar6 = *(uint *)(uVar3 & 0xfffffffc);
      uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
      uVar1 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      TimeTrialRecord_CopyFrom_from_thumb
                (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20,iVar8,
                 (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                 *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + 0x1c +
                 iVar7);
      puVar5 = puRam020c7098;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0x20;
    } while (iVar8 < 6);
    *(undefined4 *)
     ((*(uint *)((uint)puRam020c7098 & 0xfffffffc) >> ((uint)puRam020c7098 & 3) * 8 |
      *(uint *)((uint)puRam020c7098 & 0xfffffffc) << ((uint)puRam020c7098 & 3) * -8 + 0x20) + 0x18)
         = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
      *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) + 0xdc) = 0;
    *(undefined4 *)
     ((*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
      *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) + 0xe0) = 0xffffff00;
    *(undefined4 *)
     ((*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
      *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) + 0xe4) = 0;
    return;
  }
  return;
}

