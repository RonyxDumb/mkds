/* Decompiled C draft; module arm7; ROM address 060090b4. No matching claim. */
#include "types.h"
#include "deps/060090b4_FUN_060090b4.h"

int FUN_060090b4(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar4;
  uint uVar5;
  uint uVar3;
  
  uVar5 = *(uint *)(DAT_06009130 & 0xfffffffc) >> (DAT_06009130 & 3) * 8 |
          *(uint *)(DAT_06009130 & 0xfffffffc) << (DAT_06009130 & 3) * -8 + 0x20;
  if (*(ushort *)(param_2 + 10) == DAT_06009134) {
    iVar1 = FUN_06008e50(param_1);
    if (iVar1 == 0) {
      uVar3 = uVar5 + 0x17c & 3;
      uVar2 = *(uint *)(uVar5 + 0x17c & 0xfffffffc);
      uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
      if (uVar3 == 0) {
        uVar3 = uVar5 + 0x180 & 3;
        uVar4 = *(uint *)(uVar5 + 0x180 & 0xfffffffc);
        uVar2 = uVar5 + 0x184 & 3;
        uVar5 = *(uint *)(uVar5 + 0x184 & 0xfffffffc);
        thunk_FUN_037f9fd8(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                           uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20,param_2);
      }
      else if (uVar3 == 1) {
        uVar3 = uVar5 + 0x184 & 3;
        uVar5 = *(uint *)(uVar5 + 0x184 & 0xfffffffc);
        (*(code *)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20))(param_2);
      }
    }
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}

