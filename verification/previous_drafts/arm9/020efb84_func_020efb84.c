/* Decompiled C draft; module arm9; ROM address 020efb84. No matching claim. */
#include "types.h"
#include "deps/020efb84_func_020efb84.h"

void func_020efb84(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 0x44U & 3;
  uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  func_020f0ea0((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x44 +
                (*(uint *)(uRam020efbd0 & 0xfffffffc) >> (uRam020efbd0 & 3) * 8 |
                *(uint *)(uRam020efbd0 & 0xfffffffc) << (uRam020efbd0 & 3) * -8 + 0x20));
  uVar1 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  func_020efd1c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,param_2);
  uVar1 = param_2 + 0x74U & 3;
  uVar2 = *(uint *)(param_2 + 0x74U & 0xfffffffc);
  *(uint *)(param_2 + 0x74) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffffefff;
  return;
}

