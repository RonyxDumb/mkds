/* Decompiled C draft; module arm7; ROM address 03804544. No matching claim. */
#include "types.h"
#include "deps/03804544_FUN_03804544.h"

void FUN_03804544(undefined1 *param_1)

{
  ushort *puVar1;
  undefined2 *puVar2;
  
  do {
  } while ((*DAT_038045d8 & 0x80) != 0);
  *DAT_038045d8 = 0x8900;
  *DAT_038045dc = 0x9f;
  do {
  } while ((*DAT_038045d8 & 0x80) != 0);
  *DAT_038045dc = 0;
  puVar2 = DAT_038045dc;
  puVar1 = DAT_038045d8;
  do {
  } while ((*DAT_038045d8 & 0x80) != 0);
  *param_1 = (char)*DAT_038045dc;
  *puVar1 = 0x8100;
  *puVar2 = 0;
  do {
  } while ((*DAT_038045d8 & 0x80) != 0);
  param_1[1] = (char)*DAT_038045dc;
  return;
}

