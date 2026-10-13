/* Decompiled C draft; module arm9; ROM address 020b46d0. No matching claim. */
#include "types.h"
#include "deps/020b46d0_func_020b46d0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020b46d0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_2c;
  
  iVar2 = 0;
  if (0 < param_4) {
    uStack_2c = 0;
    do {
      if (0 < param_5) {
        iVar1 = uStack_2c;
        do {
          CopyMemory16(param_1 + (param_2 + iVar2) * 0x20 + (param_3 + iVar1) * 0x400,
                       param_6 + (param_7 + iVar2) * 0x20 + (param_8 + iVar1) * 0x400,0x20);
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_5);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_4);
    return;
  }
  return;
}

