/* Decompiled C draft; module arm7; ROM address 03802a84. No matching claim. */
#include "types.h"
#include "deps/03802a84_FUN_03802a84.h"

undefined2 FUN_03802a84(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 unaff_r5;
  undefined4 uVar6;
  
  uVar1 = *DAT_03802c38;
  *DAT_03802c38 = 0;
  uVar3 = FUN_037faf70();
  uVar4 = FUN_037f8850(0x1ffffff);
  uVar5 = FUN_038027cc(0);
  FUN_03802c6c(2);
  FUN_038028e8(2);
  FUN_038028e8(2);
  FUN_037fb9c0();
  FUN_0380277c(1);
  if ((*DAT_03802c3c & 1) != 0) {
    *DAT_03802c44 = *DAT_03802c40 | 0x4000;
    FUN_037f888c(0x1000);
  }
  if ((*DAT_03802c3c & 4) != 0) {
    FUN_037f888c(0x400000);
  }
  if ((*DAT_03802c3c & 2) != 0) {
    unaff_r5 = *DAT_03802c48;
    FUN_037fb808(0x8000);
    FUN_037fb824(0x40,0x40);
    FUN_037fb824(0x100,0x100);
    FUN_037f888c(0x80);
  }
  if ((*DAT_03802c3c & 8) != 0) {
    FUN_037f888c(0x100000);
  }
  if ((*DAT_03802c3c & 0x10) != 0) {
    FUN_037f888c(0x2000);
  }
  FUN_037faf84(uVar3);
  *DAT_03802c38 = 1;
  thunk_FUN_038011c2();
  FUN_0380285c(0,uVar5);
  if ((*DAT_03802c3c & 0x20) == 0) {
    uVar5 = 7;
  }
  else {
    uVar5 = 6;
  }
  if ((*DAT_03802c3c & 0x40) == 0) {
    uVar6 = 5;
  }
  else {
    uVar6 = 4;
  }
  FUN_03802950(uVar5);
  FUN_03802950(uVar6);
  *DAT_03802c48 = unaff_r5;
  FUN_038027a8(1);
  FUN_037fb96c();
  *(undefined4 *)(DAT_03802c4c + 0x20) = 0;
  FUN_03802720(0x62,0,0);
  FUN_037faf70();
  FUN_037f88c4(uVar4);
  FUN_037faf84(uVar3);
  uVar2 = *DAT_03802c38;
  *DAT_03802c38 = uVar1;
  return uVar2;
}

