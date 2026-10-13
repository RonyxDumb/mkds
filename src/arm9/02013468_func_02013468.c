/* Decompiled C draft; module arm9; ROM address 02013468. No matching claim. */
#include "types.h"
#include "deps/02013468_func_02013468.h"

void func_02013468(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  param_1 = param_1 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  uVar1 = (uint)*(ushort *)(param_1 + 4 + (uint)*(ushort *)(param_1 + 10)) * param_2 +
          param_1 + 4 + (uint)*(ushort *)(param_1 + 10) + 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  param_1 = param_1 + (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20);
  uVar1 = param_1 + 0xc;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(param_1 + 0xc) =
       (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffe0ffff | param_3 << 0x10;
  return;
}

