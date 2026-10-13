/* Decompiled C draft; module arm9; ROM address 020a1748. No matching claim. */
#include "types.h"
#include "deps/020a1748_func_020a1748.h"

void func_020a1748(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = uRam020a178c;
  iVar1 = param_1 * 0x70 +
          (*(uint *)(uRam020a178c & 0xfffffffc) >> (uRam020a178c & 3) * 8 |
          *(uint *)(uRam020a178c & 0xfffffffc) << (uRam020a178c & 3) * -8 + 0x20);
  *(undefined4 *)(iVar1 + 0x1c) = 0xfffffffe;
  *(undefined4 *)(iVar1 + 0x18) = 0xfffffffe;
  *(short *)(iVar1 + 0x44) = (short)param_1;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x388;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  (*(code *)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20))(param_1,param_1);
  return;
}

