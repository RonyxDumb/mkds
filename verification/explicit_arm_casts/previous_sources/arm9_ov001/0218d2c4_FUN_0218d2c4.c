/* Decompiled C draft; module arm9_ov001; ROM address 0218d2c4. No matching claim. */
#include "types.h"
#include "deps/0218d2c4_FUN_0218d2c4.h"

void FUN_0218d2c4(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x70),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x74));
  func_0x0209b688(*(undefined4 *)(param_1 + DAT_0218d368),0);
  piVar1 = (int *)func_0x02100138(DAT_0218d36c);
  if (piVar1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar5 = 0;
        (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1) &&
        (iVar3 = *(int *)(*piVar1 + iVar5), iVar3 != 0)); iVar5 = iVar5 + 4) {
      FUN_02187218(iVar3,1,0);
      FUN_02188d64(iVar3,*(undefined4 *)(*(int *)(iVar3 + 0xa0) + 0x70),
                   *(undefined4 *)(*(int *)(iVar3 + 0xa0) + 0x74));
      func_0x0209b688(*(undefined4 *)(iVar3 + DAT_0218d368),0);
      iVar4 = iVar4 + 1;
    }
  }
  local_24 = *DAT_0218d370;
  local_1c = DAT_0218d370[2];
  local_18 = DAT_0218d370[3];
  local_20 = param_1 + 4;
  local_18 = func_0x020d4ef4(local_20,local_18,&stack0xffffffec,DAT_0218d370 + 4);
  uVar2 = func_0x02108e7c();
  func_0x0210b734(&local_24,uVar2);
  return;
}

