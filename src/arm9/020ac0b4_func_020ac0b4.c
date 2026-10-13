/* Decompiled C draft; module arm9; ROM address 020ac0b4. No matching claim. */
#include "types.h"
#include "deps/020ac0b4_func_020ac0b4.h"

undefined4 func_020ac0b4(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_020ac238();
  if ((int)param_1 < 0x21) {
    if ((int)param_1 < 0x20) {
      switch(param_1) {
      case 4:
      case 5:
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac228);
        return 0;
      case 6:
        iVar1 = func_020a9e80();
        if (iVar1 != 6) {
          NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac218);
          return 0;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac21c);
        return 3;
      case 7:
        iVar1 = func_020a9e80();
        if (iVar1 != 7) {
          NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac220);
          return 0;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac21c);
        return 3;
      case 8:
        if (param_2 == 0) {
          return 0;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac230);
        return 0;
      case 0x10:
        uVar2 = func_020aa790(*(undefined2 *)(*(int *)(*DAT_020ac224 + 0x40) + iVar1 * 2));
        if (*(ushort *)(*(int *)(*DAT_020ac224 + 0x40) + iVar1 * 2) != uVar2) {
          return 0;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac21c);
        return 3;
      case 0x11:
        uVar2 = func_020aa738(*(undefined2 *)(*(int *)(*DAT_020ac224 + 0x40) + iVar1 * 2));
        if (*(ushort *)(*(int *)(*DAT_020ac224 + 0x40) + iVar1 * 2) != uVar2) {
          return 0;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac21c);
        return 3;
      case 0x12:
        uVar2 = func_020aa6e0(*(undefined2 *)(*(int *)(*DAT_020ac224 + 0x40) + iVar1 * 2));
        if (*(ushort *)(*(int *)(*DAT_020ac224 + 0x40) + iVar1 * 2) != uVar2) {
          return 0;
        }
        NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac21c);
        return 3;
      }
switchD_020ac0dc_caseD_0:
      if (param_2 == 0) {
        return 0;
      }
      if (param_1 < 0x20) {
        return 0;
      }
      NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac234);
      return 0;
    }
  }
  else if (param_1 != DAT_020ac210) goto switchD_020ac0dc_caseD_0;
  if (param_2 != 0) {
    NNSi_MaybeSndPlayerStartSeq(DAT_020ac214,0,DAT_020ac22c);
  }
  return 0;
}

