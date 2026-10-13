/* Decompiled C draft; module arm9; ROM address 0205660c. No matching claim. */
#include "types.h"
#include "deps/0205660c_StructNKPG_AnotherCopyToTime_from_thumb.h"

undefined4 StructNKPG_AnotherCopyToTime_from_thumb(int param_1,int param_2,ushort *param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (param_2 + -1) * 3 & 0xff;
  if ((*(uint *)(param_1 + 8) & 1) == 0) {
    return 0;
  }
  uVar3 = (uint)*(byte *)(param_1 + uVar2 + 0x20) << 0x10;
  uVar4 = (uint)*(byte *)(param_1 + uVar2 + 0x21) << 8;
  bVar1 = *(byte *)(param_1 + uVar2 + 0x22);
  *(char *)(param_3 + 1) = (char)(uVar3 >> 0x11);
  *(byte *)((int)param_3 + 3) = (byte)((uVar3 | uVar4) >> 10) & 0x7f;
  *param_3 = ((ushort)uVar4 | (ushort)bVar1) & (ushort)uRam0205666c;
  return 1;
}

