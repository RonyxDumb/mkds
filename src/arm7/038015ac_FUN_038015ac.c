/* Decompiled C draft; module arm7; ROM address 038015ac. No matching claim. */
#include "types.h"
#include "deps/038015ac_FUN_038015ac.h"

void FUN_038015ac(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar3 = DAT_0380160c;
  uVar2 = DAT_03801608;
  while( true ) {
    uVar4 = FUN_037faf70();
    uVar1 = uVar3 & 3;
    uVar5 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar5 >> uVar1 * 8 == 0 && uVar5 << uVar1 * -8 + 0x20 == 0) break;
    FUN_037faf84();
    FUN_037f9104(uVar2);
  }
  FUN_03801438(4);
  *(undefined4 *)(DAT_0380160c + 0x498) = param_1;
  FUN_037faf84(uVar4);
  return;
}

