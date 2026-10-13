/* Decompiled C draft; module arm9; ROM address 020e44e4. No matching claim. */
#include "types.h"
#include "deps/020e44e4_func_020e44e4.h"

void func_020e44e4(undefined4 param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = *(ushort *)(param_2 + 0x7e);
  StateDualHandler_Execute(param_2 + 0x80);
  iVar5 = (uint)*(ushort *)(param_2 + 0x7e) - (uint)uVar2;
  if (0x8000 < iVar5) {
    iVar5 = iVar5 + -0x10000;
  }
  uVar1 = param_2 + 0x34U & 3;
  uVar6 = *(uint *)(param_2 + 0x34U & 0xfffffffc);
  if (iVar5 < -0x8000) {
    iVar5 = iVar5 + 0x10000;
  }
  lVar3 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)iVar5;
  *(uint *)(param_2 + 0x124) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar1 = param_2 + 0x38U & 3;
  uVar6 = *(uint *)(param_2 + 0x38U & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)iVar5;
  *(uint *)(param_2 + 0x128) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  uVar1 = param_2 + 0x3cU & 3;
  uVar6 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
  lVar3 = (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * (longlong)iVar5;
  *(uint *)(param_2 + 300) = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  *(undefined4 *)(param_2 + 0xa0) = *(undefined4 *)(param_2 + 0x28);
  *(undefined4 *)(param_2 + 0xa4) = *(undefined4 *)(param_2 + 0x2c);
  *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_2 + 0x30);
  *(undefined4 *)(param_2 + 0xac) = *(undefined4 *)(param_2 + 0x34);
  *(undefined4 *)(param_2 + 0xb0) = *(undefined4 *)(param_2 + 0x38);
  *(undefined4 *)(param_2 + 0xb4) = *(undefined4 *)(param_2 + 0x3c);
  *(undefined4 *)(param_2 + 0xb8) = *(undefined4 *)(param_2 + 0x40);
  *(undefined4 *)(param_2 + 0xbc) = *(undefined4 *)(param_2 + 0x44);
  iVar4 = iRam020e460c;
  uVar1 = param_2 + 0x48U & 3;
  uVar6 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  *(uint *)(param_2 + 0xc0) = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
  iVar5 = (int)(uint)*(ushort *)(param_2 + 0x7e) >> 4;
  MTX_RotY33__from_thumb
            ((undefined4 *)(uintptr_t)(param_2 + 0x28),(int)*(short *)(iVar4 + iVar5 * 4),
             (int)*(short *)(iVar4 + (iVar5 * 2 + 1) * 2));
  MTX_Concat33(param_2 + 0x28,(uint *)(uintptr_t)(param_2 + 0xc4),(uint *)(uintptr_t)(param_2 + 0x28));
  uVar1 = param_2 + 0x104U & 3;
  uVar6 = *(uint *)(param_2 + 0x104U & 0xfffffffc);
  VecFx32_AddScale1(-(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20),param_2 + 0x34,param_2 + 4,
                    (int *)(uintptr_t)(param_2 + 0xf4));
  if (*(short *)(param_2 + 0x8e) != 3) {
    uVar1 = param_2 + 0x15cU & 3;
    uVar6 = *(uint *)(param_2 + 0x15cU & 0xfffffffc);
    if ((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) != 0xffffffff) {
      func_020d275c(param_2);
      return;
    }
    return;
  }
  return;
}

