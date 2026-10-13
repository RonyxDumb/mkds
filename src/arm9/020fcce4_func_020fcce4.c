/* Decompiled C draft; module arm9; ROM address 020fcce4. No matching claim. */
#include "types.h"
#include "deps/020fcce4_func_020fcce4.h"

void func_020fcce4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar7;
  int unaff_r7;
  bool bVar8;
  int local_30;
  int local_2c;
  int local_28;
  uint uVar6;
  
  uVar5 = param_1 + 0x228U & 3;
  uVar1 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 0x1fc;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  uVar5 = uVar6 + 0x48 & 3;
  uVar1 = *(uint *)(uVar6 + 0x48 & 0xfffffffc);
  bVar8 = ((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 1) != 0;
  uVar3 = *(undefined4 *)(uVar6 + 0x60);
  uVar4 = *(undefined4 *)(uVar6 + 100);
  *(undefined4 *)(param_1 + 0x22c) = *(undefined4 *)(uVar6 + 0x5c);
  *(undefined4 *)(param_1 + 0x230) = uVar3;
  *(undefined4 *)(param_1 + 0x234) = uVar4;
  if (bVar8) {
    unaff_r7 = 1;
  }
  uVar5 = uVar6 + 0x44 & 3;
  uVar1 = *(uint *)(uVar6 + 0x44 & 0xfffffffc);
  if (!bVar8) {
    unaff_r7 = 0;
  }
  iVar7 = param_1 + 0x50;
  if (((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0x100) != 0) {
    uVar5 = param_1 + 0x22cU & 3;
    uVar1 = *(uint *)(param_1 + 0x22cU & 0xfffffffc);
    *(uint *)(param_1 + 0x22c) = -(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
    uVar5 = param_1 + 0x230U & 3;
    uVar1 = *(uint *)(param_1 + 0x230U & 0xfffffffc);
    *(uint *)(param_1 + 0x230) = -(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
    uVar5 = param_1 + 0x234U & 3;
    uVar1 = *(uint *)(param_1 + 0x234U & 0xfffffffc);
    *(uint *)(param_1 + 0x234) = -(uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
  }
  iVar2 = StructMQRacerEntry_SomeFn_64(uVar6);
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)(uVar6 + 0x9c);
    uVar4 = *(undefined4 *)(uVar6 + 0xa0);
    *(undefined4 *)(param_1 + 0x244) = *(undefined4 *)(uVar6 + 0x98);
    *(undefined4 *)(param_1 + 0x248) = uVar3;
    *(undefined4 *)(param_1 + 0x24c) = uVar4;
  }
  VecFx32_AddScale1(uRam020fce90,param_1 + 0x22c,param_1 + 0x244,&local_30);
  if (unaff_r7 == 0) {
    local_2c = local_2c + param_3;
  }
  else {
    VecFx32_AddScale1(param_3,uVar6 + 0x244,(uint)(uintptr_t)(&local_30),&local_30);
  }
  VecFx32_Subtract((uint)(uintptr_t)(&local_30),iVar7,&local_30);
  *(uint *)(param_1 + 0x5c) =
       (uint)((longlong)local_30 * (longlong)param_2) >> 0xc |
       (int)((ulonglong)((longlong)local_30 * (longlong)param_2) >> 0x20) << 0x14;
  *(uint *)(param_1 + 0x60) =
       (uint)((longlong)local_2c * (longlong)param_2) >> 0xc |
       (int)((ulonglong)((longlong)local_2c * (longlong)param_2) >> 0x20) << 0x14;
  *(uint *)(param_1 + 100) =
       (uint)((longlong)local_28 * (longlong)param_2) >> 0xc |
       (int)((ulonglong)((longlong)local_28 * (longlong)param_2) >> 0x20) << 0x14;
  VecFx32_Add((uint)(uintptr_t)((uint *)(param_1 + 0x5c)),iVar7,(int *)(uintptr_t)(iVar7));
  if (unaff_r7 != 0) {
    uVar5 = param_1 + 0xdcU & 3;
    uVar1 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
    iVar2 = func_01ffdee4(iVar7,param_1 + 0xe4,0,uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20);
    if (iVar2 != 0) {
      VecFx32_Add(iVar7,(uint)(uintptr_t)(&local_30),(int *)(uintptr_t)(iVar7));
      return;
    }
    return;
  }
  return;
}

