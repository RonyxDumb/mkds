/* Decompiled C draft; module arm9_ov001; ROM address 021882b8. No matching claim. */
#include "types.h"
#include "deps/021882b8_FUN_021882b8.h"

void FUN_021882b8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int extraout_r1;
  undefined4 *puVar8;
  
  if (*(int *)(*DAT_02188420 + 8) == 4) {
    iVar2 = func_0x020a1084((short)*(char *)(*DAT_02188420 + 0x62));
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 == 0) {
    if (*(int *)(*DAT_02188420 + 8) == 4) {
      uVar3 = FUN_02181b54();
    }
    else {
      uVar3 = 0;
    }
    while( true ) {
      if (*(int *)(*DAT_02188420 + 8) == 4) {
        uVar6 = FUN_02181b30();
      }
      else {
        uVar6 = 0;
      }
      if (uVar6 < uVar3) break;
      if (*(int *)(*DAT_02188420 + 8) == 4) {
        iVar2 = FUN_02181b68(uVar3);
      }
      else {
        iVar2 = 0;
      }
      piVar4 = (int *)func_0x02100138(DAT_02188424);
      FUN_02188e88(iVar2);
      *(undefined4 *)(iVar2 + DAT_02188428) = 0;
      *(undefined4 *)(iVar2 + DAT_0218842c) = 3;
      iVar5 = DAT_02188430;
      *(undefined4 *)(iVar2 + DAT_02188430) = 0;
      iVar1 = DAT_02188434;
      *(undefined4 *)(iVar2 + DAT_02188434) = *(undefined4 *)(iVar2 + iVar5);
      *(undefined4 *)(iVar2 + DAT_02188438) = *(undefined4 *)(iVar2 + iVar1);
      *(undefined4 *)(iVar2 + DAT_0218843c) = 0;
      iVar5 = DAT_02188440;
      *(undefined4 *)(iVar2 + DAT_02188440) = 0;
      iVar1 = DAT_02188444;
      *(undefined4 *)(iVar2 + DAT_02188444) = *(undefined4 *)(iVar2 + iVar5);
      *(undefined4 *)(iVar2 + DAT_02188448) = *(undefined4 *)(iVar2 + iVar1);
      *(undefined4 *)(iVar2 + DAT_0218844c) = 0;
      iVar5 = DAT_02188450;
      *(undefined4 *)(iVar2 + DAT_02188450) = 0;
      iVar1 = DAT_02188454;
      *(undefined4 *)(iVar2 + DAT_02188454) = *(undefined4 *)(iVar2 + iVar5);
      *(undefined4 *)(iVar2 + DAT_02188458) = *(undefined4 *)(iVar2 + iVar1);
      iVar5 = DAT_0218845c;
      *(undefined4 *)(iVar2 + DAT_0218845c) = 0;
      iVar1 = DAT_02188460;
      *(undefined4 *)(iVar2 + DAT_02188460) = *(undefined4 *)(iVar2 + iVar5);
      *(undefined4 *)(iVar2 + DAT_02188464) = *(undefined4 *)(iVar2 + iVar1);
      iVar5 = DAT_0218846c;
      *(undefined4 *)(iVar2 + DAT_0218846c) = DAT_02188468;
      *(undefined4 *)(iVar2 + DAT_02188470) = *(undefined4 *)(iVar2 + iVar5);
      *(undefined4 *)(iVar2 + DAT_02188474) = 0;
      if (*(int *)(*DAT_02188420 + 8) == 4) {
        iVar5 = FUN_02181b54();
      }
      else {
        iVar5 = 0;
      }
      if ((int)(uVar3 - iVar5) < (int)(uint)*(ushort *)(piVar4 + 1)) {
        if (*(int *)(*DAT_02188420 + 8) == 4) {
          iVar5 = FUN_02181b54();
        }
        else {
          iVar5 = 0;
        }
        puVar8 = *(undefined4 **)(*(int *)(*piVar4 + (uVar3 - iVar5) * 4) + 0x9c);
        uVar7 = puVar8[1];
        *(undefined4 *)(iVar2 + 4) = *puVar8;
        *(undefined4 *)(iVar2 + 8) = uVar7;
        *(undefined4 *)(iVar2 + 0xc) = puVar8[2];
        if (*(int *)(*DAT_02188420 + 8) == 4) {
          iVar5 = FUN_02181b54();
        }
        else {
          iVar5 = 0;
        }
        iVar5 = *(int *)(*(int *)(*(int *)(*piVar4 + (uVar3 - iVar5) * 4) + 0x9c) + 0x10);
        func_0x02133048(iVar5,iVar5 >> 0x1f,DAT_02188478,0xb6);
        *(uint *)(iVar2 + DAT_02188480) = (uint)((extraout_r1 + DAT_0218847c) * 0x10) >> 0x10;
      }
      uVar3 = uVar3 + 1 & 0xffff;
    }
  }
  func_0x020a305c();
  return;
}

