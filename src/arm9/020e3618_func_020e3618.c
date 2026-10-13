/* Decompiled C draft; module arm9; ROM address 020e3618. No matching claim. */
#include "types.h"
#include "deps/020e3618_func_020e3618.h"

void func_020e3618(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  switch(*(undefined2 *)(param_2 + 0x8e)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    *(undefined2 *)
     ((*(uint *)(DAT_020e3720 & 0xfffffffc) >> (DAT_020e3720 & 3) * 8 |
      *(uint *)(DAT_020e3720 & 0xfffffffc) << (DAT_020e3720 & 3) * -8 + 0x20) + 0x18) = 1;
    uVar1 = func_020e6cf8(param_2 + 4);
    func_020e67c4(*(uint *)(DAT_020e3720 & 0xfffffffc) >> (DAT_020e3720 & 3) * 8 |
                  *(uint *)(DAT_020e3720 & 0xfffffffc) << (DAT_020e3720 & 3) * -8 + 0x20,uVar1,
                  param_2 + 0x1c,0,param_4);
    return;
  case 5:
    return;
  case 6:
    goto LAB_020e3698;
  case 7:
LAB_020e3698:
    *(undefined2 *)
     ((*(uint *)(DAT_020e3720 & 0xfffffffc) >> (DAT_020e3720 & 3) * 8 |
      *(uint *)(DAT_020e3720 & 0xfffffffc) << (DAT_020e3720 & 3) * -8 + 0x20) + 0x18) = 1;
    uVar1 = func_020e6cf8(param_2 + 4);
    func_020e66e4(*(uint *)(DAT_020e3720 & 0xfffffffc) >> (DAT_020e3720 & 3) * 8 |
                  *(uint *)(DAT_020e3720 & 0xfffffffc) << (DAT_020e3720 & 3) * -8 + 0x20,uVar1,
                  *(undefined2 *)(param_2 + 0xb8),param_2 + 0x1c,0,param_4);
    return;
  }
  *(undefined2 *)
   ((*(uint *)(DAT_020e3720 & 0xfffffffc) >> (DAT_020e3720 & 3) * 8 |
    *(uint *)(DAT_020e3720 & 0xfffffffc) << (DAT_020e3720 & 3) * -8 + 0x20) + 0x18) = 0;
  uVar1 = func_020e6cf8(param_2 + 4);
  func_020e67c4(*(uint *)(DAT_020e3720 & 0xfffffffc) >> (DAT_020e3720 & 3) * 8 |
                *(uint *)(DAT_020e3720 & 0xfffffffc) << (DAT_020e3720 & 3) * -8 + 0x20,uVar1,
                param_2 + 0x1c,0,param_4);
  return;
}

