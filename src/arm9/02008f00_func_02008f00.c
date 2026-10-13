/* Decompiled C draft; module arm9; ROM address 02008f00. No matching claim. */
#include "types.h"
#include "deps/02008f00_func_02008f00.h"

void func_02008f00(code *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = 0;
  bVar1 = false;
  iVar9 = 0;
  do {
    iVar4 = iRam02008fe8;
    puVar6 = (ushort *)*piRam02008fe4;
    iVar2 = iVar9 + 0x10;
    uVar5 = 1 << (uVar8 & 0xff);
    uVar7 = uVar5 & 0xffff;
    if (((*puVar6 & uVar7) != 0) &&
       (*(ushort *)((int)puVar6 + iRam02008fe8 + iVar2) =
             *(short *)((int)puVar6 + iRam02008fe8 + iVar2) - puVar6[6],
       *(short *)((int)puVar6 + iVar4 + iVar2) < 0)) {
      *(undefined2 *)((int)puVar6 + iRam02008fe8 + iVar2) = 0;
      if (((*(ushort *)(*piRam02008fe4 + 4) & uVar7) != 0) && (param_1 != (code *)0x0)) {
        (*param_1)(3,0,uVar8);
      }
      puVar6 = (ushort *)*piRam02008fe4;
      if ((puVar6[3] & uVar7) != 0) {
        bVar1 = true;
      }
      *puVar6 = *puVar6 & ~(ushort)uVar5;
      func_020089d0(uVar8);
    }
    piVar3 = piRam02008fe4;
    iVar9 = iVar9 + iRam02008fec;
    uVar8 = uVar8 + 1;
  } while ((int)uVar8 < 0x10);
  iVar9 = *piRam02008fe4;
  if ((*(short *)(iVar9 + 6) != 0) && (0 < *(short *)(iVar9 + 8))) {
    *(short *)(iVar9 + 8) = *(short *)(iVar9 + 8) - *(short *)(iVar9 + 0xc);
    iVar9 = *piVar3;
    if (*(short *)(iVar9 + 8) < 0) {
      bVar1 = true;
    }
    else if (param_2 == 0) {
      *(short *)(iVar9 + 10) = *(short *)(iVar9 + 10) + 1;
      if (4 < *(short *)(*piVar3 + 10)) {
        bVar1 = true;
      }
    }
    else {
      *(undefined2 *)(iVar9 + 10) = 0;
    }
  }
  if (bVar1) {
    *(undefined2 *)(*piRam02008fe4 + 8) = 0;
    func_02008a14();
  }
  return;
}

