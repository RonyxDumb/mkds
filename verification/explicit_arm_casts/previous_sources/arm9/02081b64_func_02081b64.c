/* Decompiled C draft; module arm9; ROM address 02081b64. No matching claim. */
#include "types.h"
#include "deps/02081b64_func_02081b64.h"

void func_02081b64(int param_1,int param_2,int param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int local_28;
  int local_24;
  int local_20;
  short local_1c [2];
  short local_18;
  short local_14;
  uint uVar4;
  
  uVar2 = param_2 + 0x508U & 3;
  uVar3 = *(uint *)(param_2 + 0x508U & 0xfffffffc);
  uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  local_28 = (int)(*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                  *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) >> 4;
  uVar2 = uVar4 + 4 & 3;
  uVar3 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  local_24 = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = uVar4 + 8 & 3;
  uVar3 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  local_20 = (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 4;
  uVar2 = param_2 + 0xc4U & 3;
  uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)param_4 +
          0x800;
  VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,param_2 + 0x138,
                    &local_28,&local_28);
  uVar2 = param_2 + 0xc0U & 3;
  uVar3 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * (longlong)param_3 +
          0x800;
  VecFx32_AddScale1((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000,param_2 + 300,
                    &local_28,&local_28);
  uVar2 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 4;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = local_28 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar2 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = local_24 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar2 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0xc;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) = local_20 + (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  GetMQRacerVector333(param_2,local_1c);
  *(short *)(param_1 + 0x50) = -local_1c[0];
  *(short *)(param_1 + 0x52) = -local_18;
  *(short *)(param_1 + 0x54) = -local_14;
  return;
}

