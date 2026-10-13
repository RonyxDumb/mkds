/* Decompiled C draft; module arm9_ov000; ROM address 02188068. No matching claim. */
#include "types.h"
#include "deps/02188068_FUN_02188068.h"

void FUN_02188068(void)

{
  int iVar1;
  
  if (*DAT_021880f0 != 0) {
    FUN_02186d04();
    (**(code **)(*DAT_021880f8 + DAT_021880fc))(DAT_021880f4,*DAT_021880f0,0);
    *DAT_021880f0 = 0;
  }
  FUN_02186430();
  iVar1 = *DAT_021880f8;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + DAT_02188100) != 0) {
      (**(code **)(iVar1 + DAT_021880fc))(DAT_02188104,*(int *)(iVar1 + DAT_02188100),0);
      *(undefined4 *)(*DAT_021880f8 + DAT_02188100) = 0;
    }
    iVar1 = *(int *)(*DAT_021880f8 + DAT_02188108);
    if (iVar1 != 0) {
      (**(code **)(*DAT_021880f8 + DAT_021880fc))(DAT_0218810c,iVar1,0);
      *(undefined4 *)(*DAT_021880f8 + DAT_02188108) = 0;
    }
    (**(code **)(*DAT_021880f8 + DAT_021880fc))(DAT_02188110,*DAT_021880f8,0);
    *DAT_021880f8 = 0;
  }
  return;
}

