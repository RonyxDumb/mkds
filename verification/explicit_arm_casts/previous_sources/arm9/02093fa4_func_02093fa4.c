/* Decompiled C draft; module arm9; ROM address 02093fa4. No matching claim. */
#include "types.h"
#include "deps/02093fa4_func_02093fa4.h"

void func_02093fa4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  func_020d7da8(param_1 + 0xac,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  func_020d7d80(param_1 + 0xac);
  func_020ac588(uRam02093fe8,0x14,param_1);
  uVar1 = iRam02093fec + 0x164U & 3;
  uVar2 = *(uint *)(iRam02093fec + 0x164U & 0xfffffffc);
  *(uint *)(param_1 + 0x70) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  return;
}

