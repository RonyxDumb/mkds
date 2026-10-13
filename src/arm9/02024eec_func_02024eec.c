/* Decompiled C draft; module arm9; ROM address 02024eec. No matching claim. */
#include "types.h"
#include "deps/02024eec_func_02024eec.h"

uint func_02024eec(int param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar3;
  
  uVar4 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  uVar4 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = param_1 + 0x10U & 3;
  uVar6 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  if (uVar3 == 0xffffffff) {
    param_2 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar2 = param_2;
  }
  else if ((uVar3 & uRam02024fb0) == (param_2 & uRam02024fb0)) {
    *(uint *)(param_1 + 0xc) = param_2;
    uVar2 = 0;
  }
  else if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) & uRam02024fb0) ==
           (param_2 & uRam02024fb0)) {
    if (uVar2 != 0) {
      param_2 = uVar2 + uVar3;
    }
  }
  else {
    if ((int)param_2 < (int)uVar3) {
      param_3 = uRam02024fb4;
    }
    *(uint *)(param_1 + 0xc) = param_2;
    if ((int)param_2 < (int)uVar3) {
      uVar4 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
              *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
    }
    else if (param_3 == 0) {
      uVar4 = *(uint *)(uRam02024fbc & 0xfffffffc) >> (uRam02024fbc & 3) * 8 |
              *(uint *)(uRam02024fbc & 0xfffffffc) << (uRam02024fbc & 3) * -8 + 0x20;
    }
    else {
      uVar4 = *(uint *)(uRam02024fb8 & 0xfffffffc) >> (uRam02024fb8 & 3) * 8 |
              *(uint *)(uRam02024fb8 & 0xfffffffc) << (uRam02024fb8 & 3) * -8 + 0x20;
    }
    lVar1 = (longlong)(int)uVar4 * (longlong)(int)(param_2 - uVar3) + 0x800;
    uVar2 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    param_2 = uVar2 + uVar3;
  }
  if (0x880000 < (int)param_2) {
    param_2 = 0x880000;
  }
  if ((int)param_2 < 0) {
    param_2 = 0;
  }
  *(uint *)(param_1 + 0x10) = uVar2;
  return param_2;
}

