/* Decompiled C draft; module arm9; ROM address 020f9a14. No matching claim. */
#include "types.h"
#include "deps/020f9a14_func_020f9a14.h"

void func_020f9a14(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  
  uVar3 = param_2 * 0xa8 +
          (*(uint *)(uRam020f9b00 & 0xfffffffc) >> (uRam020f9b00 & 3) * 8 |
          *(uint *)(uRam020f9b00 & 0xfffffffc) << (uRam020f9b00 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  pcVar4 = (code *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *(int *)(param_1 + 0x44) = param_2;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined2 *)(param_1 + 0x7a) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0x7b;
  *(undefined4 *)(param_1 + 0xe0) = 0x7b;
  *(undefined2 *)(param_1 + 0xd8) = 0x1f;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined2 *)(param_1 + 0x118) = 0;
  *(undefined2 *)(param_1 + 0x114) = 5;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(int *)(param_1 + 0xd0) = param_1 + 0x50;
  *(undefined2 *)(param_1 + 0xda) = 0xffff;
  uVar1 = uRam020f9b04;
  uVar3 = param_1 + 0x104U & 3;
  uVar2 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
  *(undefined4 *)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) = 0;
  uVar3 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 8;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 5) {
    uVar3 = param_1 + 0x74U & 3;
    uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20 | 0x8000000;
  }
  *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) | *puRam020f9b08;
  LightInfo_SomeFn(param_1 + 0x7c,1);
  *(undefined4 *)(param_1 + 0x90) = 0;
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(param_1);
  }
  *(undefined1 *)(param_1 + 0x128) = 0;
  return;
}

