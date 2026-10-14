/* Decompiled C draft; module arm9; ROM address 0201c528. No matching claim. */
#include "types.h"
#include "deps/0201c528_func_0201c528.h"

void func_0201c528(uint param_1,int param_2,int *param_3)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  lVar1 = (ulonglong)uRam0201c5cc * (ulonglong)(0x1000U - param_2);
  uVar4 = (uint)lVar1;
  uVar3 = (uint)((ulonglong)uRam0201c5d0 * (ulonglong)param_1);
  uVar4 = uVar4 + 0x800 >> 0xc |
          (((int)(0x1000U - param_2) >> 0x1f) * uRam0201c5cc + (int)((ulonglong)lVar1 >> 0x20) +
          (uint)(0xfffff7ff < uVar4)) * 0x100000;
  param_2 = uVar4 + param_2;
  uVar3 = uVar3 + 0x800 >> 0xc |
          (((int)param_1 >> 0x1f) * uRam0201c5d0 +
           (int)((ulonglong)uRam0201c5d0 * (ulonglong)param_1 >> 0x20) + (uint)(0xfffff7ff < uVar3))
          * 0x100000;
  *param_3 = param_2;
  iVar5 = uVar4 + uVar3;
  param_3[3] = iVar5;
  iVar2 = uVar4 - uVar3;
  param_3[6] = iVar2;
  param_3[9] = 0;
  param_3[1] = iVar2;
  param_3[4] = param_2;
  param_3[7] = iVar5;
  param_3[10] = 0;
  param_3[2] = iVar5;
  param_3[5] = iVar2;
  param_3[8] = param_2;
  param_3[0xb] = 0;
  return;
}

