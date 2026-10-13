/* Decompiled C draft; module arm9_ov003; ROM address 021ba560. No matching claim. */
#include "types.h"
#include "deps/021ba560_FUN_021ba560.h"

undefined4 FUN_021ba560(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  
  bVar1 = true;
  uVar3 = 0xffffffff;
  if (*DAT_021ba60c == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_021ba9c0();
  if (iVar2 != 0) {
    do {
      func_0x0200ea3c(DAT_021ba610,&local_10,1);
      switch(local_10) {
      default:
        bVar1 = false;
        break;
      case 4:
      case 5:
        break;
      case 0x14:
        bVar1 = false;
        uVar3 = 0;
        (*(code *)*DAT_021ba60c)(*DAT_021ba614);
      }
    } while (bVar1);
    func_0x0200fca0();
    *DAT_021ba618 = 0;
    *DAT_021ba60c = 0;
    func_0x0200fcb4();
    return uVar3;
  }
  return 0xffffffff;
}

