/* Decompiled C draft; module arm9_ov000; ROM address 021881d0. No matching claim. */
#include "types.h"
#include "deps/021881d0_FUN_021881d0.h"

byte * FUN_021881d0(int param_1,uint param_2,byte *param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  byte *pbVar3;
  char *pcVar4;
  uint uVar5;
  char local_18 [4];
  
  if ((param_2 & 3) != 0) {
    return (byte *)0xffffffff;
  }
  iVar2 = 0;
  uVar5 = 0;
  if (param_2 != 0) {
    do {
      if (*(char *)(param_1 + uVar5) != '*') {
        iVar2 = iVar2 + 6;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_2);
  }
  if (param_3 == (byte *)0x0) {
    pbVar3 = (byte *)func_0x02133068(iVar2,8);
    return pbVar3;
  }
  uVar5 = func_0x02133068(iVar2,8);
  if (param_4 < uVar5) {
    return (byte *)0xffffffff;
  }
  pbVar3 = param_3;
  if (param_2 != 0) {
    do {
      iVar2 = 0;
      pcVar4 = local_18;
      do {
        cVar1 = *(char *)(param_1 + iVar2);
        if ((cVar1 < 'A') || ('Z' < cVar1)) {
          if ((cVar1 < 'a') || ('z' < cVar1)) {
            if ((cVar1 < '0') || ('9' < cVar1)) {
              if (cVar1 == '.') {
                *pcVar4 = '>';
              }
              else if (cVar1 == '-') {
                *pcVar4 = '?';
              }
              else {
                *pcVar4 = '\0';
              }
            }
            else {
              *pcVar4 = cVar1 + '\x04';
            }
          }
          else {
            *pcVar4 = cVar1 + -0x47;
          }
        }
        else {
          *pcVar4 = cVar1 + -0x41;
        }
        pcVar4 = pcVar4 + 1;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
      param_1 = param_1 + 4;
      *pbVar3 = (byte)((int)local_18[0] << 2) | local_18[1] >> 4;
      if ((int)uVar5 <= (int)(pbVar3 + (1 - (int)param_3))) {
        return pbVar3 + (1 - (int)param_3);
      }
      pbVar3[1] = (byte)((int)local_18[1] << 4) | local_18[2] >> 2;
      if ((int)uVar5 <= (int)(pbVar3 + (2 - (int)param_3))) {
        return pbVar3 + (2 - (int)param_3);
      }
      pbVar3[2] = (byte)((int)local_18[2] << 6) | local_18[3];
      pbVar3 = pbVar3 + 3;
    } while ((int)(pbVar3 + -(int)param_3) < (int)uVar5);
    return pbVar3 + -(int)param_3;
  }
  *param_3 = 0;
  return (byte *)0x0;
}

