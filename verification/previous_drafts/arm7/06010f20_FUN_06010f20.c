/* Decompiled C draft; module arm7; ROM address 06010f20. No matching claim. */
#include "types.h"
#include "deps/06010f20_FUN_06010f20.h"

undefined4 FUN_06010f20(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(undefined2 *)(param_2 + 2) = 9;
  if (*(ushort *)(param_1 + 0x10) < 2) {
    if (*(ushort *)(param_1 + 0x12) < 2) {
      if (*(ushort *)(param_1 + 0x14) < 2) {
        FUN_0600ae2c(*(ushort *)(param_1 + 0x10));
        if (*(short *)(param_1 + 0x10) == 1) {
          if (*(short *)(param_1 + 0x12) == 1) {
            FUN_0600adec(DAT_06010fc4);
          }
          else {
            FUN_0600adec(0);
          }
          *(undefined2 *)
           ((*(uint *)(DAT_06010fc8 & 0xfffffffc) >> (DAT_06010fc8 & 3) * 8 |
            *(uint *)(DAT_06010fc8 & 0xfffffffc) << (DAT_06010fc8 & 3) * -8 + 0x20) + 0x358) =
               *(undefined2 *)(param_1 + 0x14);
        }
        else {
          FUN_0600adec(0x8000);
          FUN_0600ae00(2);
        }
        uVar1 = 0;
      }
      else {
        uVar1 = 5;
      }
    }
    else {
      uVar1 = 5;
    }
  }
  else {
    uVar1 = 5;
  }
  return uVar1;
}

