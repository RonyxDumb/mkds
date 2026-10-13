/* Decompiled C draft; module arm7; ROM address 060000dc. No matching claim. */
#include "types.h"
#include "deps/060000dc_FUN_060000dc.h"

void FUN_060000dc(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = thunk_FUN_037faf70();
  thunk_FUN_037f8d78();
  uVar1 = DAT_06000134 + 0x564U & 3;
  uVar4 = *(uint *)(DAT_06000134 + 0x564U & 0xfffffffc);
  thunk_FUN_037f8e98(DAT_06000130,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar3 = FUN_06008724();
  uVar1 = DAT_06000134 + 0x568U & 3;
  uVar4 = *(uint *)(DAT_06000134 + 0x568U & 0xfffffffc);
  thunk_FUN_037f8e98(uVar3,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar1 = DAT_06000134 + 0x56cU & 3;
  uVar4 = *(uint *)(DAT_06000134 + 0x56cU & 0xfffffffc);
  thunk_FUN_037f8e98(DAT_06000138,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  thunk_FUN_037f8d40();
  thunk_FUN_037faf84(uVar2);
  return;
}

