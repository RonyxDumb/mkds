/* Decompiled C draft; module arm9; ROM address 021349c4. No matching claim. */
#include "types.h"
#include "deps/021349c4_func_021349c4.h"

undefined4 func_021349c4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  if (param_1 == 0) {
    uVar1 = func_021343b0();
    return uVar1;
  }
  uVar3 = param_1 + 0xdU & 3;
  uVar2 = *(uint *)(param_1 + 0xdU & 0xfffffffc);
  if ((((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xff) != 0) ||
     (uVar3 = param_1 + 4U & 3, uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc),
     uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20, (uVar3 << 0x16) >> 0x1d == 0)) {
    return 0xffffffff;
  }
  if ((uVar3 << 0x1b) >> 0x1d == 1) {
    return 0;
  }
  uVar3 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (2 < (uVar3 & 7)) {
    *(uint *)(param_1 + 8) = uVar3 & 0xfffffff8 | 2;
  }
  uVar3 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 7) == 2) {
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  uVar3 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar3 & 7) == 1) {
    iVar4 = func_0213446c(param_1,0);
    if (iVar4 == 0) {
      uVar3 = param_1 + 8U & 3;
      uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *(uint *)(param_1 + 8) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xfffffff8;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
      return 0;
    }
    puVar5 = (uint *)(param_1 + 0xd);
    uVar2 = (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00 | 1
    ;
    uVar3 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
    *puVar5 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
    *(undefined4 *)(param_1 + 0x28) = 0;
    return 0xffffffff;
  }
  *(uint *)(param_1 + 8) = uVar3 & 0xfffffff8;
  return 0;
}

