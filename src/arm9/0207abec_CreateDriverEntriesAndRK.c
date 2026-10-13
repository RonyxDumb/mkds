/* Decompiled C draft; module arm9; ROM address 0207abec. No matching claim. */
#include "types.h"
#include "deps/0207abec_CreateDriverEntriesAndRK.h"

void CreateDriverEntriesAndRK(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  GetActiveExecutionContext();
  uVar5 = ExecutionContext_GetHeapHandle();
  uVar6 = Mem_AllocateHeap(uVar5,param_1 * iRam0207ad54);
  puVar3 = puRam0207ad5c;
  *puRam0207ad58 = uVar6;
  *puVar3 = (short)param_1;
  puVar7 = (undefined4 *)Mem_AllocateHeap(uVar5,0x1c);
  puVar4 = puRam0207ad68;
  puVar3 = puRam0207ad64;
  puVar2 = puRam0207ad60;
  *puRam0207ad6c = 0xffffffff;
  *puVar2 = puVar7;
  *puVar3 = 0;
  *puVar4 = 0;
  *puVar7 = 0;
  puVar7[1] = 0;
  puVar7[2] = 0;
  puVar7[3] = 0;
  puVar7[4] = 0;
  puVar7[5] = 0;
  uVar8 = uRam0207ad70;
  puVar7[6] = 0;
  uVar9 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 8;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if ((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) == 2) {
    uVar5 = 1;
  }
  else {
    uVar5 = 2;
  }
  *puRam0207ad74 = uVar5;
  func_02073630();
  func_0208c284();
  func_020845cc(param_1);
  puVar2 = puRam0207ad78;
  uVar9 = uRam0207ad70 & 3;
  uVar8 = *(uint *)(uRam0207ad70 & 0xfffffffc);
  *puRam0207ad78 = 0;
  uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 8;
  uVar8 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  if (((uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20) == 4) &&
     (*(char *)((*(uint *)(uRam0207ad7c & 0xfffffffc) >> (uRam0207ad7c & 3) * 8 |
                *(uint *)(uRam0207ad7c & 0xfffffffc) << (uRam0207ad7c & 3) * -8 + 0x20) + 0x10f) !=
      '\0')) {
    *puVar2 = 1;
  }
  uVar5 = uRam0207ad80;
  uVar8 = uRam0207ad70;
  puVar2 = puRam0207ad58;
  iVar1 = iRam0207ad54;
  uVar9 = 0;
  if (param_1 != 0) {
    do {
      iVar10 = uVar9 * iVar1;
      *(short *)((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                 *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar10 +
                0x74) = (short)uVar9;
      uVar12 = uVar8 & 3;
      uVar11 = *(uint *)(uVar8 & 0xfffffffc);
      uVar12 = uVar9 * 0x30 + (uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20) + 0x7c;
      uVar11 = uVar12 & 3;
      uVar12 = *(uint *)(uVar12 & 0xfffffffc);
      *(uint *)((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar10 +
               0x78) = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20;
      DriverContext_Create
                ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                 *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) + iVar10,
                 uVar5);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < param_1);
  }
  *puRam0207ad84 = 0;
  return;
}

