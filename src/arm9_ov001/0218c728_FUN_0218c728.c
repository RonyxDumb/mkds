/* Decompiled C draft; module arm9_ov001; ROM address 0218c728. No matching claim. */
#include "types.h"
#include "deps/0218c728_FUN_0218c728.h"

void FUN_0218c728(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xa0);
  FUN_0218875c(param_1,*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0xc),
               *(undefined4 *)(iVar2 + DAT_0218c774));
  FUN_021888a4(param_1,0,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc));
  puVar1 = (undefined4 *)(param_1 + DAT_0218c77c);
  *puVar1 = DAT_0218c778;
  *(undefined4 *)(param_1 + DAT_0218c780) = *puVar1;
  puVar1 = (undefined4 *)(param_1 + DAT_0218c788);
  *puVar1 = DAT_0218c784;
  *(undefined4 *)(param_1 + DAT_0218c78c) = *puVar1;
  return;
}

