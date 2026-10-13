/* Decompiled C draft; module arm9; ROM address 020912a0. No matching claim. */
#include "types.h"
#include "deps/020912a0_func_020912a0.h"

void func_020912a0(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = DAT_02091518;
  uVar4 = param_2 + 200U & 3;
  uVar2 = *(uint *)(param_2 + 200U & 0xfffffffc);
  switch(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) {
  case 0:
    *(undefined4 *)(param_2 + 0xa0) = 1;
    break;
  case 1:
    uVar4 = param_2 + 0xb8U & 3;
    uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
    uVar2 = param_2 + 0xbcU & 3;
    uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    *(uint *)(param_2 + 0xb8) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
         (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    uVar4 = param_2 + 0xbcU & 3;
    uVar2 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    *(uint *)(param_2 + 0xbc) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) - 0x400;
    uVar4 = param_2 + 0xbcU & 3;
    uVar2 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
    if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < -0x6000) {
      *(undefined4 *)(param_2 + 0xbc) = 0xffffa000;
    }
    uVar4 = param_2 + 0x9cU & 3;
    uVar2 = *(uint *)(param_2 + 0x9cU & 0xfffffffc);
    if (*(short *)((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x28) < 1) {
      uVar4 = param_2 + 0xc4U & 3;
      uVar2 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
      uVar4 = param_2 + 0xb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < (int)uVar3) {
        *(uint *)(param_2 + 0xb8) = uVar3;
        *(undefined4 *)(param_2 + 0xbc) = 0;
        local_10 = 2;
        *(undefined4 *)(param_2 + 200) = 2;
        uVar4 = param_2 + 0x78U & 3;
        uVar2 = *(uint *)(param_2 + 0x78U & 0xfffffffc);
        if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 4) == 0) {
          uVar4 = param_2 + 0x70U & 3;
          uVar2 = *(uint *)(param_2 + 0x70U & 0xfffffffc);
          uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
          uVar4 = DAT_02091510 + 0x68U & 3;
          uVar2 = *(uint *)(DAT_02091510 + 0x68U & 0xfffffffc);
          if (uVar3 != (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
            uVar4 = DAT_02091510 + 0x8cU & 3;
            uVar2 = *(uint *)(DAT_02091510 + 0x8cU & 0xfffffffc);
            if (uVar3 == (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
              local_10 = 3;
            }
            else {
              local_10 = 4;
            }
          }
          local_14 = param_2 + 4;
          local_18 = DAT_02091514;
          local_c = func_020d4ef4();
          func_0210b7a8((uint)(uintptr_t)(&local_18));
        }
      }
    }
    else {
      uVar4 = param_2 + 0xb8U & 3;
      uVar2 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      if ((int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) < 0) {
        func_020d2398(param_2);
      }
    }
    *(undefined4 *)(param_2 + 0xa0) = 0;
    break;
  case 2:
    uVar4 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 1;
    uVar4 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if (iVar1 <= (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
      *(undefined4 *)(param_2 + 0xac) = 0;
      uVar4 = param_2 + 0xc0U & 3;
      uVar5 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      uVar2 = param_2 + 0xc4U & 3;
      uVar3 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
      iVar1 = ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) -
              (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) * 0x40;
      *(int *)(param_2 + 0xbc) = (int)(iVar1 + ((uint)(iVar1 >> 0xb) >> 0x14)) >> 0xc;
      *(undefined4 *)(param_2 + 200) = 3;
    }
    *(undefined4 *)(param_2 + 0xa0) = 0;
    break;
  case 3:
    uVar4 = param_2 + 0xb0U & 3;
    uVar2 = *(uint *)(param_2 + 0xb0U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 0x1000) {
      *(uint *)(param_2 + 0xb0) = uVar4 + 0x40;
      uVar4 = param_2 + 0xb8U & 3;
      uVar5 = *(uint *)(param_2 + 0xb8U & 0xfffffffc);
      uVar2 = param_2 + 0xbcU & 3;
      uVar3 = *(uint *)(param_2 + 0xbcU & 0xfffffffc);
      *(uint *)(param_2 + 0xb8) =
           (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
           (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
    }
    else {
      *(undefined4 *)(param_2 + 0xb0) = 0x1000;
      uVar4 = param_2 + 0xc0U & 3;
      uVar2 = *(uint *)(param_2 + 0xc0U & 0xfffffffc);
      *(uint *)(param_2 + 0xb8) = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    }
    uVar4 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    *(uint *)(param_2 + 0xac) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 1;
    uVar4 = param_2 + 0xacU & 3;
    uVar2 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
    if ((10 < (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) &&
       (uVar4 = param_2 + 0xb4U & 3, uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc),
       *(uint *)(param_2 + 0xb4) = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 0x40,
       uVar4 = param_2 + 0xb4U & 3, uVar2 = *(uint *)(param_2 + 0xb4U & 0xfffffffc),
       0xfff < (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20))) {
      *(undefined4 *)(param_2 + 0xac) = 0;
      *(undefined4 *)(param_2 + 0xb4) = 0x1000;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xfffe;
      *(undefined4 *)(param_2 + 200) = 0;
    }
    *(undefined4 *)(param_2 + 0xa0) = 1;
  }
  uVar4 = param_2 + 0xa0U & 3;
  uVar2 = *(uint *)(param_2 + 0xa0U & 0xfffffffc);
  if (uVar2 >> uVar4 * 8 == 0 && uVar2 << uVar4 * -8 + 0x20 == 0) {
    return;
  }
  uVar4 = param_2 + 0xa4U & 3;
  uVar5 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  uVar2 = param_2 + 0xa8U & 3;
  uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  *(uint *)(param_2 + 0xa4) =
       (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) +
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar4 = param_2 + 0xa4U & 3;
  uVar2 = *(uint *)(param_2 + 0xa4U & 0xfffffffc);
  if (-1 < (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    uVar4 = param_2 + 0xa8U & 3;
    uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    if ((int)uVar4 < 0) {
      *(undefined4 *)(param_2 + 0xa8) = 0xffffff10;
    }
    else {
      *(uint *)(param_2 + 0xa8) = uVar4 - 8;
    }
    return;
  }
  uVar4 = param_2 + 0xa8U & 3;
  uVar2 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < 0) {
    *(uint *)(param_2 + 0xa8) = uVar4 + 8;
  }
  else {
    *(undefined4 *)(param_2 + 0xa8) = 0xf0;
  }
  return;
}

