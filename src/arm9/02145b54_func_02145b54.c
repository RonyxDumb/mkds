/* Decompiled C draft; module arm9; ROM address 02145b54. No matching claim. */
#include "types.h"
#include "deps/02145b54_func_02145b54.h"

void func_02145b54(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(uRam02145d1c & 0xfffffffc) >> (uRam02145d1c & 3) * 8 |
          *(uint *)(uRam02145d1c & 0xfffffffc) << (uRam02145d1c & 3) * -8 + 0x20;
  Mem_CpuFill8((uint *)(uintptr_t)(uVar4 + 0x18),0,0x28);
  *(uint *)(uVar4 + 4) = param_1;
  if (param_1 == 0) {
    return;
  }
  iVar1 = 1 << ((int)param_1 >> 8 & 0xffU);
  param_1 = param_1 & 0xff;
  *(int *)(uVar4 + 0x18) = iVar1;
  uVar2 = uRam02145d24;
  if (param_1 == 1) {
    if (iVar1 == 0x200) {
      *(undefined4 *)(uVar4 + 0x20) = 0x10;
      *(undefined4 *)(uVar4 + 0x24) = 1;
      *(undefined4 *)(uVar4 + 0x28) = 0x4f;
      return;
    }
    if (iVar1 == 0x2000) {
      *(undefined4 *)(uVar4 + 0x20) = 0x20;
      *(undefined4 *)(uVar4 + 0x24) = 2;
      *(undefined4 *)(uVar4 + 0x28) = 0x4f;
      return;
    }
    if (iVar1 == 0x10000) {
      *(undefined4 *)(uVar4 + 0x20) = 0x80;
      *(undefined4 *)(uVar4 + 0x24) = 2;
      *(undefined4 *)(uVar4 + 0x28) = 0x9e;
      return;
    }
  }
  else {
    if (param_1 == 2) {
      if (iVar1 == 0x40000) {
        *(undefined4 *)(uVar4 + 0x2c) = uRam02145d20;
        *(undefined4 *)(uVar4 + 0x30) = uVar2;
        uVar3 = uRam02145d28;
        *(undefined4 *)(uVar4 + 0x3c) = uVar2;
        *(undefined4 *)(uVar4 + 0x38) = uVar3;
        *(undefined4 *)(uVar4 + 0x34) = uVar3;
      }
      else {
        if ((iVar1 != 0x80000) && (iVar1 != 0x100000)) goto LAB_02145cf4;
        *(undefined4 *)(uVar4 + 0x2c) = uRam02145d20;
        uVar2 = uRam02145d24;
        *(undefined4 *)(uVar4 + 0x30) = 0;
        uVar3 = uRam02145d28;
        *(undefined4 *)(uVar4 + 0x3c) = uVar2;
        *(undefined4 *)(uVar4 + 0x38) = uVar3;
      }
      *(undefined4 *)(uVar4 + 0x1c) = 0x10000;
      *(undefined4 *)(uVar4 + 0x20) = 0x100;
      *(undefined4 *)(uVar4 + 0x24) = 3;
      *(undefined4 *)(uVar4 + 0x28) = 0x4f;
      return;
    }
    if ((param_1 == 3) && ((iVar1 == 0x2000 || (iVar1 == 0x8000)))) {
      *(int *)(uVar4 + 0x20) = iVar1;
      *(undefined4 *)(uVar4 + 0x24) = 2;
      return;
    }
  }
LAB_02145cf4:
  *(undefined4 *)(uVar4 + 4) = 0;
  *(undefined4 *)(uVar4 + 0x18) = 0;
  *(undefined4 *)
   (*(uint *)(uRam02145d1c & 0xfffffffc) >> (uRam02145d1c & 3) * 8 |
   *(uint *)(uRam02145d1c & 0xfffffffc) << (uRam02145d1c & 3) * -8 + 0x20) = 3;
  return;
}

