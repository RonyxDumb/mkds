/* Decompiled C draft; module arm9_ov000; ROM address 0218f808. No matching claim. */
#include "types.h"
#include "deps/0218f808_FUN_0218f808.h"

void FUN_0218f808(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_02190ff8(param_1,1);
  FUN_021a3668(*(undefined4 *)(iVar1 + DAT_0218f840));
  *(undefined4 *)(iVar1 + DAT_0218f840) = 0;
  FUN_0218dfb4(*(undefined4 *)(iVar1 + DAT_0218f844));
  FUN_021a3668(iVar1);
  *param_1 = 0;
  return;
}

