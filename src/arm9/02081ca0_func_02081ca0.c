/* Decompiled C draft; module arm9; ROM address 02081ca0. No matching claim. */
#include "types.h"
#include "deps/02081ca0_func_02081ca0.h"

void func_02081ca0(int param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    func_02081b64(param_1,param_2,uRam02081d64,iRam02081d68);
    uVar2 = param_2 + 0xc4U & 3;
    uVar4 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
    *(int *)(param_1 + 0x5c) =
         (int)(short)(iRam02081d68 * (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x800 >>
                     0xc);
    return;
  }
  bVar1 = true;
  func_02081b64(param_1,param_2,uRam02081d6c,uRam02081d70);
  uVar2 = param_2 + 0xc4U & 3;
  uVar4 = *(uint *)(param_2 + 0xc4U & 0xfffffffc);
  *(int *)(param_1 + 0x6c) =
       (int)(short)((ushort)(uVar4 >> uVar2 * 8) | (ushort)(uVar4 << uVar2 * -8 + 0x20));
  uVar2 = param_2 + 0x7cU & 3;
  uVar4 = *(uint *)(param_2 + 0x7cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = uVar4 & 1;
  if ((uVar2 == 0) && (uVar2 = uVar4 & uRam02081d74, uVar2 != 0)) {
    bVar1 = false;
  }
  if (!bVar1) {
    uVar2 = 1;
  }
  uVar4 = param_1 + 0x24U & 3;
  uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if (bVar1) {
    uVar2 = 0;
  }
  *(uint *)(param_1 + 0x24) =
       (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffff7 | (uVar2 & 1) << 3;
  return;
}

