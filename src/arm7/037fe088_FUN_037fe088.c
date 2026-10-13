/* Decompiled C draft; module arm7; ROM address 037fe088. No matching claim. */
#include "types.h"
#include "deps/037fe088_FUN_037fe088.h"

void FUN_037fe088(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  sVar3 = *(short *)(DAT_037fe1c4 + (uint)*(byte *)(param_2 + 5) * 2);
  sVar4 = *(short *)(DAT_037fe1c4 + (uint)*(byte *)(param_1 + 4) * 2);
  sVar5 = *(short *)(DAT_037fe1c4 + (uint)*(byte *)(param_1 + 5) * 2);
  sVar6 = *(short *)(param_1 + 10);
  sVar7 = *(short *)(param_2 + 6);
  cVar2 = *(char *)(param_1 + 6);
  bVar1 = *(byte *)(param_1 + 7);
  sVar8 = *(short *)(param_1 + 0xc);
  iVar10 = (int)*(char *)(param_1 + 8);
  if (*(byte *)(param_1 + 1) != 0x7f) {
    iVar10 = (int)(iVar10 * (uint)*(byte *)(param_1 + 1) + 0x40) >> 7;
  }
  iVar10 = iVar10 + *(char *)(param_1 + 9);
  if (iVar10 < -0x80) {
    iVar10 = -0x80;
  }
  else if (0x7f < iVar10) {
    iVar10 = 0x7f;
  }
  uVar12 = param_1 + 0x3cU & 3;
  uVar11 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  for (uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20; uVar12 != 0;
      uVar12 = uVar12 >> uVar11 * 8 | uVar12 << uVar11 * -8 + 0x20) {
    *(short *)(uVar12 + 6) = sVar6 + sVar7;
    if (*(char *)(uVar12 + 2) != '\x03') {
      *(short *)(uVar12 + 0xc) = sVar3 + sVar4 + sVar5;
      *(short *)(uVar12 + 0xe) =
           (short)((uint)(((int)sVar8 + ((int)((int)cVar2 * (uint)bVar1 * 0x40) >> 7)) * 0x10000) >>
                  0x10);
      *(char *)(uVar12 + 0xb) = (char)iVar10;
      *(undefined1 *)(uVar12 + 4) = *(undefined1 *)(param_1 + 1);
      *(undefined2 *)(uVar12 + 0x28) = *(undefined2 *)(param_1 + 0x18);
      *(undefined2 *)(uVar12 + 0x2a) = *(undefined2 *)(param_1 + 0x1a);
      *(undefined2 *)(uVar12 + 0x2c) = *(undefined2 *)(param_1 + 0x1c);
      uVar11 = uVar12 + 0x34 & 3;
      uVar9 = *(uint *)(uVar12 + 0x34 & 0xfffffffc);
      if ((uVar9 >> uVar11 * 8 == 0 && uVar9 << uVar11 * -8 + 0x20 == 0) && (param_3 != 0)) {
        *(undefined1 *)(uVar12 + 0x22) = 1;
        FUN_037fcc24(uVar12);
      }
    }
    uVar11 = uVar12 + 0x50 & 3;
    uVar12 = *(uint *)(uVar12 + 0x50 & 0xfffffffc);
  }
  return;
}

