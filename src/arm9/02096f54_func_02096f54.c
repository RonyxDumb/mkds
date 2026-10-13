/* Decompiled C draft; module arm9; ROM address 02096f54. No matching claim. */
#include "types.h"
#include "deps/02096f54_func_02096f54.h"

undefined1 func_02096f54(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0xb0U & 3;
  uVar4 = *(uint *)(param_1 + 0xb0U & 0xfffffffc);
  uVar2 = *param_4;
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 4) {
    if (*param_3 == '\x02') {
      *(undefined4 *)(param_1 + 0x104) = 1;
      uVar1 = param_1 + 0xa0U & 3;
      uVar4 = *(uint *)(param_1 + 0xa0U & 0xfffffffc);
      *(uint *)(param_1 + 0xb4) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
      uVar3 = uRam02097024;
      uVar1 = param_1 + 0xa4U & 3;
      uVar4 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
      *(uint *)(param_1 + 0xb8) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
      *(undefined4 *)(param_1 + 0xbc) = 0x4000;
      *(undefined4 *)(param_1 + 0xc0) = uVar3;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined2 *)(param_1 + 0xc4) = 0;
      *(undefined4 *)(param_1 + 0xd0) = 0;
      *(undefined4 *)(param_1 + 0xd4) = 0x2000;
      *(undefined4 *)(param_1 + 0xd8) = 0xffffffc0;
      *(undefined4 *)(param_1 + 0xdc) = 0x200;
      *(undefined4 *)(param_1 + 0xe0) = 0;
      *(undefined2 *)(param_1 + 0xe4) = 0;
      *(undefined4 *)(param_1 + 0xf0) = 0;
      *(undefined4 *)(param_1 + 0xf4) = 0x1000;
      *(undefined4 *)(param_1 + 0xf8) = 0xffffffd0;
      *(undefined4 *)(param_1 + 0xfc) = 0x800;
      *(undefined4 *)(param_1 + 0x100) = 0x100;
      uVar1 = param_1 + 0x78U & 3;
      uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
      *(uint *)(param_1 + 0x78) =
           uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 |
           *(uint *)(uRam02097028 & 0xfffffffc) >> (uRam02097028 & 3) * 8 |
           *(uint *)(uRam02097028 & 0xfffffffc) << (uRam02097028 & 3) * -8 + 0x20;
      if ((*(ushort *)(param_1 + 2) & 0x800) == 0) {
        *(undefined4 *)(param_1 + 0xb0) = 7;
      }
    }
    return uVar2;
  }
  return 0;
}

