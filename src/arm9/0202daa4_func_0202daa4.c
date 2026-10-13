/* Decompiled C draft; module arm9; ROM address 0202daa4. No matching claim. */
#include "types.h"
#include "deps/0202daa4_func_0202daa4.h"

void func_0202daa4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = func_0202dd80();
  if (iVar1 == 0) {
    uVar3 = *(uint *)(*piRam0202daf8 + param_1 * 4 + iRam0202dafc);
    uVar2 = func_0202ddec();
    ReadSaveDataSection_PersonalGhost_from_thumb(uVar3 & 0xff,uVar2);
    return;
  }
  iVar1 = func_0202ddb0();
  uVar3 = *(uint *)(*piRam0202daf8 + (param_1 - iVar1) * 4 + iRam0202db00);
  uVar2 = func_0202ddd8();
  ReadSaveDataSection_DownloadGhost_from_thumb(uVar3 & 0xff,uVar2);
  return;
}

