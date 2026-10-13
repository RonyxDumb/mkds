/* Decompiled C draft; module arm9; ROM address 0210823c. No matching claim. */
#include "types.h"
#include "deps/0210823c_LoopFn_Sound.h"

void LoopFn_Sound(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*(uint *)(uRam02108324 & 0xfffffffc) >> (uRam02108324 & 3) * 8 != 0 ||
      *(uint *)(uRam02108324 & 0xfffffffc) << (uRam02108324 & 3) * -8 + 0x20 != 0) {
    func_021060dc();
  }
  func_0210fa28();
  func_0210bac0();
  iVar2 = iRam02108328;
  iVar4 = 0;
  do {
    func_0210dd44(iVar2 + iVar4 * 8);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 7);
  func_0210e280(uRam0210832c);
  func_0210d2cc();
  if ((*(uint *)(uRam02108330 & 0xfffffffc) >> (uRam02108330 & 3) * 8 |
      *(uint *)(uRam02108330 & 0xfffffffc) << (uRam02108330 & 3) * -8 + 0x20) == 1) {
    uVar3 = *(uint *)(uRam02108334 & 0xfffffffc) >> (uRam02108334 & 3) * 8 |
            *(uint *)(uRam02108334 & 0xfffffffc) << (uRam02108334 & 3) * -8 + 0x20;
    if (((uVar3 == 0) || (*(short *)(uVar3 + 0x3a) != 0)) || (*(short *)(uVar3 + 0x38) != 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      Sound_MaybeSetActiveSdat(uRam02108338);
      if (*(uint *)(uRam02108334 & 0xfffffffc) >> (uRam02108334 & 3) * 8 != 0 ||
          *(uint *)(uRam02108334 & 0xfffffffc) << (uRam02108334 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uRam02108334,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uRam02108334,0,0);
      Sound_MaybeSetActiveSdat(uRam0210833c);
    }
  }
  func_0210d7ac();
  *puRam02108340 = 0;
  return;
}

