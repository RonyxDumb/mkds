/* Decompiled C draft; module arm9_ov001; ROM address 0218263c. No matching claim. */
#include "types.h"
#include "deps/0218263c_FUN_0218263c.h"

void FUN_0218263c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  if ((0 < *(int *)(param_2 + 0xb0)) && (*(short *)(param_2 + 0xa0) != 0)) {
    local_20 = 0x1e;
    func_0x01ff9048(0x14,&local_20,1);
    uVar1 = func_0x020e6cbc(param_2 + 4);
    func_0x01ff9048(0x19,uVar1,0xc);
    iVar3 = *(int *)(param_2 + 0xb0);
    if (iVar3 != DAT_021826f4) {
      local_1c = iVar3;
      local_18 = iVar3;
      local_14 = iVar3;
      func_0x01ff9048(0x1b,&local_1c,3);
    }
    func_0x01ff9048(0x1b,param_2 + 0x1c,3);
    uVar1 = func_0x020d3c44();
    func_0x0209b940(*DAT_021826f8,uVar1);
    uVar2 = *(ushort *)(param_2 + 0xa0);
    if (0x1e < uVar2) {
      uVar2 = 0x1f;
    }
    func_0x0209b9a4(*DAT_021826f8,uVar2);
    func_0x0209b688(*DAT_021826f8,*(uint *)(param_2 + 0xa4) & 0xffff);
    func_0x0209bbd0(param_1,*DAT_021826f8);
    func_0x0209bb2c(param_1,*DAT_021826f8,param_2);
  }
  return;
}

