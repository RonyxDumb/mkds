/* Decompiled C draft; module arm7; ROM address 0600ebbc. No matching claim. */
#include "types.h"
#include "deps/0600ebbc_FUN_0600ebbc.h"

void FUN_0600ebbc(uint param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 *puVar5;
  
  uVar1 = thunk_FUN_037f8850(0x1000000);
  if (param_2 < 0x40) {
    FUN_0600eadc(param_1);
    uVar3 = DAT_0600ec84;
    uVar2 = *(uint *)(DAT_0600ec84 & 0xfffffffc) >> (DAT_0600ec84 & 3) * 8 |
            *(uint *)(DAT_0600ec84 & 0xfffffffc) << (DAT_0600ec84 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 0x532) = *(ushort *)(uVar2 + 0x532) | (ushort)(1 << (param_1 & 0xff));
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if ((*(short *)((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 0x350) == 1) &&
       (iVar4 = FUN_0600e840(param_1), iVar4 != 0)) {
      FUN_0600e934(param_1);
    }
  }
  else {
    uVar2 = *(uint *)(DAT_0600ec84 & 0xfffffffc) >> (DAT_0600ec84 & 3) * 8 |
            *(uint *)(DAT_0600ec84 & 0xfffffffc) << (DAT_0600ec84 & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 0x532) = *(ushort *)(uVar2 + 0x532) & ~(ushort)(1 << (param_1 & 0xff));
    iVar4 = FUN_0600e8d8(param_1);
    if (iVar4 != 0) {
      FUN_0600eb00(param_1);
    }
  }
  puVar5 = (undefined2 *)FUN_0600e808(param_1);
  *puVar5 = (short)param_2;
  thunk_FUN_037f888c(uVar1);
  return;
}

