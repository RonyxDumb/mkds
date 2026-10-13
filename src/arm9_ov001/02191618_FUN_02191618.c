/* Decompiled C draft; module arm9_ov001; ROM address 02191618. No matching claim. */
#include "types.h"
#include "deps/02191618_FUN_02191618.h"

void FUN_02191618(int param_1)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  FUN_02187218(param_1,3);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021916b4),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021916b8));
  FUN_02188e24(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_021916bc),DAT_021916c0);
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  FUN_02188950(param_1,&local_18);
  FUN_02188200(param_1,DAT_021916c4);
  func_0x02073fb0(*(uint *)(param_1 + 0x78) & DAT_021916c8,DAT_021916cc);
  FUN_02187518(param_1,DAT_021916cc,0,DAT_021916d4,DAT_021916d0,0);
  FUN_02187518(param_1,DAT_021916cc,0,DAT_021916d4,DAT_021916d8,0);
  func_0x020d2774(param_1,DAT_021916dc);
  return;
}

