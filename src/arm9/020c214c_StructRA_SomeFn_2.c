/* Decompiled C draft; module arm9; ROM address 020c214c. No matching claim. */
#include "types.h"
#include "deps/020c214c_StructRA_SomeFn_2.h"

void StructRA_SomeFn_2(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_40 [4];
  uint local_30;
  uint local_2c;
  uint uVar10;
  
  uVar2 = uRam020c22fc;
  local_40[2] = *(uint *)(uRam020c22f0 & 0xfffffffc) >> (uRam020c22f0 & 3) * 8 |
                *(uint *)(uRam020c22f0 & 0xfffffffc) << (uRam020c22f0 & 3) * -8 + 0x20;
  uVar9 = uRam020c22f0 + 4 & 3;
  uVar7 = *(uint *)(uRam020c22f0 + 4 & 0xfffffffc);
  local_40[3] = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
  uVar6 = *(uint *)(uRam020c22f4 & 0xfffffffc) >> (uRam020c22f4 & 3) * 8 |
          *(uint *)(uRam020c22f4 & 0xfffffffc) << (uRam020c22f4 & 3) * -8 + 0x20;
  uVar9 = uRam020c22f4 + 4 & 3;
  uVar7 = *(uint *)(uRam020c22f4 + 4 & 0xfffffffc);
  local_2c = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
  uVar9 = (*(uint *)(uRam020c22f8 & 0xfffffffc) >> (uRam020c22f8 & 3) * 8 |
          *(uint *)(uRam020c22f8 & 0xfffffffc) << (uRam020c22f8 & 3) * -8 + 0x20) + 0xa0;
  uVar7 = uVar9 & 3;
  uVar9 = *(uint *)(uVar9 & 0xfffffffc);
  uVar10 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  uVar9 = 0;
  uVar7 = 0;
  do {
    local_40[uVar9] = 0;
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 2);
  uVar9 = *(uint *)(uRam020c22fc & 0xfffffffc) >> (uRam020c22fc & 3) * 8 |
          *(uint *)(uRam020c22fc & 0xfffffffc) << (uRam020c22fc & 3) * -8 + 0x20;
  local_30 = uVar6;
  if (*(char *)(uVar9 + 0x3d0) != '\0') {
    do {
      uVar6 = uVar7 * 0x30 + uVar9 + 0x74;
      uVar8 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
      if (uVar8 == 0) {
        uVar9 = -uVar10;
      }
      if (uVar8 != 0) {
        uVar9 = uVar10;
      }
      uVar6 = local_40[uVar8] * 0x17 + 0x11;
      func_020c2570(param_1,uVar7,local_40[uVar8 + 2] + uVar9,uVar6);
      local_40[uVar8] = local_40[uVar8] + 1;
      uVar9 = uVar2 & 3;
      uVar8 = *(uint *)(uVar2 & 0xfffffffc);
      uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      uVar7 = uVar7 + 1 & 0xffff;
    } while (uVar7 < *(byte *)(uVar9 + 0x3d0));
  }
  uVar7 = uRam020c2300;
  uVar9 = 0;
  do {
    bVar5 = true;
    uVar8 = *(uint *)(uRam020c22fc & 0xfffffffc) >> (uRam020c22fc & 3) * 8 |
            *(uint *)(uRam020c22fc & 0xfffffffc) << (uRam020c22fc & 3) * -8 + 0x20;
    uVar2 = uVar8 + 0x1c;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) != 1) &&
       (uVar8 = uVar8 + 8, uVar2 = uVar8 & 3, uVar8 = *(uint *)(uVar8 & 0xfffffffc),
       (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) != 2)) {
      bVar5 = false;
    }
    if (bVar5) {
      iVar3 = GetSomeLUMaxIndex();
      uVar4 = (ushort)*(byte *)((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) +
                                iVar3 * 8 + uVar9 * 4 + 0x146);
    }
    else {
      iVar3 = GetSomeLUMaxIndex();
      uVar4 = *(ushort *)
               ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x144 + iVar3 * 8 +
               uVar9 * 4);
    }
    if (uVar9 == 0) {
      uVar6 = -uVar10;
    }
    uVar2 = uVar6;
    if (uVar9 != 0) {
      uVar2 = uVar10;
    }
    uVar6 = 0xb6;
    func_020c2304(param_1,uVar4,local_40[uVar9 + 4] + uVar2);
    uVar9 = uVar9 + 1 & 0xffff;
  } while (uVar9 < 2);
  return;
}

