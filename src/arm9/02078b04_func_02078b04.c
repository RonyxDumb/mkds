/* Decompiled C draft; module arm9; ROM address 02078b04. No matching claim. */
#include "types.h"
#include "deps/02078b04_func_02078b04.h"

int func_02078b04(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = piRam02078b44;
  iVar3 = *piRam02078b44;
  iVar2 = *(int *)(iVar3 + 0x1c) + param_1 * 0xc;
  *(undefined2 *)(iVar3 + 0xc) = *(undefined2 *)(*(int *)(iVar3 + 0x1c) + param_1 * 0xc);
  *(undefined2 *)(iVar3 + 0xe) = *(undefined2 *)(iVar2 + 2);
  *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(iVar2 + 4);
  *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)(iVar2 + 6);
  *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(iVar2 + 8);
  *(undefined2 *)(iVar3 + 0x16) = *(undefined2 *)(iVar2 + 10);
  *(short *)(iVar3 + 0x10) =
       *(short *)(iVar3 + 0x10) + *(short *)(*(int *)(iVar3 + 0x18) + param_2 * 2);
  return *piVar1 + 0xc;
}

