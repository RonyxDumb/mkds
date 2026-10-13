/* Decompiled C draft; module arm9; ROM address 020745d4. No matching claim. */
#include "types.h"
#include "deps/020745d4_func_020745d4.h"

void func_020745d4(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4,int param_5,
                  int param_6)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  
  local_54 = *(undefined4 *)(param_4 + 0x80);
  local_50 = *(int *)(param_4 + 0x84);
  local_4c = *(undefined4 *)(param_4 + 0x88);
  local_48 = *(undefined4 *)(param_4 + 0x80);
  uStack_40 = *(undefined4 *)(param_4 + 0x88);
  local_44 = *(int *)(param_4 + 0x84) - param_5;
  VecFx32_AddScale1(param_6,param_4 + 300,&local_48);
  local_50 = local_50 + (param_6 - param_5);
  uVar3 = param_4 + 0x48U & 3;
  uVar2 = *(uint *)(param_4 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x40000000) == 0) {
    uStack_3c = *puRam020747e8;
    uStack_38 = puRam020747e8[1];
    uStack_34 = puRam020747e8[2];
  }
  else {
    VecFx32_Subtract(&local_48,&local_54,&uStack_3c);
    VecFx32_AddScale1(0xa000,param_4 + 300,&uStack_3c,&uStack_3c);
  }
  VecFx32_Subtract(&uStack_3c,param_2,&local_30);
  local_30 = (uint)((ulonglong)uRam020747ec * (ulonglong)local_30) >> 0xc |
             (((int)local_30 >> 0x1f) * uRam020747ec +
             (int)((ulonglong)uRam020747ec * (ulonglong)local_30 >> 0x20)) * 0x100000;
  local_2c = (uint)((ulonglong)uRam020747ec * (ulonglong)local_2c) >> 0xc |
             (((int)local_2c >> 0x1f) * uRam020747ec +
             (int)((ulonglong)uRam020747ec * (ulonglong)local_2c >> 0x20)) * 0x100000;
  local_28 = (uint)((ulonglong)uRam020747ec * (ulonglong)local_28) >> 0xc |
             (((int)local_28 >> 0x1f) * uRam020747ec +
             (int)((ulonglong)uRam020747ec * (ulonglong)local_28 >> 0x20)) * 0x100000;
  VecFx32_Add(param_2,&local_30,param_2);
  VecFx32_Add(&local_54,param_2,&local_54);
  *param_1 = local_54;
  param_1[2] = local_4c;
  uVar3 = param_4 + 0x48U & 3;
  uVar2 = *(uint *)(param_4 + 0x48U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x10000) == 0) {
    uVar4 = *(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
            *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20;
    uVar3 = -uVar4;
    lVar1 = (ulonglong)uVar3 * 0x29;
    uVar2 = (uint)lVar1;
    *param_3 = uVar4 + (uVar2 + 0x800 >> 0xc |
                       (((int)uVar3 >> 0x1f) * 0x29 + (int)((ulonglong)lVar1 >> 0x20) +
                       (uint)(0xfffff7ff < uVar2)) * 0x100000);
  }
  else {
    *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) + 0x1000;
    if (0xa000 < (int)(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
                      *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20)) {
      *param_3 = 0xa000;
    }
  }
  uVar3 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar4 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = (local_50 -
          (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
          *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20)) - uVar4;
  lVar1 = (ulonglong)uRam020747f0 * (ulonglong)uVar3;
  uVar2 = (uint)lVar1;
  param_1[1] = uVar4 + (uVar2 + 0x800 >> 0xc |
                       (((int)uVar3 >> 0x1f) * uRam020747f0 + (int)((ulonglong)lVar1 >> 0x20) +
                       (uint)(0xfffff7ff < uVar2)) * 0x100000);
  return;
}

