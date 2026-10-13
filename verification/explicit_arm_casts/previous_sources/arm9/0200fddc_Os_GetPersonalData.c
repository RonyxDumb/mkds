/* Decompiled C draft; module arm9; ROM address 0200fddc. No matching claim. */
#include "types.h"
#include "deps/0200fddc_Os_GetPersonalData.h"

void Os_GetPersonalData(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = iRam0200fe54;
  iVar2 = iRam0200fe54 + 6;
  *param_1 = (byte)(((uint)*(ushort *)(iRam0200fe54 + 100) << 0x1d) >> 0x1d);
  param_1[1] = (byte)(((uint)*(byte *)(iVar1 + 2) << 0x1c) >> 0x1c);
  param_1[2] = *(byte *)(iVar1 + 3);
  param_1[3] = *(byte *)(iVar1 + 4);
  *(ushort *)(param_1 + 0x18) = (ushort)*(byte *)(iVar1 + 0x1a);
  *(ushort *)(param_1 + 0x4e) = (ushort)*(byte *)(iVar1 + 0x50);
  CopyMemory16(iVar2,param_1 + 4,0x14);
  CopyMemory16(iRam0200fe54 + 0x1c,param_1 + 0x1a,0x34);
  return;
}

