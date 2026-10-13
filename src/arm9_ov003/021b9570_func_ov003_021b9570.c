/* Decompiled C draft; module arm9_ov003; ROM address 021b9570. No matching claim. */
#include "types.h"
#include "deps/021b9570_func_ov003_021b9570.h"

undefined4 func_ov003_021b9570(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int extraout_r1;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int local_d0;
  int local_cc;
  undefined4 local_c4;
  short local_b0;
  short local_ae;
  short local_ac;
  short local_aa;
  undefined4 local_a8;
  int local_a4;
  undefined1 auStack_a0 [8];
  undefined4 local_98;
  undefined1 auStack_94 [8];
  undefined4 local_8c;
  int local_88;
  undefined1 uStack_84;
  undefined1 local_83;
  undefined2 local_82;
  undefined4 local_80;
  undefined1 auStack_7c [24];
  undefined1 auStack_64 [60];
  undefined4 local_28 [4];
  undefined4 local_18;
  
  local_cc = 0;
  local_a8 = 1;
  local_a4 = 0;
  local_c4 = 0;
  func_ov003_021b7d84(auStack_7c,0,0x18);
  local_b0 = *(short *)(param_1 + DAT_021b990c);
  if (local_b0 == -1) {
    local_b0 = 10;
  }
  local_ac = *(short *)(param_1 + DAT_021b9910);
  if (local_ac == -1) {
    local_ac = 10;
  }
  local_ae = *(short *)(param_1 + DAT_021b9914);
  if (local_ae == -1) {
    local_ae = 100;
  }
  local_aa = *(short *)(param_1 + DAT_021b9918);
  if (local_aa == -1) {
    local_aa = 100;
  }
  local_d0 = (int)*(short *)(param_1 + DAT_021b991c);
  if (local_d0 == -1) {
    local_d0 = DAT_021b9920;
  }
  func_ov003_021b94c4((ushort *)(uintptr_t)(param_1));
  if ((*(uint *)(DAT_021b9924 + 8) & 1) != 1) {
    func_ov003_021b94b8(0x13);
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  iVar8 = 0;
  func_ov003_021b9134(0);
  piVar3 = DAT_021b992c;
  iVar9 = (int)local_ae;
  while( true ) {
    if (*piVar3 != 0) {
      func_ov003_021ba164();
      *piVar3 = 0;
    }
    iVar2 = func_ov003_021ba394(piVar3);
    if (iVar2 == -1) {
      *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
      func_ov003_021b9518();
      return 0xffffffff;
    }
    iVar2 = func_ov003_021b91f0((uint *)(uintptr_t)(*piVar3));
    if (iVar2 == 4) {
      *(undefined1 *)(param_1 + DAT_021b9928) = 2;
      func_ov003_021b9518();
      return 0xffffffff;
    }
    if (iVar2 == 0) break;
    if (local_b0 <= iVar8) {
      *(undefined1 *)(param_1 + DAT_021b9928) = 1;
      func_ov003_021b9518();
      return 0xffffffff;
    }
    func_ov003_021ba1a8(iVar9);
    iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
  }
  func_ov003_021b9134(1);
  func_ov003_021b7d84(auStack_64,0,0x3c);
  iVar8 = func_ov003_021b91a4((undefined4 *)(void *)(auStack_64));
  if (iVar8 != 0) {
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  iVar8 = func_ov003_021ba178(0x58);
  *DAT_021b9930 = iVar8;
  if (iVar8 == 0) {
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  func_ov003_021b7d84(iVar8,0,0x58);
  iVar8 = 0;
  if (0 < local_b0) {
    do {
      iVar2 = func_ov003_021ba1b0((undefined4 *)(void *)(auStack_64),*DAT_021b9930);
      if (iVar2 == -1) {
        *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      if ((iVar2 == 0) && (*(int *)*DAT_021b9930 == 1)) break;
      func_ov003_021ba1a8(iVar9);
      iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
    } while (iVar8 < local_b0);
  }
  if (iVar8 == local_b0) {
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  iVar2 = func_ov003_021b7df4(DAT_021b9934,0xffffff00,DAT_021b9934);
  if (iVar2 != 0) {
    func_ov003_021b94b8(0xc);
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  func_ov003_021b9518();
  func_ov003_021b916c(3,(int)(uintptr_t)(auStack_7c),param_1 + DAT_021b9938);
  iVar2 = func_ov003_021b7cf8(2,2,0);
  *DAT_021b993c = iVar2;
  if (iVar2 < 0) {
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  iVar2 = func_ov003_021b7d00(iVar2,DAT_021b9940,1,&local_a8,4);
  if (iVar2 < 0) {
    func_ov003_021b94b8(0xb);
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  func_ov003_021b7d84(&uStack_84,0,8);
  local_83 = 2;
  local_80 = func_ov003_021b7cac(DAT_021b9934);
  local_82 = func_ov003_021b7c94(DAT_021b9944);
  iVar2 = func_ov003_021b7cec(*DAT_021b993c,&uStack_84,8);
  if (iVar2 < 0) {
    *(undefined1 *)(param_1 + DAT_021b9928) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
LAB_021b98ac:
  piVar3 = (int *)*DAT_021b9948;
  func_ov003_021b7d84(local_28,0,0x14);
  local_18 = DAT_021b9934;
  local_28[0] = DAT_021b994c;
  uVar4 = func_0x02133068(local_d0,DAT_021b9950);
  func_0x02133068(local_d0,DAT_021b9950);
  iVar2 = DAT_021b9950 * extraout_r1;
  do {
    if ((local_cc == 1) && (*(char *)(DAT_021b9924 + 0x18) != '\x01')) {
      if (*DAT_021b993c != -1) {
        func_ov003_021b7ce4();
      }
      *DAT_021b993c = -1;
      iVar6 = func_ov003_021b7dc8();
      if (iVar6 != 0) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      if (*DAT_021b9cd8 != 0) {
        func_ov003_021ba164();
        *DAT_021b9cd8 = 0;
      }
      iVar6 = func_ov003_021ba178(0x58);
      *DAT_021b9cd8 = iVar6;
      if (iVar6 == 0) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      while( true ) {
        iVar6 = func_ov003_021ba394(DAT_021b9cd8);
        if (iVar6 == -1) {
          *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        iVar5 = func_ov003_021b91f0((uint *)(uintptr_t)(*DAT_021b9cd8));
        if (iVar5 == 4) {
          *(undefined1 *)(param_1 + DAT_021b9cd4) = 2;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        if (iVar5 == 0) break;
        if (local_b0 <= iVar8) {
          *(undefined1 *)(param_1 + DAT_021b9cd4) = 1;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        func_ov003_021ba1a8(iVar9);
        iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
      }
      if (iVar6 == -1) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      iVar8 = func_ov003_021ba178(0x58);
      *DAT_021b9cdc = iVar8;
      if (iVar8 == 0) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      func_ov003_021b7d84(iVar8,0,0x58);
      iVar8 = 0;
      if (0 < local_b0) {
        do {
          iVar6 = func_ov003_021ba1b0(auStack_64,*DAT_021b9cdc);
          if (iVar6 == -1) {
            *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
            func_ov003_021b9518();
            return 0xffffffff;
          }
          if ((iVar6 == 0) && (*(int *)*DAT_021b9cdc == 1)) break;
          func_ov003_021ba1a8(iVar9);
          iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
        } while (iVar8 < local_b0);
      }
      if (iVar8 == local_b0) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      local_c4 = func_ov003_021b9550(*(undefined4 *)(DAT_021b9ce0 + 0x10),
                                     *(undefined4 *)(DAT_021b9ce0 + 0x14));
      iVar6 = func_ov003_021b7df4(local_c4,*(undefined4 *)(DAT_021b9ce0 + 0x14),local_c4);
      if (iVar6 != 0) {
        func_ov003_021b94b8(0xc);
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      *(undefined1 *)(DAT_021b9ce0 + 0x18) = 1;
      func_ov003_021b9518();
      iVar6 = func_ov003_021b7cf8(2,2,0);
      *DAT_021b9ce4 = iVar6;
      if (iVar6 < 0) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      iVar6 = func_ov003_021b7d00(iVar6,DAT_021b9ce8,1,&local_a8,4);
      if (iVar6 < 0) {
        func_ov003_021b94b8(0xb);
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
      func_ov003_021b7d84(&uStack_84,0,8);
      local_83 = 2;
      local_80 = func_ov003_021b7cac(local_c4);
      local_82 = func_ov003_021b7c94(DAT_021b9cec);
      iVar6 = func_ov003_021b7cec(*DAT_021b9ce4,&uStack_84,8);
      if (iVar6 < 0) {
        *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
        func_ov003_021b9518();
        return 0xffffffff;
      }
    }
    iVar6 = func_ov003_021b86e4(local_cc,local_28,auStack_7c,*DAT_021b9ce4);
    if (iVar6 == -1) {
      func_ov003_021b94b8(local_cc + DAT_021b9cf0);
      *(undefined1 *)(param_1 + DAT_021b9cd4) = 0xf;
      func_ov003_021b9518();
      return 0xffffffff;
    }
    func_ov003_021b7d84(piVar3,0,DAT_021b9cf4);
    func_ov003_021b7ba8(auStack_94);
    func_ov003_021b7ba0(*DAT_021b9ce4,auStack_94);
    local_8c = uVar4;
    local_88 = iVar2;
    iVar6 = func_ov003_021b7d1c(*DAT_021b9ce4 + 1,auStack_94,0,0,&local_8c);
    if (0 < iVar6) break;
    local_a4 = local_a4 + 1;
    if (local_ac < local_a4) {
      if (local_cc == 0) {
        func_ov003_021b94b8(0xf);
      }
      else if (local_cc == 1) {
        func_ov003_021b94b8(0x10);
      }
      else {
        func_ov003_021b94b8(0x11);
      }
      iVar8 = -1;
      goto LAB_021b9f84;
    }
    func_ov003_021ba1a8((int)local_aa);
  } while( true );
  local_98 = 8;
  uVar1 = func_ov003_021b7d68(*DAT_021b9ce4,piVar3 + 3,DAT_021b9cf8,0,auStack_a0,&local_98);
  *piVar3 = *DAT_021b9ce4;
  iVar2 = func_ov003_021b7c44(uVar1);
  piVar3[1] = iVar2;
  iVar2 = func_ov003_021b9078(local_cc,piVar3,&local_a4,auStack_7c,*DAT_021b9ce4);
  if (iVar2 == 100) {
    iVar8 = 0;
  }
  else if (iVar2 == -1) {
    iVar8 = -1;
  }
  else {
    if (local_cc != iVar2) {
      local_cc = iVar2;
      if (iVar2 == 2) {
        if (*DAT_021ba040 != -1) {
          func_ov003_021b7ce4();
        }
        *DAT_021ba040 = -1;
        iVar8 = func_ov003_021b7dc8();
        if (iVar8 != 0) {
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        iVar8 = 0;
        func_ov003_021b9134(4);
        while( true ) {
          if (*DAT_021ba048 != 0) {
            func_ov003_021ba164();
            *DAT_021ba048 = 0;
          }
          iVar6 = func_ov003_021ba394(DAT_021ba048);
          if (iVar6 == -1) {
            *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
            func_ov003_021b9518();
            return 0xffffffff;
          }
          iVar6 = func_ov003_021b91f0(*DAT_021ba048);
          if (iVar6 == 4) {
            *(undefined1 *)(param_1 + DAT_021ba044) = 2;
            func_ov003_021b9518();
            return 0xffffffff;
          }
          if (iVar6 == 0) break;
          if (local_b0 <= iVar8) {
            *(undefined1 *)(param_1 + DAT_021ba044) = 1;
            func_ov003_021b9518();
            return 0xffffffff;
          }
          func_ov003_021ba1a8(iVar9);
          iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
        }
        iVar8 = func_ov003_021ba178(0x58);
        *DAT_021ba04c = iVar8;
        if (iVar8 == 0) {
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        func_ov003_021b7d84(iVar8,0,0x58);
        iVar8 = 0;
        if (0 < local_b0) {
          do {
            iVar6 = func_ov003_021ba1b0(auStack_64,*DAT_021ba04c);
            if (iVar6 == -1) {
              *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
              func_ov003_021b9518();
              return 0xffffffff;
            }
            if ((iVar6 == 0) && (*(int *)*DAT_021ba04c == 1)) break;
            func_ov003_021ba1a8(iVar9);
            iVar8 = (iVar8 + 1) * 0x10000 >> 0x10;
          } while (iVar8 < local_b0);
        }
        if (iVar8 == local_b0) {
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        iVar6 = func_ov003_021b7df4(local_c4,*(undefined4 *)(DAT_021ba050 + 0x14),local_c4);
        if (iVar6 != 0) {
          func_ov003_021b94b8(0xc);
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        func_ov003_021b9518();
        iVar6 = func_ov003_021b7cf8(2,2,0);
        *DAT_021ba040 = iVar6;
        if (iVar6 < 0) {
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        iVar6 = func_ov003_021b7d00(iVar6,DAT_021ba054,1,&local_a8,4);
        if (iVar6 < 0) {
          func_ov003_021b94b8(0xb);
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
        func_ov003_021b7d84(&uStack_84,0,8);
        local_83 = 2;
        local_80 = func_ov003_021b7cac(local_c4);
        local_82 = func_ov003_021b7c94(DAT_021ba058);
        iVar6 = func_ov003_021b7cec(*DAT_021ba040,&uStack_84,8);
        if (iVar6 < 0) {
          *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
          func_ov003_021b9518();
          return 0xffffffff;
        }
      }
      goto LAB_021b98ac;
    }
    if (local_a4 <= local_ac) {
      func_ov003_021ba1a8((int)local_aa);
      local_cc = iVar2;
      goto LAB_021b98ac;
    }
    if (iVar2 == 0) {
      func_ov003_021b94b8(0xf);
    }
    else if (iVar2 == 1) {
      func_ov003_021b94b8(0x10);
    }
    else {
      func_ov003_021b94b8(0x11);
    }
    iVar8 = -1;
  }
LAB_021b9f84:
  if (*DAT_021ba040 != -1) {
    func_ov003_021b7ce4();
  }
  *DAT_021ba040 = -1;
  iVar9 = func_ov003_021b7dc8();
  if (iVar9 != 0) {
    *(undefined1 *)(param_1 + DAT_021ba044) = 0xf;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  if (iVar8 != 0) {
    uVar4 = func_ov003_021b94ac();
    switch(uVar4) {
    case 0xf:
      uVar7 = 3;
      break;
    case 0x10:
      uVar7 = 4;
      break;
    case 0x11:
      uVar7 = 5;
      break;
    default:
      uVar7 = 0xf;
      break;
    case 0x14:
      uVar7 = 7;
      break;
    case 0x15:
      uVar7 = 8;
    }
    *(undefined1 *)(param_1 + DAT_021ba044) = uVar7;
    func_ov003_021b9518();
    return 0xffffffff;
  }
  iVar8 = func_ov003_021b929c(param_1);
  if (iVar8 == 0) {
    return 0;
  }
  *(undefined1 *)(param_1 + DAT_021ba044) = 6;
  func_ov003_021b9518();
  return 0xffffffff;
}

