/* Decompiled C draft; module arm9; ROM address 02040a8c. No matching claim. */
#include "types.h"
#include "deps/02040a8c_MaybeComputeGPScore.h"

void MaybeComputeGPScore(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = GetGlobalRK();
  uVar3 = *(uint *)(uRam02040bbc & 0xfffffffc) >> (uRam02040bbc & 3) * 8 |
          *(uint *)(uRam02040bbc & 0xfffffffc) << (uRam02040bbc & 3) * -8 + 0x20;
  uVar5 = uVar3 + 0x4c8 & 3;
  uVar4 = *(uint *)(uVar3 + 0x4c8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (*(ushort *)(uVar3 + 0xc) == 0) {
    *param_1 = 0;
  }
  else {
    iVar2 = FX_Div((uint)*(ushort *)(uVar5 + 10) *
                   ((uint)*(ushort *)(uVar3 + 0xc) -
                   (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                   *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20)));
    *param_1 = iVar2 + 0x800 >> 0xc;
  }
  uVar3 = param_2 * 0x8c + uVar3 + 0x3c;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  iVar2 = FX_Div((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) << 0xc,
                 (uint)*(ushort *)
                        ((*(uint *)(uRam02040bbc & 0xfffffffc) >> (uRam02040bbc & 3) * 8 |
                         *(uint *)(uRam02040bbc & 0xfffffffc) << (uRam02040bbc & 3) * -8 + 0x20) +
                        0xc) << 0xc);
  param_1[1] = (int)((uint)*(ushort *)(uVar5 + 0xc) * iVar2) >> 0xc;
  if (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 == 0 &&
      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20 == 0) {
    param_1[2] = 0;
  }
  else {
    param_1[2] = (uint)*(ushort *)(uVar5 + 0xe);
  }
  uVar3 = uVar1 + 4 & 3;
  uVar4 = *(uint *)(uVar1 + 4 & 0xfffffffc);
  param_1[3] = (uint)*(ushort *)(uVar5 + 0x10) * (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  uVar3 = uVar1 + 8 & 3;
  uVar4 = *(uint *)(uVar1 + 8 & 0xfffffffc);
  param_1[4] = (uint)*(ushort *)(uVar5 + 0x12) * (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  iVar2 = FX_Inv((uint)*(ushort *)(uVar5 + 0x14) << 0xc);
  uVar3 = uVar1 + 0xc & 3;
  uVar4 = *(uint *)(uVar1 + 0xc & 0xfffffffc);
  param_1[5] = -((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * iVar2 >> 0xc);
  uVar3 = uVar1 + 0x10 & 3;
  uVar4 = *(uint *)(uVar1 + 0x10 & 0xfffffffc);
  param_1[6] = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * -(uint)*(ushort *)(uVar5 + 0x16);
  uVar3 = uVar1 + 0x14 & 3;
  uVar4 = *(uint *)(uVar1 + 0x14 & 0xfffffffc);
  param_1[7] = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) * -(uint)*(ushort *)(uVar5 + 0x18);
  uVar3 = uVar1 + 0x18 & 3;
  uVar1 = *(uint *)(uVar1 + 0x18 & 0xfffffffc);
  param_1[8] = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) * -(uint)*(ushort *)(uVar5 + 0x1a);
  return;
}

