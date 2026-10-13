/* Decompiled C draft; module arm9; ROM address 0207e400. No matching claim. */
#include "types.h"
#include "deps/0207e400_func_0207e400.h"

void func_0207e400(int *param_1,int param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 0x74);
  uVar2 = uRam0207e4a0;
  *(ushort *)((int)param_1 + 6) = *(ushort *)(param_1 + 1) & 3;
  param_1[0x22] = 0x1000;
  param_1[0x23] = 0;
  uVar3 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x2cc;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x10;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar3;
  uVar4 = (uint)lVar1;
  param_1[0x27] =
       uVar4 + 0x800 >> 0xc |
       (((int)uVar3 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20) + (uint)(0xfffff7ff < uVar4))
       * 0x100000;
  func_02080d34(param_1 + 2,(short)param_1[1]);
  func_0207f9cc(param_1,0);
  param_1[0x33] = 1;
  return;
}

