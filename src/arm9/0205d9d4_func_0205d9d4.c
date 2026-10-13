/* Decompiled C draft; module arm9; ROM address 0205d9d4. No matching claim. */
#include "types.h"
#include "deps/0205d9d4_func_0205d9d4.h"

void func_0205d9d4(uint param_1,int param_2,short param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  uint uVar8;
  
  uVar2 = *(uint *)(uRam0205db1c & 0xfffffffc) >> (uRam0205db1c & 3) * 8 |
          *(uint *)(uRam0205db1c & 0xfffffffc) << (uRam0205db1c & 3) * -8 + 0x20;
  uVar3 = uVar2 + 8;
  uVar8 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  iVar5 = *(ushort *)(uVar2 + 0x60) - 1;
  iVar7 = iVar5 >> 0x1f;
  uVar8 = ((uint)(iVar5 * 0x40000000 + iVar7) >> 0x1e | iVar7 << 2) - iVar7;
  iVar5 = (uVar8 & 0xff) - 1;
  iVar7 = iVar5 * 0x1000000 >> 0x18;
  if ((((uVar3 == 2) || (uVar3 == 3)) || (uVar3 == 5)) && (iVar7 < 0)) {
    iVar7 = (iVar7 + 4) * 0x1000000 >> 0x18;
  }
  if (iVar7 < 0) {
    sVar4 = 0;
  }
  else {
    sVar4 = *(short *)((param_1 & 0xff) * 10 +
                      iVar7 * 0x50 +
                      (*(uint *)(uRam0205db20 & 0xfffffffc) >> (uRam0205db20 & 3) * 8 |
                      *(uint *)(uRam0205db20 & 0xfffffffc) << (uRam0205db20 & 3) * -8 + 0x20));
  }
  iVar7 = iVar5 * 0x1000000 >> 0x18;
  if ((((uVar3 == 2) || (uVar3 == 3)) || (uVar3 == 5)) && (iVar7 < 0)) {
    iVar7 = (iVar7 + 4) * 0x1000000 >> 0x18;
  }
  if (iVar7 < 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)((param_1 & 0xff) * 10 +
                      iVar7 * 0x50 +
                      (*(uint *)(uRam0205db20 & 0xfffffffc) >> (uRam0205db20 & 3) * 8 |
                      *(uint *)(uRam0205db20 & 0xfffffffc) << (uRam0205db20 & 3) * -8 + 0x20) + 5);
  }
  iVar7 = (uVar8 & 0xff) * 0x50 +
          (*(uint *)(uRam0205db20 & 0xfffffffc) >> (uRam0205db20 & 3) * 8 |
          *(uint *)(uRam0205db20 & 0xfffffffc) << (uRam0205db20 & 3) * -8 + 0x20);
  iVar5 = (param_1 & 0xff) * 10;
  puVar6 = (undefined2 *)(iVar7 + iVar5);
  *(char *)((int)puVar6 + 3) = (char)param_2;
  *(char *)(puVar6 + 2) = (char)param_3;
  *(short *)(iVar7 + iVar5) = sVar4 + param_3;
  if (uRam0205db24 < *(ushort *)(iVar7 + iVar5)) {
    *puVar6 = (short)uRam0205db24;
  }
  if (param_2 == 1) {
    bVar1 = bVar1 + 1;
  }
  if (99 < bVar1) {
    bVar1 = 99;
  }
  *(byte *)((int)puVar6 + 5) = bVar1;
  return;
}

