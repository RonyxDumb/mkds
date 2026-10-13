/* Decompiled C draft; module arm7; ROM address 06010b38. No matching claim. */
#include "types.h"
#include "deps/06010b38_FUN_06010b38.h"

undefined4 FUN_06010b38(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  uVar3 = *(uint *)(DAT_06010c0c & 0xfffffffc) >> (DAT_06010c0c & 3) * 8 |
          *(uint *)(DAT_06010c0c & 0xfffffffc) << (DAT_06010c0c & 3) * -8 + 0x20;
  puVar4 = (undefined2 *)(uVar3 + DAT_06010c10);
  *(undefined2 *)(param_2 + 2) = 6;
  if ((*(short *)(uVar3 + 0x32e) == 3) || (*(short *)(uVar3 + 0x32e) == 2)) {
    if (*(ushort *)(uVar3 + 0x34c) < 0x20) {
      uVar1 = 1;
    }
    else if ((*(ushort *)(param_1 + 0x10) & 1) == 0) {
      if (*(ushort *)(param_1 + 0x16) < 2) {
        if (*(ushort *)(param_1 + 0x18) < 0x7d1) {
          if (*(ushort *)(param_1 + 0x18) < 10) {
            uVar1 = 5;
          }
          else {
            FUN_0600a970(0x20);
            *(int *)(puVar4 + 0xc) = param_1;
            *(int *)(puVar4 + 0xe) = param_2;
            *puVar4 = 0x30;
            uVar3 = (uint)(puVar4 + 0xc) & 3;
            uVar2 = *(uint *)((uint)(puVar4 + 0xc) & 0xfffffffc);
            *(undefined2 *)(param_2 + 0xe) =
                 *(undefined2 *)((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x16);
            uVar3 = (uint)(puVar4 + 0xc) & 3;
            uVar2 = *(uint *)((uint)(puVar4 + 0xc) & 0xfffffffc);
            FUN_0600a954(param_2 + 8,(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x10);
            FUN_06010078();
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

