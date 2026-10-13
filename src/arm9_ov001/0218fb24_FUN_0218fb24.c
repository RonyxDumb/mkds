/* Decompiled C draft; module arm9_ov001; ROM address 0218fb24. No matching claim. */
#include "types.h"
#include "deps/0218fb24_FUN_0218fb24.h"

void FUN_0218fb24(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(*DAT_0218fbd4 + 8) == 4) {
    iVar1 = func_0x020a128c();
  }
  else {
    iVar1 = 0;
  }
  if ((iVar1 != 0) && (iVar1 = FUN_021871f8(param_2,3), iVar1 != 0)) {
    if (*(int *)(*DAT_0218fbd4 + 8) == 4) {
      iVar1 = func_0x020a1084((short)*(char *)(*DAT_0218fbd4 + 0x62));
    }
    else {
      iVar1 = 0;
    }
    if (iVar1 == 0) {
      FUN_02190eb0(param_2);
    }
    else {
      FUN_02190df8(param_2);
    }
  }
  if (*(int *)(param_2 + 0xa8) == 1) {
    iVar2 = *(int *)(param_2 + DAT_0218fbd8) + 1;
    iVar1 = func_0x0209b634(*(undefined4 *)(param_2 + DAT_0218fbdc));
    if (iVar1 + -1 <= iVar2) {
      iVar2 = func_0x0209b634(*(undefined4 *)(param_2 + DAT_0218fbdc));
      iVar2 = iVar2 + -1;
    }
    *(int *)(param_2 + DAT_0218fbd8) = iVar2;
  }
  else {
    iVar1 = *(int *)(param_2 + DAT_0218fbd8) + -1;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    *(int *)(param_2 + DAT_0218fbd8) = iVar1;
  }
  func_0x0209b688(*(undefined4 *)(param_2 + DAT_0218fbdc),*(uint *)(param_2 + DAT_0218fbd8) & 0xffff
                 );
  FUN_021864ac(param_1,param_2);
  return;
}

