/* Decompiled C draft; module arm9; ROM address 0210ca4c. No matching claim. */
#include "types.h"
#include "deps/0210ca4c_func_0210ca4c.h"

undefined4 func_0210ca4c(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int local_48;
  uint local_44;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  
  uVar5 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  local_44 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  local_28 = 0;
  local_34 = 0;
  local_2c = 0;
  local_30 = 0;
  local_48 = param_1;
  if (local_44 == 0) {
    local_38 = 0;
    local_34 = 0x7f;
    local_2c = 0x7f;
    local_30 = 0;
  }
  else {
    local_38 = (*(code *)(*(uint *)(uRam0210cc2c & 0xfffffffc) >> (uRam0210cc2c & 3) * 8 |
                         *(uint *)(uRam0210cc2c & 0xfffffffc) << (uRam0210cc2c & 3) * -8 + 0x20))
                         (&local_48);
    local_34 = (*(code *)(*(uint *)(uRam0210cc30 & 0xfffffffc) >> (uRam0210cc30 & 3) * 8 |
                         *(uint *)(uRam0210cc30 & 0xfffffffc) << (uRam0210cc30 & 3) * -8 + 0x20))
                         (&local_48);
    local_2c = local_34;
    local_30 = (*(code *)(*(uint *)(uRam0210cc34 & 0xfffffffc) >> (uRam0210cc34 & 3) * 8 |
                         *(uint *)(uRam0210cc34 & 0xfffffffc) << (uRam0210cc34 & 3) * -8 + 0x20))
                         (&local_48);
  }
  puVar2 = puRam0210cc38;
  if (local_34 < 1) {
    func_0210c0bc(param_1);
    return 0;
  }
  uVar5 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  iVar1 = local_2c;
  while (uVar5 != 0) {
    iVar6 = -1;
    local_2c = iVar1;
    if ((*(byte *)(uVar5 + 0x19) & 2) != 0) {
      iVar6 = func_0212d580(*(undefined1 *)(uVar5 + 0x18),*(undefined2 *)(uVar5 + 0x16));
      iVar6 = iVar1 + (*(byte *)(iVar6 + 4) - 0x40);
      if (iVar6 < 1) {
        iVar6 = 0;
      }
      else if (0x7e < iVar6) {
        iVar6 = 0x7f;
      }
      uVar3 = param_1 + 0x2cU & 3;
      uVar4 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
      (*(code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))(param_1,uVar5,iVar6);
      *(byte *)(uVar5 + 0x19) = *(byte *)(uVar5 + 0x19) & 0xfd;
    }
    iVar1 = local_2c;
    if (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 != 0 ||
        *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20 != 0) {
      if (iVar6 == -1) {
        iVar6 = func_0212d580(*(undefined1 *)(uVar5 + 0x18),*(undefined2 *)(uVar5 + 0x16));
        iVar6 = iVar1 + (*(byte *)(iVar6 + 4) - 0x40);
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        else if (0x7e < iVar6) {
          iVar6 = 0x7f;
        }
      }
      func_0212c678(uVar5,local_34);
      func_0212c5f4(uVar5,iVar6);
      func_0212c4f4(uVar5,*puVar2,local_30);
      uVar3 = param_1 + 0x30U & 3;
      uVar4 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
      (*(code *)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20))(param_1,uVar5,&local_48);
    }
    uVar5 = IntrusiveListWrapper_NextItem(param_1 + 0xc,uVar5);
    iVar1 = local_2c;
  }
  return 1;
}

