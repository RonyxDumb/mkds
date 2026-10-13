/* Decompiled C draft; module arm9; ROM address 020749a4. No matching claim. */
#include "types.h"
#include "deps/020749a4_StructHD_SomeFn_11.h"

void StructHD_SomeFn_11(int param_1,int param_2)

{
  ushort uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint uVar8;
  
  uVar6 = param_1 + 0x218U & 3;
  uVar7 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar8 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  uVar6 = (*(uint *)(uRam02074afc & 0xfffffffc) >> (uRam02074afc & 3) * 8 |
          *(uint *)(uRam02074afc & 0xfffffffc) << (uRam02074afc & 3) * -8 + 0x20) + 8;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar1 = *(ushort *)
           ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + (uint)*(ushort *)(uVar8 + 0x40) * 4
           + 2);
  if (3 < uVar1) {
    func_0207bc9c(param_1 + 0x24,param_1 + 0x194,uVar8,param_2);
    return;
  }
  if (1 < uVar1) {
    puVar3 = (undefined4 *)GetLoadedNkmPathEntryPOIT((uint)*(ushort *)(uVar8 + 0x40),0);
    uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(uVar8 + 0x40),1);
    uStack_38 = *puVar3;
    uStack_34 = puVar3[1];
    uStack_30 = puVar3[2];
    VecFx32_Subtract(uVar4,(uint)(uintptr_t)(puVar3),&iStack_2c);
    iVar5 = 0;
    lVar2 = (longlong)iStack_24 * (longlong)iStack_24 +
            (longlong)iStack_2c * (longlong)iStack_2c + (longlong)iStack_28 * (longlong)iStack_28;
    if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
      iVar5 = Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_2c),&iStack_2c);
    }
    uVar6 = param_1 + 0x1c4U & 3;
    uVar7 = *(uint *)(param_1 + 0x1c4U & 0xfffffffc);
    *(uint *)(param_1 + 0x1c4) = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) + param_2;
    uVar6 = param_1 + 0x1c4U & 3;
    uVar7 = *(uint *)(param_1 + 0x1c4U & 0xfffffffc);
    if (0xfff < (int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x1c4) = 0x1000;
    }
    uVar6 = param_1 + 0x1c4U & 3;
    uVar7 = *(uint *)(param_1 + 0x1c4U & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) * (longlong)iVar5;
    uVar6 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
    uStack_18 = (uint)((longlong)iStack_24 * (longlong)(int)uVar6) >> 0xc |
                (int)((ulonglong)((longlong)iStack_24 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    uStack_20 = (uint)((longlong)iStack_2c * (longlong)(int)uVar6) >> 0xc |
                (int)((ulonglong)((longlong)iStack_2c * (longlong)(int)uVar6) >> 0x20) << 0x14;
    uStack_1c = (uint)((longlong)iStack_28 * (longlong)(int)uVar6) >> 0xc |
                (int)((ulonglong)((longlong)iStack_28 * (longlong)(int)uVar6) >> 0x20) << 0x14;
    VecFx32_Add((uint)(uintptr_t)(&uStack_38),(uint)(uintptr_t)(&uStack_20),(int *)(uintptr_t)(param_1 + 0x24));
    return;
  }
  return;
}

