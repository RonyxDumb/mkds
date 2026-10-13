/* Decompiled C draft; module arm9; ROM address 02099208. No matching claim. */
#include "types.h"
#include "deps/02099208_func_02099208.h"

undefined1 func_02099208(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_4;
  if (*param_3 == '\x01') {
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam02099270;
    *(undefined4 *)(param_1 + 0xcc) = 1;
    uVar3 = param_2 + 0x29cU & 3;
    uVar2 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((uVar3 == 1) || (uVar3 == 3)) {
      uVar3 = param_1 + 0x78U & 3;
      uVar2 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(uint *)(param_1 + 0x78) =
           uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 |
           *(uint *)(uRam02099274 & 0xfffffffc) >> (uRam02099274 & 3) * 8 |
           *(uint *)(uRam02099274 & 0xfffffffc) << (uRam02099274 & 3) * -8 + 0x20;
    }
    func_020d26f8();
  }
  return uVar1;
}

