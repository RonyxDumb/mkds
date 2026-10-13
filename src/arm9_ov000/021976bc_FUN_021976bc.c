/* Decompiled C draft; module arm9_ov000; ROM address 021976bc. No matching claim. */
#include "types.h"
#include "deps/021976bc_FUN_021976bc.h"

int FUN_021976bc(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_18;
  int local_14 [2];
  
  switch(*DAT_021978f0) {
  default:
    return 3;
  case 1:
    return 3;
  case 2:
    local_18 = 0;
    local_14[0] = 0;
    iVar3 = FUN_0218e68c(*DAT_021978f4,0,&local_18,local_14);
    if ((iVar3 == -1) || ((iVar3 == 1 && (local_14[0] == 1)))) {
      *DAT_021978f0 = 1;
      FUN_02197634();
      return 3;
    }
    if (iVar3 == 0) {
      iVar3 = FUN_0218e8c4();
      if (*DAT_021978fc < (uint)(iVar3 - *DAT_021978f8)) {
        *DAT_021978f0 = 1;
        FUN_02197634();
        return 7;
      }
      return 6;
    }
    if ((iVar3 != 1) || (local_18 != 1)) {
      func_0x0213442c(DAT_02197900,DAT_02197904,0,DAT_02197908);
    }
    *DAT_021978f0 = 3;
  case 3:
    iVar3 = FUN_0218e668(*DAT_021978f4);
    if (iVar3 == 0) {
      iVar3 = FUN_0218e8c4();
      if (*DAT_021978fc < (uint)(iVar3 - *DAT_021978f8)) {
        *DAT_021978f0 = 1;
        FUN_02197634();
        return 7;
      }
      return 6;
    }
    iVar3 = FUN_0218e460(*DAT_021978f4,*DAT_02197910 + *DAT_0219790c,*DAT_02197914 - *DAT_0219790c,0
                        );
    piVar1 = DAT_0219790c;
    if (iVar3 == -1) {
      *DAT_021978f0 = 1;
      FUN_02197634();
      return 3;
    }
    iVar4 = *DAT_0219790c + iVar3;
    *DAT_0219790c = iVar4;
    *DAT_02197914 = *DAT_02197914 - iVar3;
    piVar2 = DAT_02197910;
    if (iVar4 < 0x26) {
      return 6;
    }
    *(undefined1 *)(*DAT_02197910 + iVar4) = 0;
    *DAT_021978f0 = 4;
    *DAT_0219791c = DAT_02197918;
    FUN_021971ec(*piVar2,*piVar1);
    iVar3 = FUN_0219735c(*piVar2,*DAT_02197920);
    if (iVar3 != 0) {
      *DAT_021978f0 = 1;
      FUN_02197634();
      return iVar3;
    }
    *DAT_021978f0 = 4;
    piVar1 = DAT_0219790c;
    *DAT_02197914 = *DAT_02197914 + *DAT_0219790c;
    *piVar1 = 0;
    func_0x02134de0(*DAT_02197910);
  case 4:
    iVar3 = FUN_0218e668(*DAT_021978f4);
    if (iVar3 == 0) {
      iVar3 = FUN_0218e8c4();
      if (*DAT_021978fc < (uint)(iVar3 - *DAT_021978f8)) {
        *DAT_021978f0 = 1;
        FUN_02197634();
        return 7;
      }
      return 6;
    }
    iVar3 = FUN_021972b4();
    piVar1 = DAT_0219790c;
    if (iVar3 != 0) {
      *DAT_021978f0 = 1;
      FUN_02197634();
      return iVar3;
    }
    *DAT_02197914 = *DAT_02197914 + *DAT_0219790c;
    *piVar1 = 0;
    func_0x02134de0(*DAT_02197910);
    *DAT_021978f0 = 5;
  case 5:
    return 0;
  }
}

