/* Decompiled C draft; module arm9; ROM address 01ff9f60. No matching claim. */
#include "types.h"
#include "deps/01ff9f60_func_01ff9f60.h"

void func_01ff9f60(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_18 [16];
  
  *(undefined4 *)(param_1 + 0x3f8) = 0x1000;
  uVar1 = param_1 + 0x380U & 3;
  uVar2 = *(uint *)(param_1 + 0x380U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 6) {
    func_01ffad14();
  }
  else {
    *(undefined4 *)(param_1 + 0x3a8) = 0xf6;
    StructMQRacerEntry_SomeFn_88(param_1,(int *)(uintptr_t)(param_1 + 0x100));
  }
  uVar1 = param_1 + 0x3a8U & 3;
  uVar2 = *(uint *)(param_1 + 0x3a8U & 0xfffffffc);
  func_01ffce48(param_1 + 0xf0,param_1 + 0x100,(int *)(uintptr_t)(param_1 + 0xf0),
                uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  func_01ffd190(uRam01ffa0b0,*(short *)(param_1 + 0x236) + *(short *)(param_1 + 0x4de),
                (uint *)(uintptr_t)(param_1 + 0xe0));
  func_01ffcebc(param_1 + 0xf0,param_1 + 0xe0,(int *)(uintptr_t)(param_1 + 0x110));
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 2) == 0) {
    *(undefined2 *)(param_1 + 0x2c0) = 0;
  }
  else {
    uVar1 = param_1 + 0x2b8U & 3;
    uVar2 = *(uint *)(param_1 + 0x2b8U & 0xfffffffc);
    if ((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 1) {
      *(undefined2 *)(param_1 + 0x2c0) = 0;
    }
    else {
      uVar1 = param_1 + 700U & 3;
      uVar2 = *(uint *)(param_1 + 700U & 0xfffffffc);
      *(short *)(param_1 + 0x2c0) =
           (short)uRam01ffa0b4 -
           (short)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 500 >> 0xc);
      if (uRam01ffa0b8 < *(ushort *)(param_1 + 0x2c0)) {
        *(short *)(param_1 + 0x2c0) = (short)uRam01ffa0bc;
      }
    }
    func_01ffd190(uRam01ffa0c0,-*(short *)(param_1 + 0x2c0),(uint *)(void *)(auStack_18));
    func_01ffcebc(param_1 + 0x110,(uint)(uintptr_t)(auStack_18),(int *)(uintptr_t)(param_1 + 0x110));
  }
  func_01ffcf7c(param_1 + 0x110,(int *)(uintptr_t)(param_1 + 0x110));
  return;
}

