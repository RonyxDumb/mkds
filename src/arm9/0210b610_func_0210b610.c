/* Decompiled C draft; module arm9; ROM address 0210b610. No matching claim. */
#include "types.h"
#include "deps/0210b610_func_0210b610.h"

void func_0210b610(void)

{
  longlong lVar1;
  uint *puVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  puVar2 = puRam0210b68c;
  uVar5 = (*(uint *)((uint)puRam0210b68c & 0xfffffffc) >> ((uint)puRam0210b68c & 3) * 8 |
          *(uint *)((uint)puRam0210b68c & 0xfffffffc) << ((uint)puRam0210b68c & 3) * -8 + 0x20) +
          iRam0210b690;
  uVar4 = uVar5 & uRam0210b694;
  lVar1 = (ulonglong)(uint)(int)*(short *)(iRam0210b698 + ((int)uVar4 >> 4) * 4) * 0x90000 + 0x800;
  *puRam0210b68c = uVar5;
  piVar3 = piRam0210b69c;
  *puVar2 = uVar4;
  *piVar3 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc;
  return;
}

