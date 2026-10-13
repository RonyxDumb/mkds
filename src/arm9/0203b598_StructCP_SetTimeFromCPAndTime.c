/* Decompiled C draft; module arm9; ROM address 0203b598. No matching claim. */
#include "types.h"
#include "deps/0203b598_StructCP_SetTimeFromCPAndTime.h"

void StructCP_SetTimeFromCPAndTime(ushort *param_1,ushort *param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)*param_1 + (uint)*param_2 & 0xffff;
  uVar4 = (uint)(byte)param_1[1] + (uint)(byte)param_2[1];
  uVar2 = (uint)*(byte *)((int)param_1 + 3) + (uint)*(byte *)((int)param_2 + 3);
  uVar1 = (uint)((longlong)iRam0203b678 * (longlong)(int)uVar3 >> 0x26) & 0xffff;
  if (uVar1 != 0) {
    uVar2 = uVar2 + uVar1 & 0xffff;
    uVar3 = uVar3 + uVar1 * -1000 & 0xffff;
  }
  uVar1 = (int)(uVar2 + (int)((ulonglong)((longlong)iRam0203b67c * (longlong)(int)uVar2) >> 0x20))
          >> 5 & 0xffff;
  if (uVar1 != 0) {
    uVar4 = uVar4 + uVar1 & 0xffff;
    uVar2 = uVar2 + uVar1 * -0x3c & 0xffff;
  }
  if (99 < uVar4) {
    uVar4 = 99;
  }
  *(char *)(param_3 + 1) = (char)uVar4;
  *(char *)((int)param_3 + 3) = (char)uVar2;
  *param_3 = (short)uVar3;
  return;
}

