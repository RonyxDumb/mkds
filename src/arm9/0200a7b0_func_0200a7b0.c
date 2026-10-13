/* Decompiled C draft; module arm9; ROM address 0200a7b0. No matching claim. */
#include "types.h"
#include "deps/0200a7b0_func_0200a7b0.h"

void func_0200a7b0(ushort *param_1)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  piVar2 = DAT_0200aba0;
  uVar1 = *param_1;
  if (uVar1 < 0x1a) {
    if (0x18 < uVar1) {
      if (param_1[1] == 0) {
        uVar4 = func_02143bd4(DAT_0200aba8,*DAT_0200abac);
        func_02009928(8,uVar4);
        return;
      }
      (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(DAT_0200ab9c,param_1);
      return;
    }
    switch(uVar1) {
    case 0:
      if (param_1[1] == 0) {
        func_0200ad00();
        return;
      }
      (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(DAT_0200ab9c,param_1);
      return;
    case 1:
      if (*(int *)(*DAT_0200abbc + DAT_0200abe4) == 0) {
        if (param_1[1] == 0) {
          *(undefined2 *)(*DAT_0200aba0 + DAT_0200abb0) = 0;
          *(undefined2 *)(*piVar2 + DAT_0200abb4) = 0;
          uVar4 = func_02143d88(DAT_0200aba8);
          func_02009928(2,uVar4);
          return;
        }
        *(undefined2 *)(*DAT_0200aba0 + DAT_0200abb8) = 0;
        (**(code **)(*piVar2 + DAT_0200aba4))(DAT_0200ab9c,param_1);
        return;
      }
      func_0214358c(1,0,0);
      func_021435e8(0);
    case 2:
      piVar3 = DAT_0200acec;
      piVar2 = DAT_0200aba0;
      if (param_1[1] == 0) {
        *(undefined1 *)(*DAT_0200acec + DAT_0200acf0) = 0;
        *(undefined2 *)(*DAT_0200acf4 + DAT_0200acf8) = 0;
        (**(code **)(*piVar3 + DAT_0200ace8))(0x11,param_1);
        return;
      }
      *(undefined2 *)(*DAT_0200aba0 + DAT_0200abb8) = 0;
      (**(code **)(*piVar2 + DAT_0200ace8))(DAT_0200ace4,param_1);
      return;
    case 7:
      (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(0x15,param_1);
      uVar4 = func_02145530(DAT_0200aba8,1);
      func_02009928(0x19,uVar4);
      return;
    case 8:
      if (param_1[1] != 0) {
        (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(DAT_0200ab9c,param_1);
        return;
      }
      uVar7 = (uint)param_1[4];
      if (uVar7 < 8) {
        if (6 < uVar7) {
          if (*(short *)(*DAT_0200aba0 + DAT_0200abb8) == 1) {
            return;
          }
          puVar5 = (ushort *)(*DAT_0200aba0 + DAT_0200abb0);
          *puVar5 = *puVar5 | (ushort)(1 << (param_1[8] & 0xff));
          (**(code **)(*piVar2 + DAT_0200aba4))(0,param_1);
          piVar2 = DAT_0200aba0;
          if ((*(short *)(*DAT_0200aba0 + DAT_0200abb4) == 0) &&
             (*(int *)(*DAT_0200abbc + DAT_0200abc0) == 0)) {
            *(int *)(*DAT_0200abbc + DAT_0200abc0) = 1;
            iVar6 = *DAT_0200aba0;
            uVar4 = func_02144230(DAT_0200aba8,*(undefined4 *)(iVar6 + DAT_0200abcc),
                                  *(undefined2 *)(iVar6 + DAT_0200abd0),iVar6 + 0x40,
                                  *(undefined2 *)(iVar6 + DAT_0200abc8),
                                  *(short *)(*piVar2 + DAT_0200abc4) == 0,0,0,0,1,1);
            func_02009928(0xe,uVar4);
            return;
          }
          iVar6 = func_0200ad4c();
          if (iVar6 == 0) {
            return;
          }
          (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(0x19,0);
          return;
        }
        if ((uVar7 < 3) && (-1 < (int)uVar7)) {
          if (uVar7 == 0) {
            *(undefined2 *)(*DAT_0200aba0 + DAT_0200abb0) = 0;
            *(undefined2 *)(*piVar2 + DAT_0200abb4) = 0;
            return;
          }
          if (uVar7 == 2) {
            if (*(short *)(*DAT_0200aba0 + DAT_0200abb8) == 1) {
              return;
            }
            (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(0x1c,param_1);
            return;
          }
        }
      }
      else if (uVar7 == 9) {
        *(ushort *)(*DAT_0200aba0 + DAT_0200abb0) =
             *(ushort *)(*DAT_0200aba0 + DAT_0200abb0) & ~(ushort)(1 << (param_1[8] & 0xff));
        (**(code **)(*piVar2 + DAT_0200aba4))(1,param_1);
        return;
      }
      (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(DAT_0200ab9c,param_1);
      return;
    case 0xd:
      if (param_1[1] != 0) {
        return;
      }
      *(ushort *)(*DAT_0200acec + DAT_0200acfc) =
           *(ushort *)(*DAT_0200acec + DAT_0200acfc) & ~param_1[5];
      return;
    case 0xe:
      *(undefined4 *)(*DAT_0200abbc + DAT_0200abc0) = 0;
      piVar2 = DAT_0200aba0;
      if (param_1[2] == 10) {
        *(undefined2 *)(*DAT_0200aba0 + DAT_0200abb4) = 1;
        (**(code **)(*piVar2 + DAT_0200aba4))(0x19);
        return;
      }
      if (param_1[2] == 0xb) {
        (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(3,*(undefined4 *)(param_1 + 4));
        return;
      }
      (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(DAT_0200ab9c,param_1);
      return;
    case 0xf:
      iVar6 = *DAT_0200abbc;
      if (*(int *)(iVar6 + DAT_0200abd4) != 0) {
        uVar8 = 0;
        uVar7 = 0;
        do {
          if ((*(int *)(iVar6 + DAT_0200abd8) != 0) && (uVar8 = uVar8 + 1, 1 < uVar8)) break;
          iVar6 = iVar6 + 4;
          uVar7 = uVar7 + 1;
        } while (uVar7 < 0xf);
        if (uVar8 == 1) {
          Os_SpinWait(DAT_0200abdc);
        }
      }
      piVar2 = DAT_0200aba0;
      *(undefined1 *)(*DAT_0200aba0 + DAT_0200abe0) = 0;
      if (param_1[1] == 0) {
        (**(code **)(*piVar2 + DAT_0200aba4))(2,param_1);
        (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(0x19,0);
        return;
      }
      if (param_1[1] != 10) {
        (**(code **)(*piVar2 + DAT_0200aba4))(0x13,param_1);
        (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(0x19,0);
        return;
      }
      (**(code **)(*piVar2 + DAT_0200aba4))(0x2a,param_1);
      return;
    }
  }
  else if (uVar1 < 0x1e) {
    if (uVar1 == 0x1d) {
      if (param_1[1] == 0) {
        uVar4 = func_02143c80(DAT_0200aba8,*DAT_0200aba0);
        func_02009928(7,uVar4);
        return;
      }
      (**(code **)(*DAT_0200aba0 + DAT_0200aba4))(DAT_0200ab9c,param_1);
      return;
    }
  }
  else if (uVar1 == 0x80) {
    switch(param_1[2]) {
    case 0x10:
      (**(code **)(*DAT_0200acec + DAT_0200ace8))(0x1d,param_1);
      return;
    case 0x11:
      (**(code **)(*DAT_0200acec + DAT_0200ace8))(0x1f,param_1);
      return;
    case 0x12:
      (**(code **)(*DAT_0200acec + DAT_0200ace8))(0x20,param_1);
      return;
    case 0x13:
      (**(code **)(*DAT_0200acec + DAT_0200ace8))(0x21,param_1);
      return;
    default:
      return;
    case 0x16:
      Os_Terminate();
      return;
    }
  }
  (**(code **)(*DAT_0200acec + DAT_0200ace8))(DAT_0200ace4,param_1);
  return;
}

