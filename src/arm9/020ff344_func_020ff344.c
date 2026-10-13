/* Decompiled C draft; module arm9; ROM address 020ff344. No matching claim. */
#include "types.h"
#include "deps/020ff344_func_020ff344.h"

void func_020ff344(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  uint uVar5;
  
  uVar5 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar3 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x94U & 3;
  uVar2 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  uVar2 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x9cU & 3;
  uVar4 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 +
          (longlong)(int)uVar2 * (longlong)(int)uVar2 + (longlong)(int)uVar3 * (longlong)(int)uVar3;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(param_1 + 0x94,(int *)(uintptr_t)(param_1 + 0x94));
  }
  Vector3_Cross(param_1 + 0x94,param_1 + 0xa0,(uint *)(uintptr_t)(param_1 + 0xac));
  MTX_Concat33(uRam020ff3bc,(uint *)(uintptr_t)(param_1 + 0x94),(uint *)(uintptr_t)(param_1 + 0x94));
  uVar5 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam020ff3c0;
  }
  return;
}

