/* Decompiled C draft; module arm9_ov000; ROM address 0218bf78. No matching claim. */
#include "types.h"
#include "deps/0218bf78_FUN_0218bf78.h"

undefined4 FUN_0218bf78(int param_1,char *param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  uint uVar10;
  int local_38;
  
  if (param_3 < 2) {
    return 4;
  }
  cVar1 = *param_2;
  bVar2 = param_2[1];
  param_2 = param_2 + 2;
  param_3 = param_3 + -2;
  local_38 = 0;
  if (bVar2 != 0) {
    do {
      iVar8 = FUN_0218d0c8(param_2,param_3);
      if (iVar8 == -1) {
        return 4;
      }
      pcVar9 = param_2 + iVar8;
      if (param_3 - iVar8 < 0xb) {
        return 4;
      }
      uVar5 = *(undefined4 *)pcVar9;
      uVar6 = *(undefined2 *)(pcVar9 + 4);
      uVar7 = *(uint *)(pcVar9 + 6);
      uVar3 = DAT_0218c0a8 >> 0x18;
      uVar4 = DAT_0218c0ac >> 8;
      uVar10 = uVar7 >> 8 & DAT_0218c0b0;
      pcVar9 = pcVar9 + 10;
      param_3 = (param_3 - iVar8) + -10;
      iVar8 = FUN_0218d0c8(pcVar9,param_3);
      if (iVar8 == -1) {
        return 4;
      }
      (**(code **)(param_1 + DAT_0218c0b8))
                (param_1,param_2,uVar5,uVar6,
                 (uVar7 & uVar3) << 0x18 | (uVar7 & uVar4) << 8 | uVar7 >> 0x18 | uVar10,pcVar9,
                 *(undefined4 *)(param_1 + DAT_0218c0b4));
      param_2 = pcVar9 + iVar8;
      param_3 = param_3 - iVar8;
      local_38 = local_38 + 1;
    } while (local_38 < (int)(uint)bVar2);
  }
  if (cVar1 != '\0') {
    (**(code **)(param_1 + DAT_0218c0b8))(param_1,0,0,0,0,0,*(undefined4 *)(param_1 + DAT_0218c0b4))
    ;
  }
  return 0;
}

