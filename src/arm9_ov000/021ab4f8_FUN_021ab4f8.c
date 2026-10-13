/* Decompiled C draft; module arm9_ov000; ROM address 021ab4f8. No matching claim. */
#include "types.h"
#include "deps/021ab4f8_FUN_021ab4f8.h"

uint FUN_021ab4f8(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  
  pbVar3 = (byte *)*param_1 + 1;
  bVar1 = *(byte *)*param_1;
  uVar2 = (uint)bVar1;
  if ((bVar1 & 0x80) != 0) {
    uVar4 = uVar2 & 0x7f;
    uVar2 = 0;
    if ((bVar1 & 0x7f) != 0) {
      do {
        uVar4 = uVar4 - 1;
        if ((uVar2 & DAT_021ab544) != 0) {
          return 0xffffffff;
        }
        bVar1 = *pbVar3;
        pbVar3 = pbVar3 + 1;
        uVar2 = uVar2 * 0x100 + (uint)bVar1;
      } while (uVar4 != 0);
    }
  }
  *param_1 = pbVar3;
  return uVar2;
}

