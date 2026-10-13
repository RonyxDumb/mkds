/* Decompiled C draft; module arm7; ROM address 0600ecf4. No matching claim. */
#include "types.h"
#include "deps/0600ecf4_FUN_0600ecf4.h"

void FUN_0600ecf4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = (uint)*(ushort *)(param_1 + 2);
  iVar1 = FUN_0600e808(uVar3);
  uVar2 = thunk_FUN_037f8850(0x1000000);
  if ((*(short *)((*(uint *)(DAT_0600ed80 & 0xfffffffc) >> (DAT_0600ed80 & 3) * 8 |
                  *(uint *)(DAT_0600ed80 & 0xfffffffc) << (DAT_0600ed80 & 3) * -8 + 0x20) + 0x350)
       == 1) && (*(short *)(iVar1 + 0x16) == 0)) {
    FUN_0600e748(uVar3);
  }
  *(short *)(iVar1 + 0x16) = *(short *)(iVar1 + 0x16) + 1;
  thunk_FUN_037f888c(uVar2);
  if (((uint)*(ushort *)
              ((*(uint *)(DAT_0600ed80 & 0xfffffffc) >> (DAT_0600ed80 & 3) * 8 |
               *(uint *)(DAT_0600ed80 & 0xfffffffc) << (DAT_0600ed80 & 3) * -8 + 0x20) + 0x534) &
      1 << (uVar3 & 0xff)) == 0) {
    *(undefined2 *)(iVar1 + 0x18) = *(undefined2 *)(iVar1 + 0x1a);
  }
  return;
}

