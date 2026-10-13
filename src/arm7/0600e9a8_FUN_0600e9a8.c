/* Decompiled C draft; module arm7; ROM address 0600e9a8. No matching claim. */
#include "types.h"
#include "deps/0600e9a8_FUN_0600e9a8.h"

uint FUN_0600e9a8(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (*(uint *)(DAT_0600ea50 & 0xfffffffc) >> (DAT_0600ea50 & 3) * 8 |
          *(uint *)(DAT_0600ea50 & 0xfffffffc) << (DAT_0600ea50 & 3) * -8 + 0x20) + DAT_0600ea54;
  uVar1 = thunk_FUN_037f8850(0x1000000);
  uVar3 = 1;
  uVar2 = 2;
  while( true ) {
    if (0xf < uVar3) {
      thunk_FUN_037f888c(uVar1);
      return 0;
    }
    if ((*(ushort *)(iVar4 + 0xe) & uVar2) == 0) break;
    uVar3 = uVar3 + 1;
    uVar2 = uVar2 << 1;
  }
  *(ushort *)(iVar4 + 0xe) = *(ushort *)(iVar4 + 0xe) | (ushort)uVar2;
  *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + 1;
  if (*(short *)(iVar4 + 0xc) == 1) {
    FUN_0600abf8();
  }
  iVar4 = FUN_0600e808(param_1);
  *(short *)(iVar4 + 2) = (short)uVar3;
  thunk_FUN_037f888c(uVar1);
  return uVar3;
}

