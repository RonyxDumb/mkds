/* Decompiled C draft; module arm9; ROM address 0201d798. No matching claim. */
#include "types.h"
#include "deps/0201d798_func_0201d798.h"

void func_0201d798(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  short local_20;
  short local_1e;
  short local_1c;
  
  VecFx16_CrossProduct(param_3 + 0x84,param_3 + 0x8a,&local_20);
  VecFx16_Normalize(&local_20,&local_20);
  uVar1 = param_2 + 8 & 3;
  uVar7 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar5 = param_2 + 4 & 3;
  uVar6 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) * (longlong)(int)local_20
          + 0x800;
  lVar3 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
          (longlong)(int)*(short *)(param_3 + 0x84) + 0x800;
  lVar4 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
          (longlong)(int)*(short *)(param_3 + 0x8a) + 0x800;
  *param_1 = ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
             ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
             ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
  uVar1 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)local_1e
          + 0x800;
  uVar1 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar3 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
          (longlong)(int)*(short *)(param_3 + 0x86) + 0x800;
  lVar4 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
          (longlong)(int)*(short *)(param_3 + 0x8c) + 0x800;
  param_1[1] = ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
  uVar1 = param_2 + 8 & 3;
  uVar5 = *(uint *)(param_2 + 8 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)local_1c
          + 0x800;
  uVar1 = param_2 + 4 & 3;
  uVar5 = *(uint *)(param_2 + 4 & 0xfffffffc);
  lVar3 = (longlong)
          (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
               *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) *
          (longlong)(int)*(short *)(param_3 + 0x88) + 0x800;
  lVar4 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) *
          (longlong)(int)*(short *)(param_3 + 0x8e) + 0x800;
  param_1[2] = ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000) +
               ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) * 0x100000) +
               ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000);
  return;
}

