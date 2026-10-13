/* Decompiled C draft; module arm7; ROM address 03803638. No matching claim. */
#include "types.h"
#include "deps/03803638_FUN_03803638.h"

uint FUN_03803638(void)

{
  ushort uVar1;
  ushort *puVar2;
  
  do {
  } while ((*DAT_038036ec & 0x80) != 0);
  *DAT_038036ec = (ushort)DAT_038036f0;
  *DAT_038036f4 = 0xec;
  do {
  } while ((*DAT_038036ec & 0x80) != 0);
  *DAT_038036f4 = 0;
  puVar2 = DAT_038036f4;
  do {
  } while ((*DAT_038036ec & 0x80) != 0);
  uVar1 = *DAT_038036f4;
  *DAT_038036ec = (ushort)DAT_038036f8;
  *puVar2 = 0;
  do {
  } while ((*DAT_038036ec & 0x80) != 0);
  return ((DAT_038036fc & ((uint)uVar1 << 0x18 | (*DAT_038036f4 & 0xff) << 0x10) >> 0x10) << 9) >>
         0x10;
}

