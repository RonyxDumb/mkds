/* Decompiled C draft; module arm9; ROM address 0209c964. No matching claim. */
#include "types.h"
#include "deps/0209c964_func_0209c964.h"

undefined1 func_0209c964(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar2 = *param_4;
  if ((*param_3 == '\x02') &&
     (uVar1 = param_1 + 0x11cU & 3, uVar3 = *(uint *)(param_1 + 0x11cU & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    *(undefined2 *)(param_1 + 0xb8) = 0x8000;
    *(undefined4 *)(param_1 + 0xc4) = 0x1000;
    *(undefined4 *)(param_1 + 200) = 0x200;
    *(undefined4 *)(param_1 + 0xcc) = 0xffffffec;
    *(undefined4 *)(param_1 + 0xd0) = 0x1000;
    *(undefined4 *)(param_1 + 0xd4) = 0;
    *(undefined2 *)(param_1 + 0xd8) = 0;
    *(undefined4 *)(param_1 + 0xe4) = 0x1000;
    *(undefined4 *)(param_1 + 0xe8) = 0x200;
    *(undefined4 *)(param_1 + 0xec) = 0xffffffec;
    *(undefined4 *)(param_1 + 0xf0) = 0x1000;
    *(undefined4 *)(param_1 + 0xf4) = 0;
    *(undefined4 *)(param_1 + 0x11c) = 1;
    uVar1 = param_1 + 0x78U & 3;
    uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(uint *)(param_1 + 0x78) =
         uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 |
         *(uint *)(uRam0209c9f8 & 0xfffffffc) >> (uRam0209c9f8 & 3) * 8 |
         *(uint *)(uRam0209c9f8 & 0xfffffffc) << (uRam0209c9f8 & 3) * -8 + 0x20;
  }
  return uVar2;
}

