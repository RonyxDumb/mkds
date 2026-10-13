/* Decompiled C draft; module arm9; ROM address 0214f2a8. No matching claim. */
#include "types.h"
#include "deps/0214f2a8_func_0214f2a8.h"

undefined4 func_0214f2a8(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  if (((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) & 0x1f) != 0) {
    return 2;
  }
  uVar8 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  if ((uVar8 & 0x1f) != 0) {
    return 2;
  }
  if (uVar8 == 0) {
    return 2;
  }
  uVar8 = param_1 + 0xc & 3;
  uVar3 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  if ((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) < 0x400) {
    return 2;
  }
  switch(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) {
  case 0:
    uVar8 = 0;
    break;
  case 1:
    uVar8 = 1;
    break;
  case 2:
    uVar8 = 2;
    break;
  case 3:
    uVar8 = 3;
    break;
  case 4:
    uVar8 = 5;
    break;
  case 5:
    uVar8 = 7;
    break;
  default:
    return 2;
  }
  uVar3 = param_1 + 0x10 & 3;
  uVar4 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  if (uVar4 >> uVar3 * 8 != 0 || uVar4 << uVar3 * -8 + 0x20 != 0) {
    uVar8 = uVar8 | 0x10;
  }
  Os_DisableIrq();
  if (*(uint *)((uint)DAT_0214f414 & 0xfffffffc) >> ((uint)DAT_0214f414 & 3) * 8 != 0 ||
      *(uint *)((uint)DAT_0214f414 & 0xfffffffc) << ((uint)DAT_0214f414 & 3) * -8 + 0x20 != 0) {
    Os_RestoreIrq();
    return 1;
  }
  *DAT_0214f414 = 1;
  Os_RestoreIrq();
  puVar2 = DAT_0214f414;
  DAT_0214f414[1] = param_2;
  puVar2[2] = param_3;
  uVar3 = param_1 + 0x14 & 3;
  uVar4 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  puVar2[4] = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x18 & 3;
  uVar4 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  puVar2[5] = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 4 & 3;
  uVar5 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar4 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar1 = param_1 + 0xc & 3;
  uVar10 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  iVar6 = func_0214ef34(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,
                        uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20,
                        uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20,uVar8);
  if (iVar6 == 0) {
    uVar7 = 3;
  }
  else {
    uVar7 = 0;
  }
  return uVar7;
}

