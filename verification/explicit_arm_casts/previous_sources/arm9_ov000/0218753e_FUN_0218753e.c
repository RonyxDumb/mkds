/* Decompiled C draft; module arm9_ov000; ROM address 0218753e. No matching claim. */
#include "types.h"
#include "deps/0218753e_FUN_0218753e.h"

void FUN_0218753e(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *unaff_r4;
  int *unaff_r5;
  int *unaff_r6;
  int iVar7;
  int in_stack_00000008;
  int in_stack_00000010;
  int in_stack_00000018;
  int iStack0000001c;
  int in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000038;
  undefined1 in_stack_0000003c;
  undefined4 in_stack_00000040;
  int in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000064;
  undefined1 in_stack_00000068;
  int in_stack_0000006c;
  undefined1 in_stack_00000070;
  undefined4 in_stack_00000074;
  int in_stack_00000078;
  undefined2 in_stack_0000007c;
  int in_stack_00000084;
  int in_stack_00000088;
  undefined4 in_stack_000000bc;
  
  *unaff_r6 = *DAT_02187890;
  unaff_r6[1] = 1;
  unaff_r6[2] = in_stack_00000028;
  unaff_r6[3] = DAT_02187894;
  iVar3 = *unaff_r5;
  unaff_r6[4] = *(int *)(iVar3 + DAT_02187898);
  unaff_r6[5] = *(int *)(iVar3 + DAT_0218789c);
  unaff_r6[7] = DAT_021878a0;
  *(undefined4 *)(iVar3 + 4) = in_stack_0000002c;
  iVar3 = FUN_021873d4(*unaff_r4,unaff_r6);
  if (iVar3 != 0) {
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(1);
    FUN_02187f22();
  }
  iVar3 = FUN_0218735c(*unaff_r4);
  if (iVar3 != 0) {
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(1);
    FUN_02187f22();
  }
  FUN_021872bc(*unaff_r4);
  if (*(int *)(*unaff_r4 + DAT_021878a4) != 0) {
    func_0x0200e084(*unaff_r4 + DAT_021878a8);
  }
  iVar7 = *unaff_r4;
  iVar3 = *(int *)(iVar7 + 0x24);
  if (iVar3 == 2) {
    *(undefined4 *)(*DAT_02187888 + 4) = 0xffffffff;
LAB_021875d0:
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(3);
    FUN_02187f22();
  }
  else if (iVar3 != 8) goto LAB_021875d0;
  iVar3 = FUN_021866fc(*unaff_r5 + 8,0x20,in_stack_00000030,*(undefined4 *)(iVar7 + DAT_021878ac));
  if (iVar3 != 1) {
    FUN_02186d04(*DAT_02187884);
    FUN_02187490(2);
    FUN_02187f22();
  }
  FUN_021866b8(*unaff_r5 + 8,0x20,DAT_021878b0);
  iVar3 = func_0x0213bf90();
  if (*DAT_021878b4 == 0x22) {
    FUN_02187490(2);
    FUN_02187f22();
  }
  if (iVar3 != 200) {
    if (iVar3 != DAT_021878b8) {
      FUN_02186d04(*DAT_02187884);
      FUN_02187490(10);
      goto code_r0x02187f22;
    }
    iVar7 = *unaff_r5;
    if (*(int *)(iVar7 + DAT_021878bc) != 0) {
      *(undefined4 *)(iVar7 + 4) = 0xfffffffa;
      FUN_02186d04(*DAT_02187884);
      puVar1 = DAT_0218788c;
      uVar4 = *DAT_021878c0;
      *DAT_0218788c = uVar4;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = DAT_021878c4;
      iVar3 = *DAT_02187888;
      puVar1[4] = *(undefined4 *)(iVar3 + DAT_02187898);
      puVar1[5] = *(undefined4 *)(iVar3 + DAT_0218789c);
      puVar1[7] = DAT_021878a0;
      iVar3 = func_0x0213a074(uVar4,DAT_021878c8);
      if (iVar3 != 0) {
        DAT_0218788c[6] = 1;
      }
      iVar3 = FUN_021873d4(*DAT_02187884,DAT_0218788c);
      if (iVar3 != 0) {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(1);
        FUN_02187f22();
      }
      iVar3 = FUN_02185984(*DAT_02187884,DAT_021878cc,DAT_021878cc,*DAT_02187888 + 8);
      if (iVar3 != 0) {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(8);
        FUN_02187f22();
      }
      iVar3 = FUN_02186b0c(*DAT_02187884,DAT_021878d0,DAT_021878d4,7);
      if (iVar3 != 0) {
        FUN_02186d04(*DAT_02187884);
        FUN_02187490(8);
        FUN_02187f22();
      }
      uVar4 = func_0x0200fca0();
      func_0x0214d168(&stack0x00000098,0,0x21);
      FUN_021a6abc(&stack0x0000007c);
      uVar5 = FUN_021a6abc(0);
      func_0x0214d1fc(uVar5,&stack0x00000098,in_stack_0000007c);
      func_0x0200fcb4(uVar4);
      uVar4 = func_0x0213a434(&stack0x00000098);
      iVar3 = FUN_02186b0c(*DAT_02187884,DAT_021878d8,&stack0x00000098,uVar4);
      if (iVar3 == 0) {
        uVar5 = *(undefined4 *)(*DAT_02187888 + DAT_021878bc);
        uVar4 = func_0x0213a434(uVar5);
        iVar3 = FUN_02186b0c(*DAT_02187884,DAT_021878dc,uVar5,uVar4);
        if (iVar3 == 0) {
          (**(code **)(*DAT_02187888 + DAT_0218789c))
                    (DAT_021878e0,*(undefined4 *)(*DAT_02187888 + DAT_021878bc),0);
          *(undefined4 *)(*DAT_02187888 + DAT_021878bc) = 0;
          iVar3 = FUN_0218735c(*DAT_02187884);
          if (iVar3 == 0) {
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
    iVar7 = FUN_021866b8(iVar7 + 8,0x20,DAT_021878e4);
    if (iVar7 == 0) {
      FUN_02186d04(*DAT_02187884);
      FUN_02187490(2);
      goto code_r0x02187f22;
    }
    iVar6 = func_0x0213a434();
    uVar4 = (**(code **)(*unaff_r5 + DAT_02187898))(DAT_021878e8,iVar6 + 1);
    *(undefined4 *)(*unaff_r5 + DAT_021878ec) = uVar4;
    iVar6 = *(int *)(*unaff_r5 + DAT_021878ec);
    if (iVar6 == 0) {
      FUN_02186d04(*DAT_02187884);
      FUN_02187490(4);
      goto code_r0x02187f22;
    }
    uVar4 = func_0x0213a434(iVar7);
    func_0x0213a228(iVar6,iVar7,uVar4);
  }
  FUN_02186d04(*unaff_r4);
  func_0x02151910(&stack0x00000084);
  if (in_stack_00000088 == 0 && in_stack_00000084 == 0) {
    *(undefined4 *)(*unaff_r5 + 4) = in_stack_00000038;
    puVar2 = DAT_02187c80;
    *DAT_02187c80 = in_stack_0000003c;
    puVar2[0x15] = in_stack_0000003c;
    iVar7 = *unaff_r5;
    *(undefined4 *)(DAT_02187c80 + 0x24) = *(undefined4 *)(iVar7 + DAT_02187c84);
    puVar2 = DAT_02187c80;
    *(undefined4 *)(DAT_02187c80 + 0x28) = *(undefined4 *)(iVar7 + DAT_02187c88);
    iVar7 = FUN_02186560(puVar2,*unaff_r4);
    if (iVar7 != 0) {
      FUN_02187490(5);
      goto code_r0x02187f22;
    }
    FUN_02186404();
    iVar7 = FUN_021863cc();
    if (iVar7 != 0x14) {
      iVar3 = FUN_021863cc();
      if (iVar3 == 9) {
        *(undefined4 *)(*DAT_02187c8c + 4) = 0xffffffff;
      }
      else {
        FUN_0218635c(&stack0x000000bc);
        *(undefined4 *)(*DAT_02187c8c + 4) = in_stack_000000bc;
      }
      FUN_02187490(6);
      goto code_r0x02187f22;
    }
    FUN_02186430();
  }
  if (iVar3 == 200) {
    *(undefined4 *)(*DAT_02187c8c + 4) = 0;
    FUN_02187490(0xb);
  }
  else {
    *(undefined4 *)(*unaff_r5 + 4) = in_stack_00000040;
    iVar3 = *DAT_02187c90;
    *unaff_r6 = iVar3;
    unaff_r6[1] = in_stack_00000044;
    unaff_r6[2] = in_stack_00000044;
    unaff_r6[3] = DAT_02187c94;
    iVar7 = *unaff_r5;
    unaff_r6[4] = *(int *)(iVar7 + DAT_02187c84);
    unaff_r6[5] = *(int *)(iVar7 + DAT_02187c88);
    unaff_r6[7] = DAT_02187c98;
    iVar3 = func_0x0213a074(iVar3,DAT_02187c9c);
    if (iVar3 != 0) {
      unaff_r6[6] = 1;
    }
    iVar3 = FUN_021873d4(*unaff_r4,unaff_r6);
    if (iVar3 == 0) {
      iVar3 = FUN_02185984(*unaff_r4,DAT_02187ca4,DAT_02187ca4,*unaff_r5 + 8);
      if (iVar3 == 0) {
        iVar3 = FUN_02186b0c(*unaff_r4,DAT_02187ca8,DAT_02187cac,5);
        if (iVar3 == 0) {
          uVar4 = func_0x0200fca0();
          func_0x0214d168(&stack0x00000098,in_stack_00000048,0x21);
          FUN_021a6abc(&stack0x0000007c);
          uVar5 = FUN_021a6abc(in_stack_0000004c);
          func_0x0214d1fc(uVar5,&stack0x00000098,in_stack_0000007c);
          func_0x0200fcb4(uVar4);
          uVar4 = func_0x0213a434(&stack0x00000098);
          iVar3 = FUN_02186b0c(*unaff_r4,DAT_02187cb0,&stack0x00000098,uVar4);
          if (iVar3 == 0) {
            uVar5 = *(undefined4 *)(*unaff_r5 + DAT_02187cb4);
            uVar4 = func_0x0213a434(uVar5);
            iVar3 = FUN_02186b0c(*unaff_r4,DAT_02187cb8,uVar5,uVar4);
            if (iVar3 == 0) {
              (**(code **)(*unaff_r5 + DAT_02187c88))
                        (DAT_02187cbc,*(undefined4 *)(*unaff_r5 + DAT_02187cb4),in_stack_00000050);
              *(undefined4 *)(*unaff_r5 + DAT_02187cb4) = in_stack_00000054;
              iVar3 = FUN_0218735c(*unaff_r4);
              if (iVar3 == 0) {
                FUN_021872bc(*unaff_r4);
                if (*(int *)(*unaff_r4 + DAT_02187cc0) != 0) {
                  func_0x0200e084(*unaff_r4 + DAT_02187cc4);
                }
                iVar3 = *(int *)(*unaff_r4 + 0x24);
                if (iVar3 == 2) {
                  *(undefined4 *)(*DAT_02187c8c + 4) = 0xffffffff;
                }
                else if (iVar3 == 8) {
                  iVar3 = FUN_021866fc(*unaff_r5 + 8,0x20,in_stack_00000058,
                                       *(undefined4 *)(*unaff_r4 + DAT_02187cc8));
                  if (iVar3 == 1) {
                    FUN_021866b8(*unaff_r5 + 8,0x20,DAT_02187ccc);
                    iVar3 = func_0x0213bf90();
                    if (*DAT_02187cd0 == 0x22) {
                      FUN_02186d04(*DAT_02187ca0);
                      FUN_02187490(2);
                    }
                    else if (iVar3 == 200) {
                      iVar3 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187cd4,&stack0x0000007e);
                      if (iVar3 < 1) {
                        FUN_02186d04(*DAT_02187ca0);
                        FUN_02187490(9);
                      }
                      else {
                        iVar3 = func_0x0213bf90(&stack0x0000007e);
                        if (*DAT_02187cd0 == 0x22) {
                          FUN_02186d04(*DAT_02187ca0);
                          FUN_02187490(9);
                        }
                        else if (iVar3 < 100) {
                          iVar3 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187cd8,in_stack_0000005c);
                          if (iVar3 < 1) {
                            FUN_02186d04(*DAT_02187ca0);
                            FUN_02187490(9);
                          }
                          else {
                            iVar7 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187cdc,in_stack_00000060);
                            if (iVar7 < 1) {
                              FUN_02186d04(*DAT_02187ca0);
                              FUN_02187490(9);
                            }
                            else {
                              iVar6 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187ce0,in_stack_00000064
                                                  );
                              in_stack_00000008 =
                                   (**(code **)(*unaff_r5 + DAT_02187c84))(DAT_02187cd8,iVar3 + 1);
                              if (in_stack_00000008 == 0) {
                                FUN_02186d04(*DAT_02187ca0);
                                FUN_02187490(4);
                              }
                              else {
                                in_stack_00000010 =
                                     (**(code **)(*unaff_r5 + DAT_02187c84))(DAT_02187cdc,iVar7 + 1)
                                ;
                                if (in_stack_00000010 == 0) {
                                  FUN_02186d04(*DAT_02187ca0);
                                  FUN_02187490(4);
                                }
                                else if ((iVar6 < 1) ||
                                        (in_stack_00000018 =
                                              (**(code **)(*unaff_r5 + DAT_02187f74))
                                                        (DAT_02187f70,iVar6 + 1),
                                        in_stack_00000018 != 0)) {
                                  iVar3 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187f7c,
                                                       in_stack_00000008);
                                  if (iVar3 < 0) {
                                    FUN_02186d04(*DAT_02187f78);
                                    FUN_02187490(9);
                                  }
                                  else {
                                    *(undefined1 *)(in_stack_00000008 + iVar3) = in_stack_00000068;
                                    iVar3 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187f80,
                                                         in_stack_00000010);
                                    if (iVar3 < 0) {
                                      FUN_02186d04(*DAT_02187f78);
                                      FUN_02187490(9);
                                    }
                                    else {
                                      *(char *)(in_stack_00000010 + iVar3) = (char)in_stack_0000006c
                                      ;
                                      iStack0000001c = in_stack_0000006c;
                                      if (0 < iVar6) {
                                        iVar3 = FUN_02186674(*unaff_r5 + 8,0x20,DAT_02187f70,
                                                             in_stack_00000018);
                                        if (iVar3 < 0) {
                                          FUN_02186d04(*DAT_02187f78);
                                          FUN_02187490(9);
                                          goto code_r0x02187f22;
                                        }
                                        *(undefined1 *)(in_stack_00000018 + iVar3) =
                                             in_stack_00000070;
                                        iStack0000001c = func_0x0213bf90(in_stack_00000018);
                                        if (*DAT_02187f84 == 0x22) {
                                          FUN_02186d04(*DAT_02187f78);
                                          FUN_02187490(9);
                                          goto code_r0x02187f22;
                                        }
                                        iStack0000001c = DAT_02187f88 * iStack0000001c;
                                        if (iStack0000001c - DAT_02187f8c != 0 &&
                                            DAT_02187f8c <= iStack0000001c) {
                                          iStack0000001c = DAT_02187f8c;
                                        }
                                      }
                                      FUN_02186d04(*unaff_r4);
                                      *(undefined4 *)(*unaff_r5 + 4) = in_stack_00000074;
                                      *unaff_r6 = in_stack_00000008;
                                      unaff_r6[1] = in_stack_00000078;
                                      unaff_r6[2] = in_stack_00000078;
                                      unaff_r6[3] = DAT_02187f90;
                                      iVar3 = *unaff_r5;
                                      unaff_r6[4] = *(int *)(iVar3 + DAT_02187f74);
                                      unaff_r6[5] = *(int *)(iVar3 + DAT_02187f94);
                                      unaff_r6[7] = DAT_02187f98;
                                      iVar3 = FUN_021873d4(*unaff_r4,unaff_r6);
                                      if (iVar3 == 0) {
                                        iVar3 = FUN_02186a9c(*unaff_r4,in_stack_00000010);
                                        if (iVar3 == 0) {
                                          iVar3 = FUN_0218735c(*unaff_r4);
                                          if (iVar3 == 0) {
                                            FUN_021872bc(*unaff_r4);
                                            if (*(int *)(*unaff_r4 + DAT_02187f9c) != 0) {
                                              func_0x0200e084(*unaff_r4 + DAT_02187fa0);
                                            }
                                            iVar3 = *(int *)(*unaff_r4 + 0x24);
                                            if (iVar3 == 2) {
                                              *(undefined4 *)(*DAT_02187fa4 + 4) = 0xffffffff;
                                            }
                                            else if (iVar3 == 8) {
                                              iVar3 = FUN_021866fc(*unaff_r5 + 8,0x20,1,
                                                                   *(undefined4 *)
                                                                    (*unaff_r4 + DAT_02187fa8));
                                              if (iVar3 == 1) {
                                                iVar3 = FUN_021866b8(*unaff_r5 + 8,0x20,DAT_02187fac
                                                                    );
                                                if (iVar3 == 0) {
                                                  FUN_02186d04(*DAT_02187f78);
                                                  FUN_02187490(2);
                                                }
                                                else {
                                                  iVar7 = func_0x0213a434();
                                                  uVar4 = (**(code **)(*unaff_r5 + DAT_02187f74))
                                                                    (DAT_02187fb0,iVar7 + 1);
                                                  *(undefined4 *)(*unaff_r5 + DAT_02187fb4) = uVar4;
                                                  iVar7 = *(int *)(*unaff_r5 + DAT_02187fb4);
                                                  if (iVar7 == 0) {
                                                    FUN_02186d04(*DAT_02187f78);
                                                    FUN_02187490(4);
                                                  }
                                                  else {
                                                    uVar4 = func_0x0213a434(iVar3);
                                                    func_0x0213a228(iVar7,iVar3,uVar4);
                                                    FUN_02186d04(*unaff_r4);
                                                    func_0x0200dc3c(iStack0000001c);
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
  if (in_stack_00000008 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f7c,in_stack_00000008,0);
  }
  if (in_stack_00000010 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f80,in_stack_00000010,0);
  }
  if (in_stack_00000018 != 0) {
    (**(code **)(*DAT_02187fa4 + DAT_02187f94))(DAT_02187f70,in_stack_00000018,0);
  }
  return;
}

