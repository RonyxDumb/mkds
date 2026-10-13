/* Decompiled C draft; module arm9; ROM address 02071fb8. No matching claim. */
#include "types.h"
#include "deps/02071fb8_DriverContext_CreateNetworkState.h"

void DriverContext_CreateNetworkState(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar9;
  undefined4 *puVar8;
  
  uVar9 = param_1 + 0x514U & 3;
  uVar7 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  puVar8 = (undefined4 *)(uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20);
  if (puVar8 != (undefined4 *)0x0) {
    uVar3 = *(undefined4 *)(param_1 + 0x84);
    uVar5 = *(undefined4 *)(param_1 + 0x88);
    *puVar8 = *(undefined4 *)(param_1 + 0x80);
    puVar8[1] = uVar3;
    puVar8[2] = uVar5;
    puVar8[4] = *puVar8;
    puVar8[5] = puVar8[1];
    puVar8[6] = puVar8[2];
    puVar1 = puRam020720d4;
    uVar9 = 0;
    *(undefined2 *)((int)puVar8 + 0xe) = *(undefined2 *)(param_1 + 0x236);
    *(undefined2 *)(puVar8 + 3) = *(undefined2 *)((int)puVar8 + 0xe);
    puVar8[7] = 0;
    puVar8[8] = 0;
    puVar8[9] = 0;
    puVar8[10] = 0;
    puVar8[0xc] = 0;
    uVar7 = (uint)(puVar8 + 0xc) & 3;
    uVar4 = *(uint *)((uint)(puVar8 + 0xc) & 0xfffffffc);
    puVar8[0xb] = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    uVar3 = *puVar1;
    uVar5 = puVar1[1];
    uVar6 = puVar1[2];
    puVar8[0xd] = uVar3;
    puVar8[0xe] = uVar5;
    puVar8[0xf] = uVar6;
    puVar8[0x11] = 0;
    puVar8[0x12] = 0;
    *(undefined2 *)(puVar8 + 0x10) = 0;
    *(undefined2 *)(puVar8 + 0x17) = 0;
    puVar8[0x18] = 0;
    puVar8[0x19] = 0;
    puVar8[0x26] = uVar3;
    puVar8[0x27] = uVar5;
    puVar8[0x28] = uVar6;
    puVar8[0x2a] = uVar3;
    puVar8[0x2b] = uVar5;
    puVar8[0x2c] = uVar6;
    *(undefined2 *)(puVar8 + 0x2d) = 0;
    IntrusiveListWrapper_InitializeEmpty(puVar8 + 0x20,0);
    IntrusiveListWrapper_InitializeEmpty(puVar8 + 0x23,0);
    iVar2 = Mem_AllocateHeap(param_2,uRam020720d8);
    do {
      IntrusiveListWrapper_InsertLast(puVar8 + 0x23,uVar9 * 0x24 + iVar2);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < 0x1e);
    return;
  }
  return;
}

