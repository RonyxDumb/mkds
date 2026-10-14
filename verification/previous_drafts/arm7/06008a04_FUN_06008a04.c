/* Decompiled C draft; module arm7; ROM address 06008a04. No matching claim. */
#include "types.h"
#include "deps/06008a04_FUN_06008a04.h"

uint FUN_06008a04(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(DAT_06008a70 & 0xfffffffc) >> (DAT_06008a70 & 3) * 8 |
          *(uint *)(DAT_06008a70 & 0xfffffffc) << (DAT_06008a70 & 3) * -8 + 0x20;
  thunk_FUN_037f8850(DAT_06008a74);
  uVar3 = DAT_06008a78;
  param_1 = param_1 * 2;
  uVar4 = (uint)*(ushort *)(uVar5 + param_1);
  if (uVar4 != DAT_06008a78) {
    iVar6 = uVar5 + 0xbc;
    *(undefined2 *)(iVar6 + uVar4 * 8 + 2) = 0;
    uVar1 = *(ushort *)(iVar6 + uVar4 * 8);
    uVar2 = (undefined2)uVar3;
    if (uVar1 == uVar3) {
      *(undefined2 *)(uVar5 + param_1) = uVar2;
      *(undefined2 *)(uVar5 + param_1 + 8) = uVar2;
    }
    else {
      *(ushort *)(uVar5 + param_1) = uVar1;
      *(undefined2 *)(iVar6 + uVar4 * 8) = uVar2;
    }
  }
  thunk_FUN_037f888c();
  return uVar4;
}

