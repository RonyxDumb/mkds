/* Decompiled C draft; module arm9_ov000; ROM address 021874ec. No matching claim. */
#include "types.h"
#include "deps/021874ec_FUN_021874ec.h"

void FUN_021874ec(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int local_290;
  int local_288;
  int local_280;
  int iStack_27c;
  undefined2 uStack_21c;
  undefined1 auStack_21a [6];
  int iStack_214;
  int iStack_210;
  undefined1 auStack_200 [36];
  undefined4 auStack_1dc [114];
  
  piVar3 = DAT_0218788c;
  piVar2 = DAT_02187888;
  piVar1 = DAT_02187884;
  local_290 = 0;
  local_288 = 0;
  local_280 = 0;
  *DAT_0218788c = *DAT_02187890;
  piVar3[1] = 1;
  piVar3[2] = 0;
  piVar3[3] = DAT_02187894;
  iVar5 = *piVar2;
  piVar3[4] = *(int *)(iVar5 + DAT_02187898);
  piVar3[5] = *(int *)(iVar5 + DAT_0218789c);
  piVar3[7] = DAT_021878a0;
  *(undefined4 *)(iVar5 + 4) = 0xfffffffe;
  iVar5 = FUN_021873d4(*piVar1,piVar3);
  if (iVar5 != 0) {
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(1);
    FUN_02187f22();
  }
  iVar5 = FUN_0218735c(*piVar1);
  if (iVar5 != 0) {
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(1);
    FUN_02187f22();
  }
  FUN_021872bc(*piVar1);
  if (*(int *)(*piVar1 + DAT_021878a4) != 0) {
    func_0x0200e084(*piVar1 + DAT_021878a8);
  }
  iVar9 = *piVar1;
  iVar5 = *(int *)(iVar9 + 0x24);
  if (iVar5 == 2) {
    *(undefined4 *)(*DAT_02187888 + 4) = 0xffffffff;
LAB_021875d0:
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(3);
    FUN_02187f22();
  }
  else if (iVar5 != 8) goto LAB_021875d0;
  iVar5 = FUN_021866fc(*piVar2 + 8,0x20,0,*(undefined4 *)(iVar9 + DAT_021878ac));
  if (iVar5 != 1) {
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(2);
    FUN_02187f22();
  }
  FUN_021866b8(*piVar2 + 8,0x20,DAT_021878b0);
  iVar5 = func_0x0213bf90();
  if (*DAT_021878b4 == 0x22) {
    FUN_02187490(2);
    FUN_02187f22();
  }
  if (iVar5 != 200) {
    if (iVar5 != DAT_021878b8) {
      FUN_02186d04(*DAT_02187884);
      FUN_02187490(10);
      goto code_r0x02187f22;
    }
    iVar9 = *piVar2;
    if (*(int *)(iVar9 + DAT_021878bc) != 0) {
      *(undefined4 *)(iVar9 + 4) = 0xfffffffa;
      FUN_02186d04(*DAT_02187884);
      piVar1 = DAT_0218788c;
      iVar5 = *DAT_021878c0;
      *DAT_0218788c = iVar5;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = DAT_021878c4;
      iVar9 = *DAT_02187888;
      piVar1[4] = *(int *)(iVar9 + DAT_02187898);
      piVar1[5] = *(int *)(iVar9 + DAT_0218789c);
      piVar1[7] = DAT_021878a0;
      iVar5 = func_0x0213a074(iVar5,DAT_021878c8);
      if (iVar5 != 0) {
        DAT_0218788c[6] = 1;
      }
      iVar5 = FUN_021873d4(*DAT_02187884,DAT_0218788c);
      if (iVar5 != 0) {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(1);
        FUN_02187f22();
      }
      iVar5 = FUN_02185984(*DAT_02187884,DAT_021878cc,DAT_021878cc,*DAT_02187888 + 8,0x20,1);
      if (iVar5 != 0) {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(8);
        FUN_02187f22();
      }
      iVar5 = FUN_02186b0c(*DAT_02187884,DAT_021878d0,DAT_021878d4,7);
      if (iVar5 != 0) {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(8);
        FUN_02187f22();
      }
      uVar6 = func_0x0200fca0();
      func_0x0214d168(auStack_200,0,0x21);
      FUN_021a6abc(&uStack_21c);
      uVar7 = FUN_021a6abc(0);
      func_0x0214d1fc(uVar7,auStack_200,uStack_21c);
      func_0x0200fcb4(uVar6);
      uVar6 = func_0x0213a434(auStack_200);
      iVar5 = FUN_02186b0c(*DAT_02187884,DAT_021878d8,auStack_200,uVar6);
      if (iVar5 == 0) {
        uVar7 = *(undefined4 *)(*DAT_02187888 + DAT_021878bc);
        uVar6 = func_0x0213a434(uVar7);
        iVar5 = FUN_02186b0c(*DAT_02187884,DAT_021878dc,uVar7,uVar6);
        if (iVar5 == 0) {
          (**(code **)(*DAT_02187888 + DAT_0218789c))
                    (DAT_021878e0,*(undefined4 *)(*DAT_02187888 + DAT_021878bc),0);
          *(undefined4 *)(*DAT_02187888 + DAT_021878bc) = 0;
          iVar5 = FUN_0218735c(*DAT_02187884);
          if (iVar5 == 0) {
            FUN_021872bc(*DAT_02187884);
            if (*(int *)(*DAT_02187884 + DAT_021878a4) != 0) {
              func_0x0200e084(*DAT_02187884 + DAT_021878a8);
            }
            if (*(int *)(*DAT_02187884 + 0x24) == 2) {
              *(undefined4 *)(*DAT_02187888 + 4) = 0xffffffff;
            }
            else if (*(int *)(*DAT_02187884 + 0x24) == 8) {
              FUN_02186d04();
              FUN_02187490(7);
              goto code_r0x02187f22;
            }
            FUN_02186d04(*DAT_02187884);
            FUN_02187490(3);
          }
          else {
            FUN_02186d04(*DAT_02187884);
            FUN_02187490(1);
          }
        }
        else {
          FUN_02186d04(*DAT_02187884);
          FUN_02187490(8);
        }
      }
      else {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(8);
      }
      goto code_r0x02187f22;
    }
    iVar9 = FUN_021866b8(iVar9 + 8,0x20,DAT_021878e4);
    if (iVar9 == 0) {
      FUN_02186d04(*DAT_02187884);
      FUN_02187490(2);
      goto code_r0x02187f22;
    }
    iVar8 = func_0x0213a434();
    uVar6 = (**(code **)(*piVar2 + DAT_02187898))(DAT_021878e8,iVar8 + 1);
    *(undefined4 *)(*piVar2 + DAT_021878ec) = uVar6;
    iVar8 = *(int *)(*piVar2 + DAT_021878ec);
    if (iVar8 == 0) {
      FUN_02186d04(*DAT_02187884);
      FUN_02187490(4);
      goto code_r0x02187f22;
    }
    uVar6 = func_0x0213a434(iVar9);
    func_0x0213a228(iVar8,iVar9,uVar6);
  }
  FUN_02186d04(*piVar1);
  func_0x02151910(&iStack_214);
  if (iStack_210 == 0 && iStack_214 == 0) {
    *(undefined4 *)(*piVar2 + 4) = 0xfffffffd;
    puVar4 = DAT_02187c80;
    *DAT_02187c80 = 0;
    puVar4[0x15] = 0;
    iVar9 = *piVar2;
    *(undefined4 *)(DAT_02187c80 + 0x24) = *(undefined4 *)(iVar9 + DAT_02187c84);
    puVar4 = DAT_02187c80;
    *(undefined4 *)(DAT_02187c80 + 0x28) = *(undefined4 *)(iVar9 + DAT_02187c88);
    iVar9 = FUN_02186560(puVar4,*piVar1);
    if (iVar9 != 0) {
      FUN_02187490(5);
      goto code_r0x02187f22;
    }
    FUN_02186404();
    iVar9 = FUN_021863cc();
    if (iVar9 != 0x14) {
      iVar5 = FUN_021863cc();
      if (iVar5 == 9) {
        *(undefined4 *)(*DAT_02187c8c + 4) = 0xffffffff;
      }
      else {
        FUN_0218635c(auStack_1dc);
        *(undefined4 *)(*DAT_02187c8c + 4) = auStack_1dc[0];
      }
      FUN_02187490(6);
      goto code_r0x02187f22;
    }
    FUN_02186430();
  }
  if (iVar5 == 200) {
    *(undefined4 *)(*DAT_02187c8c + 4) = 0;
    FUN_02187490(0xb);
  }
  else {
    *(undefined4 *)(*piVar2 + 4) = 0xfffffffc;
    iVar5 = *DAT_02187c90;
    *piVar3 = iVar5;
    piVar3[1] = 0;
    piVar3[2] = 0;
    piVar3[3] = DAT_02187c94;
    iVar9 = *piVar2;
    piVar3[4] = *(int *)(iVar9 + DAT_02187c84);
    piVar3[5] = *(int *)(iVar9 + DAT_02187c88);
    piVar3[7] = DAT_02187c98;
    iVar5 = func_0x0213a074(iVar5,DAT_02187c9c);
    if (iVar5 != 0) {
      piVar3[6] = 1;
    }
    iVar5 = FUN_021873d4(*piVar1,piVar3);
    if (iVar5 == 0) {
      iVar5 = FUN_02185984(*piVar1,DAT_02187ca4,DAT_02187ca4,*piVar2 + 8,0x20,1);
      if (iVar5 == 0) {
        iVar5 = FUN_02186b0c(*piVar1,DAT_02187ca8,DAT_02187cac,5);
        if (iVar5 == 0) {
          uVar6 = func_0x0200fca0();
          func_0x0214d168(auStack_200,0,0x21);
          FUN_021a6abc(&uStack_21c);
          uVar7 = FUN_021a6abc(0);
          func_0x0214d1fc(uVar7,auStack_200,uStack_21c);
          func_0x0200fcb4(uVar6);
          uVar6 = func_0x0213a434(auStack_200);
          iVar5 = FUN_02186b0c(*piVar1,DAT_02187cb0,auStack_200,uVar6);
          if (iVar5 == 0) {
            uVar7 = *(undefined4 *)(*piVar2 + DAT_02187cb4);
            uVar6 = func_0x0213a434(uVar7);
            iVar5 = FUN_02186b0c(*piVar1,DAT_02187cb8,uVar7,uVar6);
            if (iVar5 == 0) {
              (**(code **)(*piVar2 + DAT_02187c88))
                        (DAT_02187cbc,*(undefined4 *)(*piVar2 + DAT_02187cb4),0);
              *(undefined4 *)(*piVar2 + DAT_02187cb4) = 0;
              iVar5 = FUN_0218735c(*piVar1);
              if (iVar5 == 0) {
                FUN_021872bc(*piVar1);
                if (*(int *)(*piVar1 + DAT_02187cc0) != 0) {
                  func_0x0200e084(*piVar1 + DAT_02187cc4);
                }
                iVar5 = *(int *)(*piVar1 + 0x24);
                if (iVar5 == 2) {
                  *(undefined4 *)(*DAT_02187c8c + 4) = 0xffffffff;
                }
                else if (iVar5 == 8) {
                  iVar5 = FUN_021866fc(*piVar2 + 8,0x20,0,*(undefined4 *)(*piVar1 + DAT_02187cc8));
                  if (iVar5 == 1) {
                    FUN_021866b8(*piVar2 + 8,0x20,DAT_02187ccc);
                    iVar5 = func_0x0213bf90();
                    if (*DAT_02187cd0 == 0x22) {
                      FUN_02186d04(*DAT_02187ca0);
                      FUN_02187490(2);
                    }
                    else if (iVar5 == 200) {
                      iVar5 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187cd4,auStack_21a,4);
                      if (iVar5 < 1) {
                        FUN_02186d04(*DAT_02187ca0);
                        FUN_02187490(9);
                      }
                      else {
                        iVar5 = func_0x0213bf90(auStack_21a);
                        if (*DAT_02187cd0 == 0x22) {
                          FUN_02186d04(*DAT_02187ca0);
                          FUN_02187490(9);
                        }
                        else if (iVar5 < 100) {
                          iVar5 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187cd8,0,0);
                          if (iVar5 < 1) {
                            FUN_02186d04(*DAT_02187ca0);
                            FUN_02187490(9);
                          }
                          else {
                            iVar9 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187cdc,0,0);
                            if (iVar9 < 1) {
                              FUN_02186d04(*DAT_02187ca0);
                              FUN_02187490(9);
                            }
                            else {
                              iVar8 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187ce0,0,0);
                              local_290 = (**(code **)(*piVar2 + DAT_02187c84))
                                                    (DAT_02187cd8,iVar5 + 1);
                              if (local_290 == 0) {
                                FUN_02186d04(*DAT_02187ca0);
                                FUN_02187490(4);
                              }
                              else {
                                local_288 = (**(code **)(*piVar2 + DAT_02187c84))
                                                      (DAT_02187cdc,iVar9 + 1);
                                if (local_288 == 0) {
                                  FUN_02186d04(*DAT_02187ca0);
                                  FUN_02187490(4);
                                }
                                else if ((iVar8 < 1) ||
                                        (local_280 = (**(code **)(*piVar2 + DAT_02187f74))
                                                               (DAT_02187f70,iVar8 + 1),
                                        local_280 != 0)) {
                                  iVar5 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187f7c,local_290,
                                                       iVar5 + 1);
                                  if (iVar5 < 0) {
                                    FUN_02186d04(*DAT_02187f78);
                                    FUN_02187490(9);
                                  }
                                  else {
                                    *(undefined1 *)(local_290 + iVar5) = 0;
                                    iVar5 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187f80,local_288,
                                                         iVar9 + 1);
                                    if (iVar5 < 0) {
                                      FUN_02186d04(*DAT_02187f78);
                                      FUN_02187490(9);
                                    }
                                    else {
                                      *(undefined1 *)(local_288 + iVar5) = 0;
                                      iStack_27c = 0;
                                      if (0 < iVar8) {
                                        iVar5 = FUN_02186674(*piVar2 + 8,0x20,DAT_02187f70,local_280
                                                             ,iVar8 + 1);
                                        if (iVar5 < 0) {
                                          FUN_02186d04(*DAT_02187f78);
                                          FUN_02187490(9);
                                          goto code_r0x02187f22;
                                        }
                                        *(undefined1 *)(local_280 + iVar5) = 0;
                                        iStack_27c = func_0x0213bf90(local_280);
                                        if (*DAT_02187f84 == 0x22) {
                                          FUN_02186d04(*DAT_02187f78);
                                          FUN_02187490(9);
                                          goto code_r0x02187f22;
                                        }
                                        iStack_27c = DAT_02187f88 * iStack_27c;
                                        if (iStack_27c - DAT_02187f8c != 0 &&
                                            DAT_02187f8c <= iStack_27c) {
                                          iStack_27c = DAT_02187f8c;
                                        }
                                      }
                                      FUN_02186d04(*piVar1);
                                      *(undefined4 *)(*piVar2 + 4) = 0xfffffffb;
                                      *piVar3 = local_290;
                                      piVar3[1] = 0;
                                      piVar3[2] = 0;
                                      piVar3[3] = DAT_02187f90;
                                      iVar5 = *piVar2;
                                      piVar3[4] = *(int *)(iVar5 + DAT_02187f74);
                                      piVar3[5] = *(int *)(iVar5 + DAT_02187f94);
                                      piVar3[7] = DAT_02187f98;
                                      iVar5 = FUN_021873d4(*piVar1,piVar3);
                                      if (iVar5 == 0) {
                                        iVar5 = FUN_02186a9c(*piVar1,local_288);
                                        if (iVar5 == 0) {
                                          iVar5 = FUN_0218735c(*piVar1);
                                          if (iVar5 == 0) {
                                            FUN_021872bc(*piVar1);
                                            if (*(int *)(*piVar1 + DAT_02187f9c) != 0) {
                                              func_0x0200e084(*piVar1 + DAT_02187fa0);
                                            }
                                            iVar5 = *(int *)(*piVar1 + 0x24);
                                            if (iVar5 == 2) {
                                              *(undefined4 *)(*DAT_02187fa4 + 4) = 0xffffffff;
                                            }
                                            else if (iVar5 == 8) {
                                              iVar5 = FUN_021866fc(*piVar2 + 8,0x20,1,
                                                                   *(undefined4 *)
                                                                    (*piVar1 + DAT_02187fa8));
                                              if (iVar5 == 1) {
                                                iVar5 = FUN_021866b8(*piVar2 + 8,0x20,DAT_02187fac);
                                                if (iVar5 == 0) {
                                                  FUN_02186d04(*DAT_02187f78);
                                                  FUN_02187490(2);
                                                }
                                                else {
                                                  iVar9 = func_0x0213a434();
                                                  uVar6 = (**(code **)(*piVar2 + DAT_02187f74))
                                                                    (DAT_02187fb0,iVar9 + 1);
                                                  *(undefined4 *)(*piVar2 + DAT_02187fb4) = uVar6;
                                                  iVar9 = *(int *)(*piVar2 + DAT_02187fb4);
                                                  if (iVar9 == 0) {
                                                    FUN_02186d04(*DAT_02187f78);
                                                    FUN_02187490(4);
                                                  }
                                                  else {
                                                    uVar6 = func_0x0213a434(iVar5);
                                                    func_0x0213a228(iVar9,iVar5,uVar6);
                                                    FUN_02186d04(*piVar1);
                                                    func_0x0200dc3c(iStack_27c);
                                                    FUN_0218753e();
                                                  }
                                                }
                                              }
                                              else {
                                                FUN_02186d04(*DAT_02187f78);
                                                FUN_02187490(2);
                                              }
                                              goto code_r0x02187f22;
                                            }
                                            FUN_02186d04(*DAT_02187f78);
                                            FUN_02187490(3);
                                          }
                                          else {
                                            FUN_02186d04(*DAT_02187f78);
                                            FUN_02187490(1);
                                          }
                                        }
                                        else {
                                          FUN_02186d04(*DAT_02187f78);
                                          FUN_02187490(8);
                                        }
                                      }
                                      else {
                                        FUN_02186d04(*DAT_02187f78);
                                        FUN_02187490(1);
                                      }
                                    }
                                  }
                                }
                                else {
                                  FUN_02186d04(*DAT_02187f78);
                                  FUN_02187490(4);
                                }
                              }
                            }
                          }
                        }
                        else {
                          FUN_02186d04(*DAT_02187ca0);
                          FUN_02187490(6);
                        }
                      }
                    }
                    else {
                      FUN_02186d04(*DAT_02187ca0);
                      FUN_02187490(2);
                    }
                  }
                  else {
                    FUN_02186d04(*DAT_02187ca0);
                    FUN_02187490(2);
                  }
                  goto code_r0x02187f22;
                }
                FUN_02186d04(*DAT_02187ca0);
                FUN_02187490(3);
              }
              else {
                FUN_02186d04(*DAT_02187ca0);
                FUN_02187490(1);
              }
            }
            else {
              FUN_02186d04(*DAT_02187ca0);
              FUN_02187490(8);
            }
          }
          else {
            FUN_02186d04(*DAT_02187ca0);
            FUN_02187490(8);
          }
        }
        else {
          FUN_02186d04(*DAT_02187ca0);
          FUN_02187490(8);
        }
      }
      else {
        FUN_02186d04(*DAT_02187ca0);
        FUN_02187490(8);
      }
    }
    else {
      FUN_02186d04(*DAT_02187ca0);
      FUN_02187490(1);
    }
  }
code_r0x02187f22:
  if (local_290 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f7c,local_290,0);
  }
  if (local_288 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f80,local_288,0);
  }
  if (local_280 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f70,local_280,0);
  }
  return;
}

