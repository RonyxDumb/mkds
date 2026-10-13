/* Decompiled C draft; module arm9_ov001; ROM address 0218b1d8. No matching claim. */
#include "types.h"
#include "deps/0218b1d8_FUN_0218b1d8.h"

void FUN_0218b1d8(int param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  
  iVar1 = FUN_02187c4c();
  if (iVar1 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b264);
    iVar2 = (int)*(short *)(DAT_0218b26c +
                           ((int)(*(uint *)(param_1 + DAT_0218b268) & 0xffff) >> 4) * 4);
    uVar3 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar2,iVar2 >> 0x1f);
    local_18 = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
    local_14 = *(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218b270);
    iVar1 = *(int *)(*(int *)(param_1 + 0xa0) + DAT_0218b264);
    iVar2 = (int)*(short *)(DAT_0218b26c +
                           (((int)(*(uint *)(param_1 + DAT_0218b268) & 0xffff) >> 4) * 2 + 1) * 2);
    uVar3 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar2,iVar2 >> 0x1f);
    local_10 = (uint)uVar3 >> 0xc | (int)((ulonglong)uVar3 >> 0x20) << 0x14;
    FUN_02187bfc(param_1,&local_18,*(undefined4 *)(*(int *)(param_1 + 0xa0) + DAT_0218b274));
  }
  return;
}

