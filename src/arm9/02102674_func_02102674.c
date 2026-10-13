/* Decompiled C draft; module arm9; ROM address 02102674. No matching claim. */
#include "types.h"
#include "deps/02102674_func_02102674.h"

void func_02102674(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  GetActiveExecutionContext();
  uVar4 = ExecutionContext_GetHeapHandle();
  uVar4 = Mem_AllocateHeap(uVar4,0x52);
  puVar1 = puRam02102714;
  *puRam02102714 = uVar4;
  iVar8 = 0;
  do {
    iVar7 = iVar8;
    uVar3 = _s32_div_f((0x28 - iVar7) * 0x1000,0x29 - iVar7);
    uVar9 = (uint)puVar1 & 3;
    uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
    *(undefined2 *)((uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) + iVar7 * 2) = uVar3;
    puVar2 = puRam02102714;
    iVar8 = iVar7 + 1;
  } while (iVar7 + 1 < 0x29);
  iVar8 = iVar7 + -4;
  if (iVar8 == 0x28 || iVar7 + -0x2c < 0 != SBORROW4(iVar8,0x28)) {
    do {
      iVar5 = iVar8 + -1;
      iVar7 = iVar8 * 2;
      uVar9 = (uint)puVar2 & 3;
      uVar6 = *(uint *)((uint)puVar2 & 0xfffffffc);
      uVar9 = uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20;
      iVar8 = iVar8 + 1;
      *(short *)(uVar9 + iVar7) =
           (short)((int)((uint)*(ushort *)(uVar9 + iVar7) + (uint)*(ushort *)(uVar9 + iVar5 * 2)) >>
                  1);
    } while (iVar8 < 0x29);
    return;
  }
  return;
}

