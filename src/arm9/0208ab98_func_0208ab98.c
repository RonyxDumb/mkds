/* Decompiled C draft; module arm9; ROM address 0208ab98. No matching claim. */
#include "types.h"
#include "deps/0208ab98_func_0208ab98.h"

void func_0208ab98(ushort *param_1,uint param_2,int param_3)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = ~(uint)param_1[7] & param_2 & 0xffff;
  if (uVar3 != 0) {
    uVar4 = 0;
    do {
      if ((uVar3 & 1 << (uVar4 & 0xff)) != 0) break;
      uVar4 = uVar4 + 1 & 0xffff;
    } while (uVar4 < 4);
    uVar3 = (*(uint *)(uRam0208ad70 & 0xfffffffc) >> (uRam0208ad70 & 3) * 8 |
            *(uint *)(uRam0208ad70 & 0xfffffffc) << (uRam0208ad70 & 3) * -8 + 0x20) + 0x18;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar2 = *(ushort *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar4 * 2 + 0x18);
    param_1[1] = *param_1 & 0x1f;
    param_1[4] = (uVar2 & 0x1f) - param_1[1];
    param_1[2] = (ushort)((int)(uint)*param_1 >> 5) & 0x1f;
    param_1[5] = ((ushort)((int)(uint)uVar2 >> 5) & 0x1f) - param_1[2];
    param_1[3] = (ushort)((int)(uint)*param_1 >> 10) & 0x1f;
    param_1[6] = ((ushort)((int)(uint)uVar2 >> 10) & 0x1f) - param_1[3];
    param_1[8] = 0;
    param_1[7] = (ushort)(1 << (uVar4 & 0xff));
  }
  if (param_1[8] != 0x1000) {
    param_1[8] = param_1[8] + (short)(param_3 * 0xa4 + 0x800U >> 0xc) + 0x29;
    if (0xfff < (short)param_1[8]) {
      param_1[8] = 0x1000;
    }
    iVar5 = (int)(short)param_1[8];
    *param_1 = (short)(((int)(short)param_1[1] + ((short)param_1[4] * iVar5 + 0x800U >> 0xc)) *
                       0x10000 >> 0x10) +
               (short)((int)(((int)(short)param_1[2] + ((short)param_1[5] * iVar5 + 0x800U >> 0xc))
                            * 0x10000) >> 0xb) +
               (short)((int)(((int)(short)param_1[3] + ((short)param_1[6] * iVar5 + 0x800U >> 0xc))
                            * 0x10000) >> 6);
    return;
  }
  return;
}

