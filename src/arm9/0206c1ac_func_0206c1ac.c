/* Decompiled C draft; module arm9; ROM address 0206c1ac. No matching claim. */
#include "types.h"
#include "deps/0206c1ac_func_0206c1ac.h"

void func_0206c1ac(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_20;
  int local_1c;
  int local_18;
  
  local_20 = *(int *)(param_2 + 0x80);
  local_1c = *(int *)(param_2 + 0x84);
  local_18 = *(int *)(param_2 + 0x88);
  uVar5 = param_2 + 0x1d0U & 3;
  uVar6 = *(uint *)(param_2 + 0x1d0U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = (uint)((ulonglong)uRam0206c2b0 * (ulonglong)uVar6);
  VecFx32_AddScale1(uVar5 + 0x800 >> 0xc |
                    (((int)uVar6 >> 0x1f) * uRam0206c2b0 +
                     ((int)((ulonglong)uRam0206c2b0 * (ulonglong)uVar6 >> 0x20) - uVar6) +
                    (uint)(0xfffff7ff < uVar5)) * 0x100000,param_2 + 0x138,&local_20);
  uVar5 = param_1 + 0x20U & 3;
  uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 4;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + (local_20 >> 4);
  uVar5 = param_1 + 0x20U & 3;
  uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 8;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) = (local_1c >> 4) + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  uVar5 = param_1 + 0x20U & 3;
  uVar6 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0xc;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) = (local_18 >> 4) + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  uVar5 = param_2 + 0x138U & 3;
  uVar2 = *(uint *)(param_2 + 0x138U & 0xfffffffc);
  uVar6 = param_2 + 0x13cU & 3;
  uVar3 = *(uint *)(param_2 + 0x13cU & 0xfffffffc);
  uVar1 = param_2 + 0x140U & 3;
  uVar4 = *(uint *)(param_2 + 0x140U & 0xfffffffc);
  *(ushort *)(param_1 + 0x50) = (ushort)(uVar2 >> uVar5 * 8) | (ushort)(uVar2 << uVar5 * -8 + 0x20);
  *(ushort *)(param_1 + 0x52) = (ushort)(uVar3 >> uVar6 * 8) | (ushort)(uVar3 << uVar6 * -8 + 0x20);
  *(ushort *)(param_1 + 0x54) = (ushort)(uVar4 >> uVar1 * 8) | (ushort)(uVar4 << uVar1 * -8 + 0x20);
  return;
}

