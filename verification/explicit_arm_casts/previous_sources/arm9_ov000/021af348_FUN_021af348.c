/* Decompiled C draft; module arm9_ov000; ROM address 021af348. No matching claim. */
#include "types.h"
#include "deps/021af348_FUN_021af348.h"

void FUN_021af348(int param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 | (*(ushort *)(param_1 + 0xc) & 0xff) << 8) <<
          0x10 | (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                 (*(ushort *)(param_1 + 0xe) & 0xff) << 8;
  iVar1 = FUN_021b0094(uVar3);
  if ((iVar1 == 0) && (iVar1 = FUN_021b00e0(uVar3), iVar1 != 0)) {
    iVar2 = FUN_021afd00();
    if (iVar2 == 0) {
      FUN_021afc5c(iVar1);
      return;
    }
    *param_2 = 0;
    *(undefined2 *)(param_2 + 2) = 0;
    iVar1 = FUN_021b0188(param_2,param_3);
    *(ushort *)(param_2 + 2) = (ushort)((uint)iVar1 >> 8) | (ushort)(iVar1 << 8);
    FUN_021af858(param_2,param_3,0,0,
                 ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                 (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
                 (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                 (*(ushort *)(param_1 + 0xe) & 0xff) << 8,1);
  }
  return;
}

