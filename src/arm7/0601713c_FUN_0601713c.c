/* Decompiled C draft; module arm7; ROM address 0601713c. No matching claim. */
#include "types.h"
#include "deps/0601713c_FUN_0601713c.h"

void FUN_0601713c(int param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int local_44 [2];
  short local_3c;
  ushort local_3a;
  undefined2 local_38;
  undefined2 local_2e;
  undefined4 local_28;
  
  uVar7 = *(uint *)(DAT_060172d0 & 0xfffffffc) >> (DAT_060172d0 & 3) * 8 |
          *(uint *)(DAT_060172d0 & 0xfffffffc) << (DAT_060172d0 & 3) * -8 + 0x20;
  uVar1 = *(ushort *)(param_1 + 6);
  if (((10 < uVar1) && (*(short *)(uVar7 + 0x350) == 1)) &&
     (iVar4 = FUN_06013528(param_1 + 0x1e,0x30), iVar4 == 0)) {
    uVar2 = *(undefined2 *)(param_1 + 2);
    uVar5 = FUN_0600e918(uVar2);
    if (uVar5 < 0x30) {
      iVar4 = FUN_0601364c(param_1 + 0x1e,6);
      if (iVar4 != 0) {
        FUN_060143ac();
      }
    }
    else {
      iVar4 = FUN_0600e918(uVar2);
      if (iVar4 == 0x40) {
        FUN_0600ebbc(uVar2,0x30);
        FUN_0600f79c(param_1 + 0x1e,1);
      }
      else {
        iVar4 = FUN_0600e840(uVar2);
        if (iVar4 != 0) {
          return;
        }
      }
      thunk_FUN_037fb24c(0,local_44,0x2c);
      local_44[0] = param_1 + 0x36;
      local_3c = uVar1 - 10;
      local_38 = 0x800;
      FUN_060161b4((uint)(uintptr_t)(local_44));
      uVar5 = (uint)*(ushort *)(param_1 + 0x2c);
      if ((((DAT_060172d4 & uVar5) == 0) &&
          ((sVar3 = *(short *)(uVar7 + 0x334), sVar3 != 0 || (-1 < (int)(uVar5 << 0x1b))))) &&
         ((sVar3 == 0 || ((int)((uint)*(ushort *)(param_1 + 0x2c) << 0x1b) < 0)))) {
        FUN_0600eac4(uVar2);
        if ((local_3a & 1) == 0) {
          uVar6 = 1;
        }
        else if ((local_3a & 4) == 0) {
          uVar6 = 0x12;
        }
        else {
          FUN_0600eaac(uVar2,local_2e);
          uVar6 = 0;
        }
      }
      else {
        uVar6 = 10;
      }
      iVar4 = FUN_060138e4(uVar2,uVar6,local_28);
      if (iVar4 != 0) {
        FUN_060143ac();
      }
    }
  }
  return;
}

