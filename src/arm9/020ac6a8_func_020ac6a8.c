/* Decompiled C draft; module arm9; ROM address 020ac6a8. No matching claim. */
#include "types.h"
#include "deps/020ac6a8_func_020ac6a8.h"

void func_020ac6a8(undefined4 param_1,int param_2)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar5 = param_2 + 0xb0U & 3;
  uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
  switch(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    uVar5 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    *(uint *)(param_2 + 0xa8) = uVar5 - 1;
    if (0 < (int)uVar5) {
      return;
    }
    *(undefined4 *)(param_2 + 0xa8) = 0;
    uVar5 = param_2 + 0xa0U & 3;
    uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
    uVar2 = param_2 + 0xa4U & 3;
    uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    *(uint *)(param_2 + 0xa0) =
         (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    uVar5 = param_2 + 0xa4U & 3;
    uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) - 4;
    uVar5 = param_2 + 0xa4U & 3;
    uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
    if (((int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) < 0) &&
       (uVar5 = param_2 + 0xa0U & 3, uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc),
       (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) < 0x4b)) {
      *(undefined4 *)(param_2 + 0xa0) = 0x4a;
      *(undefined4 *)(param_2 + 0xb0) = 2;
    }
    uVar5 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar7 = *(undefined4 *)(uVar5 + 0x84);
    uVar8 = *(undefined4 *)(uVar5 + 0x88);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(uVar5 + 0x80);
    *(undefined4 *)(param_2 + 8) = uVar7;
    *(undefined4 *)(param_2 + 0xc) = uVar8;
    return;
  case 2:
    uVar5 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    iVar3 = func_020a1154(*(undefined2 *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x74))
    ;
    if (iVar3 == 0) {
      *(undefined4 *)(param_2 + 0xa8) = 0x1e;
      *(undefined4 *)(param_2 + 0xa4) = 8;
      *(undefined4 *)(param_2 + 0xb0) = 3;
    }
    uVar5 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar7 = *(undefined4 *)(uVar5 + 0x84);
    uVar8 = *(undefined4 *)(uVar5 + 0x88);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(uVar5 + 0x80);
    *(undefined4 *)(param_2 + 8) = uVar7;
    *(undefined4 *)(param_2 + 0xc) = uVar8;
    return;
  case 3:
    uVar5 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    *(uint *)(param_2 + 0xa8) = uVar5 - 1;
    if ((int)uVar5 < 1) {
      *(undefined4 *)(param_2 + 0xa8) = 0;
      uVar5 = param_2 + 0xa0U & 3;
      uVar6 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
      uVar2 = param_2 + 0xa4U & 3;
      uVar4 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa0) =
           (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) +
           (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      uVar5 = param_2 + 0xa4U & 3;
      uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      *(uint *)(param_2 + 0xa4) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) - 4;
      uVar5 = param_2 + 0xa4U & 3;
      uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
      if (((int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) < 0) &&
         (uVar5 = param_2 + 0xa0U & 3, uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc),
         (int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) < 1)) {
        *(undefined4 *)(param_2 + 0xa0) = 0;
        *(undefined4 *)(param_2 + 0xb0) = 0;
        puVar1 = DAT_020ac88c;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *DAT_020ac888;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | *puVar1;
      }
    }
    uVar5 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
    uVar7 = *(undefined4 *)(uVar5 + 0x84);
    uVar8 = *(undefined4 *)(uVar5 + 0x88);
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(uVar5 + 0x80);
    *(undefined4 *)(param_2 + 8) = uVar7;
    *(undefined4 *)(param_2 + 0xc) = uVar8;
  default:
    return;
  }
  uVar5 = param_2 + 0xacU & 3;
  uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  iVar3 = func_020a1154(*(undefined2 *)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x74));
  if (iVar3 == 0) {
    return;
  }
  *(undefined4 *)(param_2 + 0xa8) = 0x1e;
  *(undefined4 *)(param_2 + 0xa4) = 0x19;
  *(undefined4 *)(param_2 + 0xb0) = 1;
  *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffd;
  *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfff7;
  *(undefined2 *)(param_2 + 0x66) = 0x1f;
  return;
}

