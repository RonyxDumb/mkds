/* Decompiled C draft; module arm9; ROM address 020ba520. No matching claim. */
#include "types.h"
#include "deps/020ba520_func_020ba520.h"

/* WARNING: Removing unreachable block (ram,0x020ba568) */

void func_020ba520(void)

{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined2 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  GetActiveExecutionContext();
  uVar3 = ExecutionContext_GetHeapHandle();
  puVar4 = (undefined2 *)Mem_AllocateHeap(uVar3,0xc);
  uVar9 = *(uint *)(uRam020ba618 & 0xfffffffc) >> (uRam020ba618 & 3) * 8 |
          *(uint *)(uRam020ba618 & 0xfffffffc) << (uRam020ba618 & 3) * -8 + 0x20;
  *puRam020ba61c = puVar4;
  uVar7 = uVar9 + 8;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  if (uVar7 != 1) {
    if (uVar7 == 2) {
      uVar9 = uVar9 + 0x18;
      uVar7 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      if (uVar9 >> uVar7 * 8 == 0 && uVar9 << uVar7 * -8 + 0x20 == 0) {
        *puVar4 = 0;
        GetCurrentPlayerRacerId();
        uVar2 = func_020a10d4();
        *(undefined2 *)
         ((*(uint *)((uint)puRam020ba61c & 0xfffffffc) >> ((uint)puRam020ba61c & 3) * 8 |
          *(uint *)((uint)puRam020ba61c & 0xfffffffc) << ((uint)puRam020ba61c & 3) * -8 + 0x20) + 2)
             = uVar2;
      }
      else {
        GetCurrentPlayerRacerId();
        uVar2 = func_020a1154();
        *(undefined2 *)
         (*(uint *)((uint)puRam020ba61c & 0xfffffffc) >> ((uint)puRam020ba61c & 3) * 8 |
         *(uint *)((uint)puRam020ba61c & 0xfffffffc) << ((uint)puRam020ba61c & 3) * -8 + 0x20) =
             uVar2;
      }
    }
    else if (uVar7 == 4) {
      uVar3 = func_0x02181820();
      puVar1 = puRam020ba61c;
      uVar9 = uRam020ba618;
      *(undefined4 *)
       (*(uint *)((uint)puRam020ba61c & 0xfffffffc) >> ((uint)puRam020ba61c & 3) * 8 |
       *(uint *)((uint)puRam020ba61c & 0xfffffffc) << ((uint)puRam020ba61c & 3) * -8 + 0x20) = uVar3
      ;
      uVar7 = uVar9 & 3;
      uVar8 = *(uint *)(uVar9 & 0xfffffffc);
      uVar9 = (uint)puVar1 & 3;
      uVar5 = *(uint *)((uint)puVar1 & 0xfffffffc);
      *(uint *)((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) + 4) =
           (uint)*(byte *)((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 0x37);
    }
    else {
      GetCurrentPlayerRacerId();
      iVar6 = GetDriverPlace();
      *(int *)(*(uint *)((uint)puRam020ba61c & 0xfffffffc) >> ((uint)puRam020ba61c & 3) * 8 |
              *(uint *)((uint)puRam020ba61c & 0xfffffffc) << ((uint)puRam020ba61c & 3) * -8 + 0x20)
           = iVar6 + -1;
    }
  }
  *(undefined4 *)
   ((*(uint *)((uint)puRam020ba61c & 0xfffffffc) >> ((uint)puRam020ba61c & 3) * 8 |
    *(uint *)((uint)puRam020ba61c & 0xfffffffc) << ((uint)puRam020ba61c & 3) * -8 + 0x20) + 8) = 1;
  return;
}

