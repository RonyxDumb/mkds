/* Decompiled C draft; module arm9; ROM address 02051e98. No matching claim. */
#include "types.h"
#include "deps/02051e98_func_02051e98.h"

void func_02051e98(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = uRam02051efc;
  uVar1 = uRam02051ef8;
  uVar4 = *(uint *)(uRam02051ef8 & 0xfffffffc) >> (uRam02051ef8 & 3) * 8 |
          *(uint *)(uRam02051ef8 & 0xfffffffc) << (uRam02051ef8 & 3) * -8 + 0x20;
  *(ushort *)(uVar4 + 0x436) = *(ushort *)(uVar4 + 0x436) & 0xfffe;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0xc) = 9;
  *(undefined4 *)
   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_021438a8(uVar2);
  if (iVar3 != 2) {
    func_020533a0();
    return;
  }
  return;
}

