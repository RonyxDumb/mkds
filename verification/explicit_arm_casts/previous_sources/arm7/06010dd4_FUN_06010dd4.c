/* Decompiled C draft; module arm7; ROM address 06010dd4. No matching claim. */
#include "types.h"
#include "deps/06010dd4_FUN_06010dd4.h"

undefined4 FUN_06010dd4(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  uVar4 = *(uint *)(DAT_06010f18 & 0xfffffffc) >> (DAT_06010f18 & 3) * 8 |
          *(uint *)(DAT_06010f18 & 0xfffffffc) << (DAT_06010f18 & 3) * -8 + 0x20;
  puVar5 = (undefined2 *)(uVar4 + DAT_06010f1c);
  puVar5[2] = *(short *)(param_2 + 2) + -3;
  *(undefined2 *)(param_2 + 2) = 3;
  sVar1 = *(short *)(uVar4 + 0x32e);
  if (((sVar1 == 1) || (sVar1 == 3)) || (sVar1 == 2)) {
    if (*(ushort *)
         ((*(uint *)(DAT_06010f18 & 0xfffffffc) >> (DAT_06010f18 & 3) * 8 |
          *(uint *)(DAT_06010f18 & 0xfffffffc) << (DAT_06010f18 & 3) * -8 + 0x20) + 0x34c) < 0x20) {
      uVar2 = 1;
    }
    else if (*(ushort *)(param_1 + 0x16) < 0x21) {
      if (*(ushort *)(param_1 + 0x38) < 2) {
        iVar3 = FUN_060096c4(param_1 + 0x3a);
        if (iVar3 == 0) {
          uVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x4a) < 0x3e9) {
          if (*(ushort *)(param_1 + 0x4a) < 10) {
            uVar2 = 5;
          }
          else if (*(ushort *)(param_1 + 0x4c) < 0x11) {
            uVar4 = 0;
            while ((uVar4 < 0x10 && (iVar3 = FUN_060096c4(param_1 + 0x3a + uVar4), iVar3 != 0))) {
              iVar3 = FUN_0600a558();
              if (iVar3 == 0) {
                return 5;
              }
              uVar4 = uVar4 + 1;
            }
            FUN_0600b564(param_1 + 0x10);
            FUN_0600b448(*(undefined2 *)(param_1 + 0x16),param_1 + 0x18);
            *(int *)(puVar5 + 0xc) = param_1;
            *(int *)(puVar5 + 0xe) = param_2;
            *puVar5 = 0x10;
            FUN_06008a8c(2,0);
            uVar2 = 0x80;
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
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

