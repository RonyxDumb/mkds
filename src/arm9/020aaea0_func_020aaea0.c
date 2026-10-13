/* Decompiled C draft; module arm9; ROM address 020aaea0. No matching claim. */
#include "types.h"
#include "deps/020aaea0_func_020aaea0.h"

byte * func_020aaea0(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  if (((((param_1[2] < 2) || (param_1[3] < 2)) || (param_3 < (int)(uint)param_1[1])) ||
      (((int)((uint)param_1[1] + (uint)param_1[3]) <= param_3 || (param_2 < (int)(uint)*param_1))))
     || ((int)((uint)*param_1 + (uint)param_1[2]) <= param_2)) {
    if (((1 < param_1[10]) && (1 < param_1[0xb])) &&
       (((int)(uint)param_1[9] <= param_3 &&
        (((param_3 < (int)((uint)param_1[9] + (uint)param_1[0xb]) &&
          (uVar2 = (uint)param_1[8], (int)uVar2 <= param_2)) &&
         (param_2 < (int)(uVar2 + param_1[10]))))))) {
      return param_1 + 8;
    }
    pbVar1 = (byte *)**(undefined4 **)(param_1 + 0x2c);
    uVar2 = (uint)*(ushort *)((int)*(undefined4 **)(param_1 + 0x2c) + 0xe);
    iVar4 = 0;
    if (uVar2 != 0) {
      pbVar3 = pbVar1;
      do {
        if ((((1 < pbVar3[2]) && (1 < pbVar3[3])) &&
            (((int)(*piRam020aaf68 + (uint)pbVar3[1]) <= param_3 &&
             ((param_3 < (int)(*piRam020aaf68 + (uint)pbVar3[1] + (uint)pbVar3[3]) &&
              ((int)(*piRam020aaf6c + (uint)*pbVar3) <= param_2)))))) &&
           (param_2 < (int)(*piRam020aaf6c + (uint)*pbVar3 + (uint)pbVar3[2]))) {
          return pbVar1 + iVar4 * 8;
        }
        pbVar3 = pbVar3 + 8;
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)uVar2);
    }
    param_1 = (byte *)0x0;
  }
  return param_1;
}

