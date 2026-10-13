/* Decompiled C draft; module arm9_ov003; ROM address 021c73cc. No matching claim. */
#include "types.h"
#include "deps/021c73cc_FUN_021c73cc.h"

void FUN_021c73cc(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  
  iVar6 = FUN_021c1ca0();
  if (iVar6 < 1) {
    if (iVar6 == 0) {
      return;
    }
switchD_021c73f6_default:
    if ((*(char *)(*DAT_021c75d4 + 0x14) != '\x03') || (iVar7 = FUN_021c735c(0x1a), iVar7 == 0)) {
      FUN_021cdc10(1);
      piVar5 = DAT_021c75d4;
      iVar10 = *DAT_021c75d4 + 8;
      iVar7 = (uint)*(byte *)(*DAT_021c75d4 + 0x14) * 3;
      pcVar9 = (char *)(iVar10 + iVar7 + 2);
      cVar2 = *(char *)(iVar10 + iVar7 + 2);
      cVar4 = (char)iVar6;
      if (cVar2 == '\0') {
        *pcVar9 = cVar4;
      }
      else {
        pcVar11 = (char *)(iVar10 + iVar7 + 1);
        cVar3 = *(char *)(iVar10 + iVar7 + 1);
        if (cVar3 == '\0') {
          *pcVar11 = cVar2;
          *pcVar9 = cVar4;
          iVar6 = FUN_021c735c(0x1a);
          if (iVar6 != 0) {
            iVar6 = *piVar5;
            bVar1 = *(byte *)(iVar6 + 0x14);
            if (bVar1 < 3) {
              *(byte *)(iVar6 + 0x14) = bVar1 + 1;
            }
          }
        }
        else {
          *(char *)(iVar10 + iVar7) = cVar3;
          *pcVar11 = *pcVar9;
          *pcVar9 = cVar4;
          iVar6 = *piVar5;
          bVar1 = *(byte *)(iVar6 + 0x14);
          if (bVar1 < 3) {
            *(byte *)(iVar6 + 0x14) = bVar1 + 1;
          }
        }
      }
      FUN_021c1c90(1);
      if (*(byte *)(*DAT_021c75d4 + 0x14) < 3) {
        FUN_021c1c70(1);
      }
      else {
        FUN_021c1c70(0);
      }
      if ((*(char *)(*DAT_021c75d4 + 0x14) == '\x03') && (iVar6 = FUN_021c735c(0x1a), iVar6 != 0)) {
        FUN_021c1c80(0);
      }
    }
  }
  else {
    switch(iVar6) {
    case 0x10:
      if ((*(char *)(*DAT_021c75d4 + 0x14) != '\0') || (*(char *)(*DAT_021c75d4 + 10) != '\0')) {
        FUN_021cdc10(3);
        iVar6 = *DAT_021c75d4;
        if (*(char *)(iVar6 + (uint)*(byte *)(iVar6 + 0x14) * 3 + 10) == '\0') {
          *(byte *)(iVar6 + 0x14) = *(byte *)(iVar6 + 0x14) - 1;
        }
        func_0x0214d168(*DAT_021c75d4 + 8 + (uint)*(byte *)(*DAT_021c75d4 + 0x14) * 3,0);
        if ((*(char *)(*DAT_021c75d4 + 0x14) == '\0') && (*(char *)(*DAT_021c75d4 + 10) == '\0')) {
          FUN_021c1c90(0);
        }
        FUN_021c1c80(1);
        FUN_021c1c70(0);
      }
      break;
    case 0x11:
      uVar8 = (uint)*(byte *)(*DAT_021c75d4 + 0x14);
      if ((uVar8 < 3) && (*(char *)(*DAT_021c75d4 + uVar8 * 3 + 10) != '\0')) {
        FUN_021cdc10(1);
        *(char *)(*DAT_021c75d4 + 0x14) = *(char *)(*DAT_021c75d4 + 0x14) + '\x01';
        FUN_021c1c70(0);
      }
      break;
    case 0x12:
      *(undefined1 *)(*DAT_021c75d4 + 0x15) = 0;
      FUN_021cdc10(7);
      FUN_021c212c(DAT_021c75d8);
      return;
    case 0x13:
      iVar6 = FUN_021c6f64();
      if (iVar6 == 0) {
        *(undefined1 *)(*DAT_021c75d4 + 0x15) = 2;
        FUN_021cdc10(9);
      }
      else {
        FUN_021cdc10(6);
        *(undefined1 *)(*DAT_021c75d4 + 0x15) = 1;
      }
      piVar5 = DAT_021c75d4;
      *(undefined1 *)(*DAT_021c75d4 + 0x14) = 3;
      **(uint **)(*piVar5 + 4) = **(uint **)(*piVar5 + 4) & DAT_021c75dc | DAT_021c75e0;
      FUN_021c7160();
      FUN_021c7050();
      FUN_021c212c(DAT_021c75d8);
      return;
    default:
      goto switchD_021c73f6_default;
    }
  }
  FUN_021c71a0();
  FUN_021c7160();
  return;
}

