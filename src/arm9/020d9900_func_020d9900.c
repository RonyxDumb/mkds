/* Decompiled C draft; module arm9; ROM address 020d9900. No matching claim. */
#include "types.h"
#include "deps/020d9900_func_020d9900.h"

void func_020d9900(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    Model_CreateFromNsbmd(param_1 + 0x68);
    uVar2 = uRam020d99f0;
    uVar5 = 0;
    iVar3 = *(int *)(param_1 + 0x6c);
    if (*(char *)(iVar3 + 0x18) != '\0') {
      do {
        ModelBlock_SomeTexPltFn_7(iVar3,uVar5,uVar2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(byte *)(iVar3 + 0x18));
    }
    uVar5 = 0;
    iVar3 = *(int *)(param_1 + 0x6c);
    if (*(char *)(iVar3 + 0x18) != '\0') {
      do {
        ModelBlock_SomeTexPltFn_3(iVar3,uVar5,1);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(byte *)(iVar3 + 0x18));
    }
  }
  Model_CreateFromNsbmd(param_1 + 0xd4,*(undefined4 *)(param_1 + 100));
  uVar2 = uRam020d99f0;
  uVar5 = 0;
  iVar3 = *(int *)(param_1 + 0xd8);
  if (*(char *)(iVar3 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_7(iVar3,uVar5,uVar2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(byte *)(iVar3 + 0x18));
  }
  uVar5 = 0;
  iVar3 = *(int *)(param_1 + 0xd8);
  if (*(char *)(iVar3 + 0x18) != '\0') {
    do {
      ModelBlock_SomeTexPltFn_3(iVar3,uVar5,2);
      uVar5 = uVar5 + 1;
    } while (uVar5 < *(byte *)(iVar3 + 0x18));
  }
  iVar3 = *(int *)(param_1 + 0xd8);
  uVar2 = Dict_SomeFn_0(iVar3 + *(int *)(iVar3 + 8) + 4,uRam020d99f4);
  if (*(int *)(param_1 + 0x60) != 0) {
    uVar1 = *(undefined2 *)(param_1 + 0x58);
    uVar5 = 0;
    iVar4 = *(int *)(param_1 + 0x6c);
    if (*(char *)(iVar4 + 0x18) != '\0') {
      do {
        func_02013468(iVar4,uVar5,uVar1);
        uVar5 = uVar5 + 1;
      } while (uVar5 < *(byte *)(iVar4 + 0x18));
    }
  }
  func_02013468(iVar3,uVar2,*(undefined2 *)(param_1 + 0x5a));
  return;
}

