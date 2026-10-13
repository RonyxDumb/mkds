/* Decompiled C draft; module arm7; ROM address 0380222c. No matching claim. */
#include "types.h"
#include "deps/0380222c_FUN_0380222c.h"

undefined1 FUN_0380222c(void)

{
  undefined1 uVar1;
  
  FUN_037fb808(0x8000);
  do {
  } while ((*DAT_03802370 & 0x80) != 0);
  *DAT_03802370 = (ushort)DAT_03802374;
  *DAT_03802378 = 0x84;
  do {
  } while ((*DAT_03802370 & 0x80) != 0);
  *DAT_03802378 = 0;
  do {
  } while ((*DAT_03802370 & 0x80) != 0);
  *DAT_03802370 = (ushort)DAT_0380237c;
  *DAT_03802378 = 0;
  do {
  } while ((*DAT_03802370 & 0x80) != 0);
  if (*DAT_03802380 == 0) {
    uVar1 = (*DAT_03802384 & 0x40) == 0;
  }
  else if ((*DAT_03802384 & 0x40) == 0) {
    uVar1 = 1;
  }
  else {
    *DAT_03802370 = (ushort)DAT_03802374;
    *DAT_03802378 = 0x84;
    do {
    } while ((*DAT_03802370 & 0x80) != 0);
    *DAT_03802378 = 0;
    do {
    } while ((*DAT_03802370 & 0x80) != 0);
    *DAT_03802370 = (ushort)DAT_0380237c;
    *DAT_03802378 = 0;
    do {
    } while ((*DAT_03802370 & 0x80) != 0);
    if ((*DAT_03802384 & 0x40) == 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

