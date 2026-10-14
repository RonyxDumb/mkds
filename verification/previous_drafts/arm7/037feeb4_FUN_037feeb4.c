/* Decompiled C draft; module arm7; ROM address 037feeb4. No matching claim. */
#include "types.h"
#include "deps/037feeb4_FUN_037feeb4.h"

void FUN_037feeb4(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  
  iVar1 = DAT_037fef4c;
  uVar3 = 0;
  uVar4 = 0;
  do {
    pbVar5 = (byte *)(iVar1 + uVar4 * 0x24);
    uVar2 = (uint)*(byte *)(iVar1 + uVar4 * 0x24);
    if ((int)(uVar2 << 0x1f) < 0) {
      if ((int)(uVar2 << 0x1e) < 0) {
        if ((param_1 != 0) && (-1 < (int)(uVar2 << 0x1d))) {
          FUN_037fe310((int)(uintptr_t)(pbVar5));
        }
        FUN_037fe044((undefined4)(uintptr_t)(pbVar5));
      }
      if ((int)((uint)*pbVar5 << 0x1f) < 0) {
        uVar3 = uVar3 | 1 << (uVar4 & 0xff);
      }
    }
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 0x10);
  uVar4 = *(uint *)(DAT_037fef50 & 0xfffffffc) >> (DAT_037fef50 & 3) * 8 |
          *(uint *)(DAT_037fef50 & 0xfffffffc) << (DAT_037fef50 & 3) * -8 + 0x20;
  if (uVar4 != 0) {
    *(uint *)(uVar4 + 4) = uVar3;
  }
  return;
}

