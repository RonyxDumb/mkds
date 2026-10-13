/* Decompiled C draft; module arm9_ov000; ROM address 021aa1e0. No matching claim. */
#include "types.h"
#include "deps/021aa1e0_FUN_021aa1e0.h"

int FUN_021aa1e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_r7;
  undefined1 auStack_58 [20];
  undefined1 auStack_44 [48];
  
  iVar1 = FUN_021aa380(param_1,param_2 + 5,
                       (uint)*(byte *)(param_2 + 3) * 0x100 + (uint)*(byte *)(param_2 + 4));
  if (*(short *)(param_1 + 6) == 4) {
    iVar1 = iVar1 + -0x10;
    *(char *)(param_2 + 3) = (char)((uint)iVar1 >> 8);
    *(char *)(param_2 + 4) = (char)iVar1;
    iVar2 = param_1 + DAT_021aa36c;
    FUN_021ab7b4((undefined4 *)(uintptr_t)(iVar2));
    FUN_021ab728(iVar2,*(undefined4 *)(param_1 + DAT_021aa370),0x10);
    func_0x0214d168((uint *)(void *)(auStack_44),0x36,0x30);
    FUN_021ab728(iVar2,(int)(uintptr_t)(auStack_44),0x30);
    FUN_021ab728(iVar2,param_1 + DAT_021aa374,8);
    FUN_021ab728(iVar2,param_2,1);
    FUN_021ab728(iVar2,param_2 + 3,2);
    FUN_021ab728(iVar2,param_2 + 5,iVar1);
    FUN_021ab6d4(iVar2,(undefined4)(uintptr_t)(auStack_58));
    FUN_021ab7b4((undefined4 *)(uintptr_t)(iVar2));
    FUN_021ab728(iVar2,*(undefined4 *)(param_1 + DAT_021aa370),0x10);
    func_0x0214d168((uint *)(void *)(auStack_44),0x5c,0x30);
    FUN_021ab728(iVar2,(int)(uintptr_t)(auStack_44),0x30);
    FUN_021ab728(iVar2,(int)(uintptr_t)(auStack_58),0x10);
    FUN_021ab6d4(iVar2,(undefined4)(uintptr_t)(auStack_58));
    unaff_r7 = 0x10;
  }
  else if (*(short *)(param_1 + 6) == 5) {
    iVar1 = iVar1 + -0x14;
    *(char *)(param_2 + 3) = (char)((uint)iVar1 >> 8);
    *(char *)(param_2 + 4) = (char)iVar1;
    iVar2 = param_1 + DAT_021aa378;
    FUN_021abd2c((undefined4 *)(uintptr_t)(iVar2));
    FUN_021abca0(iVar2,*(undefined4 *)(param_1 + DAT_021aa370),0x14);
    func_0x0214d168((uint *)(void *)(auStack_44),0x36,0x28);
    FUN_021abca0(iVar2,(int)(uintptr_t)(auStack_44),0x28);
    FUN_021abca0(iVar2,param_1 + DAT_021aa374,8);
    FUN_021abca0(iVar2,param_2,1);
    FUN_021abca0(iVar2,param_2 + 3,2);
    FUN_021abca0(iVar2,param_2 + 5,iVar1);
    FUN_021abc4c(iVar2,(undefined4)(uintptr_t)(auStack_58));
    FUN_021abd2c((undefined4 *)(uintptr_t)(iVar2));
    FUN_021abca0(iVar2,*(undefined4 *)(param_1 + DAT_021aa370),0x14);
    func_0x0214d168((uint *)(void *)(auStack_44),0x5c,0x28);
    FUN_021abca0(iVar2,(int)(uintptr_t)(auStack_44),0x28);
    FUN_021abca0(iVar2,(int)(uintptr_t)(auStack_58),0x14);
    FUN_021abc4c(iVar2,(undefined4)(uintptr_t)(auStack_58));
    unaff_r7 = 0x14;
  }
  iVar2 = func_0x02134d30(param_2 + 5 + iVar1,(uint)(uintptr_t)(auStack_58),unaff_r7);
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + DAT_021aa37c) = 9;
  }
  FUN_021aa398(param_1 + DAT_021aa374,8);
  return iVar1 + 5;
}

