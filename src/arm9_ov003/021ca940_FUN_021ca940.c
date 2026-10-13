/* Decompiled C draft; module arm9_ov003; ROM address 021ca940. No matching claim. */
#include "types.h"
#include "deps/021ca940_FUN_021ca940.h"

void FUN_021ca940(void)

{
  int iVar1;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  
  local_10[0] = *DAT_021ca9b8;
  local_10[1] = DAT_021ca9b8[1];
  local_10[2] = DAT_021ca9b8[2];
  local_10[3] = DAT_021ca9b8[3];
  local_c[0] = *DAT_021ca9bc;
  local_c[1] = DAT_021ca9bc[1];
  local_c[2] = DAT_021ca9bc[2];
  local_c[3] = DAT_021ca9bc[3];
  if (*DAT_021ca9c0 < 4) {
    FUN_021cc948(*(undefined4 *)*DAT_021ca9c4,local_10[*DAT_021ca9c0],local_10[*DAT_021ca9c0]);
    if (*DAT_021ca9c0 != 3) {
      iVar1 = FUN_021cd844();
      if (2 < iVar1) {
        iVar1 = 3;
      }
      FUN_021d1890(*(undefined4 *)(*DAT_021ca9c4 + (uint)*DAT_021ca9c0 * 4 + 4),0xffffffff,0,
                   local_c[iVar1]);
    }
  }
  return;
}

