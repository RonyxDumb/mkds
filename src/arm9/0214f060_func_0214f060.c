/* Decompiled C draft; module arm9; ROM address 0214f060. No matching claim. */
#include "types.h"
#include "deps/0214f060_func_0214f060.h"

void func_0214f060(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  uint uVar6;
  code *pcVar7;
  
  puVar3 = DAT_0214f198;
  if (param_3 != 0) {
    uVar2 = (uint)(DAT_0214f198 + 1) & 3;
    uVar6 = *(uint *)((uint)(DAT_0214f198 + 1) & 0xfffffffc);
    pcVar7 = (code *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    if (*(uint *)((uint)DAT_0214f198 & 0xfffffffc) >> ((uint)DAT_0214f198 & 3) * 8 != 0 ||
        *(uint *)((uint)DAT_0214f198 & 0xfffffffc) << ((uint)DAT_0214f198 & 3) * -8 + 0x20 != 0) {
      *DAT_0214f198 = 0;
    }
    if (pcVar7 != (code *)0x0) {
      puVar1 = puVar3 + 2;
      uVar2 = (uint)puVar1 & 3;
      uVar6 = *(uint *)((uint)puVar1 & 0xfffffffc);
      puVar3[1] = 0;
      (*pcVar7)(6,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    }
  }
  uVar2 = ((param_2 & 0x7f00) << 8) >> 0x10;
  switch(param_2 & 0xff) {
  case 0:
    uVar4 = 0;
    break;
  case 1:
    uVar4 = 4;
    break;
  case 2:
    uVar4 = 2;
    break;
  case 3:
    uVar4 = 5;
    break;
  case 4:
    uVar4 = 1;
    break;
  default:
    uVar4 = 6;
  }
  if (uVar2 == 0x51) {
    uVar2 = (uint)(DAT_0214f198 + 4) & 3;
    uVar6 = *(uint *)((uint)(DAT_0214f198 + 4) & 0xfffffffc);
    pcVar7 = (code *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    if (pcVar7 == (code *)0x0) {
      return;
    }
    uVar2 = (uint)(DAT_0214f198 + 5) & 3;
    uVar6 = *(uint *)((uint)(DAT_0214f198 + 5) & 0xfffffffc);
    (*pcVar7)(uVar4,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
    return;
  }
  if ((uVar2 == 0x40) &&
     (uVar2 = (uint)(DAT_0214f198 + 6) & 3, uVar6 = *(uint *)((uint)(DAT_0214f198 + 6) & 0xfffffffc)
     , puVar5 = (undefined2 *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20),
     puVar5 != (undefined2 *)0x0)) {
    *puVar5 = *DAT_0214f19c;
  }
  if (*(uint *)((uint)DAT_0214f198 & 0xfffffffc) >> ((uint)DAT_0214f198 & 3) * 8 != 0 ||
      *(uint *)((uint)DAT_0214f198 & 0xfffffffc) << ((uint)DAT_0214f198 & 3) * -8 + 0x20 != 0) {
    *DAT_0214f198 = 0;
  }
  uVar2 = (uint)(DAT_0214f198 + 1) & 3;
  uVar6 = *(uint *)((uint)(DAT_0214f198 + 1) & 0xfffffffc);
  pcVar7 = (code *)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  if (pcVar7 == (code *)0x0) {
    return;
  }
  uVar2 = (uint)(DAT_0214f198 + 2) & 3;
  uVar6 = *(uint *)((uint)(DAT_0214f198 + 2) & 0xfffffffc);
  DAT_0214f198[1] = 0;
  (*pcVar7)(uVar4,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  return;
}

