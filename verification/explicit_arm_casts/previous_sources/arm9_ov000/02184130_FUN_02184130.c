/* Decompiled C draft; module arm9_ov000; ROM address 02184130. No matching claim. */
#include "types.h"
#include "deps/02184130_FUN_02184130.h"

void FUN_02184130(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_24;
  int local_20;
  int local_1c [2];
  
  uVar4 = func_0x0204799c(DAT_021842f8);
  func_0x020b4934(&local_24,uVar4);
  uVar4 = func_0x0204799c(DAT_021842fc);
  func_0x020b47d8(&local_20,uVar4);
  uVar4 = func_0x0204799c(DAT_02184300);
  func_0x020b4a44(local_1c,uVar4);
  uVar4 = func_0x0204799c(DAT_02184304);
  *(undefined4 *)(*DAT_02184308 + DAT_0218430c) = uVar4;
  uVar4 = func_0x0204799c(DAT_02184310);
  *(undefined4 *)(*DAT_02184308 + DAT_02184314) = uVar4;
  uVar4 = func_0x0204799c(DAT_02184318);
  *(undefined4 *)(*DAT_02184308 + DAT_0218431c) = uVar4;
  uVar4 = func_0x0204799c(DAT_02184320);
  func_0x020b49bc(*DAT_02184308 + DAT_02184324,uVar4);
  uVar4 = func_0x0204799c(DAT_02184328);
  func_0x020b48b4(*DAT_02184308 + DAT_0218432c,uVar4);
  uVar4 = func_0x0204799c(DAT_02184330);
  func_0x020b4a44(*DAT_02184308 + DAT_02184334,uVar4);
  *DAT_02184338 = *DAT_02184338 & 0x43 | (ushort)DAT_0218433c;
  func_0x0214cfe4(0,*DAT_02184308 + 0xd4,DAT_02184340);
  func_0x0214cffc(local_20 + 0xc,*DAT_02184308 + 0xd4,DAT_02184344);
  func_0x02016468(0x17,0,*(undefined4 *)(local_24 + 0x14),*(undefined4 *)(local_24 + 0x10));
  func_0x02016468(0x1b,0,*DAT_02184308 + 0xd4,DAT_02184340);
  func_0x02016468(0x1f,0,*(undefined4 *)(local_1c[0] + 0xc),0x80);
  func_0x02016468(0x23,0,*(undefined4 *)(*(int *)(*DAT_02184308 + DAT_02184324) + 0x14),
                  *(undefined4 *)(*(int *)(*DAT_02184308 + DAT_02184324) + 0x10));
  func_0x02016468(0x1e,0,*(undefined4 *)(*(int *)(*DAT_02184308 + DAT_02184334) + 0xc),
                  *(undefined4 *)(*(int *)(*DAT_02184308 + DAT_02184334) + 8));
  piVar2 = DAT_02184308;
  iVar8 = 0;
  iVar7 = 0;
  iVar6 = 0;
  bVar1 = *DAT_02184348;
  do {
    uVar5 = (uint)*(ushort *)
                   (iVar7 + (uint)bVar1 * 2 + *(int *)(*(int *)(*piVar2 + DAT_02184334) + 0xc) +
                   0xc0);
    *(uint *)(*piVar2 + iVar6 + 0x58) = uVar5 & 0x1f;
    *(int *)(*piVar2 + iVar6 + 0x5c) = (int)(uVar5 & DAT_0218434c) >> 5;
    *(int *)(*piVar2 + iVar6 + 0x60) = (int)(uVar5 & DAT_02184350) >> 10;
    piVar3 = DAT_02184308;
    iVar7 = iVar7 + 2;
    iVar6 = iVar6 + 0xc;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 5);
  iVar6 = 0;
  iVar8 = 0;
  iVar7 = 0;
  bVar1 = DAT_02184348[1];
  do {
    uVar5 = (uint)*(ushort *)
                   (iVar8 + (uint)bVar1 * 2 + *(int *)(*(int *)(*piVar3 + DAT_02184334) + 0xc) +
                   0xc0);
    *(uint *)(*piVar3 + iVar7 + 0x94) = uVar5 & 0x1f;
    *(int *)(*piVar3 + iVar7 + 0x98) = (int)(uVar5 & DAT_0218434c) >> 5;
    *(int *)(*piVar3 + iVar7 + 0x9c) = (int)(uVar5 & DAT_02184350) >> 10;
    iVar8 = iVar8 + 2;
    iVar7 = iVar7 + 0xc;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  return;
}

