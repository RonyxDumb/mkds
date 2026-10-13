/* Decompiled C draft; module arm9; ROM address 0204984c. No matching claim. */
#include "types.h"
#include "deps/0204984c_func_0204984c.h"

undefined4 func_0204984c(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  uVar1 = *(uint *)(uRam02049978 & 0xfffffffc) >> (uRam02049978 & 3) * 8 |
          *(uint *)(uRam02049978 & 0xfffffffc) << (uRam02049978 & 3) * -8 + 0x20;
  bVar5 = false;
  if ((uVar1 != 0) &&
     (uVar1 = uVar1 + 0x1f30, uVar3 = uVar1 & 3, uVar1 = *(uint *)(uVar1 & 0xfffffffc),
     uVar1 >> uVar3 * 8 != 0 || uVar1 << uVar3 * -8 + 0x20 != 0)) {
    bVar5 = true;
  }
  if (bVar5) {
    iVar2 = func_02120644();
    if ((param_2 != 0) && (iVar2 != 0)) {
      if (iVar2 == 1) {
        uVar8 = 5;
      }
      else if (iVar2 == 2) {
        uVar8 = 6;
      }
      else {
        uVar8 = 4;
      }
      NotifyError(uVar8);
      uVar8 = 1;
    }
  }
  else {
    if (param_2 != 0) {
      bVar5 = false;
      uVar1 = *(uint *)(uRam0204997c & 0xfffffffc) >> (uRam0204997c & 3) * 8 |
              *(uint *)(uRam0204997c & 0xfffffffc) << (uRam0204997c & 3) * -8 + 0x20;
      bVar7 = false;
      if (uVar1 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      }
      bVar6 = false;
      if ((uVar3 != 0) &&
         (uVar3 = uVar1 + 4 & 3, uVar4 = *(uint *)(uVar1 + 4 & 0xfffffffc),
         (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 0xd)) {
        bVar6 = true;
      }
      if ((bVar6) && ((*(ushort *)(uVar1 + 0x454) & 0x80) == 0)) {
        bVar7 = true;
      }
      if ((bVar7) &&
         (uVar3 = uVar1 + 8 & 3, uVar1 = *(uint *)(uVar1 + 8 & 0xfffffffc),
         (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) != 9)) {
        bVar5 = true;
      }
      if (bVar5) {
        NotifyError(0);
        *(undefined4 *)
         ((*(uint *)(uRam0204997c & 0xfffffffc) >> (uRam0204997c & 3) * 8 |
          *(uint *)(uRam0204997c & 0xfffffffc) << (uRam0204997c & 3) * -8 + 0x20) + 8) = 9;
        return 1;
      }
    }
    func_02055340();
  }
  return uVar8;
}

