/* Decompiled C draft; module arm9_ov001; ROM address 0218ce30. No matching claim. */
#include "types.h"
#include "deps/0218ce30_FUN_0218ce30.h"

void FUN_0218ce30(undefined4 param_1,int param_2)

{
  int iVar1;
  
  FUN_0218dc20(param_2);
  FUN_0218dba8(param_2);
  iVar1 = func_0x020d2c2c(param_2 + DAT_0218ce84,param_2 + 0x10,
                          *(undefined4 *)(*(int *)(param_2 + 0xa0) + DAT_0218ce88),
                          (int)*(short *)(param_2 + 100),9,0);
  if (iVar1 == 2) {
    func_0x020d2774(param_2,DAT_0218ce8c);
  }
  FUN_021864ac(param_1,param_2);
  return;
}

