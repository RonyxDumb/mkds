/* Decompiled C draft; module arm7; ROM address 06010844. No matching claim. */
#include "types.h"
#include "deps/06010844_FUN_06010844.h"

undefined4 FUN_06010844(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(DAT_0601090c & 0xfffffffc) >> (DAT_0601090c & 3) * 8 |
          *(uint *)(DAT_0601090c & 0xfffffffc) << (DAT_0601090c & 3) * -8 + 0x20;
  puVar3 = (undefined2 *)(uVar4 + DAT_06010910);
  *(undefined2 *)(param_2 + 2) = 3;
  if ((*(short *)(uVar4 + 0x32e) == 3) || (*(short *)(uVar4 + 0x32e) == 2)) {
    if (*(ushort *)(uVar4 + 0x34c) < 0x30) {
      uVar2 = 1;
    }
    else if ((*(ushort *)(param_1 + 0x10) & 1) == 0) {
      uVar1 = *(ushort *)(param_1 + 0x16);
      if (uVar1 == 0) {
        uVar2 = 5;
      }
      else if (uVar1 < 0x100) {
        if (*(ushort *)(param_1 + 0x18) < 0x7d1) {
          if (*(ushort *)(param_1 + 0x18) < 10) {
            uVar2 = 5;
          }
          else {
            *(ushort *)(uVar4 + 0x3b4) = uVar1;
            *(undefined2 *)(uVar4 + 0x3b6) = *(undefined2 *)(param_1 + 0x16);
            *(int *)(puVar3 + 0xc) = param_1;
            *(int *)(puVar3 + 0xe) = param_2;
            *puVar3 = 0x60;
            FUN_0600fe70();
            uVar2 = 0x80;
          }
        }
        else {
          uVar2 = 5;
        }
      }
      else {
        uVar2 = 5;
      }
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

