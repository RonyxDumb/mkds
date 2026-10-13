/* Decompiled C draft; module arm9; ROM address 020019b0. No matching claim. */
#include "types.h"
#include "deps/020019b0_Logo_StateHandler_ReadSaveData_Second.h"

void Logo_StateHandler_ReadSaveData_Second(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = uRam02001a38;
  uVar5 = *(uint *)(uRam02001a38 & 0xfffffffc) >> (uRam02001a38 & 3) * 8 |
          *(uint *)(uRam02001a38 & 0xfffffffc) << (uRam02001a38 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x30;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar5 + 0x30) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 1;
  uVar3 = uVar1 & 3;
  uVar4 = *(uint *)(uVar1 & 0xfffffffc);
  uVar4 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 0x30 & 3;
  uVar1 = *(uint *)(uVar4 + 0x30 & 0xfffffffc);
  uVar1 = uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20;
  uVar3 = uVar1;
  if (0x78 < (int)uVar1) {
    uVar4 = uVar4 + 0x18;
    uVar3 = 1;
  }
  if (0x78 < (int)uVar1) {
    *(short *)(uVar4 + 0x10) = (short)uVar3;
    *(short *)(uVar4 + 0x12) = (short)uVar3;
  }
  iVar2 = GetDirectInputUnitIndex();
  if ((uRam02001a40 & *(ushort *)(iRam02001a3c + iVar2 * 0x5c)) == uRam02001a40) {
    uVar1 = *(uint *)(uRam02001a38 & 0xfffffffc) >> (uRam02001a38 & 3) * 8 |
            *(uint *)(uRam02001a38 & 0xfffffffc) << (uRam02001a38 & 3) * -8 + 0x20;
    uVar3 = uVar1 + 0x2c;
    uVar4 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    *(uint *)(uVar1 + 0x2c) = (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xfffffffe | 1;
    return;
  }
  return;
}

