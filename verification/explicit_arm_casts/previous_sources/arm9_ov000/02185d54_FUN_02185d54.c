/* Decompiled C draft; module arm9_ov000; ROM address 02185d54. No matching claim. */
#include "types.h"
#include "deps/02185d54_FUN_02185d54.h"

undefined4 FUN_02185d54(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14 [2];
  
  local_14[0] = 0;
  FUN_021866b8(*DAT_02185eb0 + DAT_02185eb4,0x20,DAT_02185eb8);
  iVar2 = func_0x0213bf90();
  if (*DAT_02185ebc == 0x22) {
    *(undefined4 *)(*DAT_02185eb0 + 8) = DAT_02185ec0;
    return 0xb;
  }
  if (iVar2 != 200) {
    *(int *)(*DAT_02185eb0 + 8) = iVar2 + DAT_02185ec4;
    return 0x11;
  }
  iVar2 = FUN_02186674(*DAT_02185eb0 + DAT_02185eb4,0x20,DAT_02185ec8,*DAT_02185eb0 + 0xc,4);
  if (iVar2 < 1) {
    *(undefined4 *)(*DAT_02185eb0 + 8) = DAT_02185ec0;
    return 0xd;
  }
  iVar2 = func_0x0213bfa4(*DAT_02185eb0 + 0xc,local_14,10);
  iVar4 = *DAT_02185eb0;
  iVar3 = func_0x0213a434(iVar4 + 0xc);
  if (local_14[0] != iVar4 + 0xc + iVar3) {
    *(undefined4 *)(iVar4 + 8) = DAT_02185ec0;
    return 0xb;
  }
  *(int *)(iVar4 + 8) = iVar2 + DAT_02185ecc;
  piVar1 = DAT_02185eb0;
  if (iVar2 < 100) {
    *(undefined1 *)(*DAT_02185eb0 + 0x52) = 0;
    *(undefined1 *)(*piVar1 + 0x1f) = 0;
    *(undefined1 *)(*piVar1 + DAT_02185ed0) = 0;
    *(undefined1 *)(*piVar1 + 0x10) = 0;
    *(undefined1 *)(*piVar1 + DAT_02185ed4) = 0;
    FUN_02186674(*piVar1 + DAT_02185eb4,0x20,DAT_02185edc,*piVar1 + 0x52,DAT_02185ed8);
    FUN_02186674(*DAT_02185eb0 + DAT_02185eb4,0x20,DAT_02185ee0,*DAT_02185eb0 + 0x1f,0x33);
    FUN_02186674(*DAT_02185eb0 + DAT_02185eb4,0x20,DAT_02185ee4,*DAT_02185eb0 + DAT_02185ed0,9);
    FUN_02186674(*DAT_02185eb0 + DAT_02185eb4,0x20,DAT_02185ee8,*DAT_02185eb0 + 0x10,0xf);
    FUN_02186634(*DAT_02185eb0 + DAT_02185eb4,0x20,DAT_02185eec,*DAT_02185eb0 + DAT_02185ed4,0x41);
    *(undefined1 *)(*DAT_02185eb0 + DAT_02185ef0) = 0;
  }
  return 0;
}

