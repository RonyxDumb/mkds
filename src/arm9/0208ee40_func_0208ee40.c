/* Decompiled C draft; module arm9; ROM address 0208ee40. No matching claim. */
#include "types.h"
#include "deps/0208ee40_func_0208ee40.h"

void func_0208ee40(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_2 + 0x14U & 3;
  uVar2 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x1cU & 3;
  uVar2 = *(uint *)(param_2 + 0x1cU & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(int *)(param_1 + 0x10) =
       (int)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) >> 4;
  uVar1 = uVar3 + 4 & 3;
  uVar2 = *(uint *)(uVar3 + 4 & 0xfffffffc);
  *(int *)(param_1 + 0x14) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar3 + 8 & 3;
  uVar2 = *(uint *)(uVar3 + 8 & 0xfffffffc);
  *(int *)(param_1 + 0x18) = (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) >> 4;
  return;
}

