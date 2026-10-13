/* Decompiled C draft; module arm9; ROM address 020898bc. No matching claim. */
#include "types.h"
#include "deps/020898bc_func_020898bc.h"

void func_020898bc(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *puRam02089970;
  uVar2 = puRam02089970[1];
  uVar3 = puRam02089970[2];
  *(undefined4 *)(param_1 + 0x60) = uVar1;
  *(undefined4 *)(param_1 + 100) = uVar2;
  *(undefined4 *)(param_1 + 0x68) = uVar3;
  *(undefined2 *)(param_1 + 0x6c) = 0;
  *(undefined2 *)(param_1 + 0x6e) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x7a) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined2 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0xfffff000;
  *(undefined4 *)(param_1 + 0x50) = uVar1;
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  *(undefined4 *)(param_1 + 0x58) = uVar3;
  *(int *)(param_1 + 0x5c) = param_1 + 0x44;
  *(undefined2 *)(param_1 + 0xc2) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined2 *)(param_1 + 200) = 0;
  *(undefined2 *)(param_1 + 0xca) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined2 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = uVar1;
  *(undefined4 *)(param_1 + 0xe0) = uVar2;
  *(undefined4 *)(param_1 + 0xe4) = uVar3;
  return;
}

