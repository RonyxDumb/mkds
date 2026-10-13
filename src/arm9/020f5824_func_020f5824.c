/* Decompiled C draft; module arm9; ROM address 020f5824. No matching claim. */
#include "types.h"
#include "deps/020f5824_func_020f5824.h"

void func_020f5824(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar3 = param_1 + 0x228U & 3;
  uVar2 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x1fc;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  bVar5 = true;
  uVar3 = uVar2 + 0x7c;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (((uVar3 & uRam020f5950) == 0) &&
     (uVar2 = uVar2 + 0x4c, uVar4 = uVar2 & 3, uVar2 = *(uint *)(uVar2 & 0xfffffffc),
     ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x800) == 0)) {
    bVar5 = false;
  }
  if (bVar5) {
    func_020f1104(param_1);
    *(undefined2 *)(param_1 + 0x24c) = 6;
    *(undefined2 *)(param_1 + 0x24e) = 1;
  }
  else {
    uVar2 = param_1 + 0x74U & 3;
    uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if ((uVar2 & 0x10000000) == 0) {
      iVar1 = func_020f14a0(param_1,0x4800,uRam020f5958,(uVar2 & 0x8000000) == 0);
    }
    else if ((uVar3 & 1) == 0) {
      iVar1 = func_020f14a0(param_1,uRam020f595c,uRam020f5958,0);
    }
    else {
      iVar1 = func_020f14a0(param_1,uRam020f5954,uRam020f5958,1);
    }
    if (iVar1 != 0) {
      func_020f1104(param_1);
      *(undefined2 *)(param_1 + 0x24c) = 2;
      *(undefined2 *)(param_1 + 0x24e) = 1;
      *(undefined4 *)(param_1 + 0x21c) = 0;
      *(undefined4 *)(param_1 + 0x220) = 1;
    }
  }
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 1) != 0) {
    return;
  }
  uVar3 = param_1 + 0xd4U & 3;
  uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
  func_0210ddf4(uRam020f5960,(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0x3fffffe0,
                uRam020f5964,param_1);
  return;
}

