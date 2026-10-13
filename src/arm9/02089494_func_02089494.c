/* Decompiled C draft; module arm9; ROM address 02089494. No matching claim. */
#include "types.h"
#include "deps/02089494_func_02089494.h"

/* WARNING: Type propagation algorithm not settling */

void func_02089494(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_58 [12];
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [4];
  undefined4 uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [16];
  undefined4 *puVar3;
  uint uVar8;
  
  uVar9 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar10 = param_1 + 0x28;
  uVar2 = param_1 + 0x3c & 3;
  uVar7 = *(uint *)(param_1 + 0x3c & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  GetDriverMaybeSfxPosition((undefined4 *)(void *)(auStack_58),*(undefined2 *)(param_1 + 4));
  uVar2 = uVar9 + 0x48 & 3;
  uVar7 = *(uint *)(uVar9 + 0x48 & 0xfffffffc);
  if (((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) & 0x3840) != 0) {
    return;
  }
  if ((uVar8 == 0) ||
     ((*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
      *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) == uVar8)) {
    uVar2 = func_02061f90();
    if (*(ushort *)(param_1 + 4) == uVar2) {
      uVar2 = param_1 + 0x5c & 3;
      uVar7 = *(uint *)(param_1 + 0x5c & 0xfffffffc);
      uStack_34 = *(undefined4 *)(uVar9 + 0x138);
      uStack_30 = *(undefined4 *)(uVar9 + 0x13c);
      uStack_2c = *(undefined4 *)(uVar9 + 0x140);
      VecFx32_Subtract(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20,uVar9 + 0x80,(int *)(void *)(auStack_40));
      uStack_30 = 0;
      uStack_3c = 0;
      VecFx32_CrossProduct((uint)(uintptr_t)(&uStack_34),(uint)(uintptr_t)(auStack_40),(uint *)(void *)(auStack_28));
      uVar1 = VecFx32_Norm((uint)(uintptr_t)(auStack_28));
      uVar5 = Vector3_DotProduct((uint)(uintptr_t)(&uStack_34),(uint)(uintptr_t)(auStack_40));
      uVar2 = func_02148538(uVar1,uVar5);
      *(uint *)(param_1 + 0x70) =
           ((int)uVar2 >> 0x1f) * uRam020896dc +
           uVar2 * 0x39 + (int)((ulonglong)uRam020896dc * (ulonglong)uVar2 >> 0x20) +
           (uint)(0x7fffffff < (uint)((ulonglong)uRam020896dc * (ulonglong)uVar2));
    }
    iVar4 = func_02080e2c(uVar10,(undefined4)(uintptr_t)(auStack_58));
    if ((iVar4 != 0) || (iVar4 = func_02080dbc(uVar10,(undefined4)(uintptr_t)(auStack_58)), iVar4 != 0)) {
      func_020800f4(uVar10,auStack_58,uVar9 + 0x138,*(undefined2 *)(param_1 + 4));
      uVar1 = func_020800a0(uVar10);
      *(undefined4 *)(param_1 + 0xa4) = uVar1;
      func_020892bc(param_1);
      puVar6 = (undefined4 *)(param_1 + 0x44);
      uVar2 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
              *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x20;
      uVar7 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      puVar3 = (undefined4 *)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
      uVar1 = puVar3[1];
      uVar5 = puVar3[2];
      *puVar6 = *puVar3;
      *(undefined4 *)(param_1 + 0x48) = uVar1;
      *(undefined4 *)(param_1 + 0x4c) = uVar5;
      VecFx32_Add((uint)(uintptr_t)(puVar6),param_1 + 0x60,puVar6);
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
  }
  else {
    func_0208001c((undefined4 *)(uintptr_t)(uVar10),uVar8);
    uVar1 = func_020800a0(uVar10);
    *(undefined4 *)(param_1 + 0xa4) = uVar1;
    func_020892bc(param_1);
    puVar6 = (undefined4 *)(param_1 + 0x44);
    uVar2 = (*(uint *)(uVar10 & 0xfffffffc) >> (uVar10 & 3) * 8 |
            *(uint *)(uVar10 & 0xfffffffc) << (uVar10 & 3) * -8 + 0x20) + 0x20;
    uVar7 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    puVar3 = (undefined4 *)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
    uVar1 = puVar3[1];
    uVar5 = puVar3[2];
    *puVar6 = *puVar3;
    *(undefined4 *)(param_1 + 0x48) = uVar1;
    *(undefined4 *)(param_1 + 0x4c) = uVar5;
    VecFx32_Add((uint)(uintptr_t)(puVar6),param_1 + 0x60,puVar6);
  }
  uVar2 = uVar9 + 0x180 & 3;
  uVar7 = *(uint *)(uVar9 + 0x180 & 0xfffffffc);
  if (uVar7 >> uVar2 * 8 != 0 || uVar7 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  uVar2 = param_1 + 0xc4 & 3;
  uVar7 = *(uint *)(param_1 + 0xc4 & 0xfffffffc);
  if (uVar7 >> uVar2 * 8 != 0 || uVar7 << uVar2 * -8 + 0x20 != 0) {
    return;
  }
  uVar2 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x78;
  uVar7 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_0204360c(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20,1);
  uVar2 = param_1 + 0x5c & 3;
  uVar7 = *(uint *)(param_1 + 0x5c & 0xfffffffc);
  VecFx32_Subtract(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20,(uint)(uintptr_t)(auStack_58),(int *)(void *)(auStack_4c));
  func_01ffd224(param_1,(uint)(uintptr_t)(auStack_4c),(undefined4)(uintptr_t)((undefined4 *)(uVar9 + 0x138)));
  return;
}

