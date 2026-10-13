/* Decompiled C draft; module arm9; ROM address 020845cc. No matching claim. */
#include "types.h"
#include "deps/020845cc_func_020845cc.h"

void func_020845cc(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar7 = 0;
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar4,param_1 * 0x58);
  puVar3 = puRam020846a0;
  puVar2 = puRam0208469c;
  *puRam0208469c = uVar4;
  *puVar3 = (short)param_1;
  if (param_1 != 0) {
    do {
      uVar5 = (uint)puVar2 & 3;
      uVar9 = *(uint *)((uint)puVar2 & 0xfffffffc);
      uVar9 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
      uVar5 = 0;
      iVar6 = uVar9 + uVar7 * 0x58;
      *(undefined4 *)(iVar6 + 0xc) = 0;
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x2c) = 0;
      *(undefined4 *)(iVar6 + 0x30) = 0;
      *(undefined4 *)(uVar9 + uVar7 * 0x58) = 0xffffffff;
      *(undefined4 *)(iVar6 + 0x24) = 0;
      uVar9 = iVar6 + 0x24U & 3;
      uVar8 = *(uint *)(iVar6 + 0x24U & 0xfffffffc);
      *(uint *)(iVar6 + 0x20) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      do {
        iVar10 = iVar6 + uVar5 * 8;
        *(undefined4 *)(iVar10 + 0x14) = 0;
        uVar9 = iVar10 + 0x14U & 3;
        uVar8 = *(uint *)(iVar10 + 0x14U & 0xfffffffc);
        iVar1 = uVar5 * 4;
        *(uint *)(iVar10 + 0x10) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        uVar5 = uVar5 + 1 & 0xffff;
        *(undefined4 *)(iVar6 + iVar1 + 4) = 0xffffffff;
      } while (uVar5 < 2);
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < param_1);
  }
  *puRam020846a4 = 0;
  return;
}

