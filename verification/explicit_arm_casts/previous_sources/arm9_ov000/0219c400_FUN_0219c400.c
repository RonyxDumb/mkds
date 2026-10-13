/* Decompiled C draft; module arm9_ov000; ROM address 0219c400. No matching claim. */
#include "types.h"
#include "deps/0219c400_FUN_0219c400.h"

void FUN_0219c400(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined1 auStack_50 [21];
  undefined1 auStack_3b [21];
  undefined1 auStack_26 [26];
  
  if (*param_2 == 0) {
    iVar1 = *DAT_0219c508;
    if (*(int *)(iVar1 + 4) == 3) {
      if (*(char *)((int)param_2 + 0x8e) != '\0') {
        FUN_0218f130();
        FUN_0219c67c(DAT_0219c514,0);
        *(undefined4 *)(*DAT_0219c508 + 4) = 1;
        return;
      }
      func_0x02152808(*(int *)(iVar1 + 0x20) + 4,*(undefined4 *)(iVar1 + 0xc),auStack_50);
      FUN_0218efa8(param_1,DAT_0219c50c,auStack_50);
      iVar1 = FUN_0219c8dc();
      if (iVar1 == 0) {
        *(undefined4 *)(*DAT_0219c508 + 4) = 4;
        FUN_0218eff8(param_1,param_2[1],0,0,DAT_0219c510,0);
        FUN_0219c8dc();
        return;
      }
    }
    else if (*(int *)(iVar1 + 4) == 4) {
      func_0x02152808(*(int *)(iVar1 + 0x20) + 4,*(undefined4 *)(iVar1 + 0xc),auStack_3b);
      iVar1 = func_0x0213a074((int)param_2 + 0x8e,auStack_3b);
      if (iVar1 == 0) {
        func_0x02152808(*DAT_0219c508 + 0x40,*(undefined4 *)(*DAT_0219c508 + 0xc),auStack_26);
        func_0x021525f0(*(undefined4 *)(*DAT_0219c508 + 0x20),*DAT_0219c508 + 0x40,param_2[1]);
        FUN_0218f130(param_1);
        (*(code *)*DAT_0219c520)(*DAT_0219c508 + 0x4c,*DAT_0219c508 + DAT_0219c518,*DAT_0219c51c);
        return;
      }
      FUN_0218eff8(param_1,param_2[1],0,0,DAT_0219c510,0);
      FUN_0219c8dc();
    }
  }
  return;
}

