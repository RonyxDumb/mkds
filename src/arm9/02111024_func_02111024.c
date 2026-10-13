/* Decompiled C draft; module arm9; ROM address 02111024. No matching claim. */
#include "types.h"
#include "deps/02111024_func_02111024.h"

void func_02111024(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int in_r3;
  
  if (*(uint *)((uint)puRam02111104 & 0xfffffffc) >> ((uint)puRam02111104 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02111104 & 0xfffffffc) << ((uint)puRam02111104 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar6 = iRam02111108 + 0xcU & 3;
  uVar3 = *(uint *)(iRam02111108 + 0xcU & 0xfffffffc);
  if (uVar3 >> uVar6 * 8 != 0 || uVar3 << uVar6 * -8 + 0x20 != 0) {
    return;
  }
  iVar4 = func_02110e58();
  if (iVar4 == 2) {
    in_r3 = 0x91;
  }
  iVar5 = (*(uint *)((uint)piRam0211110c & 0xfffffffc) >> ((uint)piRam0211110c & 3) * 8 |
          *(uint *)((uint)piRam0211110c & 0xfffffffc) << ((uint)piRam0211110c & 3) * -8 + 0x20) + 1;
  if (iVar4 != 2) {
    in_r3 = 0x82;
  }
  *piRam0211110c = iVar5;
  if (iVar5 <= in_r3) {
    return;
  }
  if (*(uint *)((uint)puRam02111110 & 0xfffffffc) >> ((uint)puRam02111110 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam02111110 & 0xfffffffc) << ((uint)puRam02111110 & 3) * -8 + 0x20 == 0) {
    return;
  }
  uVar6 = iRam02111114 + 8U & 3;
  uVar3 = *(uint *)(iRam02111114 + 8U & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar3 = 0xff;
  if ((iVar4 == 0) || (iVar4 == 1)) {
    uVar6 = uVar6 + 0xc;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  }
  else if (iVar4 == 2) {
    uVar6 = uVar6 + 0x10;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  }
  func_0210d614(iRam02111108,uVar3,0);
  piVar2 = piRam0211110c;
  puVar1 = puRam02111104;
  *puRam02111110 = 0;
  *puVar1 = 0;
  *piVar2 = 0;
  return;
}

