/* Decompiled C draft; module arm9_ov001; ROM address 0218274c. No matching claim. */
#include "types.h"
#include "deps/0218274c_FUN_0218274c.h"

undefined1 FUN_0218274c(int param_1,int param_2,char *param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = *param_4;
  if ((*(uint *)(param_2 + 0x48) & DAT_0218279c) != 0) {
    return 0;
  }
  if ((((*param_3 == '\x01') && (iVar2 = *(int *)(param_1 + 0xf8), iVar2 != 3)) && (iVar2 != 5)) &&
     ((iVar2 != 6 && (func_0x020d2398(), *(int *)(*DAT_021827a0 + 8) == 4)))) {
    func_ov001_021815d0(1);
  }
  return uVar1;
}

