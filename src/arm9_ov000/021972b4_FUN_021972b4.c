/* Decompiled C draft; module arm9_ov000; ROM address 021972b4. No matching claim. */
#include "types.h"
#include "deps/021972b4_FUN_021972b4.h"

undefined4 FUN_021972b4(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_88 [128];
  
  iVar1 = FUN_0218e460(*DAT_02197348,auStack_88,0x80,0);
  if ((((iVar1 == -1) && (iVar2 = FUN_0218e368(*DAT_02197348), iVar2 != -6)) && (iVar2 != -0x4c)) &&
     (iVar2 != -0x1a)) {
    FUN_0218e53c(*DAT_02197348);
    return 3;
  }
  auStack_88[iVar1] = 0;
  *DAT_02197350 = DAT_0219734c;
  FUN_021971ec((int)(uintptr_t)(auStack_88),iVar1);
  *DAT_02197354 = 0x73;
  iVar1 = FUN_021970fc((undefined4)(uintptr_t)(auStack_88));
  if (iVar1 == 0) {
    FUN_0218e53c(*DAT_02197348);
    return 5;
  }
  uVar3 = func_0x0213bf90();
  *DAT_02197358 = uVar3;
  return 0;
}

