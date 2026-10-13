/* Decompiled C draft; module arm9; ROM address 0205ad88. No matching claim. */
#include "types.h"
#include "deps/0205ad88_func_0205ad88.h"

void func_0205ad88(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar8 = 0;
  iVar7 = 0;
  local_30 = 0;
  local_2c = 0;
  iVar5 = local_2c;
  iVar6 = local_2c;
  do {
    do {
      iVar2 = (*(uint *)(uRam0205ae88 & 0xfffffffc) >> (uRam0205ae88 & 3) * 8 |
              *(uint *)(uRam0205ae88 & 0xfffffffc) << (uRam0205ae88 & 3) * -8 + 0x20) + 0x3e4 +
              iVar7;
      iVar4 = iVar2 + iVar5;
      *(undefined1 *)(iVar4 + 8) = 0;
      *(undefined4 *)(iVar2 + iVar5) = 0;
      *(undefined1 *)(iVar4 + 9) = 0xf;
      *(undefined1 *)(iVar4 + 10) = 0;
      *(undefined1 *)(iVar4 + 0xb) = 0;
      uVar1 = iVar4 + 4U & 3;
      uVar3 = *(uint *)(iVar4 + 4U & 0xfffffffc);
      Mem_CpuFill8((uint *)(uintptr_t)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20),0,0x14);
      iVar2 = iVar6 + 1;
      *(undefined1 *)
       (iVar6 + (*(uint *)(uRam0205ae88 & 0xfffffffc) >> (uRam0205ae88 & 3) * 8 |
                *(uint *)(uRam0205ae88 & 0xfffffffc) << (uRam0205ae88 & 3) * -8 + 0x20) + iVar8 * 4
       + 0x6e4) = 0;
      iVar5 = iVar5 + 0xc;
      iVar6 = iVar2;
    } while (iVar2 < 4);
    iVar5 = (*(uint *)(uRam0205ae88 & 0xfffffffc) >> (uRam0205ae88 & 3) * 8 |
            *(uint *)(uRam0205ae88 & 0xfffffffc) << (uRam0205ae88 & 3) * -8 + 0x20) + 0x324;
    iVar6 = iVar5 + local_30;
    *(undefined1 *)(iVar6 + 8) = 0;
    *(undefined4 *)(iVar5 + local_30) = 0;
    *(undefined1 *)(iVar6 + 9) = 0xf;
    *(undefined1 *)(iVar6 + 10) = 0;
    *(undefined1 *)(iVar6 + 0xb) = 0;
    uVar1 = iVar6 + 4U & 3;
    uVar3 = *(uint *)(iVar6 + 4U & 0xfffffffc);
    Mem_CpuFill8((uint *)(uintptr_t)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20),0,0x14);
    iVar8 = iVar8 + 1;
    local_30 = local_30 + 0xc;
    iVar7 = iVar7 + 0x30;
    iVar5 = local_2c;
    iVar6 = local_2c;
  } while (iVar8 < 0x10);
  *(undefined2 *)
   ((*(uint *)(uRam0205ae88 & 0xfffffffc) >> (uRam0205ae88 & 3) * 8 |
    *(uint *)(uRam0205ae88 & 0xfffffffc) << (uRam0205ae88 & 3) * -8 + 0x20) + 0x724) = 0x30;
  return;
}

