/* Decompiled C draft; module arm9; ROM address 020d29cc. No matching claim. */
#include "types.h"
#include "deps/020d29cc_func_020d29cc.h"

void func_020d29cc(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  *(uint *)(param_1 + 0x1c) =
       *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar6 = param_2 + 4 & 3;
  uVar2 = *(uint *)(param_2 + 4 & 0xfffffffc);
  *(uint *)(param_1 + 0x20) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x98U & 3;
  uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar2 = param_1 + 0x1cU & 3;
  uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0xc;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0x58) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (*(short *)(param_1 + 100) < 0) goto LAB_020d2a5c;
  uVar6 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar6 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 8;
  uVar2 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020d2a40;
  case 4:
    goto LAB_020d2a40;
  case 5:
LAB_020d2a40:
    uVar6 = VecFx32_Norm(param_1 + 0x58);
    goto LAB_020d2a54;
  }
  uVar6 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
LAB_020d2a54:
  func_020d5148((int)*(short *)(param_1 + 100),uVar6);
LAB_020d2a5c:
  uVar6 = param_1 + 0x98U & 3;
  uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar2 = param_1 + 0x20U & 3;
  uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x10;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0x5c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (*(short *)(param_1 + 100) < 0) goto LAB_020d2acc;
  uVar6 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar6 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 8;
  uVar2 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020d2ab0;
  case 4:
    goto LAB_020d2ab0;
  case 5:
LAB_020d2ab0:
    uVar6 = VecFx32_Norm(param_1 + 0x58);
    goto LAB_020d2ac4;
  }
  uVar6 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
LAB_020d2ac4:
  func_020d5148((int)*(short *)(param_1 + 100),uVar6);
LAB_020d2acc:
  uVar6 = param_1 + 0x98U & 3;
  uVar5 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar2 = param_1 + 0x24U & 3;
  uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x14;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) *
          (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  *(uint *)(param_1 + 0x60) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  if (*(short *)(param_1 + 100) < 0) goto LAB_020d2b3c;
  uVar6 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar6 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 8;
  uVar2 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_020d2b20;
  case 4:
    goto LAB_020d2b20;
  case 5:
LAB_020d2b20:
    uVar6 = VecFx32_Norm(param_1 + 0x58);
    goto LAB_020d2b34;
  }
  uVar6 = param_1 + 0x58U & 3;
  uVar2 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
LAB_020d2b34:
  func_020d5148((int)*(short *)(param_1 + 100),uVar6);
LAB_020d2b3c:
  uVar6 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x20U & 3;
  uVar5 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x98U & 3;
  uVar3 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  if ((int)uVar2 < (int)uVar5) {
    uVar2 = uVar5;
  }
  uVar5 = param_1 + 0x24U & 3;
  uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar6 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) + 0x2c;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((int)uVar2 < (int)uVar4) {
    uVar2 = uVar4;
  }
  lVar1 = (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) * (longlong)(int)uVar2;
  *(uint *)(param_1 + 0x68) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  return;
}

