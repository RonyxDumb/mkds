/* Decompiled C draft; module arm9_ov000; ROM address 0218c550. No matching claim. */
#include "types.h"
#include "deps/0218c550_FUN_0218c550.h"

int FUN_0218c550(int param_1,undefined4 param_2,byte *param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  byte *pbVar10;
  int local_20;
  ushort local_1a;
  undefined4 local_18;
  
  bVar3 = *param_3;
  FUN_0218af24(param_2,bVar3);
  puVar9 = (ushort *)(param_3 + 5);
  iVar8 = param_4 + -5;
  if ((bVar3 & 0x10) != 0) {
    puVar9 = (ushort *)(param_3 + 7);
    iVar8 = param_4 + -7;
  }
  if ((bVar3 & 2) == 0) {
    local_18 = 0;
  }
  else {
    local_18 = *(undefined4 *)puVar9;
    puVar9 = puVar9 + 2;
    iVar8 = iVar8 + -4;
  }
  if ((bVar3 & 0x20) == 0) {
    local_1a = *(ushort *)(param_1 + DAT_0218c73c);
  }
  else {
    local_1a = *puVar9;
    puVar9 = puVar9 + 1;
    iVar8 = iVar8 + -2;
  }
  FUN_0218af1c(param_2,local_18,local_1a);
  if ((bVar3 & 8) != 0) {
    uVar1 = *(undefined4 *)puVar9;
    puVar9 = puVar9 + 2;
    iVar8 = iVar8 + -4;
    FUN_0218af18(param_2,uVar1);
  }
  if ((bVar3 & 0x40) != 0) {
    iVar4 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 8)));
    local_20 = 0;
    if (0 < iVar4) {
      do {
        puVar5 = (undefined4 *)FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 8)),local_20);
        iVar6 = puVar5[1];
        if (iVar6 == 0) {
          if (param_5 == 0) {
            uVar7 = 0xff;
          }
          else {
            uVar7 = (uint)(byte)*puVar9;
            puVar9 = (ushort *)((int)puVar9 + 1);
            iVar8 = iVar8 + -1;
          }
          if (uVar7 == 0xff) {
            FUN_0218b380(param_2,*puVar5,(undefined4)(uintptr_t)(puVar9));
            iVar6 = func_0x0213a434(puVar9);
            puVar9 = (ushort *)((int)puVar9 + iVar6 + 1);
            iVar8 = iVar8 - (iVar6 + 1);
          }
          else {
            FUN_0218b380(param_2,*puVar5,*(undefined4 *)(param_1 + uVar7 * 4 + 0x84));
          }
        }
        else if (iVar6 == 1) {
          FUN_0218b358(param_2,*puVar5,(byte)*puVar9);
          puVar9 = (ushort *)((int)puVar9 + 1);
          iVar8 = iVar8 + -1;
        }
        else if (iVar6 == 2) {
          FUN_0218b358(param_2,*puVar5,
                       (int)(uint)*puVar9 >> 8 | (uint)*puVar9 << 8 & DAT_0218c740 & 0xffff);
          puVar9 = puVar9 + 1;
          iVar8 = iVar8 + -2;
        }
        local_20 = local_20 + 1;
      } while (local_20 < iVar4);
    }
    bVar2 = FUN_0218af10(param_2);
    FUN_0218af14(param_2,bVar2 | 1);
  }
  if ((bVar3 & 0x80) != 0) {
    for (; ((byte)*puVar9 != 0 && (0 < iVar8)); iVar8 = (iVar8 - (iVar4 + 1)) - (iVar6 + 1)) {
      iVar4 = func_0x0213a434(puVar9);
      pbVar10 = (byte *)((int)puVar9 + iVar4 + 1);
      FUN_0218b380(param_2,(undefined4)(uintptr_t)(puVar9),(undefined4)(uintptr_t)(pbVar10));
      iVar6 = func_0x0213a434(pbVar10);
      puVar9 = (ushort *)(pbVar10 + iVar6 + 1);
    }
    iVar8 = iVar8 + -1;
    bVar3 = FUN_0218af10(param_2);
    FUN_0218af14(param_2,bVar3 | 2);
  }
  return param_4 - iVar8;
}

