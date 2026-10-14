/* Decompiled C draft; module arm9; ROM address 02083d4c. No matching claim. */
#include "types.h"
#include "deps/02083d4c_func_02083d4c.h"

undefined4 func_02083d4c(int param_1,undefined1 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  
  iVar8 = (uint)*(ushort *)(param_3 + 0x74) * 0x58;
  uVar6 = *(uint *)(uRam02083ddc & 0xfffffffc) >> (uRam02083ddc & 3) * 8 |
          *(uint *)(uRam02083ddc & 0xfffffffc) << (uRam02083ddc & 3) * -8 + 0x20;
  uVar3 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = uVar6 + iVar8;
  uVar5 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar7 = (uint *)(uVar6 + iVar8);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) !=
      (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20)) {
    uVar2 = (uint)(puVar7 + 3) & 3;
    uVar3 = *(uint *)((uint)(puVar7 + 3) & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if (uVar2 != 0) {
      *(undefined1 *)(uVar2 + 0x99) = 1;
    }
    uVar2 = param_1 + 4U & 3;
    uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar3 = func_0208b7bc(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20,uRam02083de0);
    puVar7[3] = uVar3;
    uVar1 = uRam02083de4;
    uVar2 = param_1 + 4U & 3;
    uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
    *puVar7 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
    *(int *)(uVar3 + 0x94) = param_3;
    *(undefined1 *)(uVar3 + 0x98) = param_2;
    *(undefined4 *)(uVar3 + 0x90) = uVar1;
    return 1;
  }
  return 0;
}

