/* Decompiled C draft; module arm9; ROM address 02006144. No matching claim. */
#include "types.h"
#include "deps/02006144_func_02006144.h"

void func_02006144(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_3 * 0x68 + DAT_020061d4;
  uVar4 = 1 << (param_3 & 0xff);
  uVar2 = (ushort)uVar4;
  *(ushort *)((int)param_1 + 10) = uVar2;
  cVar1 = *(char *)((int)param_1 + iVar3 + 2);
  if (*(char *)(param_1 + 3) == cVar1) {
    *(char *)((int)param_1 + 0xd) = cVar1;
    if (((uint)*(ushort *)(param_1 + 2) & uVar4 & 0xffff) != 0) {
      *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & ~uVar2;
      switch(param_2) {
      case 3:
        *(undefined2 *)(param_1 + 5) = *(undefined2 *)((int)param_1 + iVar3 + 10);
        *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)((int)param_1 + iVar3 + 6);
        *(undefined2 *)(param_1 + 6) = *(undefined2 *)((int)param_1 + iVar3 + 4);
      }
      param_1[1] = param_2;
      if ((code *)param_1[4] != (code *)0x0) {
        (*(code *)param_1[4])(param_1);
      }
    }
    if (*(short *)(param_1 + 2) == 0) {
      *param_1 = 0;
    }
  }
  return;
}

