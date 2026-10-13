/* Decompiled C draft; module arm7; ROM address 0600e4c4. No matching claim. */
#include "types.h"
#include "deps/0600e4c4_FUN_0600e4c4.h"

void FUN_0600e4c4(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  uint uVar10;
  
  uVar10 = *(uint *)(DAT_0600e694 & 0xfffffffc) >> (DAT_0600e694 & 3) * 8 |
           *(uint *)(DAT_0600e694 & 0xfffffffc) << (DAT_0600e694 & 3) * -8 + 0x20;
  uVar5 = uVar10 + 0x31c & 3;
  uVar4 = *(uint *)(uVar10 + 0x31c & 0xfffffffc);
  uVar1 = *(ushort *)(uVar10 + 0x52c);
  uVar7 = 0;
  uVar8 = 1;
  puVar3 = (ushort *)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  do {
    puVar9 = puVar3 + 0xe;
    if (*(ushort *)(uVar10 + 0x322) <= uVar8) {
      return;
    }
    if (*puVar9 == 0) {
LAB_0600e668:
      if (uVar1 <= uVar7) {
        return;
      }
    }
    else {
      uVar2 = puVar3[0x1a];
      if (((uVar2 == 0) || (uVar2 == DAT_0600e698)) || (puVar3[0x1a] = uVar2 - 1, puVar3[0x1a] != 0)
         ) {
LAB_0600e664:
        uVar7 = uVar7 + 1;
        goto LAB_0600e668;
      }
      if (*puVar9 < 0x20) {
LAB_0600e64c:
        *puVar9 = 0;
        *(short *)(uVar10 + 0x52c) = *(short *)(uVar10 + 0x52c) + -1;
        goto LAB_0600e664;
      }
      uVar5 = FUN_0600e918(uVar8);
      FUN_0600ebbc(uVar8 & 0xffff,0x20);
      FUN_060145f8(uVar8);
      if (*(short *)(uVar10 + 0x350) != 1) {
        if (uVar8 == *(ushort *)(uVar10 + 0x3cc)) {
          puVar6 = (undefined2 *)FUN_0601364c(puVar3 + 0x10,1);
          if (puVar6 != (undefined2 *)0x0) {
            *puVar6 = 1;
            FUN_060143ac();
            uVar7 = uVar7 + 1;
            goto LAB_0600e670;
          }
          FUN_0600a970(0x20);
          FUN_0600aa54();
          FUN_0600fa04(puVar3 + 0x10,1);
        }
        goto LAB_0600e64c;
      }
      if (uVar5 < 0x21) goto LAB_0600e64c;
      uVar5 = *(uint *)(DAT_0600e694 & 0xfffffffc) >> (DAT_0600e694 & 3) * 8 |
              *(uint *)(DAT_0600e694 & 0xfffffffc) << (DAT_0600e694 & 3) * -8 + 0x20;
      *(ushort *)(uVar5 + 0x534) = *(ushort *)(uVar5 + 0x534) | (ushort)(1 << (uVar8 & 0xff));
      FUN_0600eb40(uVar8 & 0xffff,0);
      FUN_0600eadc(uVar8);
      puVar6 = (undefined2 *)FUN_0601364c(puVar3 + 0x10,1);
      if (puVar6 == (undefined2 *)0x0) {
        FUN_0600fa04(puVar3 + 0x10,1);
        goto LAB_0600e64c;
      }
      *puVar6 = 1;
      FUN_060143ac();
      uVar7 = uVar7 + 1;
    }
LAB_0600e670:
    uVar8 = uVar8 + 1;
    puVar3 = puVar9;
  } while( true );
}

