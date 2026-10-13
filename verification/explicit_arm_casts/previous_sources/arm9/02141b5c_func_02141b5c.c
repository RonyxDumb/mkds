/* Decompiled C draft; module arm9; ROM address 02141b5c. No matching claim. */
#include "types.h"
#include "deps/02141b5c_func_02141b5c.h"

void func_02141b5c(uint *param_1,uint param_2,undefined2 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  *(undefined2 *)((int)param_1 + 2) = param_3;
  uVar2 = 0;
  uVar3 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0xffffff00;
  uVar4 = (4 - ((uint)param_1 & 3)) * 8 & 0x1f;
  *param_1 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
  while (((int)uVar2 < 0x20 &&
         (((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff) != 0))) {
    puVar5 = (uint *)((int)param_1 + uVar2 + 5);
    uVar3 = ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff) - 0x30 & 0xff |
            (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
            *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00;
    uVar4 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
    *puVar5 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
    param_2 = param_2 + 1;
    uVar2 = uVar2 + 1;
  }
  puVar5 = param_1 + 1;
  uVar3 = uVar2 & 0xff |
          (*(uint *)((uint)puVar5 & 0xfffffffc) >> ((uint)puVar5 & 3) * 8 |
          *(uint *)((uint)puVar5 & 0xfffffffc) << ((uint)puVar5 & 3) * -8 + 0x20) & 0xffffff00;
  uVar4 = (4 - ((uint)puVar5 & 3)) * 8 & 0x1f;
  *puVar5 = uVar3 >> uVar4 | uVar3 << 0x20 - uVar4;
  uVar4 = (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff;
  if (uVar4 == 0) {
    return;
  }
  if (uVar4 < 5) {
    return;
  }
  if (uVar4 < 6) {
    uVar3 = param_2 + 1;
    uVar4 = param_2 + 1 & 3;
    uVar1 = *(uint *)(param_2 + 1 & 0xfffffffc);
    uVar4 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
    while ((uVar4 & 0xff) != 0) {
      if ((uVar4 & 0xff) != 0x30) goto LAB_02141c80;
      uVar3 = uVar3 + 1;
      uVar4 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    }
    uVar4 = (int)param_1 + uVar2 + 4;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if (((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) & 1) == 0) {
      return;
    }
  }
LAB_02141c80:
  uVar4 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  func_0214214c(param_1,(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) & 0xff);
  return;
}

