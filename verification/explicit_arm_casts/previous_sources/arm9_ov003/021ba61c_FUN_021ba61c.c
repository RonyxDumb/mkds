/* Decompiled C draft; module arm9_ov003; ROM address 021ba61c. No matching claim. */
#include "types.h"
#include "deps/021ba61c_FUN_021ba61c.h"

undefined4 FUN_021ba61c(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_18;
  
  func_0x0200eb90(DAT_021ba6f0,DAT_021ba6f4,4);
  if ((param_1 != 0) && (param_2 != 0)) {
    func_0x0200fca0();
    *DAT_021ba6f8 = param_1;
    *DAT_021ba6fc = param_2;
    func_0x0200fcb4();
    iVar2 = (*(code *)*DAT_021ba6f8)(DAT_021ba700);
    *DAT_021ba704 = iVar2;
    if (iVar2 != 0) {
      iVar2 = FUN_021ba818(DAT_021ba708,iVar2,DAT_021ba700);
      uVar1 = DAT_021ba6f0;
      bVar3 = iVar2 != 0;
      if (bVar3) {
        do {
          func_0x0200ea3c(uVar1,&local_18,1);
          switch(local_18) {
          case 4:
          case 5:
            goto switchD_021ba6a6_caseD_4;
          case 6:
            return 0;
          }
          bVar3 = false;
switchD_021ba6a6_caseD_4:
        } while (bVar3);
      }
      (*(code *)*DAT_021ba6fc)(*DAT_021ba704);
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  return 0xffffffff;
}

