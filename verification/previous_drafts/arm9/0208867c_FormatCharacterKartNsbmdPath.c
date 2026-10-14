/* Decompiled C draft; module arm9; ROM address 0208867c. No matching claim. */
#include "types.h"
#include "deps/0208867c_FormatCharacterKartNsbmdPath.h"

char * FormatCharacterKartNsbmdPath(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  iVar3 = iRam02088704 *
          ((int)((ulonglong)((longlong)(int)uRam02088700 * (longlong)param_1) >> 0x20) -
          (param_1 >> 0x1f));
  lVar2 = CONCAT44(iRam02088704,iVar3);
  bVar6 = param_1 == iVar3;
  uVar5 = uRam02088700;
  if (bVar6) {
    uVar5 = uRam02088708;
  }
  if (!bVar6) {
    lVar2 = (longlong)(int)uVar5 * (longlong)param_1;
  }
  if (!bVar6) {
    lVar2 = CONCAT44((int)((ulonglong)lVar2 >> 0x20) - (param_1 >> 0x1f),uRam0208870c);
  }
  if (!bVar6) {
    uVar5 = (int)lVar2 + (int)((ulonglong)lVar2 >> 0x20) * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  }
  uVar4 = iRam02088710 + param_1 * 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  _snprintf(pcRam02088720,0x100,pcRam02088724,
            *(uint *)(uRam0208871c & 0xfffffffc) >> (uRam0208871c & 3) * 8 |
            *(uint *)(uRam0208871c & 0xfffffffc) << (uRam0208871c & 3) * -8 + 0x20,
            *(uint *)(uRam02088714 & 0xfffffffc) >> (uRam02088714 & 3) * 8 |
            *(uint *)(uRam02088714 & 0xfffffffc) << (uRam02088714 & 3) * -8 + 0x20,uVar5,
            uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uRam02088718);
  return pcRam02088720;
}

