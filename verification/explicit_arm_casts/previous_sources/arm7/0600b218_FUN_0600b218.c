/* Decompiled C draft; module arm7; ROM address 0600b218. No matching claim. */
#include "types.h"
#include "deps/0600b218_FUN_0600b218.h"

void FUN_0600b218(void)

{
  ushort local_10;
  undefined1 auStack_e [14];
  
  FUN_06018844(0x36,6,auStack_e);
  FUN_06018844(0x3c,2,&local_10);
  FUN_0600bce4(auStack_e);
  FUN_0600bcb0(7);
  FUN_0600bc70(DAT_0600b34c & local_10);
  FUN_0600bbe8(2);
  FUN_0600bbac(0);
  FUN_0600baf8(0);
  FUN_0600bad4(0);
  FUN_0600ba70(DAT_0600b350);
  FUN_0600b3e8(500);
  FUN_0600ba38(0);
  FUN_0600ba00(0);
  FUN_0600b9c8(0x10);
  FUN_0600b908(DAT_0600b354,0);
  FUN_0600b8d8(DAT_0600b358);
  FUN_0600b818(1);
  FUN_0600b7f4(0);
  FUN_0600af34(DAT_0600b35c);
  FUN_0600b7ac(0,0x1f);
  FUN_0600ac7c(5);
  FUN_0600b668(0,0);
  FUN_0600b744(0);
  FUN_0600b628(0);
  FUN_0600b5cc(0);
  FUN_06009690((uint)*DAT_0600b360 + (uint)*DAT_0600b360 * 0x100,*DAT_0600b360);
  *(undefined2 *)
   ((*(uint *)(DAT_0600b364 & 0xfffffffc) >> (DAT_0600b364 & 3) * 8 |
    *(uint *)(DAT_0600b364 & 0xfffffffc) << (DAT_0600b364 & 3) * -8 + 0x20) + 0x358) = 1;
  return;
}

