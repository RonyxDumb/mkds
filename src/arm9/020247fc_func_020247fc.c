/* Decompiled C draft; module arm9; ROM address 020247fc. No matching claim. */
#include "types.h"
#include "deps/020247fc_func_020247fc.h"

uint func_020247fc(undefined4 *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar3 = (int)*(char *)(param_1 + 1);
  bVar1 = *(byte *)((int)param_1 + 5);
  if (iVar3 < param_2) {
    puVar4 = (undefined1 *)
             (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
    *param_1 = puVar4 + 1;
    *(undefined1 *)((int)param_1 + 5) = *puVar4;
    *(undefined1 *)(param_1 + 1) = 8;
    uVar2 = func_020247fc();
    uVar2 = uVar2 | (uint)bVar1 << (param_2 - iVar3 & 0xffU);
  }
  else {
    uVar2 = (uint)(bVar1 >> (iVar3 - param_2 & 0xffU));
    *(char *)(param_1 + 1) = (char)(iVar3 - param_2);
  }
  return uVar2 & 0xff >> (8U - param_2 & 0xff);
}

