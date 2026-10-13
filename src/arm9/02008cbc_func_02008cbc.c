/* Decompiled C draft; module arm9; ROM address 02008cbc. No matching claim. */
#include "types.h"
#include "deps/02008cbc_func_02008cbc.h"

void func_02008cbc(char *param_1)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0;
  do {
    puVar2 = (ushort *)*puRam02008d20;
    if ((((((uint)*puVar2 & 1 << (uVar4 & 0xff)) != 0) &&
         (iVar1 = iVar3 + iRam02008d24, *param_1 == *(char *)((int)puVar2 + iVar3 + iRam02008d24)))
        && (param_1[1] == *(char *)((int)puVar2 + iVar1 + 1))) &&
       (((param_1[2] == *(char *)((int)puVar2 + iVar1 + 2) &&
         (param_1[3] == *(char *)((int)puVar2 + iVar1 + 3))) &&
        ((param_1[4] == *(char *)((int)puVar2 + iVar1 + 4) &&
         (param_1[5] == *(char *)((int)puVar2 + iVar1 + 5))))))) {
      *(undefined2 *)((int)puVar2 + iRam02008d28 + iVar3) = 0;
    }
    iVar3 = iVar3 + iRam02008d2c;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x10);
  return;
}

