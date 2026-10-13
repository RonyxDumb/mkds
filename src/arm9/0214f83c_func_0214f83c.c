/* Decompiled C draft; module arm9; ROM address 0214f83c. No matching claim. */
#include "types.h"
#include "deps/0214f83c_func_0214f83c.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_0214f83c(uint param_1,ushort param_2,ushort param_3)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int local_34;
  int local_30;
  uint local_2c;
  
  bVar3 = false;
  func_0214f51c(*(uint *)(uRam0214fa58 & 0xfffffffc) >> (uRam0214fa58 & 3) * 8 |
                *(uint *)(uRam0214fa58 & 0xfffffffc) << (uRam0214fa58 & 3) * -8 + 0x20);
  uVar1 = *puRam0214fa5c;
  *puRam0214fa5c = 0;
  uVar7 = Os_DisableIrq();
  uVar8 = Os_DisableIrqHandler(uRam0214fa60);
  SetIE(0x40000);
  Os_RestoreIrq(uVar7);
  *puRam0214fa5c = 1;
  if (((param_1 & 8) != 0) && (*psRam0214fa64 == 2)) {
    param_1 = param_1 & 0xfffffff7;
  }
  if (((param_1 & 0x10) != 0) && (iVar9 = MaybeDebuggerOrAddonCode_from_thumb(), iVar9 == 0)) {
    param_1 = param_1 & 0xffffffef;
  }
  uVar6 = _DAT_04000000;
  uVar4 = (uint)puRam0214fa68 & 3;
  uVar12 = *(uint *)((uint)puRam0214fa68 & 0xfffffffc);
  iVar9 = PM_GetLCDPower();
  Pm_GetBacklightStatus(&local_34,&local_30);
  func_0214fba8(2,0);
  do {
  } while ((*(uint *)(uRam0214fa6c & 0xfffffffc) >> (uRam0214fa6c & 3) * 8 |
           *(uint *)(uRam0214fa6c & 0xfffffffc) << (uRam0214fa6c & 3) * -8 + 0x20) ==
           (*(uint *)(uRam0214fa6c & 0xfffffffc) >> (uRam0214fa6c & 3) * 8 |
           *(uint *)(uRam0214fa6c & 0xfffffffc) << (uRam0214fa6c & 3) * -8 + 0x20));
  uVar5 = uRam0214fa6c & 3;
  uVar10 = *(uint *)(uRam0214fa6c & 0xfffffffc);
  _DAT_04000000 = _DAT_04000000 & 0xfffcffff;
  *puRam0214fa68 =
       (*(uint *)((uint)puRam0214fa68 & 0xfffffffc) >> ((uint)puRam0214fa68 & 3) * 8 |
       *(uint *)((uint)puRam0214fa68 & 0xfffffffc) << ((uint)puRam0214fa68 & 3) * -8 + 0x20) &
       0xfffeffff;
  do {
  } while ((uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20) ==
           (*(uint *)(uRam0214fa6c & 0xfffffffc) >> (uRam0214fa6c & 3) * 8 |
           *(uint *)(uRam0214fa6c & 0xfffffffc) << (uRam0214fa6c & 3) * -8 + 0x20));
  local_2c = *(uint *)(uRam0214fa6c & 0xfffffffc) >> (uRam0214fa6c & 3) * 8 |
             *(uint *)(uRam0214fa6c & 0xfffffffc) << (uRam0214fa6c & 3) * -8 + 0x20;
  do {
  } while (local_2c ==
           (*(uint *)(uRam0214fa6c & 0xfffffffc) >> (uRam0214fa6c & 3) * 8 |
           *(uint *)(uRam0214fa6c & 0xfffffffc) << (uRam0214fa6c & 3) * -8 + 0x20));
  do {
    iVar11 = func_0214fefc((param_1 | local_34 << 5 | local_30 << 6) & 0xffff,param_2 | param_3);
  } while (iVar11 != 0);
  Os_Halt();
  Os_SpinWait(uRam0214fa70);
  if (((param_1 & 8) != 0) &&
     (((*(uint *)(uRam0214fa74 & 0xfffffffc) >> (uRam0214fa74 & 3) * 8 |
       *(uint *)(uRam0214fa74 & 0xfffffffc) << (uRam0214fa74 & 3) * -8 + 0x20) & 0x100000) != 0)) {
    bVar3 = true;
  }
  if (!bVar3) {
    if (iVar9 == 1) {
      PM_SetLCDPower(1,1,1,0);
    }
    else {
      func_0214fc74(1);
    }
    _DAT_04000000 = uVar6;
    *puRam0214fa68 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
  }
  Os_DisableIrq();
  SetIE(uVar8);
  Os_RestoreIrq(uVar7);
  uVar2 = *puRam0214fa5c;
  *puRam0214fa5c = uVar1;
  if (bVar3) {
    func_0214fb54(uVar2);
  }
  func_0214f51c(*(uint *)(uRam0214fa78 & 0xfffffffc) >> (uRam0214fa78 & 3) * 8 |
                *(uint *)(uRam0214fa78 & 0xfffffffc) << (uRam0214fa78 & 3) * -8 + 0x20);
  return;
}

