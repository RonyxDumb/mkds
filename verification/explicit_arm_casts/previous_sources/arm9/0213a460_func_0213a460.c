/* Decompiled C draft; module arm9; ROM address 0213a460. No matching claim. */
#include "types.h"
#include "deps/0213a460_func_0213a460.h"

undefined8 func_0213a460(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iStack_24;
  int local_20;
  int local_1c [2];
  
  local_1c[1] = 0;
  local_1c[0] = param_1;
  uVar4 = func_0213a550(0x7fffffff,uRam0213a544,local_1c,&iStack_24,&local_20);
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  if (param_2 != (int *)0x0) {
    *param_2 = param_1 + iStack_24;
  }
  uVar5 = func_021400c8((int)uVar4,uVar2);
  uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
  if ((local_20 != 0) ||
     ((iVar1 = FUN_02131b74(0,0,(int)uVar4,uVar2), iVar1 != 0 &&
      ((iVar1 = FUN_02131ce8((int)uVar5,uVar3,0,0x100000), iVar1 != 0 ||
       (iVar1 = FUN_02131e60((int)uVar5,uVar3,0xffffffff,uRam0213a548), iVar1 != 0)))))) {
    *puRam0213a54c = 0x22;
  }
  return uVar4;
}

