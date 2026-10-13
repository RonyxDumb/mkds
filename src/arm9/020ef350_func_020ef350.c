/* Decompiled C draft; module arm9; ROM address 020ef350. No matching claim. */
#include "types.h"
#include "deps/020ef350_func_020ef350.h"

void func_020ef350(int param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  code *pcVar5;
  uint uVar6;
  uint local_18;
  uint local_14;
  uint local_10;
  uint uVar7;
  
  uVar3 = param_1 + 0x14U & 3;
  uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar7 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  func_020ef4a0();
  uVar3 = uVar7 + 0x74 & 3;
  uVar6 = *(uint *)(uVar7 + 0x74 & 0xfffffffc);
  if (((uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) & 0x1000) != 0) {
    uVar3 = param_1 + 0x9cU & 3;
    uVar6 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
    local_18 = (uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14;
    uVar3 = param_1 + 0xa0U & 3;
    uVar6 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
    local_14 = (uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14;
    uVar3 = param_1 + 0xa4U & 3;
    uVar6 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
    local_10 = (uVar3 << 0xd) >> 0xc | (uVar3 >> 0x13) << 0x14;
    VecFx32_Add((uint)(uintptr_t)(&local_18),param_1 + 0x44,&local_18);
    lVar1 = (longlong)(int)local_10 * (longlong)(int)local_10 +
            (longlong)(int)local_18 * (longlong)(int)local_18 +
            (longlong)(int)local_14 * (longlong)(int)local_14;
    if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
      Vector3_MaybeNormalize((uint)(uintptr_t)(&local_18),&local_18);
    }
    *(uint *)(uVar7 + 0xac) = -local_18;
    *(uint *)(uVar7 + 0xb0) = -local_14;
    *(uint *)(uVar7 + 0xb4) = -local_10;
    uVar2 = *(undefined4 *)(param_1 + 0x3c);
    uVar4 = *(undefined4 *)(param_1 + 0x40);
    *(undefined4 *)(uVar7 + 0xa0) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(uVar7 + 0xa4) = uVar2;
    *(undefined4 *)(uVar7 + 0xa8) = uVar4;
    Vector3_Cross((uint)(uintptr_t)((undefined4 *)(uVar7 + 0xa0)),uVar7 + 0xac,(uint *)(uintptr_t)(uVar7 + 0x94));
  }
  uVar3 = uVar7 + 0x44 & 3;
  uVar6 = *(uint *)(uVar7 + 0x44 & 0xfffffffc);
  uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020ef49c & 0xfffffffc) >> (uRam020ef49c & 3) * 8 |
          *(uint *)(uRam020ef49c & 0xfffffffc) << (uRam020ef49c & 3) * -8 + 0x20) + 0x20;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  pcVar5 = (code *)(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20);
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(param_1,uVar7);
    return;
  }
  return;
}

