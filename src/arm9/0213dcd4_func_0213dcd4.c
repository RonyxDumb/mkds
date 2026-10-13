/* Decompiled C draft; module arm9; ROM address 0213dcd4. No matching claim. */
#include "types.h"
#include "deps/0213dcd4_func_0213dcd4.h"

void func_0213dcd4(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  
  if (-1 < (int)param_2) {
    uVar5 = param_1 + 4U & 3;
    uVar1 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 0xff;
    if ((int)uVar5 <= (int)param_2) {
      return;
    }
    puVar2 = (uint *)(param_1 + 5 + param_2);
    uVar1 = ((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
             *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xff) - 0x30
            & 0xff;
    if (uVar1 == 5) {
      puVar4 = (uint *)(param_1 + 5 + uVar5);
      do {
        puVar4 = (uint *)((int)puVar4 + -1);
        if (puVar4 <= puVar2) break;
      } while (((*(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20) & 0xff) ==
               0x30);
      if (puVar4 == puVar2) {
        uVar5 = (int)puVar2 - 1U & 3;
        uVar1 = *(uint *)((int)puVar2 - 1U & 0xfffffffc);
        uVar5 = (uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) & 1;
      }
      else {
        uVar5 = 1;
      }
    }
    else if (uVar1 < 6) {
      uVar5 = 0;
    }
    else {
      uVar5 = 1;
    }
    if (param_2 != 0) {
      do {
        puVar2 = (uint *)((int)puVar2 + -1);
        uVar1 = (((*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                  *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xff) -
                0x30) + uVar5 & 0xff;
        uVar5 = (uint)(9 < uVar1);
        if ((uVar5 == 0) && (uVar1 != 0)) {
          uVar3 = uVar1 + 0x30 & 0xff |
                  (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
                  *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) &
                  0xffffff00;
          uVar1 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
          *puVar2 = uVar3 >> uVar1 | uVar3 << 0x20 - uVar1;
          break;
        }
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
    if (uVar5 != 0) {
      puVar2 = (uint *)(param_1 + 4);
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
      uVar1 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00 |
              1;
      uVar5 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
      *puVar2 = uVar1 >> uVar5 | uVar1 << 0x20 - uVar5;
      puVar2 = (uint *)(param_1 + 5);
      uVar1 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00 |
              0x31;
      uVar5 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
      *puVar2 = uVar1 >> uVar5 | uVar1 << 0x20 - uVar5;
      return;
    }
    if (param_2 != 0) {
      puVar2 = (uint *)(param_1 + 4);
      uVar1 = param_2 & 0xff |
              (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
              *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00;
      uVar5 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
      *puVar2 = uVar1 >> uVar5 | uVar1 << 0x20 - uVar5;
      return;
    }
  }
  puVar2 = (uint *)(param_1 + 4);
  *(undefined2 *)(param_1 + 2) = 0;
  uVar1 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00 | 1;
  uVar5 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
  *puVar2 = uVar1 >> uVar5 | uVar1 << 0x20 - uVar5;
  puVar2 = (uint *)(param_1 + 5);
  uVar1 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
          *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) & 0xffffff00 |
          0x30;
  uVar5 = (4 - ((uint)puVar2 & 3)) * 8 & 0x1f;
  *puVar2 = uVar1 >> uVar5 | uVar1 << 0x20 - uVar5;
  return;
}

