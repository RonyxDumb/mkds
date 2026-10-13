/* Decompiled C draft; module arm7; ROM address 06000154. No matching claim. */
#include "types.h"
#include "deps/06000154_FUN_06000154.h"

void FUN_06000154(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = thunk_FUN_037faf70();
  thunk_FUN_037f8d78();
  uVar1 = DAT_060001ac + 0x578U & 3;
  uVar4 = *(uint *)(DAT_060001ac + 0x578U & 0xfffffffc);
  thunk_FUN_037f8e98(DAT_060001a8,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar3 = FUN_06008724();
  uVar1 = DAT_060001ac + 0x574U & 3;
  uVar4 = *(uint *)(DAT_060001ac + 0x574U & 0xfffffffc);
  thunk_FUN_037f8e98(uVar3,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar1 = DAT_060001ac + 0x570U & 3;
  uVar4 = *(uint *)(DAT_060001ac + 0x570U & 0xfffffffc);
  thunk_FUN_037f8e98(DAT_060001b0,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  thunk_FUN_037f8d40();
  thunk_FUN_037faf84(uVar2);
  return;
}

