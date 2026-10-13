/* Decompiled C draft; module arm9_ov001; ROM address 02187614. No matching claim. */
#include "types.h"
#include "deps/02187614_FUN_02187614.h"

void FUN_02187614(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 auStack_20 [16];
  
  iVar3 = param_2 * 0x18;
  *(undefined4 *)(param_1 + iVar3 + 0xc0) = param_7;
  if ((*(ushort *)(param_1 + 2) & DAT_02187680) != 0) {
    param_3 = -param_3;
  }
  iVar1 = param_1 + iVar3;
  *(int *)(iVar1 + 0xc4) = param_3 << 4;
  *(int *)(iVar1 + 200) = param_4 << 4;
  *(int *)(iVar1 + 0xcc) = param_5 << 4;
  FUN_02187684(param_1,param_2,auStack_20);
  if (param_6 != 0) {
    puVar4 = (undefined4 *)(param_1 + 0xd0 + iVar3);
    if (*(int *)(param_1 + 0xd0 + iVar3) != 0) {
      func_0x0208b6b0(puVar4);
    }
    uVar2 = func_0x0208b7bc(param_6,auStack_20);
    *puVar4 = uVar2;
  }
  return;
}

