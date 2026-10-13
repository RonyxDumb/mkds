/* Decompiled C draft; module arm7; ROM address 03803570. No matching claim. */
#include "types.h"
#include "deps/03803570_FUN_03803570.h"

uint FUN_03803570(void)

{
  ushort uVar1;
  ushort *puVar2;
  
  do {
  } while ((*DAT_03803624 & 0x80) != 0);
  *DAT_03803624 = (ushort)DAT_03803628;
  *DAT_0380362c = 0xe4;
  do {
  } while ((*DAT_03803624 & 0x80) != 0);
  *DAT_0380362c = 0;
  puVar2 = DAT_0380362c;
  do {
  } while ((*DAT_03803624 & 0x80) != 0);
  uVar1 = *DAT_0380362c;
  *DAT_03803624 = (ushort)DAT_03803630;
  *puVar2 = 0;
  do {
  } while ((*DAT_03803624 & 0x80) != 0);
  return ((DAT_03803634 & ((uint)uVar1 << 0x18 | (*DAT_0380362c & 0xff) << 0x10) >> 0x10) << 0x11)
         >> 0x10;
}

