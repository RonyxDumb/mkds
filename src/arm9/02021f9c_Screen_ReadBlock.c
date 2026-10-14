/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G2dFindBinaryBlock Common_FindBlockByMagic
#define NNS_G2dGetUnpackedScreenData Screen_ReadBlock
#include <nitro.h>

#include <nnsys/g2d/load/g2d_NSC_load.h>
#include <nnsys/g2d/g2d_Load.h>

#include "g2di_Debug.h"

#pragma thumb off
BOOL NNS_G2dGetUnpackedScreenData (void * pNscrFile, NNSG2dScreenData ** ppScrData)
{
    NNS_G2D_NULL_ASSERT(pNscrFile);
    NNS_G2D_NULL_ASSERT(ppScrData);
    NNS_G2D_ASSERTMSG(NNS_G2dIsBinFileValid(pNscrFile, NNS_G2D_BINFILE_SIG_SCRDATA,
                                            BIN_FILE_VERSION(NSCR)), "Input file is obsolete. Please use the new g2dcvtr.exe.");

    {
        NNSG2dBinaryFileHeader * pBinFile = (NNSG2dBinaryFileHeader *)pNscrFile;
        {
            NNSG2dScreenDataBlock * pBinBlk =
                (NNSG2dScreenDataBlock *)NNS_G2dFindBinaryBlock(pBinFile,
                                                                NNS_G2D_BINBLK_SIG_SCRDATA);
            if (pBinBlk) {

                *ppScrData = &(pBinBlk->screenData);
                NNS_G2D_NULL_ASSERT((*ppScrData));
                NNS_G2D_ASSERT((*ppScrData)->screenWidth > 0);
                NNS_G2D_ASSERT((*ppScrData)->screenHeight > 0);
                NNS_G2D_ASSERT(((*ppScrData)->screenWidth & 0x7) == 0);
                NNS_G2D_ASSERT(((*ppScrData)->screenHeight & 0x7) == 0);
                NNS_G2D_MINMAX_ASSERT((*ppScrData)->colorMode, NNS_G2D_SCREENCOLORMODE_16x16, NNS_G2D_SCREENCOLORMODE_256x16);
                NNS_G2D_MINMAX_ASSERT((*ppScrData)->screenFormat, NNS_G2D_SCREENFORMAT_TEXT, NNS_G2D_SCREENFORMAT_AFFINEEXT);
                NNS_G2D_ASSERT(
                    ((*ppScrData)->screenFormat != NNS_G2D_SCREENFORMAT_AFFINE)
                    || ((*ppScrData)->colorMode == NNS_G2D_SCREENCOLORMODE_256x1));
                NNS_G2D_ASSERT(
                    ((*ppScrData)->screenFormat != NNS_G2D_SCREENFORMAT_AFFINEEXT)
                    || ((*ppScrData)->colorMode == NNS_G2D_SCREENCOLORMODE_256x16));

                return TRUE;
            } else {
                *ppScrData = NULL;
                return FALSE;

            }
        }
    }
}
