/* Decompiled C draft; module arm7; ROM address 06010c14. No matching claim. */
#include "types.h"
#include "deps/06010c14_FUN_06010c14.h"

undefined4 FUN_06010c14(int param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  
  uVar4 = *(uint *)(DAT_06010dc8 & 0xfffffffc) >> (DAT_06010dc8 & 3) * 8 |
          *(uint *)(DAT_06010dc8 & 0xfffffffc) << (DAT_06010dc8 & 3) * -8 + 0x20;
  puVar5 = (undefined2 *)(uVar4 + DAT_06010dcc);
  *(undefined2 *)(param_2 + 2) = 5;
  if ((*(short *)(uVar4 + 0x32e) == 3) || (*(short *)(uVar4 + 0x32e) == 2)) {
    if (*(ushort *)(uVar4 + 0x34c) < 0x20) {
      uVar2 = 1;
    }
    else {
      FUN_0600a970(0x20);
      if ((*(ushort *)(param_1 + 0x18) & 1) == 0) {
        if (*(ushort *)(param_1 + 0x1e) == 0) {
          uVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x1e) < 0x21) {
          if (*(ushort *)(param_1 + 0x46) < 10) {
            uVar2 = 5;
          }
          else if (*(ushort *)(param_1 + 0x46) < 0x3e9) {
            if (*(ushort *)(param_1 + 0x48) < 0x100) {
              if ((DAT_06010dd0 & *(ushort *)(param_1 + 0x4a)) == 0) {
                iVar3 = FUN_0600a558((uint)*(ushort *)(param_1 + 0x4a));
                if (iVar3 == 0) {
                  uVar2 = 5;
                }
                else {
                  uVar1 = *(ushort *)(param_1 + 0x42);
                  if ((uVar1 & 0xf000) == 0) {
                    if ((*(ushort *)(param_1 + 0x44) & 0xf000) == 0) {
                      if (uVar1 == 0) {
                        uVar2 = 5;
                      }
                      else if (*(ushort *)(param_1 + 0x44) == 0 && uVar1 == 0) {
                        uVar2 = 5;
                      }
                      else if (*(ushort *)(param_1 + 0x10) < 0x7d1) {
                        iVar3 = FUN_060188f4(0);
                        if (iVar3 == 0) {
                          if ((*(ushort *)(param_1 + 0x40) & 0x20) == 0) {
                            FUN_0600b818(0);
                          }
                          else {
                            FUN_0600b818(1);
                          }
                          FUN_0600b564((ushort *)(uintptr_t)(param_1 + 0x18));
                          FUN_0600b448(*(undefined2 *)(param_1 + 0x1e),param_1 + 0x20);
                          FUN_0600b3e8(*(undefined2 *)(param_1 + 0x46));
                          FUN_0600af7c(*(undefined2 *)(param_1 + 0x4a),0);
                          FUN_0600af34((ushort *)(uintptr_t)(param_1 + 0x42));
                          *(int *)(puVar5 + 0xc) = param_1;
                          *(int *)(puVar5 + 0xe) = param_2;
                          *puVar5 = 0x20;
                          FUN_06008a8c(2,1);
                          uVar2 = 0x80;
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
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}

