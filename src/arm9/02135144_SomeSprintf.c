/* Decompiled C draft; module arm9; ROM address 02135144. No matching claim. */
#include "types.h"
#include "deps/02135144_SomeSprintf.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 SomeSprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar1 = func_0213c94c(uRam02135240,0xffffffff);
  if (iVar1 < 0) {
    iVar2 = Os_Mutex_TryLock(uRam02135244);
    iVar1 = iRam02135250;
    if (iVar2 == 0) {
      uVar7 = iRam02135248 + 8U & 3;
      uVar6 = *(uint *)(iRam02135248 + 8U & 0xfffffffc);
      uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x6c;
      uVar6 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      *(uint *)(iRam0213524c + 0xc) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
      *(undefined4 *)(iVar1 + 0xc) = 1;
    }
    else {
      uVar7 = iRam02135248 + 8U & 3;
      uVar3 = *(uint *)(iRam02135248 + 8U & 0xfffffffc);
      uVar6 = iRam0213524c + 0xcU & 3;
      uVar5 = *(uint *)(iRam0213524c + 0xcU & 0xfffffffc);
      uVar7 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) + 0x6c;
      uVar3 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) ==
          (uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20)) {
        uVar7 = iRam02135250 + 0xcU & 3;
        uVar6 = *(uint *)(iRam02135250 + 0xcU & 0xfffffffc);
        *(uint *)(iRam02135250 + 0xc) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 1;
      }
      else {
        Os_Mutex_Lock(uRam02135244);
        iVar1 = iRam02135250;
        uVar7 = iRam02135248 + 8U & 3;
        uVar6 = *(uint *)(iRam02135248 + 8U & 0xfffffffc);
        uVar7 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x6c;
        uVar6 = uVar7 & 3;
        uVar7 = *(uint *)(uVar7 & 0xfffffffc);
        *(uint *)(iRam0213524c + 0xc) = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
        *(undefined4 *)(iVar1 + 0xc) = 1;
      }
    }
    uVar4 = SomeVsnprintf(uRam02135254,uRam02135240,(char *)(uintptr_t)(param_1),(uint)(uintptr_t)(&uStack_c));
    uVar7 = iRam02135250 + 0xcU & 3;
    uVar6 = *(uint *)(iRam02135250 + 0xcU & 0xfffffffc);
    iVar1 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) - 1;
    *(int *)(iRam02135250 + 0xc) = iVar1;
    if (iVar1 == 0) {
      Os_Mutex_Unlock(uRam02135244);
    }
    return uVar4;
  }
  return 0xffffffff;
}

