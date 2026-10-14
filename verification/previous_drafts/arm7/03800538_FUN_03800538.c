/* Decompiled C draft; module arm7; ROM address 03800538. No matching claim. */
#include "types.h"
#include "deps/03800538_FUN_03800538.h"

void FUN_03800538(int param_1,int param_2,int param_3,code *param_4)

{
  int *piVar1;
  ushort *puVar2;
  
  piVar1 = DAT_038005bc;
  DAT_038005bc[1] = param_1;
  piVar1[2] = param_2;
  puVar2 = DAT_038005c4;
  *DAT_038005c4 = (ushort)DAT_038005c0;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *piVar1 = (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 |
              *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20) - 1;
    if (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 == 0 &&
        *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20 == 0) {
      *puVar2 = 0xa000;
    }
    do {
    } while ((*puVar2 & 0x80) != 0);
    (*param_4)(piVar1);
  }
  if (*(uint *)((uint)piVar1 & 0xfffffffc) >> ((uint)piVar1 & 3) * 8 == 0 &&
      *(uint *)((uint)piVar1 & 0xfffffffc) << ((uint)piVar1 & 3) * -8 + 0x20 == 0) {
    *DAT_038005c4 = 0;
  }
  return;
}

