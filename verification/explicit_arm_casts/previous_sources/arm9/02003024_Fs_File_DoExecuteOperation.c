/* Decompiled C draft; module arm9; ROM address 02003024. No matching claim. */
#include "types.h"
#include "deps/02003024_Fs_File_DoExecuteOperation.h"

uint Fs_File_DoExecuteOperation(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_1 + 0xcU & 3;
  uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar4 = param_1 + 8U & 3;
  uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar4 = 1 << (param_2 & 0xff);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 4) == 0) {
    uVar2 = uVar5 + 0x1c & 3;
    uVar1 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
    *(uint *)(uVar5 + 0x1c) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x100;
  }
  else {
    uVar2 = uVar5 + 0x1c & 3;
    uVar1 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
    *(uint *)(uVar5 + 0x1c) = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 | 0x200;
  }
  uVar2 = uVar5 + 0x58 & 3;
  uVar1 = *(uint *)(uVar5 + 0x58 & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & uVar4) == 0) {
    uVar2 = 7;
    goto switchD_02003088_default;
  }
  uVar2 = uVar5 + 0x54 & 3;
  uVar1 = *(uint *)(uVar5 + 0x54 & 0xfffffffc);
  uVar2 = (*(code *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20))(param_1,param_2);
  switch(uVar2) {
  case 0:
    goto LAB_020030b4;
  case 1:
    goto LAB_020030b4;
  case 2:
    break;
  case 3:
    break;
  case 4:
LAB_020030b4:
    *(uint *)(param_1 + 0x14) = uVar2;
    break;
  case 5:
    break;
  case 6:
    break;
  case 7:
    break;
  case 8:
    uVar2 = uVar5 + 0x58 & 3;
    uVar1 = *(uint *)(uVar5 + 0x58 & 0xfffffffc);
    *(uint *)(uVar5 + 0x58) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & ~uVar4;
    uVar2 = 7;
  }
switchD_02003088_default:
  if (uVar2 == 7) {
    uVar4 = DAT_0200319c + param_2 * 4;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar2 = (*(code *)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20))(param_1);
  }
  if (uVar2 == 6) {
    uVar4 = param_1 + 0xcU & 3;
    uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 4) != 0) {
      uVar3 = Os_DisableIrq();
      uVar4 = uVar5 + 0x1c & 3;
      uVar2 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
      if (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x200) != 0) {
        do {
          Os_Thread_Sleep(uVar5 + 0xc);
          uVar4 = uVar5 + 0x1c & 3;
          uVar2 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
        } while (((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0x200) != 0);
      }
      uVar4 = param_1 + 0x14U & 3;
      uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      uVar2 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
      Os_RestoreIrq(uVar3);
    }
  }
  else {
    uVar4 = param_1 + 0xcU & 3;
    uVar1 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    if (((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 4) == 0) {
      uVar4 = uVar5 + 0x1c & 3;
      uVar1 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
      *(uint *)(uVar5 + 0x1c) = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0xfffffeff;
      Fs_File_ReleaseOperation(param_1,uVar2);
    }
    else {
      uVar4 = uVar5 + 0x1c & 3;
      uVar1 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
      *(uint *)(uVar5 + 0x1c) = (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) & 0xfffffdff;
      *(uint *)(param_1 + 0x14) = uVar2;
    }
  }
  return uVar2;
}

