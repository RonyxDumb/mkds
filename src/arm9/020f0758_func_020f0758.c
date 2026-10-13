/* Decompiled C draft; module arm9; ROM address 020f0758. No matching claim. */
#include "types.h"
#include "deps/020f0758_func_020f0758.h"

void func_020f0758(uint param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
                  )

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  switch(param_2) {
  case 0:
    uVar3 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 0xa8 +
            (*(uint *)(DAT_020f0894 & 0xfffffffc) >> (DAT_020f0894 & 3) * 8 |
            *(uint *)(DAT_020f0894 & 0xfffffffc) << (DAT_020f0894 & 3) * -8 + 0x20) + 0x48;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
      return;
    }
    if (*(char *)(param_4 + 1) != -1) {
      func_020f0b00(param_1,param_3,param_4,0);
      if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 6) {
        func_020f82e8(0);
      }
      if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 10) {
        func_020f82a4(0);
        return;
      }
      return;
    }
    return;
  case 1:
    func_020f0b00(param_1,param_3,param_4,1);
    return;
  case 2:
    iVar2 = func_020f0950(param_1,*(undefined1 *)(param_4 + 2),*(undefined1 *)(param_4 + 1));
    if (iVar2 != 0) {
      return;
    }
    break;
  case 3:
    iVar2 = func_020f0898(param_1,param_4);
    if (iVar2 != 0) {
      return;
    }
    break;
  default:
    return;
  }
  func_020fe56c(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,param_2,param_3,param_4
                ,param_5);
  return;
}

