/* Decompiled C draft; module arm9; ROM address 020df890. No matching claim. */
#include "types.h"
#include "deps/020df890_func_020df890.h"

void func_020df890(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < iRam020df928) {
    if (iRam020df92c < (int)uVar5) {
      uVar4 = (*(uint *)(uRam020df930 & 0xfffffffc) >> (uRam020df930 & 3) * 8 |
              *(uint *)(uRam020df930 & 0xfffffffc) << (uRam020df930 & 3) * -8 + 0x20) + 0x28;
      uVar2 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      lVar1 = (longlong)(int)(iRam020df928 - uVar5) *
              (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
      *(short *)(param_1 + 0xa8) =
           (short)((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) >> 0xc);
    }
    else {
      *(undefined2 *)(param_1 + 0xa8) = 0x8000;
    }
  }
  uVar5 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) - iRam020df934;
  uVar5 = param_1 + 0x14U & 3;
  uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < -0x3000) {
    *(undefined4 *)(param_1 + 0x14) = 0xffffd000;
  }
  uVar5 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar4 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) +
       (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20);
  uVar5 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0xa4U & 3;
  uVar4 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4;
  if ((int)uVar2 < (int)uVar4) {
    uVar5 = 1;
  }
  if ((int)uVar2 < (int)uVar4) {
    *(short *)(param_1 + 0x90) = (short)uVar5;
    *(short *)(param_1 + 0x92) = (short)uVar5;
  }
  return;
}

