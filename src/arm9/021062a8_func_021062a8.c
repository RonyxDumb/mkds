/* Decompiled C draft; module arm9; ROM address 021062a8. No matching claim. */
#include "types.h"
#include "deps/021062a8_func_021062a8.h"

void func_021062a8(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = DAT_02106534;
  uVar2 = *(uint *)(DAT_02106530 & 0xfffffffc) >> (DAT_02106530 & 3) * 8 |
          *(uint *)(DAT_02106530 & 0xfffffffc) << (DAT_02106530 & 3) * -8 + 0x20;
  uVar4 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar5 = iVar1;
  switch(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) {
  case 0xb:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106564;
    }
    break;
  case 0xc:
    break;
  case 0xd:
    break;
  case 0xe:
    break;
  case 0xf:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106560;
    }
    break;
  case 0x10:
    break;
  case 0x11:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106558;
    }
    break;
  case 0x12:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106544;
    }
    break;
  case 0x13:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
    iVar5 = DAT_0210654c;
    if (uVar4 != 10) {
      if (uVar4 == 0xa0) {
        func_0212c6f0(DAT_02106550,0x3c);
        iVar5 = iVar1;
      }
      else {
        iVar5 = iVar1;
        if (uVar4 == DAT_02106548) {
          iVar5 = DAT_0210654c;
        }
      }
    }
    break;
  case 0x14:
    break;
  case 0x15:
    break;
  case 0x16:
    break;
  case 0x17:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106568;
    }
    break;
  case 0x18:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_0210653c;
    }
    break;
  case 0x19:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_0210655c;
    }
    break;
  case 0x1a:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106540;
    }
    break;
  case 0x1b:
    break;
  case 0x1c:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 0x28) {
      iVar5 = DAT_02106574;
    }
    break;
  case 0x1d:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 0x28) {
      iVar5 = DAT_02106570;
    }
    break;
  case 0x1e:
    break;
  case 0x1f:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106560;
    }
    break;
  case 0x20:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_02106554;
    }
    break;
  case 0x21:
    break;
  case 0x22:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = 0x1bc;
    }
    break;
  case 0x23:
    break;
  case 0x24:
    break;
  case 0x25:
    uVar4 = DAT_02106538 + 4U & 3;
    uVar2 = *(uint *)(DAT_02106538 + 4U & 0xfffffffc);
    if ((uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) == 10) {
      iVar5 = DAT_0210656c;
    }
  }
  if (iVar5 == DAT_02106534) {
    return;
  }
  func_0212c6f0(DAT_02106550,0);
  uVar4 = DAT_02106550;
  if (((*(uint *)(DAT_02106578 & 0xfffffffc) >> (DAT_02106578 & 3) * 8 |
       *(uint *)(DAT_02106578 & 0xfffffffc) << (DAT_02106578 & 3) * -8 + 0x20) & 2) == 0) {
    return;
  }
  uVar2 = DAT_0210657c + 0xcU & 3;
  uVar3 = *(uint *)(DAT_0210657c + 0xcU & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
    return;
  }
  if (*(uint *)(DAT_02106550 & 0xfffffffc) >> (DAT_02106550 & 3) * 8 != 0 ||
      *(uint *)(DAT_02106550 & 0xfffffffc) << (DAT_02106550 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(DAT_02106550,0);
  }
  if (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 != 0 ||
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20 != 0) {
    func_0212c6f0(uVar4,0);
  }
  NNSi_MaybeSndPlayerStartSeq(uVar4,0,iVar5);
  return;
}

