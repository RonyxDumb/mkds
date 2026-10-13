/* Decompiled C draft; module arm9_ov003; ROM address 021ba05c. No matching claim. */
#include "types.h"
#include "deps/021ba05c_func_ov003_021ba05c.h"

undefined4 func_ov003_021ba05c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + iRam021ba134) != 0) {
    iVar1 = 0;
    if ((((((-2 < *(short *)(param_1 + iRam021ba134)) && (-2 < *(short *)(param_1 + iRam021ba138)))
          && (*(short *)(param_1 + iRam021ba13c) != 0)) &&
         ((-2 < *(short *)(param_1 + iRam021ba13c) && (-2 < *(short *)(param_1 + iRam021ba140)))))
        && ((-2 < *(short *)(param_1 + iRam021ba144) &&
            ((uVar3 = (uint)*(ushort *)(param_1 + 4), uVar3 != 0 && (uVar3 <= uRam021ba148)))))) &&
       (*(char *)(param_1 + uVar3 + 5) == '\0')) goto LAB_021ba0ae;
  }
  iVar1 = -1;
LAB_021ba0ae:
  if ((*piRam021ba14c == 0) || (*piRam021ba150 == 0)) {
    iVar1 = -1;
  }
  if (iVar1 == -1) {
    *(undefined1 *)(param_1 + iRam021ba154) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  iVar1 = func_ov003_021ba178(uRam021ba158);
  *piRam021ba15c = iVar1;
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + iRam021ba154) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  func_ov003_021b9134(0xffffffff);
  uVar2 = func_ov003_021b9570(param_1);
  func_ov003_021ba164(*piRam021ba15c);
  func_ov003_021b9518();
  if (*piRam021ba160 != -1) {
    func_ov003_021b7ce4();
  }
  return uVar2;
}

