/* Decompiled C draft; module arm7; ROM address 03800b84. No matching claim. */
#include "types.h"
#include "deps/03800b84_FUN_03800b84.h"

bool FUN_03800b84(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = DAT_03800c18;
  uVar2 = DAT_03800c18 + 0x20U & 3;
  uVar3 = *(uint *)(DAT_03800c18 + 0x20U & 0xfffffffc);
  uVar4 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) & 0xfffffe00;
  uVar2 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (uVar4 == (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) {
    uVar2 = DAT_03800c18 + 0x20U & 3;
    uVar3 = *(uint *)(DAT_03800c18 + 0x20U & 0xfffffffc);
    iVar5 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - uVar4;
    uVar3 = 0x200 - iVar5;
    uVar2 = DAT_03800c18 + 0x28U & 3;
    uVar4 = *(uint *)(DAT_03800c18 + 0x28U & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (uVar2 < uVar3) {
      uVar3 = uVar2;
    }
    uVar2 = DAT_03800c18 + 0x24U & 3;
    uVar4 = *(uint *)(DAT_03800c18 + 0x24U & 0xfffffffc);
    FUN_037fb390((ushort *)(uintptr_t)(param_1 + 0x20 + iVar5),(uint *)(uintptr_t)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20),uVar3);
    uVar2 = iVar1 + 0x20U & 3;
    uVar4 = *(uint *)(iVar1 + 0x20U & 0xfffffffc);
    *(uint *)(iVar1 + 0x20) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + uVar3;
    uVar2 = iVar1 + 0x24U & 3;
    uVar4 = *(uint *)(iVar1 + 0x24U & 0xfffffffc);
    *(uint *)(iVar1 + 0x24) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + uVar3;
    uVar2 = iVar1 + 0x28U & 3;
    uVar4 = *(uint *)(iVar1 + 0x28U & 0xfffffffc);
    *(uint *)(iVar1 + 0x28) = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) - uVar3;
  }
  uVar2 = iVar1 + 0x28U & 3;
  uVar3 = *(uint *)(iVar1 + 0x28U & 0xfffffffc);
  return uVar3 >> uVar2 * 8 != 0 || uVar3 << uVar2 * -8 + 0x20 != 0;
}

