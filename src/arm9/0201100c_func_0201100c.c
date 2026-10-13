/* Decompiled C draft; module arm9; ROM address 0201100c. No matching claim. */
#include "types.h"
#include "deps/0201100c_func_0201100c.h"

void func_0201100c(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  puVar2 = puRam0201102c;
  uVar3 = param_1[1];
  uVar5 = param_1[2];
  *puRam0201102c = *param_1;
  puVar2[1] = uVar3;
  puVar2[2] = uVar5;
  uVar1 = iRam02011030 + 0xfcU & 3;
  uVar4 = *(uint *)(iRam02011030 + 0xfcU & 0xfffffffc);
  *(uint *)(iRam02011030 + 0xfc) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xffffff5b;
  return;
}

