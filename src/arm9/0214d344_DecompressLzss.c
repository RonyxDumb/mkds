/* Decompiled C draft; module arm9; ROM address 0214d344. No matching claim. */
#include "types.h"
#include "deps/0214d344_DecompressLzss.h"

void DecompressLzss(uint param_1,byte *param_2)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  uVar7 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) >> 8;
  pbVar6 = (byte *)(param_1 + 4);
  do {
    if ((int)uVar7 < 1) {
      return;
    }
    uVar11 = (uint)*pbVar6;
    pbVar5 = pbVar6 + 1;
    iVar10 = 8;
    while (pbVar6 = pbVar5, 0 < iVar10) {
      if ((uVar11 & 0x80) == 0) {
        pbVar6 = pbVar5 + 1;
        *param_2 = *pbVar5;
        param_2 = param_2 + 1;
        iVar4 = -1;
      }
      else {
        iVar8 = ((int)(uint)*pbVar5 >> 4) + 3;
        bVar2 = *pbVar5;
        pbVar6 = pbVar5 + 2;
        bVar3 = pbVar5[1];
        iVar4 = -iVar8;
        do {
          *param_2 = param_2[-(((uint)bVar3 | (bVar2 & 0xf) << 8) + 1)];
          param_2 = param_2 + 1;
          iVar9 = iVar8 + -1;
          bVar1 = 0 < iVar8;
          iVar8 = iVar9;
        } while (iVar9 != 0 && bVar1);
      }
      uVar7 = uVar7 + iVar4;
      if ((int)uVar7 < 1) break;
      uVar11 = uVar11 << 1;
      pbVar5 = pbVar6;
      iVar10 = iVar10 + -1;
    }
  } while( true );
}

