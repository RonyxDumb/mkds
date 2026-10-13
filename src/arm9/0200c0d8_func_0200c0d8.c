/* Decompiled C draft; module arm9; ROM address 0200c0d8. No matching claim. */
#include "types.h"
#include "deps/0200c0d8_func_0200c0d8.h"

byte * func_0200c0d8(undefined1 *param_1,undefined1 *param_2)

{
  byte *pbVar1;
  
  pbVar1 = param_2 + 1;
  *param_1 = *param_2;
  switch(*param_1) {
  default:
    return (byte *)0x0;
  case 1:
  case 2:
  case 3:
  case 5:
  case 6:
    break;
  case 4:
    *(ushort *)(param_1 + 2) = (ushort)*pbVar1;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | (ushort)(byte)param_2[2] << 8;
    *(ushort *)(param_1 + 4) = (ushort)(byte)param_2[3];
    pbVar1 = param_2 + 5;
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | (ushort)(byte)param_2[4] << 8;
  }
  return pbVar1;
}

