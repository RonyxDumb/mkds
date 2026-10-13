/* Decompiled C draft; module arm9_ov003; ROM address 021bdd3c. No matching claim. */
#include "types.h"
#include "deps/021bdd3c_FUN_021bdd3c.h"

undefined4 FUN_021bdd3c(void)

{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int local_ac;
  int local_a8;
  int local_98;
  int local_94;
  int *local_90;
  int *local_8c;
  int local_80;
  int local_68;
  undefined1 auStack_64 [32];
  undefined1 auStack_44 [48];
  
  local_98 = 0;
  uVar8 = 0xffffffff;
  local_68 = 0;
  iVar3 = *DAT_021bdffc * 0x30 + 0x34;
  piVar4 = (int *)FUN_021bb328(1,iVar3);
  if ((piVar4 != (int *)0x0) && (local_98 = FUN_021bb328(1,iVar3), local_98 != 0)) {
    local_ac = 0;
    local_80 = 0;
    do {
      if (((0x1d < local_ac) || (*DAT_021be010 != 0)) ||
         (uVar5 = FUN_021bb354(), *DAT_021be000 <= uVar5)) goto LAB_021bdfb4;
      iVar6 = FUN_021be860(0,0,0,DAT_021be004);
      if (iVar6 == 0) {
        uVar8 = 0xfffffffe;
        break;
      }
      func_0x0200fb08((unsigned int)(uintptr_t)(auStack_44));
      func_0x0200f950((undefined4 *)(void *)(auStack_44),DAT_021be008,0,DAT_021be00c,0x13);
      bVar1 = true;
      iVar6 = local_80;
      do {
        func_0x0200dc3c(10);
        uVar5 = FUN_021bb354();
        if ((*DAT_021be000 <= uVar5) || (*DAT_021be010 != 0)) break;
        iVar7 = FUN_021be528();
        while (iVar7 != 0) {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
          switch(iVar7) {
          default:
                    /* WARNING: This code block may not be properly labeled as switch case */
            bVar1 = false;
            break;
          case 4:
          case 8:
          case 0x12:
            break;
          case 5:
            iVar7 = FUN_021be96c(*DAT_021be014,*DAT_021bdffc);
            if (iVar6 < iVar7) {
              func_0x0200f8b8((undefined4 *)(void *)(auStack_44));
              func_0x0200f950((undefined4 *)(void *)(auStack_44),DAT_021be008,0,DAT_021be00c,0x13);
              iVar6 = iVar7;
            }
            break;
          case 10:
            bVar1 = false;
            break;
          case 0x13:
            bVar1 = false;
          }
          iVar7 = FUN_021be528();
        }
      } while (bVar1);
      func_0x0200f8b8((undefined4 *)(void *)(auStack_44));
      do {
        iVar7 = FUN_021be528();
      } while (iVar7 != 0);
      if (*DAT_021be010 != 0) goto LAB_021bdfb4;
      if (*DAT_021bdffc <= iVar6) {
        uVar8 = 0xfffffffa;
        break;
      }
      local_a8 = 0;
      local_94 = *DAT_021be014;
      if (0 < iVar6) {
        local_90 = piVar4 + 2;
        piVar9 = piVar4 + 0xb;
        local_8c = piVar4;
        do {
          func_0x02134eb8(local_90,local_94 + 0xc,0x20);
          local_8c[1] = (uint)*(ushort *)(local_94 + 10);
          *(undefined1 *)((int)local_8c + *(ushort *)(local_94 + 10) + 8) = 0;
          *(ushort *)((int)local_8c + 0x32) = (ushort)((*(ushort *)(local_94 + 0x2c) & 0x10) != 0);
          *(undefined1 *)piVar9 = *(undefined1 *)(local_94 + 4);
          *(undefined1 *)((int)piVar9 + 1) = *(undefined1 *)(local_94 + 5);
          *(undefined1 *)((int)piVar9 + 2) = *(undefined1 *)(local_94 + 6);
          *(undefined1 *)((int)piVar9 + 3) = *(undefined1 *)(local_94 + 7);
          *(undefined1 *)(piVar9 + 1) = *(undefined1 *)(local_94 + 8);
          *(undefined1 *)((int)piVar9 + 5) = *(undefined1 *)(local_94 + 9);
          local_90 = local_90 + 0xc;
          local_8c = local_8c + 0xc;
          piVar9 = piVar9 + 0xc;
          local_a8 = local_a8 + 1;
          local_94 = local_94 + 0xc0;
        } while (local_a8 < iVar6);
      }
      *piVar4 = iVar6;
      if ((*DAT_021be018 != 1) &&
         (iVar7 = FUN_021be028(piVar4,(uint *)(uintptr_t)(local_98),&local_68), iVar6 = local_68, iVar7 != 0))
      goto code_r0x021bdf48;
      func_0x02134eb8((uint *)(uintptr_t)(local_98),(uint)(uintptr_t)(piVar4),iVar3);
      *DAT_021be018 = 2;
      FUN_021bb03c();
      local_ac = local_ac + 1;
    } while( true );
  }
LAB_021bdfdc:
  if (piVar4 != (int *)0x0) {
    FUN_021bb314();
  }
  if (local_98 != 0) {
    FUN_021bb314();
  }
  return uVar8;
code_r0x021bdf48:
  iVar3 = local_68 * 0x30;
  *DAT_021be01c = local_68;
  func_0x0213a2d0((uint *)(uintptr_t)(DAT_021be020),(uint)(uintptr_t)(piVar4 + local_68 * 0xc + 2));
  puVar2 = DAT_021be024;
  *DAT_021be024 = (char)piVar4[iVar6 * 0xc + 0xb];
  puVar2[1] = *(undefined1 *)((int)piVar4 + iVar3 + 0x2d);
  puVar2[2] = *(undefined1 *)((int)piVar4 + iVar3 + 0x2e);
  puVar2[3] = *(undefined1 *)((int)piVar4 + iVar3 + 0x2f);
  puVar2[4] = (char)piVar4[iVar6 * 0xc + 0xc];
  puVar2[5] = *(undefined1 *)((int)piVar4 + iVar3 + 0x31);
  FUN_021bb29c(auStack_64);
LAB_021bdfb4:
  if ((local_ac < 0x1e) && (uVar5 = FUN_021bb354(), uVar5 <= *DAT_021be000)) {
    if (*DAT_021be010 == 0) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0xfffffff8;
    }
  }
  else {
    uVar8 = 0xfffffffd;
  }
  goto LAB_021bdfdc;
}

