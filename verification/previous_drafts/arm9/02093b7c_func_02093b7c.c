/* Decompiled C draft; module arm9; ROM address 02093b7c. No matching claim. */
#include "types.h"
#include "deps/02093b7c_func_02093b7c.h"

undefined1 func_02093b7c(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    *(undefined4 *)(param_1 + 0xa0) = 0x78;
    *(undefined4 *)(param_1 + 0xa4) = 1;
    uVar4 = param_1 + 0x10U & 3;
    uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0x10) =
         (uVar4 << 10) >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
    puVar2 = puRam02093c5c;
    uVar4 = param_1 + 0x14U & 3;
    uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0x14) =
         (uVar4 << 10) >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
    uVar4 = param_1 + 0x18U & 3;
    uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    *(uint *)(param_1 + 0x18) =
         (uVar4 << 10) >> 0xc | (((int)uVar4 >> 0x1f) << 10 | uVar4 >> 0x16) << 0x14;
    *(undefined4 *)(param_1 + 0x14) = 0x4000;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
    uVar4 = param_2 + 0x29cU & 3;
    uVar3 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((uVar4 == 1) || (uVar4 == 3)) {
      uVar4 = param_1 + 0x78U & 3;
      uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(uint *)(param_1 + 0x78) =
           uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 |
           *(uint *)(uRam02093c60 & 0xfffffffc) >> (uRam02093c60 & 3) * 8 |
           *(uint *)(uRam02093c60 & 0xfffffffc) << (uRam02093c60 & 3) * -8 + 0x20;
    }
    func_020d26f8();
  }
  return uVar1;
}

