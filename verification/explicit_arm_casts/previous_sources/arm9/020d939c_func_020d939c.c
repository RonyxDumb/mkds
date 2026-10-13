/* Decompiled C draft; module arm9; ROM address 020d939c. No matching claim. */
#include "types.h"
#include "deps/020d939c_func_020d939c.h"

void func_020d939c(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                  uint *param_5)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  func_020d970c(param_2,&local_34,&local_30,&local_2c,&local_28,&local_24,&local_20,&local_1c,
                &local_18);
  func_020d95c0(param_1,param_4,local_34,local_30,local_2c,local_28);
  func_020d95c0(param_1,param_5,local_24,local_20,local_1c,local_18);
  lVar2 = (longlong)
          (int)(*(uint *)((uint)param_5 & 0xfffffffc) >> ((uint)param_5 & 3) * 8 |
               *(uint *)((uint)param_5 & 0xfffffffc) << ((uint)param_5 & 3) * -8 + 0x20) *
          (longlong)param_3;
  *param_5 = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  uVar1 = (uint)(param_5 + 1) & 3;
  uVar3 = *(uint *)((uint)(param_5 + 1) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_3;
  param_5[1] = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  uVar1 = (uint)(param_5 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_5 + 2) & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)param_3;
  param_5[2] = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  return;
}

