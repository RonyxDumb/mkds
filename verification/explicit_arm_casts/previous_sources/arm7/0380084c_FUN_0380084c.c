/* Decompiled C draft; module arm7; ROM address 0380084c. No matching claim. */
#include "types.h"
#include "deps/0380084c_FUN_0380084c.h"

undefined4 FUN_0380084c(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  
  uVar1 = DAT_03800910;
  uVar2 = FUN_037faf70();
  while (uVar7 = uVar1 + 0xfc & 3, uVar3 = *(uint *)(uVar1 + 0xfc & 0xfffffffc),
        ((uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) & 4) != 0) {
    FUN_037f9104(uVar1 + 0xf4);
  }
  uVar7 = uVar1 + 0xfc & 3;
  uVar3 = *(uint *)(uVar1 + 0xfc & 0xfffffffc);
  *(uint *)(uVar1 + 0xfc) = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20 | 4;
  *(undefined4 *)(uVar1 + 0x3c) = 0;
  *(undefined4 *)(uVar1 + 0x40) = 0;
  FUN_037faf84(uVar2);
  uVar2 = FUN_03800988();
  uVar3 = DAT_03800910;
  *(undefined4 *)
   (*(uint *)(DAT_03800910 & 0xfffffffc) >> (DAT_03800910 & 3) * 8 |
   *(uint *)(DAT_03800910 & 0xfffffffc) << (DAT_03800910 & 3) * -8 + 0x20) = 0;
  uVar1 = uVar3 + 0x3c & 3;
  uVar7 = *(uint *)(uVar3 + 0x3c & 0xfffffffc);
  pcVar8 = (code *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  uVar1 = uVar3 + 0x40 & 3;
  uVar6 = *(uint *)(uVar3 + 0x40 & 0xfffffffc);
  uVar4 = FUN_037faf70();
  uVar7 = uVar3 + 0xfc & 3;
  uVar5 = *(uint *)(uVar3 + 0xfc & 0xfffffffc);
  *(uint *)(uVar3 + 0xfc) = (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0xffffffb3;
  FUN_037f9088(uVar3 + 0xf4);
  uVar7 = uVar3 + 0xfc & 3;
  uVar5 = *(uint *)(uVar3 + 0xfc & 0xfffffffc);
  if (((uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) & 0x10) != 0) {
    FUN_037f9054(uVar3 + 0x48);
  }
  FUN_037faf84(uVar4);
  if (pcVar8 != (code *)0x0) {
    (*pcVar8)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  }
  return uVar2;
}

