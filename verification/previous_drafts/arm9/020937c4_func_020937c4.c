/* Decompiled C draft; module arm9; ROM address 020937c4. No matching claim. */
#include "types.h"
#include "deps/020937c4_func_020937c4.h"

void func_020937c4(uint param_1,uint param_2,undefined2 param_3)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  
  func_02100138(uRam02093880);
  iVar3 = func_0209bbfc();
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0xa0) = 600;
    *(uint *)(iVar3 + 4) =
         *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar1 = param_1 + 4 & 3;
    uVar4 = *(uint *)(param_1 + 4 & 0xfffffffc);
    *(uint *)(iVar3 + 8) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x2a000;
    uVar1 = param_1 + 8 & 3;
    uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
    *(uint *)(iVar3 + 0xc) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    *(uint *)(iVar3 + 0x40) =
         *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    *(undefined4 *)(iVar3 + 0x44) = 0;
    uVar1 = param_2 + 8 & 3;
    uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
    *(uint *)(iVar3 + 0x48) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    lVar2 = (ulonglong)
            (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) * 0x6000;
    *(uint *)(iVar3 + 0x10) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    uVar1 = param_2 + 8 & 3;
    uVar4 = *(uint *)(param_2 + 8 & 0xfffffffc);
    lVar2 = (ulonglong)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * 0x6000;
    *(uint *)(iVar3 + 0x18) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    *(undefined2 *)(iVar3 + 0x7e) = param_3;
    *(undefined4 *)(iVar3 + 0xa4) = 0;
    return;
  }
  return;
}

