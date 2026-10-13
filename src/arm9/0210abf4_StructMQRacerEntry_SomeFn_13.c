/* Decompiled C draft; module arm9; ROM address 0210abf4. No matching claim. */
#include "types.h"
#include "deps/0210abf4_StructMQRacerEntry_SomeFn_13.h"

void StructMQRacerEntry_SomeFn_13(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  int iStack_28;
  uint uVar4;
  
  uVar4 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 != 0) {
    do {
      if (*(char *)(uVar4 + 0x18) == '\x02') {
        uVar3 = IntrusiveListWrapper_NextItem(param_1 + 0xc,uVar4);
        StructMQRacerEntry_SomeFn_9(param_1,uVar4,0);
      }
      else {
        uVar3 = IntrusiveListWrapper_NextItem(param_1 + 0xc,uVar4);
      }
      uVar4 = uVar3;
    } while (uVar3 != 0);
  }
  bVar2 = true;
  uVar4 = iRam0210ad54 + 4U & 3;
  uVar3 = *(uint *)(iRam0210ad54 + 4U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((uVar4 != 2) && (uVar4 != 3)) {
    bVar2 = false;
  }
  if (!bVar2) {
    return;
  }
  if (param_3 != 0) {
    StructMQRacerEntry_SomeFn_6(param_1,2,param_2 * 0xe + 0xd,0x7f);
    return;
  }
  iVar1 = IsInRaceSceneNormalOrReplay();
  if (iVar1 != 0) {
    func_0212c6a0(&iStack_28);
    if (iStack_28 != 0) {
      func_0212c6f0(&iStack_28,0);
    }
    func_0212ec04(&iStack_28,0xffffffff,0xffffffff,0x6e);
    func_02105b28((undefined4)(uintptr_t)(&iStack_28),param_4);
    func_0212c688(&iStack_28);
    return;
  }
  return;
}

