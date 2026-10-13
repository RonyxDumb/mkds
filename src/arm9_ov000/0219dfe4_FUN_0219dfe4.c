/* Decompiled C draft; module arm9_ov000; ROM address 0219dfe4. No matching claim. */
#include "types.h"
#include "deps/0219dfe4_FUN_0219dfe4.h"

undefined4 FUN_0219dfe4(int param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  code *pcVar11;
  int iVar12;
  
  iVar12 = 0;
  bVar2 = false;
  iVar4 = FUN_0218b474(*(undefined4 *)(*DAT_0219e118 + 0xe4));
  piVar3 = DAT_0219e118;
  if (0 < iVar4) {
    do {
      uVar5 = FUN_0218b480(*(undefined4 *)(*piVar3 + 0xe4),iVar12);
      if (*(char *)(*piVar3 + 0x15) == '\0') {
        iVar6 = FUN_0218b2a8(uVar5,DAT_0219e11c,0);
        bVar1 = false;
        iVar10 = 1;
        iVar7 = *piVar3;
        iVar4 = iVar7;
        if (*(char *)(iVar7 + 0xd) != '\0') {
          do {
            if (iVar6 == *(int *)(iVar4 + 0xf8)) {
              FUN_0218b4d4(*(undefined4 *)(iVar7 + 0xe4),uVar5);
              iVar12 = iVar12 + -1;
              bVar1 = true;
              break;
            }
            iVar10 = iVar10 + 1;
            iVar4 = iVar4 + 4;
          } while (iVar10 <= (int)(uint)*(byte *)(iVar7 + 0xd));
        }
        if (!bVar1) goto LAB_0219e05c;
      }
      else {
LAB_0219e05c:
        pcVar11 = *(code **)(*piVar3 + DAT_0219e120);
        if (pcVar11 == (code *)0x0) {
          uVar9 = FUN_021a3448(0x80);
          FUN_0218b358(uVar5,DAT_0219e130,uVar9);
        }
        else {
          iVar4 = (*pcVar11)(iVar12,*(undefined4 *)(*piVar3 + DAT_0219e124));
          if (iVar4 < 1) {
            FUN_0218b4d4(*(undefined4 *)(*piVar3 + 0xe4),uVar5);
            iVar12 = iVar12 + -1;
            bVar2 = true;
          }
          else {
            if (DAT_0219e128 < iVar4) {
              iVar4 = DAT_0219e128;
            }
            uVar8 = FUN_021a3448(DAT_0219e12c);
            FUN_0218b358(uVar5,DAT_0219e130,iVar4 << 8 | uVar8);
          }
        }
      }
      iVar12 = iVar12 + 1;
      iVar4 = FUN_0218b474(*(undefined4 *)(*piVar3 + 0xe4));
    } while (iVar12 < iVar4);
  }
  if ((param_1 != 0) && (iVar4 = FUN_0218b474(*(undefined4 *)(*DAT_0219e118 + 0xe4)), iVar4 != 0)) {
    FUN_0218b464(*(undefined4 *)(*DAT_0219e118 + 0xe4),0,DAT_0219e130,0);
  }
  if ((bVar2) && (iVar4 = FUN_0218b474(*(undefined4 *)(*DAT_0219e118 + 0xe4)), iVar4 == 0)) {
    return 0;
  }
  return 1;
}

