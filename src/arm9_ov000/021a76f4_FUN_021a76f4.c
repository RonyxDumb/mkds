/* Decompiled C draft; module arm9_ov000; ROM address 021a76f4. No matching claim. */
#include "types.h"
#include "deps/021a76f4_FUN_021a76f4.h"

undefined4 FUN_021a76f4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021a7064(DAT_021a7744,param_1,(int)*(char *)(param_1 + 0x72));
  if (iVar1 == 0) {
    return 0xffffffdf;
  }
  *(undefined2 *)(iVar1 + 0x10) = *(undefined2 *)(param_1 + 0x74);
  *(undefined2 *)(iVar1 + 0x12) = *(undefined2 *)(param_1 + 0x76);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 0x78);
  *(ushort *)(param_1 + 0x70) = *(ushort *)(param_1 + 0x70) | 2;
  uVar2 = FUN_021a6fb4(param_1);
  return uVar2;
}

