/* Decompiled C draft; module arm9; ROM address 020fb7f8. No matching claim. */
#include "types.h"
#include "deps/020fb7f8_func_020fb7f8.h"

void func_020fb7f8(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_1c;
  uint local_18;
  int local_14;
  uint uVar3;
  
  uVar3 = param_1 + 0x27cU & 3;
  uVar2 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 0xd001) {
    *(uint *)(param_1 + 0x27c) = uVar3 + uRam020fba5c;
  }
  else {
    *(uint *)(param_1 + 0x27c) = uVar3 - uRam020fba5c;
  }
  uVar2 = uRam020fba5c;
  uVar3 = param_1 + 0x260U & 3;
  uVar4 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
  *(uint *)(param_1 + 0x260) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - uRam020fba5c;
  *(short *)(param_1 + 0x288) = *(short *)(param_1 + 0x288) + 0x2d;
  uVar3 = param_1 + 0x25cU & 3;
  uVar4 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) < 0x8000) {
    uVar3 = param_1 + 0x284U & 3;
    uVar2 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
    *(uint *)(param_1 + 0x284) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - iRam020fba60;
  }
  else {
    uVar3 = param_1 + 0x284U & 3;
    uVar4 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
    *(uint *)(param_1 + 0x284) = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - uVar2;
  }
  uVar3 = param_1 + 0x27cU & 3;
  uVar4 = *(uint *)(param_1 + 0x27cU & 0xfffffffc);
  uVar2 = param_1 + 0x284U & 3;
  uVar5 = *(uint *)(param_1 + 0x284U & 0xfffffffc);
  func_020fce94(param_1,uRam020fba64,uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,*(undefined2 *)(param_1 + 0x288));
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 1) == 0) {
    uVar3 = param_1 + 0xd4U & 3;
    uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210b7ec((undefined4 *)(uintptr_t)(param_1 + 0x300),(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x3fffffe0);
    uVar3 = param_1 + 0x270U & 3;
    uVar2 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 != 1) {
      func_02109078(param_1,uVar3,0x7f,0);
    }
  }
  func_020fc654(param_1);
  uVar3 = param_1 + 0x25cU & 3;
  uVar2 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
  if (uRam020fba68 <= (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20)) {
    *(undefined2 *)(param_1 + 0x2f8) = 5;
    *(undefined2 *)(param_1 + 0x2fa) = 1;
    return;
  }
  if (*(ushort *)(param_1 + 0x2f6) < 3) {
    uVar3 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x40000000) != 0) {
      iVar6 = param_1 + 0xf0;
      goto LAB_020fb918;
    }
  }
  else {
    uVar3 = param_1 + 0x228U & 3;
    uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1fc;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar4 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    uVar3 = uVar4 + 0x48;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 1) != 0) {
      iVar6 = uVar4 + 0x244;
      goto LAB_020fb918;
    }
  }
  iVar6 = 0;
LAB_020fb918:
  if (iVar6 == 0) {
    uVar3 = param_1 + 600U & 3;
    uVar2 = *(uint *)(param_1 + 600U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    local_1c = (uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14;
    uVar3 = param_1 + 0x25cU & 3;
    uVar2 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x10000;
    lVar1 = (ulonglong)uRam020fba5c * (ulonglong)uVar3;
    local_18 = (uint)lVar1 >> 0xc |
               (((int)uVar3 >> 0x1f) * uRam020fba5c + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar3 = param_1 + 0x250U & 3;
    uVar2 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    local_14 = -((uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14);
  }
  else {
    uVar3 = param_1 + 0x250U & 3;
    uVar2 = *(uint *)(param_1 + 0x250U & 0xfffffffc);
    local_1c = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) << 1;
    uVar3 = param_1 + 0x254U & 3;
    uVar2 = *(uint *)(param_1 + 0x254U & 0xfffffffc);
    local_18 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) << 1;
    uVar3 = param_1 + 600U & 3;
    uVar2 = *(uint *)(param_1 + 600U & 0xfffffffc);
    local_14 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) << 1;
    Vector3_Cross(iVar6,(uint)(uintptr_t)(&local_1c),&local_1c);
    uVar3 = param_1 + 0x25cU & 3;
    uVar2 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
    uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) - 0x10000;
    lVar1 = (ulonglong)uRam020fba5c * (ulonglong)uVar3;
    VecFx32_AddScale1((uint)lVar1 >> 0xc |
                      (((int)uVar3 >> 0x1f) * uRam020fba5c + (int)((ulonglong)lVar1 >> 0x20)) *
                      0x100000,iVar6,(uint)(uintptr_t)(&local_1c),&local_1c);
  }
  uVar3 = param_1 + 0x2ecU & 3;
  uVar2 = *(uint *)(param_1 + 0x2ecU & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    VecFx32_Subtract((uint)(uintptr_t)(&local_1c),param_1 + 0x298,(int *)(uintptr_t)(param_1 + 0x28c));
  }
  func_020fc2e8(param_1,&local_1c,1,iVar6);
  return;
}

