/* Decompiled C draft; module arm9; ROM address 020dac74. No matching claim. */
#include "types.h"
#include "deps/020dac74_func_020dac74.h"

void func_020dac74(int param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [12];
  undefined1 auStack_14 [12];
  
  uVar2 = *(ushort *)(param_1 + 0xf0);
  if ((((uVar2 < 10) || ((0x13 < uVar2 && (uVar2 < 0x1e)))) && ((uVar2 == 0 || (uVar2 == 0x14)))) &&
     (*(short *)(param_1 + 0x102) = *(short *)(param_1 + 0x102) + -1,
     *(short *)(param_1 + 0x102) < 0)) {
    *(undefined2 *)(param_1 + 0x102) = 3;
    uVar1 = param_1 + 0x104U & 3;
    uVar3 = *(uint *)(param_1 + 0x104U & 0xfffffffc);
    *(uint *)(param_1 + 0x104) = (uint)(uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0);
  }
  uVar1 = param_1 + 0x14U & 3;
  uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 0x14) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 0x400;
  uVar1 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar3 = param_1 + 0x14U & 3;
  uVar5 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  *(uint *)(param_1 + 8) =
       (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) +
       (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  local_2c = *(undefined4 *)(param_1 + 4);
  uStack_24 = *(undefined4 *)(param_1 + 0xc);
  local_28 = *(int *)(param_1 + 8) + 0xa000;
  iVar4 = func_01ffdee4(&local_2c,0,0,0xa000,8,0xfffffffe,(int *)(void *)(auStack_20),(int *)(void *)(auStack_14),0,&local_30,0,0,0,0)
  ;
  if (iVar4 != 0) {
    VecFx32_Add(param_1 + 4,(uint)(uintptr_t)(auStack_20),(int *)(uintptr_t)(param_1 + 4));
    *(undefined4 *)(param_1 + 0x14) = 0;
    if ((local_30 & uRam020dade4) != 0) {
      func_020d7b88((uint)(uintptr_t)(auStack_14),(undefined4 *)(uintptr_t)(param_1 + 0xb4));
      *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffe;
    }
  }
  func_020d759c(param_1 + 0xa4,param_1 + 0xb4,(int *)(uintptr_t)(param_1 + 0xa4),*(undefined2 *)(param_1 + 0xf8));
  if (0xb4 < *(ushort *)(param_1 + 0xf8)) {
    *(undefined2 *)(param_1 + 0xf8) = 0xb4;
  }
  return;
}

