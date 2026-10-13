/* Decompiled C draft; module arm9; ROM address 0210b98c. No matching claim. */
#include "types.h"
#include "deps/0210b98c_func_0210b98c.h"

void func_0210b98c(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  switch(param_2) {
  case 0x130:
    iVar3 = 0x640;
    break;
  case 0x131:
    iVar3 = 0x1900;
    break;
  case 0x132:
    iVar3 = 0x3840;
    break;
  case 0x133:
    iVar3 = DAT_0210ba2c;
    break;
  case 0x134:
    break;
  case 0x135:
    break;
  case 0x136:
    break;
  case 0x137:
    iVar3 = 0x19;
    break;
  case 0x138:
    iVar3 = 0x6400;
    break;
  case 0x139:
    iVar3 = 0xe100;
  }
  uVar1 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  func_0210ddf4(DAT_0210ba30,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar3,DAT_0210ba34,
                param_1,param_2);
  return;
}

