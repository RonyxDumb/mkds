/* Decompiled C draft; module arm7; ROM address 0600e248. No matching claim. */
#include "types.h"
#include "deps/0600e248_FUN_0600e248.h"

void FUN_0600e248(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar3;
  int iVar4;
  uint uVar2;
  
  uVar3 = *(uint *)(DAT_0600e324 & 0xfffffffc) >> (DAT_0600e324 & 3) * 8 |
          *(uint *)(DAT_0600e324 & 0xfffffffc) << (DAT_0600e324 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x31c & 3;
  uVar1 = *(uint *)(uVar3 + 0x31c & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  iVar4 = uVar2 + param_1 * 0x1c;
  if (*(short *)(uVar2 + param_1 * 0x1c) == 0) {
    *(short *)(uVar3 + 0x52c) = *(short *)(uVar3 + 0x52c) + 1;
  }
  thunk_FUN_037fb218(0,iVar4,0x1a);
  uVar2 = *(uint *)(DAT_0600e324 & 0xfffffffc) >> (DAT_0600e324 & 3) * 8 |
          *(uint *)(DAT_0600e324 & 0xfffffffc) << (DAT_0600e324 & 3) * -8 + 0x20;
  *(ushort *)(uVar2 + 0x534) = *(ushort *)(uVar2 + 0x534) & ~(ushort)(1 << (param_1 & 0xff));
  FUN_0600eb40(param_1 & 0xffff,0);
  FUN_0600eadc(param_1);
  FUN_0600a954((undefined2 *)(uintptr_t)(iVar4 + 4),(undefined2 *)(uintptr_t)(param_2));
  *(short *)(iVar4 + 0x14) = (short)DAT_0600e328;
  *(undefined2 *)(iVar4 + 0x10) =
       *(undefined2 *)
        ((*(uint *)(DAT_0600e324 & 0xfffffffc) >> (DAT_0600e324 & 3) * 8 |
         *(uint *)(DAT_0600e324 & 0xfffffffc) << (DAT_0600e324 & 3) * -8 + 0x20) + 0x3a6);
  *(undefined2 *)(iVar4 + 0x18) = *(undefined2 *)(iVar4 + 0x1a);
  FUN_0600ebbc(param_1 & 0xffff,0x20);
  return;
}

