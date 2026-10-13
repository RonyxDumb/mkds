/* Decompiled C draft; module arm7; ROM address 037f9a0c. No matching claim. */
#include "types.h"
#include "deps/037f9a0c_FUN_037f9a0c.h"

void FUN_037f9a0c(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_037faf70();
  uVar4 = DAT_037f9a94 + 4U & 3;
  uVar3 = *(uint *)(DAT_037f9a94 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  do {
    uVar3 = param_1 + 8U & 3;
    uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if (uVar3 == 0) {
      *(uint *)(param_1 + 8) = uVar4;
      uVar3 = param_1 + 0xcU & 3;
      uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(param_1 + 0xc) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 1;
      FUN_037f993c(uVar4,param_1);
LAB_037f9a80:
      FUN_037faf84(uVar1);
      return;
    }
    if (uVar3 == uVar4) {
      uVar4 = param_1 + 0xcU & 3;
      uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *(uint *)(param_1 + 0xc) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1;
      goto LAB_037f9a80;
    }
    *(int *)(uVar4 + 0x68) = param_1;
    FUN_037f9104(param_1);
    *(undefined4 *)(uVar4 + 0x68) = 0;
  } while( true );
}

