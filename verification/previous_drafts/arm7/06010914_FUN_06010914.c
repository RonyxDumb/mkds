/* Decompiled C draft; module arm7; ROM address 06010914. No matching claim. */
#include "types.h"
#include "deps/06010914_FUN_06010914.h"

undefined4 FUN_06010914(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  uVar2 = *(uint *)(DAT_060109f4 & 0xfffffffc) >> (DAT_060109f4 & 3) * 8 |
          *(uint *)(DAT_060109f4 & 0xfffffffc) << (DAT_060109f4 & 3) * -8 + 0x20;
  puVar3 = (undefined2 *)(uVar2 + DAT_060109f8);
  *(undefined2 *)(param_2 + 2) = 3;
  if ((*(short *)(uVar2 + 0x32e) == 3) || (*(short *)(uVar2 + 0x32e) == 2)) {
    if (*(ushort *)(uVar2 + 0x34c) < 0x30) {
      uVar1 = 1;
    }
    else if ((*(ushort *)(param_1 + 0x10) & 1) == 0) {
      if (*(ushort *)(param_1 + 0x16) == 0) {
        uVar1 = 5;
      }
      else if (*(ushort *)(param_1 + 0x16) < 0x100) {
        if (*(ushort *)(param_1 + 0x18) < 0x7d1) {
          if (*(ushort *)(param_1 + 0x18) < 10) {
            uVar1 = 5;
          }
          else {
            FUN_0600a970(0x30);
            FUN_0600aa54();
            *(undefined2 *)(uVar2 + 0x3b4) = *(undefined2 *)(param_1 + 0x16);
            *(undefined2 *)(uVar2 + 0x3b6) = *(undefined2 *)(param_1 + 0x16);
            *(int *)(puVar3 + 0xc) = param_1;
            *(int *)(puVar3 + 0xe) = param_2;
            *puVar3 = 0x50;
            FUN_0600ff70();
            uVar1 = 0x80;
          }
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
  }
  else {
    uVar1 = 0xb;
  }
  return uVar1;
}

