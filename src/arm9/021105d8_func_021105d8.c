/* Decompiled C draft; module arm9; ROM address 021105d8. No matching claim. */
#include "types.h"
#include "deps/021105d8_func_021105d8.h"

void func_021105d8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_30 [4];
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  uVar2 = uRam02110638;
  iVar5 = 0;
  iVar4 = iRam02110634;
  do {
    local_30[0] = *puRam0211063c;
    local_30[1] = puRam0211063c[1];
    local_30[2] = puRam0211063c[2];
    local_30[3] = puRam0211063c[3];
    local_20 = puRam0211063c[4];
    uStack_1c = puRam0211063c[5];
    uStack_18 = puRam0211063c[6];
    uVar1 = uVar2 & 3;
    uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    func_0210e094((int *)(uintptr_t)(iVar4),local_30[iVar5],uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 + 8;
  } while (iVar5 < 7);
  return;
}

