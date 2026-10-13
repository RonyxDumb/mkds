/* Decompiled C draft; module arm9_ov000; ROM address 0219746c. No matching claim. */
#include "types.h"
#include "deps/0219746c_FUN_0219746c.h"

undefined4 FUN_0219746c(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  uVar4 = 0;
  if ((*DAT_02197540 != -1) && (*DAT_02197544 == 5)) {
    iVar5 = thunk_FUN_0218e668(*DAT_02197540);
    piVar3 = DAT_02197550;
    piVar2 = DAT_0219754c;
    piVar1 = DAT_02197548;
    while (iVar5 != 0) {
      iVar5 = *piVar2;
      if (iVar5 - *piVar3 < 0x80) {
        if (iVar5 < DAT_02197554) {
          *piVar2 = DAT_02197554;
        }
        else {
          *piVar2 = iVar5 << 1;
        }
        iVar5 = FUN_021a3678(*piVar1,*piVar2 + 1);
        *piVar1 = iVar5;
        if (iVar5 == 0) {
          return 0;
        }
      }
      iVar5 = FUN_0218e460(*DAT_02197540,*piVar1 + *piVar3,*piVar2 - *piVar3,0);
      if (iVar5 < 1) {
        FUN_02197634();
        return 0;
      }
      iVar6 = *piVar3;
      *piVar3 = iVar6 + iVar5;
      *(undefined1 *)(*piVar1 + iVar6 + iVar5) = 0;
      iVar5 = FUN_02196a84(*piVar1,*piVar3);
      if (iVar5 == *piVar3) {
        *piVar3 = 0;
      }
      else {
        func_0x02134df8(*piVar1,*piVar1 + iVar5,*piVar3 - iVar5);
        *piVar3 = *piVar3 - iVar5;
      }
      iVar5 = thunk_FUN_0218e668(*DAT_02197540);
    }
    uVar4 = 0;
    if (*DAT_02197540 != -1) {
      uVar4 = 1;
    }
  }
  return uVar4;
}

