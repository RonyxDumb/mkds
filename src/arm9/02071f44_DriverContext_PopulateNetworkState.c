/* Decompiled C draft; module arm9; ROM address 02071f44. No matching claim. */
#include "types.h"
#include "deps/02071f44_DriverContext_PopulateNetworkState.h"

void DriverContext_PopulateNetworkState(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400) != 0) {
    uVar1 = param_1 + 0x514U & 3;
    uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    puVar6 = (undefined4 *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    uVar3 = *(undefined4 *)(param_1 + 0x84);
    uVar4 = *(undefined4 *)(param_1 + 0x88);
    *puVar6 = *(undefined4 *)(param_1 + 0x80);
    puVar6[1] = uVar3;
    puVar6[2] = uVar4;
    puVar6[4] = *puVar6;
    puVar6[5] = puVar6[1];
    puVar6[6] = puVar6[2];
    uVar3 = *(undefined4 *)(param_1 + 0x114);
    uVar4 = *(undefined4 *)(param_1 + 0x118);
    uVar5 = *(undefined4 *)(param_1 + 0x11c);
    puVar6[0x13] = *(undefined4 *)(param_1 + 0x110);
    puVar6[0x14] = uVar3;
    puVar6[0x15] = uVar4;
    puVar6[0x16] = uVar5;
    uVar3 = puRam02071fb4[1];
    uVar4 = puRam02071fb4[2];
    puVar6[0x2a] = *puRam02071fb4;
    puVar6[0x2b] = uVar3;
    puVar6[0x2c] = uVar4;
    *(undefined2 *)(puVar6 + 0x2d) = 0;
    return;
  }
  return;
}

