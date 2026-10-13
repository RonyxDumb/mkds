/* Decompiled C draft; module arm9; ROM address 020c3b6c. No matching claim. */
#include "types.h"
#include "deps/020c3b6c_func_020c3b6c.h"

void func_020c3b6c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  int local_58 [4];
  int local_48;
  int iStack_44;
  int iStack_40;
  int iStack_3c;
  int local_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int local_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  
  local_58[0] = *piRam020c3d94;
  local_58[1] = piRam020c3d94[1];
  local_58[2] = piRam020c3d94[2];
  local_58[3] = piRam020c3d94[3];
  local_48 = piRam020c3d94[4];
  iStack_44 = piRam020c3d94[5];
  iStack_40 = piRam020c3d94[6];
  iStack_3c = piRam020c3d94[7];
  uVar3 = *(uint *)(uRam020c3d98 & 0xfffffffc) >> (uRam020c3d98 & 3) * 8 |
          *(uint *)(uRam020c3d98 & 0xfffffffc) << (uRam020c3d98 & 3) * -8 + 0x20;
  uVar6 = uRam020c3d98 + 4 & 3;
  uVar2 = *(uint *)(uRam020c3d98 + 4 & 0xfffffffc);
  uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 >> 0x1f;
  bVar10 = (param_1 * -0x80000000 + uVar6 >> 0x1f | uVar6 << 1) != uVar6;
  local_38 = piRam020c3d94[8];
  iStack_34 = piRam020c3d94[9];
  iStack_30 = piRam020c3d94[10];
  iStack_2c = piRam020c3d94[0xb];
  local_28 = piRam020c3d94[0xc];
  iStack_24 = piRam020c3d94[0xd];
  iStack_20 = piRam020c3d94[0xe];
  iStack_1c = piRam020c3d94[0xf];
  if (bVar10) {
    iVar5 = 2;
  }
  else {
    iVar5 = 1;
  }
  uVar6 = (uint)bVar10;
  if (param_2 == 0) {
    iVar9 = local_58[param_1 * 2];
    uVar4 = *(uint *)(uRam020c3d9c & 0xfffffffc) >> (uRam020c3d9c & 3) * 8 |
            *(uint *)(uRam020c3d9c & 0xfffffffc) << (uRam020c3d9c & 3) * -8 + 0x20;
    iVar8 = (local_58[param_1 * 2 + 1] - iVar9) + 1;
    iVar7 = (uVar2 - uVar3) + 1;
    uVar2 = uVar4 + iVar5 * 4 + 0xc0;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020b4520(uVar4 + 0xd8 + uVar6 * 0x1000,uVar3,iVar9,iVar7,iVar8,
                  (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xc,uVar3,iVar9);
    uVar6 = (*(uint *)(uRam020c3d9c & 0xfffffffc) >> (uRam020c3d9c & 3) * 8 |
            *(uint *)(uRam020c3d9c & 0xfffffffc) << (uRam020c3d9c & 3) * -8 + 0x20) + iVar5 * 4 +
            0xc0;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    func_020b44a4((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0xc,uVar3,iVar9,iVar7,iVar8,9)
    ;
    return;
  }
  if (param_2 == 1) {
    iVar9 = local_58[param_1 * 2];
    uVar4 = *(uint *)(uRam020c3d9c & 0xfffffffc) >> (uRam020c3d9c & 3) * 8 |
            *(uint *)(uRam020c3d9c & 0xfffffffc) << (uRam020c3d9c & 3) * -8 + 0x20;
    iVar8 = (local_58[param_1 * 2 + 1] - iVar9) + 1;
    iVar7 = (uVar2 - uVar3) + 1;
    uVar2 = uVar4 + iVar5 * 4 + 0xc0;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020b4520(uVar4 + 0xd8 + uVar6 * 0x1000,uVar3,iVar9,iVar7,iVar8,
                  (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xc,uVar3,iVar9);
    uVar6 = (*(uint *)(uRam020c3d9c & 0xfffffffc) >> (uRam020c3d9c & 3) * 8 |
            *(uint *)(uRam020c3d9c & 0xfffffffc) << (uRam020c3d9c & 3) * -8 + 0x20) + iVar5 * 4 +
            0xc0;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    func_020b44a4((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0xc,uVar3,iVar9,iVar7,iVar8,8)
    ;
    return;
  }
  if (param_2 == 2) {
    uVar6 = (*(uint *)(uRam020c3d9c & 0xfffffffc) >> (uRam020c3d9c & 3) * 8 |
            *(uint *)(uRam020c3d9c & 0xfffffffc) << (uRam020c3d9c & 3) * -8 + 0x20) + iVar5 * 4 +
            0xc0;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    func_020b4428((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 0xc,uVar3,
                  local_58[param_1 * 2],(uVar2 - uVar3) + 1,
                  (local_58[param_1 * 2 + 1] - local_58[param_1 * 2]) + 1,0);
    return;
  }
  return;
}

