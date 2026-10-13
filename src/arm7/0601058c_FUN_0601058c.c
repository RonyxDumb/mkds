/* Decompiled C draft; module arm7; ROM address 0601058c. No matching claim. */
#include "types.h"
#include "deps/0601058c_FUN_0601058c.h"

undefined4 FUN_0601058c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(DAT_06010724 & 0xfffffffc) >> (DAT_06010724 & 3) * 8 |
          *(uint *)(DAT_06010724 & 0xfffffffc) << (DAT_06010724 & 3) * -8 + 0x20;
  *(undefined2 *)(param_2 + 2) = 1;
  if ((*(short *)(uVar1 + 0x32e) == 1) || (*(short *)(uVar1 + 0x32e) == 0)) {
    if (*(short *)(uVar1 + 0x34c) == 0x20) {
      if (*(ushort *)(param_1 + 0x10) < 0x21) {
        if (*(ushort *)(param_1 + 0x10) == 0) {
          uVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x32) < 10) {
          uVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x32) < 0x3e9) {
          if (*(ushort *)(param_1 + 0x34) == 0) {
            uVar2 = 5;
          }
          else if (*(ushort *)(param_1 + 0x34) < 0x100) {
            if ((DAT_06010728 & *(ushort *)(param_1 + 0x36)) == 0) {
              iVar3 = FUN_0600a558((uint)*(ushort *)(param_1 + 0x36));
              if (iVar3 == 0) {
                uVar2 = 5;
              }
              else if (*(ushort *)(param_1 + 0x38) == 0) {
                uVar2 = 5;
              }
              else if ((*(ushort *)(param_1 + 0x38) & 0xf000) == 0) {
                if (*(ushort *)(param_1 + 0x3a) == 0) {
                  uVar2 = 5;
                }
                else if ((*(ushort *)(param_1 + 0x3a) & 0xf000) == 0) {
                  if (*(ushort *)(param_1 + 0x3c) < 0x81) {
                    iVar3 = FUN_060188f4(0);
                    if (iVar3 == 0) {
                      if (*(short *)(uVar1 + 0x32e) == 0) {
                        FUN_0600b564((ushort *)(uintptr_t)(DAT_0601072c));
                      }
                      else {
                        FUN_0600b564((ushort *)(uintptr_t)(uVar1 + 0x324));
                      }
                      FUN_0600b448(*(undefined2 *)(param_1 + 0x10),param_1 + 0x12);
                      FUN_0600b3e8(*(undefined2 *)(param_1 + 0x32));
                      FUN_0600b39c(*(undefined2 *)(param_1 + 0x34));
                      FUN_0600af7c(*(undefined2 *)(param_1 + 0x36),0);
                      FUN_0600af34((ushort *)(uintptr_t)(param_1 + 0x38));
                      FUN_0600abac(*(undefined2 *)(param_1 + 0x3c),param_1 + 0x3e);
                      *(undefined2 *)(uVar1 + 1000) = 0;
                      FUN_06009f84();
                      uVar2 = 0;
                    }
                    else {
                      uVar2 = 0xe;
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
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

