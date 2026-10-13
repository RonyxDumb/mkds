/* Decompiled C draft; module arm9; ROM address 020d6a54. No matching claim. */
#include "types.h"
#include "deps/020d6a54_func_020d6a54.h"

uint func_020d6a54(int param_1,ushort *param_2,uint *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_18;
  uint local_14 [2];
  
  uVar5 = (uint)*param_2;
  uVar1 = param_2[1];
  iVar2 = 0;
  if (99 < uVar5) {
    do {
      uVar5 = uVar5 - 100;
      iVar2 = iVar2 + 1;
    } while (99 < (int)uVar5);
  }
  uVar7 = (uint)(param_2 + 0x4c) & 3;
  uVar6 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
  uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if (uVar7 >> uVar6 * 8 == 0 && uVar7 << uVar6 * -8 + 0x20 == 0) {
    if (param_3 != (uint *)0x0) {
      *param_3 = 0;
    }
    uVar7 = param_1 + 0x44U & 3;
    uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    uVar6 = (uint)(param_2 + 0x4c) & 3;
    uVar4 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
    uVar7 = iVar2 * 0x38 + iRam020d6bd8 + (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) * 4;
    uVar8 = uVar7 & 3;
    uVar3 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 0x20;
    uVar6 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar5 = (uint)*(byte *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + uVar5);
    if ((uVar1 & 0x800) == 0) {
      return uVar5;
    }
    if (uVar5 != 1) {
      return uVar5;
    }
    uVar5 = 1;
    if (uVar7 >> uVar6 * 8 != 0 || uVar7 << uVar6 * -8 + 0x20 != 0) {
      uVar5 = 2;
    }
    return uVar5;
  }
  uVar7 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = iRam020d6bd4 + iVar2 * 0x38 + (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 4;
  uVar6 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  local_18 = (uint)*(byte *)((uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + uVar5);
  if ((uVar1 & 0x800) != 0) {
    local_18 = 0;
  }
  uVar7 = param_1 + 0x44U & 3;
  uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar7 = iRam020d6bd8 + iVar2 * 0x38 + (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) * 4;
  uVar6 = uVar7 & 3;
  uVar3 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = (uint)(param_2 + 0x4c) & 3;
  uVar8 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
  uVar7 = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 0x20;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  local_14[0] = (uint)*(byte *)((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + uVar5);
  if ((((uVar1 & 0x800) != 0) && (local_14[0] == 1)) &&
     (uVar7 >> uVar8 * 8 != 0 || uVar7 << uVar8 * -8 + 0x20 != 0)) {
    local_14[0] = 2;
  }
  if ((param_2[1] & 0x80) == 0) {
    uVar5 = (uint)(param_2 + 0x4c) & 3;
    uVar7 = *(uint *)((uint)(param_2 + 0x4c) & 0xfffffffc);
    uVar5 = (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) + 4;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    local_14[0] = (*(code *)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20))
                            (param_2,param_1,&local_18,local_14);
  }
  uVar5 = (*(uint *)(uRam020d6bdc & 0xfffffffc) >> (uRam020d6bdc & 3) * 8 |
          *(uint *)(uRam020d6bdc & 0xfffffffc) << (uRam020d6bdc & 3) * -8 + 0x20) + 8;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) == 4) && (local_18 == 1)) {
    func_0x0218175c(*param_2);
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = local_18;
  }
  return local_14[0];
}

