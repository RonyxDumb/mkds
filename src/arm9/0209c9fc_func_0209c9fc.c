/* Decompiled C draft; module arm9; ROM address 0209c9fc. No matching claim. */
#include "types.h"
#include "deps/0209c9fc_func_0209c9fc.h"

undefined1 func_0209c9fc(ushort *param_1,int param_2,byte *param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  ushort uVar3;
  longlong lVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint uVar15;
  
  uVar2 = *param_4;
  if (1 < *param_3 - 3) {
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    return 2;
  }
  uVar7 = (uint)(param_1 + (uint)*(ushort *)(param_2 + 0x74) * 2 + 0x90) & 3;
  uVar5 = *(uint *)((uint)(param_1 + (uint)*(ushort *)(param_2 + 0x74) * 2 + 0x90) & 0xfffffffc);
  if (uVar5 >> uVar7 * 8 == 0 && uVar5 << uVar7 * -8 + 0x20 == 0) {
    VecFx32_Subtract(param_2 + 0x80,(uint)(uintptr_t)(param_1 + 2),&local_30);
    iVar6 = Vector3_DotProduct(param_2 + 0xb0,(uint)(uintptr_t)(&local_30));
    uVar7 = param_2 + 0xb0U & 3;
    uVar5 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    local_48 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    uVar7 = param_2 + 0xb4U & 3;
    uVar5 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    local_44 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    uVar7 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    local_3c = local_30 - local_48;
    lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    local_38 = local_2c - local_44;
    local_40 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    local_34 = local_28 - local_40;
    iVar6 = Vector3_DotProduct((uint)(uintptr_t)(param_1 + 0x1a),(uint)(uintptr_t)(&local_3c));
    uVar7 = (uint)(param_1 + 0x1a) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0x1a) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    local_48 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    uVar7 = (uint)(param_1 + 0x1c) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0x1c) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    local_3c = local_3c - local_48;
    local_44 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    local_38 = local_38 - local_44;
    uVar7 = (uint)(param_1 + 0x1e) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0x1e) & 0xfffffffc);
    lVar4 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    local_40 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
    local_34 = local_34 - local_40;
    lVar4 = (longlong)(int)local_34 * (longlong)(int)local_34 +
            (longlong)(int)local_3c * (longlong)(int)local_3c +
            (longlong)(int)local_38 * (longlong)(int)local_38;
    if ((int)((ulonglong)lVar4 >> 0x20) < (int)(uint)((uint)lVar4 < 0x10)) {
      uVar7 = param_2 + 0x120U & 3;
      uVar5 = *(uint *)(param_2 + 0x120U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * 0xc000;
      *(uint *)(param_1 + 8) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      uVar7 = param_2 + 0x124U & 3;
      uVar5 = *(uint *)(param_2 + 0x124U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * 0xc000;
      *(uint *)(param_1 + 10) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
      uVar7 = param_2 + 0x128U & 3;
      uVar5 = *(uint *)(param_2 + 0x128U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * 0xc000;
      *(uint *)(param_1 + 0xc) = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) * 0x100000;
    }
    else {
      Vector3_MaybeNormalize((uint)(uintptr_t)(&local_3c),&local_3c);
      *(uint *)(param_1 + 8) =
           (uint)((ulonglong)local_3c * 0xc000) >> 0xc |
           (int)((ulonglong)local_3c * 0xc000 >> 0x20) * 0x100000;
      *(uint *)(param_1 + 10) =
           (uint)((ulonglong)local_38 * 0xc000) >> 0xc |
           (int)((ulonglong)local_38 * 0xc000 >> 0x20) * 0x100000;
      *(uint *)(param_1 + 0xc) =
           (uint)((ulonglong)local_34 * 0xc000) >> 0xc |
           (int)((ulonglong)local_34 * 0xc000 >> 0x20) * 0x100000;
    }
    VecFx32_Subtract((uint)(uintptr_t)(&local_48),(uint)(uintptr_t)(param_1 + 0x1a),&local_48);
    VecFx32_AddScale1(uRam0209ce98,(uint)(uintptr_t)(&local_48),(uint)(uintptr_t)(param_1 + 8),(int *)(void *)(param_1 + 8));
    uVar5 = uRam0209ce9c;
    uVar3 = *(ushort *)(param_2 + 0x74);
    (param_1 + (uint)uVar3 * 2 + 0x90)[0] = 0x1f;
    (param_1 + (uint)uVar3 * 2 + 0x90)[1] = 0;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 8;
    uVar5 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if ((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) == 2) {
      func_020a21bc(*(undefined2 *)(param_2 + 0x74),(int)(uintptr_t)(param_1 + 8));
    }
  }
  else {
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
  }
  uVar7 = (uint)*(ushort *)(param_2 + 0x74) * 0x30 +
          (*(uint *)(uRam0209ce9c & 0xfffffffc) >> (uRam0209ce9c & 3) * 8 |
          *(uint *)(uRam0209ce9c & 0xfffffffc) << (uRam0209ce9c & 3) * -8 + 0x20) + 0x70;
  uVar5 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if (((uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) != 2) &&
     (uVar7 = (uint)(param_1 + 0x8e) & 3, uVar5 = *(uint *)((uint)(param_1 + 0x8e) & 0xfffffffc),
     uVar5 >> uVar7 * 8 == 0 && uVar5 << uVar7 * -8 + 0x20 == 0)) {
    param_1[0x5c] = 0x8000;
    param_1[0x62] = 0x1000;
    param_1[99] = 0;
    param_1[100] = 0x400;
    param_1[0x65] = 0;
    param_1[0x66] = 0xffd7;
    param_1[0x67] = 0xffff;
    param_1[0x68] = 0x1000;
    param_1[0x69] = 0;
    param_1[0x6a] = 0;
    param_1[0x6b] = 0;
    param_1[0x6c] = 0;
    param_1[0x72] = 0x1000;
    param_1[0x73] = 0;
    param_1[0x74] = 0x400;
    param_1[0x75] = 0;
    param_1[0x76] = 0xffd7;
    param_1[0x77] = 0xffff;
    param_1[0x78] = 0x1000;
    param_1[0x79] = 0;
    param_1[0x7a] = 0;
    param_1[0x7b] = 0;
    param_1[0x8e] = 1;
    param_1[0x8f] = 0;
    uVar7 = (uint)*param_1;
    if (uVar7 == 0x1a8) {
      func_020d26ec(param_2,uRam0209ceac);
    }
    else if (uVar7 == 0x1b4) {
      func_020d26ec(param_2,uRam0209cea4);
    }
    else if (uVar7 == uRam0209cea0) {
      func_020d26ec(param_2,uRam0209cea8);
    }
    if (((uint)*param_1 + iRam0209ceb0 & 0xffff) < 2) {
      uVar8 = *(uint *)(uRam0209ceb4 & 0xfffffffc) >> (uRam0209ceb4 & 3) * 8 |
              *(uint *)(uRam0209ceb4 & 0xfffffffc) << (uRam0209ceb4 & 3) * -8 + 0x20;
      iVar6 = uVar8 + iRam0209ceb8;
      uVar7 = iVar6 + 8U & 3;
      uVar5 = *(uint *)(iVar6 + 8U & 0xfffffffc);
      uVar13 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
      uVar7 = uVar8 + 0x498 & 3;
      uVar5 = *(uint *)(uVar8 + 0x498 & 0xfffffffc);
      uVar12 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
      uVar7 = iVar6 + 4U & 3;
      uVar9 = *(uint *)(iVar6 + 4U & 0xfffffffc);
      lVar4 = (ulonglong)uVar12 * (ulonglong)uVar13;
      uVar11 = (uint)lVar4;
      uVar5 = iVar6 + 0xcU & 3;
      uVar10 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
      uVar1 = iVar6 + 0x10U & 3;
      uVar14 = *(uint *)(iVar6 + 0x10U & 0xfffffffc);
      uVar15 = uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20;
      uVar1 = iVar6 + 0x14U & 3;
      uVar14 = *(uint *)(iVar6 + 0x14U & 0xfffffffc);
      *(uint *)(uVar8 + 0x498) = uVar15 + uVar11;
      *(uint *)(iVar6 + 4) =
           (uVar14 >> uVar1 * 8 | uVar14 << uVar1 * -8 + 0x20) +
           (uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) * uVar12 +
           uVar13 * (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) +
           (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar15,uVar11);
      uVar7 = iVar6 + 4U & 3;
      uVar5 = *(uint *)(iVar6 + 4U & 0xfffffffc);
      lVar4 = (ulonglong)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * 3;
      func_02103544(*(undefined2 *)(param_2 + 0x74),(int)((ulonglong)lVar4 >> 0x20) + 1,(int)lVar4);
      VecFx32_Subtract((uint)(uintptr_t)(param_1 + 2),param_2 + 0x1b8,&local_24);
      lVar4 = (longlong)local_1c * (longlong)local_1c +
              (longlong)local_24 * (longlong)local_24 + (longlong)local_20 * (longlong)local_20;
      if ((int)(uint)((uint)lVar4 < 0x10) <= (int)((ulonglong)lVar4 >> 0x20)) {
        Vector3_MaybeNormalize((uint)(uintptr_t)(&local_24),&local_24);
      }
      uVar7 = param_2 + 0x1d0U & 3;
      uVar5 = *(uint *)(param_2 + 0x1d0U & 0xfffffffc);
      VecFx32_AddScale1(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,(uint)(uintptr_t)(&local_24),param_2 + 0x1b8,
                        &local_24);
      if ((uint)*(ushort *)(param_2 + 0x74) ==
          (int)*(char *)((*(uint *)(uRam0209ce9c & 0xfffffffc) >> (uRam0209ce9c & 3) * 8 |
                         *(uint *)(uRam0209ce9c & 0xfffffffc) << (uRam0209ce9c & 3) * -8 + 0x20) +
                        0x62)) {
        func_0208b7bc(0x74,(uint)(uintptr_t)(&local_24));
      }
      else {
        func_0208b7bc(0x75,&local_24);
      }
    }
  }
  return uVar2;
}

