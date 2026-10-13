/* Decompiled C draft; module arm9; ROM address 0209fc78. No matching claim. */
#include "types.h"
#include "deps/0209fc78_func_0209fc78.h"

void func_0209fc78(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  iVar6 = (int)*(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x28);
  uVar1 = uRam0209fd68 + iVar6 * 4;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (uVar1 >> uVar3 * 8 == 0 && uVar1 << uVar3 * -8 + 0x20 == 0) {
    GetActiveExecutionContext();
    uVar2 = ExecutionContext_GetHeapHandle();
    uVar2 = Mem_AllocateHeap(uVar2,0x40);
    uVar1 = uRam0209fd68;
    *(undefined4 *)(uRam0209fd68 + iVar6 * 4) = uVar2;
    puVar7 = (undefined4 *)
             (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
             *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
    uVar1 = uVar1 + iVar6 * 4;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    puVar8 = (undefined4 *)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20);
    uVar2 = puVar7[1];
    uVar4 = puVar7[2];
    uVar5 = puVar7[3];
    *puVar8 = *puVar7;
    puVar8[1] = uVar2;
    puVar8[2] = uVar4;
    puVar8[3] = uVar5;
    uVar2 = puVar7[5];
    uVar4 = puVar7[6];
    uVar5 = puVar7[7];
    puVar8[4] = puVar7[4];
    puVar8[5] = uVar2;
    puVar8[6] = uVar4;
    puVar8[7] = uVar5;
    uVar2 = puVar7[9];
    uVar4 = puVar7[10];
    uVar5 = puVar7[0xb];
    puVar8[8] = puVar7[8];
    puVar8[9] = uVar2;
    puVar8[10] = uVar4;
    puVar8[0xb] = uVar5;
    uVar2 = puVar7[0xd];
    uVar4 = puVar7[0xe];
    uVar5 = puVar7[0xf];
    puVar8[0xc] = puVar7[0xc];
    puVar8[0xd] = uVar2;
    puVar8[0xe] = uVar4;
    puVar8[0xf] = uVar5;
  }
  if (iVar6 == 0x10) {
    uVar1 = uRam0209fd68 + 0x40 & 3;
    uVar3 = *(uint *)(uRam0209fd68 + 0x40 & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x24) = uRam0209fd6c;
  }
  else if (iVar6 == 0x11) {
    uVar1 = uRam0209fd68 + 0x44 & 3;
    uVar3 = *(uint *)(uRam0209fd68 + 0x44 & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x24) = 0x100;
  }
  else if (iVar6 == 0x12) {
    uVar1 = uRam0209fd68 + 0x48 & 3;
    uVar3 = *(uint *)(uRam0209fd68 + 0x48 & 0xfffffffc);
    *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x24) = uRam0209fd70;
  }
  else {
    uVar2 = func_0210bafc(0,8,iVar6);
    uVar1 = uRam0209fd68 + iVar6 * 4;
    uVar3 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(undefined4 *)((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0x24) = uVar2;
  }
  uVar1 = uRam0209fd68 + iVar6 * 4;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(param_1 + 0x98) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  return;
}

