/* Decompiled C draft; module arm9; ROM address 02037a40. No matching claim. */
#include "types.h"
#include "deps/02037a40_LoopFn_Some3D.h"

void LoopFn_Some3D(void)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *(uint *)(uRam02037a8c & 0xfffffffc) >> (uRam02037a8c & 3) * 8 |
          *(uint *)(uRam02037a8c & 0xfffffffc) << (uRam02037a8c & 3) * -8 + 0x20;
  uVar3 = Os_GetTick();
  *(undefined8 *)(uVar2 + 0xbc) = uVar3;
  if (*(short *)(uVar2 + 10) == 1) {
    G3X_ResetMatrixStack();
  }
  pcVar1 = (code *)(*(uint *)(uRam02037a90 & 0xfffffffc) >> (uRam02037a90 & 3) * 8 |
                   *(uint *)(uRam02037a90 & 0xfffffffc) << (uRam02037a90 & 3) * -8 + 0x20);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(0);
    return;
  }
  return;
}

