/* Decompiled C draft; module arm9; ROM address 02139e20. No matching claim. */
#include "types.h"
#include "deps/02139e20_func_02139e20.h"

undefined4 func_02139e20(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  
  if ((param_1 < 1) || (7 < param_1)) {
    return 0xffffffff;
  }
  iVar1 = Os_Mutex_TryLock(uRam02139f5c);
  iVar4 = iRam02139f68;
  if (iVar1 == 0) {
    uVar6 = iRam02139f60 + 8U & 3;
    uVar5 = *(uint *)(iRam02139f60 + 8U & 0xfffffffc);
    uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x6c;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *(uint *)(iRam02139f64 + 0x1c) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    *(undefined4 *)(iVar4 + 0x1c) = 1;
  }
  else {
    uVar6 = iRam02139f60 + 8U & 3;
    uVar2 = *(uint *)(iRam02139f60 + 8U & 0xfffffffc);
    uVar5 = iRam02139f64 + 0x1cU & 3;
    uVar3 = *(uint *)(iRam02139f64 + 0x1cU & 0xfffffffc);
    uVar6 = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0x6c;
    uVar2 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if ((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) ==
        (uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20)) {
      uVar6 = iRam02139f68 + 0x1cU & 3;
      uVar5 = *(uint *)(iRam02139f68 + 0x1cU & 0xfffffffc);
      *(uint *)(iRam02139f68 + 0x1c) = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 1;
    }
    else {
      Os_Mutex_Lock(uRam02139f5c);
      iVar4 = iRam02139f68;
      uVar6 = iRam02139f60 + 8U & 3;
      uVar5 = *(uint *)(iRam02139f60 + 8U & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x6c;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(iRam02139f64 + 0x1c) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      *(undefined4 *)(iVar4 + 0x1c) = 1;
    }
  }
  uVar6 = iRam02139f6c + (param_1 + -1) * 4;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  pcVar7 = (code *)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  if (pcVar7 != (code *)0x1) {
    *(undefined4 *)(iRam02139f6c + (param_1 + -1) * 4) = 0;
  }
  uVar6 = iRam02139f68 + 0x1cU & 3;
  uVar5 = *(uint *)(iRam02139f68 + 0x1cU & 0xfffffffc);
  iVar4 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 1;
  *(int *)(iRam02139f68 + 0x1c) = iVar4;
  if (iVar4 == 0) {
    Os_Mutex_Unlock(uRam02139f5c);
  }
  if ((pcVar7 != (code *)0x1) && ((pcVar7 != (code *)0x0 || (param_1 != 1)))) {
    if (pcVar7 == (code *)0x0) {
      CheckZetaInvokeBeta(0);
    }
    (*pcVar7)(param_1);
    return 0;
  }
  return 0;
}

