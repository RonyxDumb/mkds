/* Decompiled C draft; module arm9; ROM address 0208ecd8. No matching claim. */
#include "types.h"
#include "deps/0208ecd8_func_0208ecd8.h"

void func_0208ecd8(int param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_50;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  uVar1 = param_2 + 0x20U & 3;
  uVar3 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
  iVar4 = GetDriverEntry(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  local_50 = *(int *)(iVar4 + 0x80);
  local_4c = *(int *)(iVar4 + 0x84);
  local_48 = *(int *)(iVar4 + 0x88);
  uVar1 = param_2 + 0x24U & 3;
  uVar3 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = iVar4 + 0x120U & 3;
  uVar5 = *(uint *)(iVar4 + 0x120U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)uVar3;
  local_44 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x124U & 3;
  uVar5 = *(uint *)(iVar4 + 0x124U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)uVar3;
  local_40 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x128U & 3;
  uVar5 = *(uint *)(iVar4 + 0x128U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)uVar3;
  local_3c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = param_2 + 0x28U & 3;
  uVar3 = *(uint *)(param_2 + 0x28U & 0xfffffffc);
  uVar5 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = iVar4 + 300U & 3;
  uVar3 = *(uint *)(iVar4 + 300U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)(int)uVar5;
  local_38 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x130U & 3;
  uVar3 = *(uint *)(iVar4 + 0x130U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)(int)uVar5;
  local_34 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x134U & 3;
  uVar3 = *(uint *)(iVar4 + 0x134U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) * (longlong)(int)uVar5;
  local_30 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x138U & 3;
  uVar6 = *(uint *)(iVar4 + 0x138U & 0xfffffffc);
  uVar3 = param_2 + 0x2cU & 3;
  uVar5 = *(uint *)(param_2 + 0x2cU & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  lVar2 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)(int)uVar3;
  local_2c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x13cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x13cU & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)uVar3;
  local_28 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar1 = iVar4 + 0x140U & 3;
  uVar5 = *(uint *)(iVar4 + 0x140U & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) * (longlong)(int)uVar3;
  local_24 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  VecFx32_Add((uint)(uintptr_t)(&local_50),(uint)(uintptr_t)(&local_44),&local_50);
  VecFx32_Add((uint)(uintptr_t)(&local_50),(uint)(uintptr_t)(&local_38),&local_50);
  VecFx32_Add((uint)(uintptr_t)(&local_50),(uint)(uintptr_t)(&local_2c),&local_50);
  uVar1 = param_2 + 0x1cU & 3;
  uVar3 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(int *)(param_1 + 0x10) = local_50 >> 4;
  *(int *)(param_1 + 0x14) = local_4c >> 4;
  *(int *)(param_1 + 0x18) = local_48 >> 4;
  return;
}

