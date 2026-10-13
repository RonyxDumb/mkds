/* Decompiled C draft; module arm9; ROM address 0203e9a0. No matching claim. */
#include "types.h"
#include "deps/0203e9a0_NotifyDriverFinished.h"

void NotifyDriverFinished(undefined4 *param_1,int param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (((uint)*(ushort *)(param_1 + 0xf) << 0x18) >> 0x1c) * 0x30 +
          (*(uint *)(uRam0203eb20 & 0xfffffffc) >> (uRam0203eb20 & 3) * 8 |
          *(uint *)(uRam0203eb20 & 0xfffffffc) << (uRam0203eb20 & 3) * -8 + 0x20) + 0x7c;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (param_2 == 0) {
    *param_1 = 3;
  }
  else {
    *param_1 = 1;
  }
  iVar3 = (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) * 0x5c;
  uVar5 = iRam0203eb24 + iVar3 & 3;
  uVar2 = *(uint *)(iRam0203eb24 + iVar3 & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if (uVar5 == 1) {
    func_0204a904(iRam0203eb28 + iVar3 + 0x28);
  }
  else if (uVar5 == 2) {
    func_0204a928(iRam0203eb28 + iVar3 + 0x28);
  }
  *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 8;
  if (((*(ushort *)(param_1 + 0xc) & 1) != 0) && ((*(ushort *)(param_1 + 0xc) & 0x10) == 0)) {
    func_020c7164();
  }
  if (param_2 == 0) {
    uVar5 = (*(uint *)(uRam0203eb20 & 0xfffffffc) >> (uRam0203eb20 & 3) * 8 |
            *(uint *)(uRam0203eb20 & 0xfffffffc) << (uRam0203eb20 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) != 5) {
      param_1[0xb] = uRam0203eb2c;
    }
  }
  else {
    param_1[0xb] = ((uint)*(byte *)((int)param_1 + 0x22) * 0x3c +
                   (uint)*(byte *)((int)param_1 + 0x23)) * 1000 + (uint)*(ushort *)(param_1 + 8);
  }
  uVar5 = (*(uint *)(uRam0203eb20 & 0xfffffffc) >> (uRam0203eb20 & 3) * 8 |
          *(uint *)(uRam0203eb20 & 0xfffffffc) << (uRam0203eb20 & 3) * -8 + 0x20) + 8;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  if (((uVar5 == 0) || (uVar5 == 4)) && ((*(ushort *)(param_1 + 0xc) & 1) != 0)) {
    uVar1 = ComputeDriverSkillRankpoints(((uint)*(ushort *)(param_1 + 0xf) << 0x18) >> 0x1c);
    *(undefined2 *)((int)param_1 + 0x3e) = uVar1;
    uVar5 = (*(uint *)(uRam0203eb20 & 0xfffffffc) >> (uRam0203eb20 & 3) * 8 |
            *(uint *)(uRam0203eb20 & 0xfffffffc) << (uRam0203eb20 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) == 4) {
      *(int *)((*(uint *)(uRam0203eb30 & 0xfffffffc) >> (uRam0203eb30 & 3) * 8 |
               *(uint *)(uRam0203eb30 & 0xfffffffc) << (uRam0203eb30 & 3) * -8 + 0x20) + 0x140) =
           (int)*(short *)((int)param_1 + 0x3e);
    }
    else {
      uVar4 = *(uint *)(uRam0203eb30 & 0xfffffffc) >> (uRam0203eb30 & 3) * 8 |
              *(uint *)(uRam0203eb30 & 0xfffffffc) << (uRam0203eb30 & 3) * -8 + 0x20;
      uVar5 = uVar4 + 0x140;
      uVar2 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      *(uint *)(uVar4 + 0x140) =
           (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + (int)*(short *)((int)param_1 + 0x3e);
    }
  }
  uVar5 = *(uint *)(uRam0203eb34 & 0xfffffffc) >> (uRam0203eb34 & 3) * 8 |
          *(uint *)(uRam0203eb34 & 0xfffffffc) << (uRam0203eb34 & 3) * -8 + 0x20;
  *(short *)(uVar5 + 0xe) = *(short *)(uVar5 + 0xe) + 1;
  return;
}

