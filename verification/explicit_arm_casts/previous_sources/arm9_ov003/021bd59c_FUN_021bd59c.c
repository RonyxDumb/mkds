/* Decompiled C draft; module arm9_ov003; ROM address 021bd59c. No matching claim. */
#include "types.h"
#include "deps/021bd59c_FUN_021bd59c.h"

undefined4 FUN_021bd59c(ushort *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 local_24;
  ushort *local_20;
  int local_1c;
  int local_18;
  
  local_20 = param_1 + 4;
  local_24 = 0;
  iVar4 = (int)local_20 + ((int)(uint)*param_1 >> 8 | (uint)*param_1 << 8 & DAT_021bd744 & 0xffff);
  puVar5 = (ushort *)FUN_021bdc08(&local_20,iVar4,&local_1c,&local_18);
  puVar1 = DAT_021bd74c;
  iVar8 = DAT_021bd750;
  puVar2 = DAT_021bd764;
  while (puVar5 != (ushort *)0x0) {
    DAT_021bd74c = puVar1;
    DAT_021bd750 = iVar8;
    DAT_021bd764 = puVar2;
    switch(local_1c - DAT_021bd748) {
    case 0:
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      func_0x02134eb8(DAT_021bd74c,puVar5,local_18);
      local_24 = 1;
      break;
    case 1:
      puVar1[0xb] = (int)(uint)*puVar5 >> 8 | (uint)*puVar5 << 8 & DAT_021bd744 & 0xffff;
      break;
    case 2:
      uVar3 = *puVar5;
      uVar7 = (uint)uVar3 << 8 & DAT_021bd744;
      iVar9 = 0;
      do {
        *(uint *)(iVar8 + DAT_021bd754) = (int)(uint)uVar3 >> 8 | uVar7 & 0xffff;
        iVar8 = iVar8 + 0x28;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
      break;
    case 3:
      uVar3 = *puVar5;
      uVar7 = (uint)uVar3 << 8 & DAT_021bd744;
      iVar9 = 0;
      do {
        *(uint *)(iVar8 + DAT_021bd758) = (int)(uint)uVar3 >> 8 | uVar7 & 0xffff;
        iVar8 = iVar8 + 0x28;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
      break;
    case 4:
      puVar1[0xc] = (int)(uint)*puVar5 >> 8 | (uint)*puVar5 << 8 & DAT_021bd744 & 0xffff;
      break;
    case 5:
    case 6:
    case 7:
    case 8:
      func_0x02134de0(DAT_021bd760 + (local_1c - DAT_021bd75c) * 0x28,0,0x20);
      if (DAT_021bd74c[0x17] == 1) {
        iVar8 = DAT_021bd760 + (local_1c - DAT_021bd75c) * 0x28;
        iVar9 = 0;
        if (0 < local_18) {
          do {
            uVar3 = *puVar5;
            puVar5 = (ushort *)((int)puVar5 + 1);
            iVar6 = FUN_021bb2d8(iVar8,(int)(char)uVar3);
            iVar8 = iVar8 + iVar6;
            iVar9 = iVar9 + 1;
          } while (iVar9 < local_18);
        }
      }
      else {
        func_0x02134eb8(DAT_021bd760 + (local_1c - DAT_021bd75c) * 0x28,puVar5,local_18);
      }
      break;
    case 9:
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
      puVar2[8] = 0;
      puVar2[9] = 0;
      puVar2[10] = 0;
      puVar2[0xb] = 0;
      puVar2[0xc] = 0;
      puVar2[0xd] = 0;
      puVar2[0xe] = 0;
      puVar2[0xf] = 0;
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
      func_0x02134eb8(DAT_021bd764,puVar5,local_18);
    }
    puVar5 = (ushort *)FUN_021bdc08(&local_20,iVar4,&local_1c,&local_18);
    puVar1 = DAT_021bd74c;
    iVar8 = DAT_021bd750;
    puVar2 = DAT_021bd764;
  }
  DAT_021bd74c = puVar1;
  DAT_021bd750 = iVar8;
  DAT_021bd764 = puVar2;
  return local_24;
}

