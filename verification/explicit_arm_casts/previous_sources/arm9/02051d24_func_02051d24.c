/* Decompiled C draft; module arm9; ROM address 02051d24. No matching claim. */
#include "types.h"
#include "deps/02051d24_func_02051d24.h"

void func_02051d24(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined1 auStack_2c [20];
  undefined1 local_18;
  undefined4 *puVar8;
  
  Mem_CpuFill8(auStack_2c,0,0x18);
  uVar1 = *(uint *)(uRam02051e48 & 0xfffffffc) >> (uRam02051e48 & 3) * 8 |
          *(uint *)(uRam02051e48 & 0xfffffffc) << (uRam02051e48 & 3) * -8 + 0x20;
  uVar7 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  Mem_CpuCopy8((uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20) + 0xc,auStack_2c,0x14);
  if (param_1 != (undefined4 *)0x0) {
    iVar6 = 0xc;
    uVar7 = (*(uint *)(uRam02051e4c & 0xfffffffc) >> (uRam02051e4c & 3) * 8 |
            *(uint *)(uRam02051e4c & 0xfffffffc) << (uRam02051e4c & 3) * -8 + 0x20) + 0x24;
    uVar1 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    puVar8 = (undefined4 *)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
    do {
      uVar2 = *param_1;
      uVar3 = param_1[1];
      uVar4 = param_1[2];
      uVar5 = param_1[3];
      param_1 = param_1 + 4;
      *puVar8 = uVar2;
      puVar8[1] = uVar3;
      puVar8[2] = uVar4;
      puVar8[3] = uVar5;
      puVar8 = puVar8 + 4;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  if (param_2 == 0) {
    local_18 = *psRam02051e50 == 2;
  }
  else {
    Mem_CpuCopy8(param_2,auStack_2c,0x18);
  }
  uVar7 = uRam02051e4c;
  *(undefined4 *)
   ((*(uint *)(uRam02051e4c & 0xfffffffc) >> (uRam02051e4c & 3) * 8 |
    *(uint *)(uRam02051e4c & 0xfffffffc) << (uRam02051e4c & 3) * -8 + 0x20) + 0xc) = 10;
  *(undefined4 *)
   ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x10) = 1;
  uVar7 = (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x24;
  uVar1 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  iVar6 = func_021437d8(uRam02051e54,uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20,auStack_2c,1,0)
  ;
  uVar7 = uRam02051e4c;
  if (iVar6 == 2) {
    *(undefined4 *)
     ((*(uint *)(uRam02051e4c & 0xfffffffc) >> (uRam02051e4c & 3) * 8 |
      *(uint *)(uRam02051e4c & 0xfffffffc) << (uRam02051e4c & 3) * -8 + 0x20) + 0x448) = param_3;
    *(undefined4 *)
     ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x44c) = param_4;
    *(undefined4 *)
     ((*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
      *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20) + 0x450) = param_5;
    return;
  }
  func_020533a0();
  return;
}

