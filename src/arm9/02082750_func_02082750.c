/* Decompiled C draft; module arm9; ROM address 02082750. No matching claim. */
#include "types.h"
#include "deps/02082750_func_02082750.h"

void func_02082750(int param_1,int param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  int aiStack_70 [3];
  undefined1 auStack_64 [12];
  int aiStack_58 [2];
  int iStack_50;
  undefined1 auStack_4c [36];
  undefined4 uStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  
  if (param_2 != 0) {
    return;
  }
  iVar2 = GetGlobalHD5();
  iVar3 = GetDriverEntry((int)*(char *)((*(uint *)(uRam020829ec & 0xfffffffc) >>
                                         (uRam020829ec & 3) * 8 |
                                        *(uint *)(uRam020829ec & 0xfffffffc) <<
                                        (uRam020829ec & 3) * -8 + 0x20) + 0x62));
  aiStack_70[0] = *(int *)(iVar2 + 0x15c);
  aiStack_70[2] = *(int *)(iVar2 + 0x164);
  lVar1 = (longlong)aiStack_70[2] * (longlong)aiStack_70[2] +
          (longlong)aiStack_70[0] * (longlong)aiStack_70[0];
  aiStack_70[1] = 0;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize((uint)(uintptr_t)(aiStack_70),aiStack_70);
  }
  VecFx32_CrossProduct(uRam020829f0,(uint)(uintptr_t)(aiStack_70),(uint *)(void *)(auStack_64));
  uVar6 = iVar3 + 0x2a4U & 3;
  uVar8 = *(uint *)(iVar3 + 0x2a4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) *
          (longlong)
          (int)(*(uint *)(uRam020829f4 & 0xfffffffc) >> (uRam020829f4 & 3) * 8 |
               *(uint *)(uRam020829f4 & 0xfffffffc) << (uRam020829f4 & 3) * -8 + 0x20) + 0x800;
  uVar8 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
  uStack_28 = *puRam020829f8;
  uStack_24 = puRam020829f8[1];
  uStack_20 = puRam020829f8[2];
  uVar6 = iVar3 + 0x44U & 3;
  uVar4 = *(uint *)(iVar3 + 0x44U & 0xfffffffc);
  if (0x1000 < (int)uVar8) {
    uVar8 = 0x1000;
  }
  bVar10 = ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x100) != 0;
  uVar6 = uStack_24;
  if (bVar10) {
    uVar8 = -uVar8;
    uVar6 = uRam02082a00;
  }
  uVar4 = 0;
  if (bVar10) {
    uVar4 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  }
  iVar3 = (int)(iRam020829fc * uVar8 + 0x800 >> 0xc & 0xffff) >> 4;
  func_02146f98((int *)(void *)(auStack_4c),(uint)(uintptr_t)(auStack_64),(int)*(short *)(iRam02082a04 + iVar3 * 4),
                (int)*(short *)(iRam02082a04 + (iVar3 * 2 + 1) * 2));
  MTX_MultVec33((uint)(uintptr_t)(&uStack_28),(uint)(uintptr_t)(auStack_4c),&uStack_28);
  *(int *)(param_1 + 0x68) =
       (int)((((0x1000 - uVar8) * 0x800 + 0x800 >> 0xc) + 0x800) * 0x10000) >> 0x10;
  uVar7 = uRam02082a08;
  uVar5 = uRam02082a00;
  *(short *)(param_1 + 0x50) = (short)uStack_28;
  *(short *)(param_1 + 0x52) = (short)uStack_24;
  *(short *)(param_1 + 0x54) = (short)uStack_20;
  uVar6 = uVar7 & 3;
  uVar9 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  lVar1 = (longlong)(int)((uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) + uVar4) *
          (longlong)(int)uVar8 + 0x800;
  VecFx32_AddScale1((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) +
                    ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000),(uint)(uintptr_t)(aiStack_70),
                    iVar2 + 0x9c,aiStack_58);
  iVar2 = GetDriverEntry((int)*(char *)((*(uint *)(uRam020829ec & 0xfffffffc) >>
                                         (uRam020829ec & 3) * 8 |
                                        *(uint *)(uRam020829ec & 0xfffffffc) <<
                                        (uRam020829ec & 3) * -8 + 0x20) + 0x62));
  uVar6 = iVar2 + 0x508U & 3;
  uVar4 = *(uint *)(iVar2 + 0x508U & 0xfffffffc);
  uVar6 = (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) + 4;
  uVar4 = uVar6 & 3;
  uVar7 = *(uint *)(uVar6 & 0xfffffffc);
  lVar1 = (longlong)
          (int)(*(uint *)(uRam02082a0c & 0xfffffffc) >> (uRam02082a0c & 3) * 8 |
               *(uint *)(uRam02082a0c & 0xfffffffc) << (uRam02082a0c & 3) * -8 + 0x20) *
          (longlong)(int)uVar8 + 0x800;
  uVar6 = param_1 + 0x20U & 3;
  uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar6 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + 4;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(param_1 + 0x28) = aiStack_58[0] + (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20);
  uVar6 = param_1 + 0x20U & 3;
  uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar6 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + 8;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (((int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) >> 4) -
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000)) +
       (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20);
  uVar6 = param_1 + 0x20U & 3;
  uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar6 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar6 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) + 0xc;
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(uint *)(param_1 + 0x30) = iStack_50 + (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20);
  return;
}

