/* Decompiled C draft; module arm9_ov000; ROM address 021aa054. No matching claim. */
#include "types.h"
#include "deps/021aa054_FUN_021aa054.h"

int FUN_021aa054(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_44 [48];
  
  iVar2 = (uint)*(byte *)(param_2 + 3) * 0x100 + (uint)*(byte *)(param_2 + 4);
  iVar1 = param_2 + 5 + iVar2;
  if (*(short *)(param_1 + 6) == 4) {
    iVar3 = param_1 + DAT_021aa1d4;
    FUN_021ab7b4(iVar3);
    FUN_021ab728(iVar3,*(undefined4 *)(param_1 + 0x90),0x10);
    func_0x0214d168(auStack_44,0x36,0x30);
    FUN_021ab728(iVar3,auStack_44,0x30);
    FUN_021ab728(iVar3,param_1 + DAT_021aa1d8,8);
    FUN_021ab728(iVar3,param_2,1);
    FUN_021ab728(iVar3,param_2 + 3,2);
    FUN_021ab728(iVar3,param_2 + 5,iVar2);
    FUN_021ab6d4(iVar3,iVar1);
    FUN_021ab7b4(iVar3);
    FUN_021ab728(iVar3,*(undefined4 *)(param_1 + 0x90),0x10);
    func_0x0214d168(auStack_44,0x5c,0x30);
    FUN_021ab728(iVar3,auStack_44,0x30);
    FUN_021ab728(iVar3,iVar1,0x10);
    FUN_021ab6d4(iVar3,iVar1);
    iVar2 = iVar2 + 0x10;
  }
  else if (*(short *)(param_1 + 6) == 5) {
    iVar3 = param_1 + DAT_021aa1dc;
    FUN_021abd2c(iVar3);
    FUN_021abca0(iVar3,*(undefined4 *)(param_1 + 0x90),0x14);
    func_0x0214d168(auStack_44,0x36,0x28);
    FUN_021abca0(iVar3,auStack_44,0x28);
    FUN_021abca0(iVar3,param_1 + DAT_021aa1d8,8);
    FUN_021abca0(iVar3,param_2,1);
    FUN_021abca0(iVar3,param_2 + 3,2);
    FUN_021abca0(iVar3,param_2 + 5,iVar2);
    FUN_021abc4c(iVar3,iVar1);
    FUN_021abd2c(iVar3);
    FUN_021abca0(iVar3,*(undefined4 *)(param_1 + 0x90),0x14);
    func_0x0214d168(auStack_44,0x5c,0x28);
    FUN_021abca0(iVar3,auStack_44,0x28);
    FUN_021abca0(iVar3,iVar1,0x14);
    FUN_021abc4c(iVar3,iVar1);
    iVar2 = iVar2 + 0x14;
  }
  *(char *)(param_2 + 3) = (char)((uint)iVar2 >> 8);
  *(char *)(param_2 + 4) = (char)iVar2;
  FUN_021ac3e4(param_1 + 0x9c,param_2 + 5,iVar2);
  FUN_021aa398(param_1 + DAT_021aa1d8,8);
  return iVar2 + 5;
}

