/* Decompiled C draft; module arm9; ROM address 020d9810. No matching claim. */
#include "types.h"
#include "deps/020d9810_func_020d9810.h"

void func_020d9810(int param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  
  iVar3 = 0x1000000 - param_1;
  lVar1 = (longlong)iVar3 *
          (longlong)
          (int)((uint)((longlong)iVar3 * (longlong)iVar3) >> 0x18 |
               (int)((ulonglong)((longlong)iVar3 * (longlong)iVar3) >> 0x20) << 8);
  lVar2 = (longlong)param_1 *
          (longlong)
          (int)((uint)((longlong)param_1 * (longlong)param_1) >> 0x18 |
               (int)((ulonglong)((longlong)param_1 * (longlong)param_1) >> 0x20) << 8);
  *param_2 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  *param_3 = ((uint)((longlong)iVar3 * (longlong)param_1) >> 0x18 |
             (int)((ulonglong)((longlong)iVar3 * (longlong)param_1) >> 0x20) << 8) * 3;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) *
          (longlong)param_1;
  *param_4 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  *param_5 = (uint)lVar2 >> 0x18 | (int)((ulonglong)lVar2 >> 0x20) << 8;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) *
          (longlong)iVar3;
  *param_3 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  return;
}

