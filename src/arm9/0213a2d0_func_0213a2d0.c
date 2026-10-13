/* Decompiled C draft; module arm9; ROM address 0213a2d0. No matching claim. */
#include "types.h"
#include "deps/0213a2d0_func_0213a2d0.h"

void func_0213a2d0(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = param_2 & 3;
  if (((uint)param_1 & 3) == uVar4) {
    if (uVar4 != 0) {
      uVar2 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
              *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
              (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
              *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00
      ;
      uVar3 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
      *param_1 = uVar2 >> uVar3 | uVar2 << 0x20 - uVar3;
      if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xff) == 0) {
        return;
      }
      for (iVar5 = 3 - uVar4; iVar5 != 0; iVar5 = iVar5 + -1) {
        param_2 = param_2 + 1;
        param_1 = (uint *)((int)param_1 + 1);
        uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
                (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
                0xffffff00;
        uVar4 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
        *param_1 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
        if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xff) == 0)
        {
          return;
        }
      }
      param_1 = (uint *)((int)param_1 + 1);
      param_2 = param_2 + 1;
    }
    uVar4 = uRam0213a430;
    iVar5 = iRam0213a42c;
    uVar3 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    if ((uVar3 + iRam0213a42c & uRam0213a430) == 0) {
      puVar1 = param_1 + -1;
      do {
        param_1 = puVar1;
        puVar1 = param_1 + 1;
        *puVar1 = uVar3;
        param_2 = param_2 + 4;
        uVar3 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
      } while ((uVar3 + iVar5 & uVar4) == 0);
      param_1 = param_1 + 2;
    }
  }
  uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
          (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
  uVar4 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
  *param_1 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
  if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xff) == 0) {
    return;
  }
  do {
    param_2 = param_2 + 1;
    param_1 = (uint *)((int)param_1 + 1);
    uVar3 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
            *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff |
            (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
    uVar4 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
    *param_1 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
  } while (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xff) != 0);
  return;
}

