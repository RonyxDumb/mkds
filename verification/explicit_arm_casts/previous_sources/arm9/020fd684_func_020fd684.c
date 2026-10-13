/* Decompiled C draft; module arm9; ROM address 020fd684. No matching claim. */
#include "types.h"
#include "deps/020fd684_func_020fd684.h"

void func_020fd684(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  
  uVar3 = param_1 + 0x198U & 3;
  uVar2 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
  if (uVar2 >> uVar3 * 8 == 0 && uVar2 << uVar3 * -8 + 0x20 == 0) {
    *(undefined4 *)(param_1 + 0x1a0) = 1;
    func_0208ad74(param_1 + 0x7c);
  }
  if (param_2 != (undefined4 *)0x0) {
    uVar4 = param_2[1];
    uVar6 = param_2[2];
    *(undefined4 *)(param_1 + 0xf0) = *param_2;
    *(undefined4 *)(param_1 + 0xf4) = uVar4;
    *(undefined4 *)(param_1 + 0xf8) = uVar6;
    uVar3 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x80;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar4 = param_3[1];
    uVar6 = param_3[2];
    *(undefined4 *)(param_1 + 0x50) = *param_3;
    *(undefined4 *)(param_1 + 0x54) = uVar4;
    *(undefined4 *)(param_1 + 0x58) = uVar6;
    VecFx32_Subtract((undefined4 *)(param_1 + 0x50),param_1 + 0xe4,param_1 + 0x5c);
    uVar3 = param_1 + 0x198U & 3;
    uVar2 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 != 0) {
      uVar4 = param_3[1];
      uVar6 = param_3[2];
      *(undefined4 *)(uVar3 + 4) = *param_3;
      *(undefined4 *)(uVar3 + 8) = uVar4;
      *(undefined4 *)(uVar3 + 0xc) = uVar6;
      uVar3 = param_1 + 0x198U & 3;
      uVar2 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
      uVar7 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      uVar2 = param_1 + 0x19cU & 3;
      uVar5 = *(uint *)(param_1 + 0x19cU & 0xfffffffc);
      uVar3 = uVar7 + 8;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      *(uint *)(uVar7 + 8) =
           (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) +
           (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
      uVar3 = param_1 + 0x198U & 3;
      uVar2 = *(uint *)(param_1 + 0x198U & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      *(ushort *)(uVar3 + 2) = *(ushort *)(uVar3 + 2) & 0xfffd;
      *(ushort *)(uVar3 + 2) = *(ushort *)(uVar3 + 2) & 0xfff7;
      *(undefined2 *)(uVar3 + 0x66) = 0x1f;
      return;
    }
    return;
  }
  return;
}

