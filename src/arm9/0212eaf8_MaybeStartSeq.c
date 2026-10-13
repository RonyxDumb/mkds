/* Decompiled C draft; module arm9; ROM address 0212eaf8. No matching claim. */
#include "types.h"
#include "deps/0212eaf8_MaybeStartSeq.h"

undefined4
MaybeStartSeq(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             int param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  iVar2 = func_0212c0e0((undefined4 *)(uintptr_t)(param_1),param_2,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = func_0212bfbc(param_2,iVar2);
  iVar4 = Sound_GetSbnkPointer(param_3,6,uVar3,0);
  if (iVar4 == 0) {
    iVar4 = NNSi_SndArcLoadSeq(param_6,1,uVar3,0);
    if (iVar4 == 0) {
      uVar1 = uStack_24 + 0x18U & 3;
      uVar5 = *(uint *)(uStack_24 + 0x18U & 0xfffffffc);
      func_0212c078(iVar2,uStack_24 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20),0,uStack_20)
      ;
      func_0212c668(param_1,*(undefined1 *)(param_5 + 6));
      func_0212c5c4(param_1,*(undefined1 *)(param_5 + 7));
      func_0212c478(param_1,param_6);
      return 1;
    }
    func_0212c0d4(iVar2);
    return 0;
  }
  func_0212c0d4(iVar2);
  return 0;
}

