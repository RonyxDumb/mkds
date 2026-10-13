/* Decompiled C draft; module arm9; ROM address 020fc654. No matching claim. */
#include "types.h"
#include "deps/020fc654_func_020fc654.h"

void func_020fc654(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_18 [12];
  uint uVar4;
  
  iVar2 = iRam020fc790;
  uVar9 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar4 = param_1 + 0x260U & 3;
  uVar3 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (((uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) & 0x40000000) != 0) {
    *(short *)(param_1 + 0x268) = *(short *)(param_1 + 0x268) + (short)uRam020fc78c;
    uVar9 = param_1 + 0x264U & 3;
    uVar3 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) *
            (longlong)(int)*(short *)(iVar2 + ((int)(uint)*(ushort *)(param_1 + 0x268) >> 4) * 4);
    VecFx32_AddScale1(uVar4 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14),
                      param_1 + 0xf0,param_1 + 0x50,(int *)(void *)(auStack_18));
    VecFx32_Subtract((uint)(uintptr_t)(auStack_18),param_1 + 0xc4,(int *)(void *)(auStack_18));
    VecFx32_AddScale1(uRam020fc794,(uint)(uintptr_t)(auStack_18),param_1 + 0xc4,(int *)(uintptr_t)(param_1 + 0xc4));
    return;
  }
  uVar9 = param_1 + 200U & 3;
  uVar6 = *(uint *)(param_1 + 200U & 0xfffffffc);
  uVar3 = param_1 + 0x60U & 3;
  uVar5 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  *(uint *)(param_1 + 200) =
       (uVar6 >> uVar9 * 8 | uVar6 << uVar9 * -8 + 0x20) +
       ((int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) >> 1);
  iVar2 = iRam020fc790;
  *(short *)(param_1 + 0x268) = *(short *)(param_1 + 0x268) + (short)uRam020fc78c;
  uVar9 = param_1 + 0x264U & 3;
  uVar8 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
  uVar3 = param_1 + 0x54U & 3;
  uVar6 = *(uint *)(param_1 + 0x54U & 0xfffffffc);
  uVar5 = param_1 + 200U & 3;
  uVar7 = *(uint *)(param_1 + 200U & 0xfffffffc);
  uVar5 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) *
          (longlong)(int)*(short *)(iVar2 + ((int)(uint)*(ushort *)(param_1 + 0x268) >> 4) * 4);
  uVar9 = (uVar4 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
          (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20)) - uVar5;
  lVar1 = (ulonglong)uRam020fc798 * (ulonglong)uVar9;
  *(uint *)(param_1 + 200) =
       uVar5 + ((uint)lVar1 >> 0xc |
               (((int)uVar9 >> 0x1f) * uRam020fc798 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar9 = param_1 + 0x50U & 3;
  uVar4 = *(uint *)(param_1 + 0x50U & 0xfffffffc);
  *(uint *)(param_1 + 0xc4) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  uVar9 = param_1 + 0x58U & 3;
  uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  *(uint *)(param_1 + 0xcc) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
  return;
}

