/* Decompiled C draft; module arm7; ROM address 0600d920. No matching claim. */
#include "types.h"
#include "deps/0600d920_FUN_0600d920.h"

void FUN_0600d920(void)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar3 = DAT_0600d9fc;
  puVar2 = DAT_0600d9f8;
  while( true ) {
    uVar1 = *puVar2 & *puVar3;
    if (uVar1 == 0) break;
    if ((uVar1 & 0x80) != 0) {
      FUN_0600c95c();
    }
    if ((uVar1 & 0x40) != 0) {
      FUN_0600c6e8();
    }
    if ((uVar1 & 0x8000) != 0) {
      FUN_0600d894();
    }
    if ((uVar1 & 0x4000) != 0) {
      FUN_0600d598();
    }
    if ((uVar1 & 0x2000) != 0) {
      FUN_0600d51c();
    }
    if ((uVar1 & 0x800) != 0) {
      FUN_0600d508();
    }
    if ((uVar1 & 8) != 0) {
      FUN_0600d3a0();
    }
    if ((uVar1 & 4) != 0) {
      FUN_0600d1dc();
    }
    if ((uVar1 & 1) != 0) {
      FUN_0600cb28();
    }
    if ((uVar1 & 0x30) != 0) {
      FUN_0600d4cc();
    }
    if ((uVar1 & 2) != 0) {
      FUN_0600cf6c();
    }
    if ((uVar1 & 0x1000) != 0) {
      FUN_0600ca18(1);
    }
  }
  *DAT_0600da00 =
       *(uint *)((uint)DAT_0600da00 & 0xfffffffc) >> ((uint)DAT_0600da00 & 3) * 8 |
       *(uint *)((uint)DAT_0600da00 & 0xfffffffc) << ((uint)DAT_0600da00 & 3) * -8 + 0x20 |
       0x1000000;
  return;
}

