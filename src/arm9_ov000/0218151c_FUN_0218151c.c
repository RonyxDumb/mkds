/* Decompiled C draft; module arm9_ov000; ROM address 0218151c. No matching claim. */
#include "types.h"
#include "deps/0218151c_FUN_0218151c.h"

uint FUN_0218151c(int param_1,int param_2,uint *param_3)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  byte *pbVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  byte local_40 [10];
  ushort local_36 [21];
  
  pbVar5 = local_40;
  iVar4 = 9;
  puVar6 = DAT_02181614;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *pbVar5 = uVar1;
    pbVar5 = pbVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  pbVar5 = local_40 + 8;
  iVar4 = 0x12;
  puVar7 = DAT_02181618;
  do {
    pbVar5 = pbVar5 + 2;
    uVar3 = *puVar7;
    puVar7 = puVar7 + 1;
    *(undefined2 *)pbVar5 = uVar3;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0;
  if (param_1 == DAT_0218161c) {
    iVar4 = 1;
  }
  else if (param_1 == DAT_02181620) {
    iVar4 = 2;
  }
  else if ((((param_1 < DAT_02181624) || (DAT_02181628 < param_1)) &&
           ((param_1 < DAT_0218162c || (DAT_02181630 < param_1)))) &&
          ((param_1 < DAT_02181634 || (DAT_02181638 < param_1)))) {
    if (((param_1 < DAT_0218163c) || (DAT_02181640 < param_1)) &&
       (((param_1 < DAT_02181644 || (DAT_02181648 < param_1)) &&
        ((param_1 < DAT_0218164c || (DAT_02181650 < param_1)))))) {
      if (param_1 == DAT_02181654) {
        iVar4 = 5;
      }
      else if ((param_1 < DAT_02181658) || (DAT_0218165c < param_1)) {
        if ((param_1 == DAT_02181660) || ((DAT_02181664 <= param_1 && (param_1 <= DAT_02181668)))) {
          iVar4 = 7;
        }
        else if ((DAT_0218166c <= param_1) && (param_1 <= DAT_02181670)) {
          iVar4 = 8;
        }
      }
      else {
        iVar4 = 6;
      }
    }
    else {
      iVar4 = 4;
    }
  }
  else {
    iVar4 = 3;
  }
  bVar2 = local_40[iVar4];
  *param_3 = (uint)bVar2;
  if ((int)(uint)bVar2 <= param_2) {
    return 0xffffffff;
  }
  return (uint)local_36[iVar4 * 2 + param_2];
}

