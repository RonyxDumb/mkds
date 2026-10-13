/* Decompiled C draft; module arm9_ov000; ROM address 02190548. No matching claim. */
#include "types.h"
#include "deps/02190548_FUN_02190548.h"

undefined4 FUN_02190548(int *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_02190b80(param_1,iVar1 + DAT_021905b8,DAT_021905bc);
  FUN_02190b80(param_1,iVar1 + DAT_021905b8,DAT_021905c0);
  FUN_02190b58(param_1,iVar1 + DAT_021905b8,*(undefined4 *)(iVar1 + DAT_021905c4));
  FUN_02190b80(param_1,iVar1 + DAT_021905b8,DAT_021905c8);
  FUN_02190b58(param_1,iVar1 + DAT_021905b8,*param_2);
  FUN_02190b80(param_1,iVar1 + DAT_021905b8,DAT_021905cc);
  FUN_02190b80(param_1,iVar1 + DAT_021905b8,param_2[4]);
  FUN_02190b80(param_1,iVar1 + DAT_021905b8,DAT_021905d0);
  return 0;
}

