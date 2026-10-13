/* Decompiled C draft; module arm9_ov000; ROM address 021ad3b8. No matching claim. */
#include "types.h"
#include "deps/021ad3b8_FUN_021ad3b8.h"

int FUN_021ad3b8(uint param_1,int param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint local_18;
  
  uVar9 = func_0x0200f5ac();
  puVar2 = DAT_021ad5fc;
  iVar8 = 0;
  do {
    while( true ) {
      iVar5 = (*(code *)*DAT_021ad61c)();
      if (((iVar5 == 0) || (iVar8 != 0)) ||
         (uVar10 = func_0x0200f5ac(),
         (param_2 + 1) * 0xf <=
         (int)(((uint)uVar10 >> 0x10 | (int)((ulonglong)uVar10 >> 0x20) << 0x10) -
              ((uint)uVar9 >> 0x10 | (int)((ulonglong)uVar9 >> 0x20) << 0x10)))) {
        return iVar8;
      }
      iVar5 = FUN_021adbac();
      if (iVar5 != 0) break;
      FUN_021b04d4();
    }
    pcVar3 = (char *)FUN_021adf78(&local_18);
    if (((0xf0 < local_18) && (*pcVar3 == '\x02')) &&
       ((param_1 ==
         (((int)(uint)*(ushort *)(pcVar3 + 4) >> 8 | (*(ushort *)(pcVar3 + 4) & 0xff) << 8) << 0x10
         | (int)(uint)*(ushort *)(pcVar3 + 6) >> 8 | (*(ushort *)(pcVar3 + 6) & 0xff) << 8) &&
        (iVar5 = FUN_021b0014(pcVar3 + 0x1c,DAT_021ad600), iVar5 == 0)))) {
      iVar8 = 3;
      uVar4 = CONCAT22(CONCAT11(pcVar3[0x10],pcVar3[0x11]),CONCAT11(pcVar3[0x12],pcVar3[0x13]));
      if (((pcVar3[0xec] == 'c') && (pcVar3[0xed] == -0x7e)) &&
         ((pcVar3[0xee] == 'S' && (pbVar7 = (byte *)(pcVar3 + 0xf0), pcVar3[0xef] == 'c')))) {
        while (pbVar6 = pbVar7, pbVar6 < pcVar3 + local_18) {
          bVar1 = *pbVar6;
          pbVar7 = pbVar6 + 1;
          if (bVar1 == 0xff) break;
          if (bVar1 != 0) {
            if (bVar1 < 0x34) {
              if (bVar1 < 0x33) {
                if ((bVar1 < 7) && (bVar1 != 0)) {
                  if (bVar1 == 1) {
                    *DAT_021ad604 =
                         CONCAT22(CONCAT11(pbVar6[2],pbVar6[3]),CONCAT11(pbVar6[4],pbVar6[5]));
                  }
                  else if (bVar1 == 3) {
                    *DAT_021ad608 =
                         CONCAT22(CONCAT11(pbVar6[2],pbVar6[3]),CONCAT11(pbVar6[4],pbVar6[5]));
                  }
                  else if (bVar1 == 6) {
                    if (*pbVar7 < 8) {
                      puVar2[1] = 0;
                    }
                    else {
                      puVar2[1] = CONCAT22(CONCAT11(pbVar6[6],pbVar6[7]),
                                           CONCAT11(pbVar6[8],pbVar6[9]));
                    }
                    *puVar2 = CONCAT22(CONCAT11(pbVar6[2],pbVar6[3]),CONCAT11(pbVar6[4],pbVar6[5]));
                  }
                }
              }
              else {
                *DAT_021ad60c =
                     CONCAT22(CONCAT11(pbVar6[2],pbVar6[3]),CONCAT11(pbVar6[4],pbVar6[5]));
              }
            }
            else if (bVar1 < 0x36) {
              if (bVar1 == 0x35) {
                if (pbVar6[2] == 2) {
                  *DAT_021ad610 = uVar4;
                  iVar8 = 1;
                }
                else if (pbVar6[2] == 5) {
                  *DAT_021ad614 = uVar4;
                  iVar8 = 2;
                }
              }
            }
            else if (bVar1 == 0x36) {
              *DAT_021ad618 = CONCAT22(CONCAT11(pbVar6[2],pbVar6[3]),CONCAT11(pbVar6[4],pbVar6[5]));
            }
            pbVar7 = pbVar7 + *pbVar7 + 1;
          }
        }
      }
    }
    FUN_021adf00(local_18);
  } while( true );
}

