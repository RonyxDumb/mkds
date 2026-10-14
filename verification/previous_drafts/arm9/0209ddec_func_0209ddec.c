/* Decompiled C draft; module arm9; ROM address 0209ddec. No matching claim. */
#include "types.h"
#include "deps/0209ddec_func_0209ddec.h"

undefined1 func_0209ddec(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = puRam0209dec4;
  uVar1 = *param_4;
  if ((*param_3 == '\x01') &&
     (uVar4 = param_1 + 0xb8U & 3, uVar3 = *(uint *)(param_1 + 0xb8U & 0xfffffffc),
     (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) < 2)) {
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam0209dec0;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
    *(undefined4 *)(param_1 + 0xb8) = 2;
    *(undefined2 *)(param_1 + 0xa0) = 0x168;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0x3000;
    *(undefined4 *)(param_1 + 0x18) = 0;
    uVar4 = param_1 + 0xbcU & 3;
    uVar3 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x70) = 0x23;
    uVar4 = param_1 + 0xc0U & 3;
    uVar3 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x70) = 0x23;
    uVar4 = param_1 + 0xbcU & 3;
    uVar3 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    *(undefined1 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x80) = 5;
    uVar4 = param_1 + 0xc0U & 3;
    uVar3 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    *(undefined1 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x80) = 5;
    uVar4 = param_2 + 0x29cU & 3;
    uVar3 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    if ((uVar4 == 1) || (uVar4 == 3)) {
      uVar4 = param_1 + 0x78U & 3;
      uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(uint *)(param_1 + 0x78) =
           uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20 |
           *(uint *)(uRam0209dec8 & 0xfffffffc) >> (uRam0209dec8 & 3) * 8 |
           *(uint *)(uRam0209dec8 & 0xfffffffc) << (uRam0209dec8 & 3) * -8 + 0x20;
    }
    func_020d26f8();
  }
  return uVar1;
}

