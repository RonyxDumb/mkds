/* Decompiled C draft; module arm9; ROM address 0209dd44. No matching claim. */
#include "types.h"
#include "deps/0209dd44_func_0209dd44.h"

undefined1 func_0209dd44(int param_1,undefined4 param_2,char *param_3,undefined1 *param_4)

{
  uint uVar1;
  undefined1 uVar2;
  ushort *puVar3;
  uint uVar4;
  
  puVar3 = puRam0209dde8;
  uVar2 = *param_4;
  if ((*param_3 == '\x01') &&
     (uVar1 = param_1 + 0xb8U & 3, uVar4 = *(uint *)(param_1 + 0xb8U & 0xfffffffc),
     (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) < 2)) {
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam0209dde4;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar3;
    *(undefined4 *)(param_1 + 0xb8) = 2;
    *(undefined2 *)(param_1 + 0xa0) = 0x168;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0x3000;
    *(undefined4 *)(param_1 + 0x18) = 0;
    uVar1 = param_1 + 0xbcU & 3;
    uVar4 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    *(undefined2 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x70) = 0x23;
    uVar1 = param_1 + 0xc0U & 3;
    uVar4 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    *(undefined2 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x70) = 0x23;
    uVar1 = param_1 + 0xbcU & 3;
    uVar4 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    *(undefined1 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x80) = 5;
    uVar1 = param_1 + 0xc0U & 3;
    uVar4 = *(uint *)(param_1 + 0xc0U & 0xfffffffc);
    *(undefined1 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + 0x80) = 5;
  }
  return uVar2;
}

