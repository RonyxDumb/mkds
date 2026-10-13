/* Decompiled C draft; module arm9; ROM address 020217b4. No matching claim. */
#include "types.h"
#include "deps/020217b4_func_020217b4.h"

void func_020217b4(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar2 = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *param_1 = 0;
  puVar3 = param_1;
  do {
    iVar4 = 0;
    puVar3[0x10] = 0;
    do {
      iVar1 = iVar4 * 2;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)puVar3 + iVar1 + 0x20) = 0xffff;
    } while (iVar4 < 0x10);
    iVar2 = iVar2 + 1;
    puVar3 = puVar3 + 9;
  } while (iVar2 < 0x10);
  iVar2 = 0;
  do {
    iVar4 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)param_1 + iVar4 + 0x260) = 0xffff;
  } while (iVar2 < 0x10);
  Arm_FlushRange(param_1,0x280);
  return;
}

