/* Decompiled C draft; module arm9; ROM address 0201ea84. No matching claim. */
#include "types.h"
#include "deps/0201ea84_func_0201ea84.h"

int func_0201ea84(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  
  puVar3 = (undefined2 *)(param_1 + 8);
  iVar4 = 0;
  iVar1 = func_0201eb98();
  if (0 < iVar1) {
    do {
      iVar1 = func_0201ebe8(*puVar3,*(undefined1 *)(puVar3 + 2));
      iVar2 = func_0201eba0(puVar3[1],*(undefined1 *)((int)puVar3 + 5));
      if ((((iVar1 <= param_2) && (param_2 <= (int)(iVar1 + (uint)*(byte *)(puVar3 + 2)))) &&
          (iVar2 <= param_3)) && (param_3 <= (int)(iVar2 + (uint)*(byte *)((int)puVar3 + 5)))) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 3;
      iVar1 = func_0201eb98(param_1);
    } while (iVar4 < iVar1);
  }
  return -1;
}

