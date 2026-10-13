/* Decompiled C draft; module arm9; ROM address 020ff3c4. No matching claim. */
#include "types.h"
#include "deps/020ff3c4_func_020ff3c4.h"

undefined4 func_020ff3c4(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  uint uVar6;
  
  uVar2 = *(uint *)(uRam020ff430 & 0xfffffffc) >> (uRam020ff430 & 3) * 8 |
          *(uint *)(uRam020ff430 & 0xfffffffc) << (uRam020ff430 & 3) * -8 + 0x20;
  uVar6 = uVar2 + 4 & 3;
  uVar3 = *(uint *)(uVar2 + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar3 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
          *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  uVar6 = uVar2 + 8 & 3;
  uVar5 = *(uint *)(uVar2 + 8 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 +
          (longlong)(int)uVar3 * (longlong)(int)uVar3 + (longlong)(int)uVar4 * (longlong)(int)uVar4;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    Vector3_MaybeNormalize(uVar2,param_1 + 0x130);
  }
  uVar6 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  *(undefined2 *)((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0xb0) = 2;
  uVar6 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0x180000) == 0) {
    *(undefined4 *)(param_1 + 0x120) = uRam020ff434;
  }
  return 2;
}

