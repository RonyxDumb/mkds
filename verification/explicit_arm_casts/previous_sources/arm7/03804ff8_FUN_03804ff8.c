/* Decompiled C draft; module arm7; ROM address 03804ff8. No matching claim. */
#include "types.h"
#include "deps/03804ff8_FUN_03804ff8.h"

void FUN_03804ff8(void)

{
  byte bVar1;
  ushort local_10;
  ushort auStack_e [3];
  
  FUN_03805b8c(&local_10);
  if (((int)((uint)local_10 << 0x1b) < 0) || ((int)((uint)local_10 << 0x1a) < 0)) {
    FUN_03805b34(auStack_e);
    bVar1 = (int)((uint)local_10 << 0x1b) < 0;
    if ((bool)bVar1) {
      auStack_e[0] = auStack_e[0] & 0xfff0;
    }
    if ((int)((uint)local_10 << 0x1a) < 0) {
      bVar1 = bVar1 | 2;
      auStack_e[0] = auStack_e[0] & 0xffbf;
    }
    FUN_03805b08(auStack_e);
    FUN_03805544(0x30,bVar1);
  }
  return;
}

