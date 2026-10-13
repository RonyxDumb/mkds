/* Decompiled C draft; module arm9; ROM address 0205a858. No matching claim. */
#include "types.h"
#include "deps/0205a858_func_0205a858.h"

void func_0205a858(undefined1 param_1,undefined1 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    piVar2 = (int *)(uVar3 * 0xc +
                    (*(uint *)(uRam0205a904 & 0xfffffffc) >> (uRam0205a904 & 3) * 8 |
                    *(uint *)(uRam0205a904 & 0xfffffffc) << (uRam0205a904 & 3) * -8 + 0x20) + 0x324)
    ;
    if ((char)piVar2[2] == '\0') goto LAB_0205a8a0;
    uVar3 = uVar3 + 1 & 0xffff;
  } while (uVar3 < 0x10);
  piVar2 = (int *)0x0;
LAB_0205a8a0:
  *(undefined1 *)((int)piVar2 + 9) = param_1;
  *(undefined1 *)((int)piVar2 + 10) = param_2;
  *(undefined1 *)(piVar2 + 2) = 1;
  uVar3 = (*(uint *)(uRam0205a904 & 0xfffffffc) >> (uRam0205a904 & 3) * 8 |
          *(uint *)(uRam0205a904 & 0xfffffffc) << (uRam0205a904 & 3) * -8 + 0x20) + 0x728;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *piVar2 = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x28;
  uVar3 = (uint)(piVar2 + 1) & 3;
  uVar1 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
  Mem_CpuFill8(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20,0,0x14);
  if (param_4 != 0) {
    uVar3 = (uint)(piVar2 + 1) & 3;
    uVar1 = *(uint *)((uint)(piVar2 + 1) & 0xfffffffc);
    Mem_CpuCopy8(param_3,uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20,param_4);
    *(char *)((int)piVar2 + 0xb) = (char)param_4;
    return;
  }
  *(undefined1 *)((int)piVar2 + 0xb) = 0;
  return;
}

