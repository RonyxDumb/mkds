/* Decompiled C draft; module arm9; ROM address 020d970c. No matching claim. */
#include "types.h"
#include "deps/020d970c_func_020d970c.h"

void func_020d970c(int param_1,uint *param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6
                  ,int *param_7,int *param_8,uint *param_9)

{
  longlong lVar1;
  int iVar2;
  
  iVar2 = 0x1000000 - param_1;
  *param_6 = (uint)((longlong)iVar2 * (longlong)iVar2) >> 0x18 |
             (int)((ulonglong)((longlong)iVar2 * (longlong)iVar2) >> 0x20) << 8;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_6 & 0xfffffffc) >> ((uint)param_6 & 3) * 8 |
               *(uint *)((uint)param_6 & 0xfffffffc) << ((uint)param_6 & 3) * -8 + 0x20) *
          (longlong)iVar2;
  *param_2 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  *param_9 = (uint)((longlong)param_1 * (longlong)param_1) >> 0x18 |
             (int)((ulonglong)((longlong)param_1 * (longlong)param_1) >> 0x20) << 8;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_9 & 0xfffffffc) >> ((uint)param_9 & 3) * 8 |
               *(uint *)((uint)param_9 & 0xfffffffc) << ((uint)param_9 & 3) * -8 + 0x20) *
          (longlong)param_1;
  *param_5 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  *param_3 = ((uint)((longlong)iVar2 * (longlong)param_1) >> 0x18 |
             (int)((ulonglong)((longlong)iVar2 * (longlong)param_1) >> 0x20) << 8) * 3;
  *param_6 = (*(uint *)((uint)param_6 & 0xfffffffc) >> ((uint)param_6 & 3) * 8 |
             *(uint *)((uint)param_6 & 0xfffffffc) << ((uint)param_6 & 3) * -8 + 0x20) * 3;
  *param_9 = (*(uint *)((uint)param_9 & 0xfffffffc) >> ((uint)param_9 & 3) * 8 |
             *(uint *)((uint)param_9 & 0xfffffffc) << ((uint)param_9 & 3) * -8 + 0x20) * 3;
  *param_8 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) << 1;
  *param_7 = (*(uint *)((uint)param_6 & 0xfffffffc) >> ((uint)param_6 & 3) * 8 |
             *(uint *)((uint)param_6 & 0xfffffffc) << ((uint)param_6 & 3) * -8 + 0x20) -
             (*(uint *)((uint)param_8 & 0xfffffffc) >> ((uint)param_8 & 3) * 8 |
             *(uint *)((uint)param_8 & 0xfffffffc) << ((uint)param_8 & 3) * -8 + 0x20);
  *param_8 = (*(uint *)((uint)param_8 & 0xfffffffc) >> ((uint)param_8 & 3) * 8 |
             *(uint *)((uint)param_8 & 0xfffffffc) << ((uint)param_8 & 3) * -8 + 0x20) -
             (*(uint *)((uint)param_9 & 0xfffffffc) >> ((uint)param_9 & 3) * 8 |
             *(uint *)((uint)param_9 & 0xfffffffc) << ((uint)param_9 & 3) * -8 + 0x20);
  *param_6 = -(*(uint *)((uint)param_6 & 0xfffffffc) >> ((uint)param_6 & 3) * 8 |
              *(uint *)((uint)param_6 & 0xfffffffc) << ((uint)param_6 & 3) * -8 + 0x20);
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) *
          (longlong)param_1;
  *param_4 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  lVar1 = (longlong)
          (int)(*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
               *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) *
          (longlong)iVar2;
  *param_3 = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
  return;
}

