/* Decompiled C draft; module arm7; ROM address 038056c0. No matching claim. */
#include "types.h"
#include "deps/038056c0_FUN_038056c0.h"

void FUN_038056c0(undefined4 param_1)

{
  undefined4 uVar1;
  
  if (*DAT_03805794 == 0) {
    *DAT_03805794 = 1;
    *(undefined4 *)(DAT_03805798 + 0x1d4) = 1;
    FUN_03804ec4();
    *(undefined4 *)(DAT_03805798 + 0x1d4) = 0;
    thunk_FUN_037fb72c();
    FUN_037fb6c0(5,DAT_0380579c);
    FUN_037f98e8(DAT_03805798,DAT_038057a0,4);
    FUN_037f92d0(DAT_038057a4,DAT_038057a8,0,DAT_038057ac,0x100,param_1);
    FUN_037f9054(DAT_038057a4);
    FUN_037fb808(0x8000);
    FUN_037fb824(0x40,0);
    FUN_037fb824(0x100,0x100);
    uVar1 = FUN_037faf70();
    FUN_037f8944(0x80,DAT_038057b0);
    FUN_037f888c(0x80);
    FUN_037faf84(uVar1);
  }
  return;
}

