/* Decompiled C draft; module arm9; ROM address 02067834. No matching claim. */
#include "types.h"
#include "deps/02067834_func_02067834.h"

undefined4 func_02067834(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1 + 0x3dcU & 3;
  uVar3 = *(uint *)(param_1 + 0x3dcU & 0xfffffffc);
  if ((((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) != 8) ||
      (uVar4 = param_1 + 0x44U & 3, uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
      ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x80000000) != 0)) &&
     ((uVar3 = *(uint *)(uRam020678c4 & 0xfffffffc) >> (uRam020678c4 & 3) * 8 |
               *(uint *)(uRam020678c4 & 0xfffffffc) << (uRam020678c4 & 3) * -8 + 0x20,
      uVar4 = uVar3 & 3, uVar3 = *(uint *)(uVar3 & 0xfffffffc),
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20, uVar4 == 0xc || (uVar4 == 0x28)))) {
    DriverContext_MaybeQueuePlaySfx(param_1,uRam020678c8,0x7f,0);
  }
  iVar1 = iRam020678cc;
  uVar4 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 | 0x10000000;
  iVar2 = iRam020678d0;
  uVar4 = param_1 + 0x3e4U & 3;
  uVar3 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
  uVar4 = iVar1 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x260) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar4 = param_1 + 0x3e4U & 3;
  uVar3 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
  uVar4 = iVar2 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) * 4;
  uVar3 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(uint *)(param_1 + 0x4c4) = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  func_020839d8(param_1);
  return 8;
}

