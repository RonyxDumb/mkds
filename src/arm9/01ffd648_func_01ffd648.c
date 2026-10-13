/* Decompiled C draft; module arm9; ROM address 01ffd648. No matching claim. */
#include "types.h"
#include "deps/01ffd648_func_01ffd648.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint func_01ffd648(uint param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined1 local_20 [12];
  
  iVar1 = param_3 + param_2 >> 0xc;
  VecFx32_Subtract(param_1,uRam01ffd768,(int *)(void *)(local_20));
  uVar3 = iRam01ffd76c + 8U & 3;
  uVar6 = *(uint *)(iRam01ffd76c + 8U & 0xfffffffc);
  uVar7 = iRam01ffd76c + 0x10U & 3;
  uVar5 = *(uint *)(iRam01ffd76c + 0x10U & 0xfffffffc);
  iVar2 = (int)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
               (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20)) >> 0xc;
  uVar3 = param_1 + 8 & 3;
  uVar6 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar3 = (int)((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) -
               (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20)) >> 0xc;
  uVar5 = iVar2 * iVar2 + uVar3 * uVar3;
  uVar7 = uVar3;
  if (param_4 < (int)uVar5) {
    uVar7 = uRam01ffd770;
  }
  uVar6 = uVar5 & 0x3fffffe0;
  if (param_4 < (int)uVar5) {
    uVar6 = uVar6 | *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  }
  if (iVar1 * iVar1 < (int)uVar5) {
    if (param_5 < 2) {
      return uVar6 | 3;
    }
    uVar6 = uVar6 | *(uint *)(uRam01ffd774 & 0xfffffffc) >> (uRam01ffd774 & 3) * 8 |
                    *(uint *)(uRam01ffd774 & 0xfffffffc) << (uRam01ffd774 & 3) * -8 + 0x20;
  }
  uVar7 = param_1 + 4 & 3;
  uVar10 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar5 = iRam01ffd76c + 0xcU & 3;
  uVar9 = *(uint *)(iRam01ffd76c + 0xcU & 0xfffffffc);
  uVar4 = iRam01ffd76c + 0x24U & 3;
  uVar8 = *(uint *)(iRam01ffd76c + 0x24U & 0xfffffffc);
  iVar1 = (int)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) -
               (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20)) >> 0xc;
  uVar7 = iRam01ffd76c + 0x20U & 3;
  uVar9 = *(uint *)(iRam01ffd76c + 0x20U & 0xfffffffc);
  uVar5 = iRam01ffd76c + 0x28U & 3;
  uVar10 = *(uint *)(iRam01ffd76c + 0x28U & 0xfffffffc);
  if ((int)(uVar3 * (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) +
           iVar2 * (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
           iVar1 * (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20)) <= param_2) {
    uVar7 = iRam01ffd76c + 0x30U & 3;
    uVar9 = *(uint *)(iRam01ffd76c + 0x30U & 0xfffffffc);
    uVar5 = iRam01ffd76c + 0x2cU & 3;
    uVar10 = *(uint *)(iRam01ffd76c + 0x2cU & 0xfffffffc);
    uVar4 = iRam01ffd76c + 0x34U & 3;
    uVar8 = *(uint *)(iRam01ffd76c + 0x34U & 0xfffffffc);
    if (param_2 < (int)(uVar3 * (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
                       iVar2 * (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) +
                       iVar1 * (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20))) {
      uVar6 = uVar6 | 2;
    }
    return uVar6;
  }
  return uVar6 | 2;
}

