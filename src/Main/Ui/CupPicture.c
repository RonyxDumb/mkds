#include "Main/Ui/CupPicture.h"
#include "Main/System/ArchiveFiles.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02134398.h"
#include "Main/Unknown/unk_0216a000.h"

#pragma opt_propagation off

#pragma thumb on
void cpic_finalize(void) {
    gCupPicture = NULL;
}

void cpic_loadPalette(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", aDataCuppictureSelect_cup_, nitroOrRetro == 0 ? aNitro : aRetro,
             pictureNumber, "_m_b.NCLR");
    arc_readFileToEnd(buf, gCupPicture->mCupPictureNclrFile, 0x228);
    g2du_unpackPaletteData(&gCupPicture->mCupPictureNclr, gCupPicture->mCupPictureNclrFile);
}

void cpic_loadCharacter(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", aDataCuppictureSelect_cup_, nitroOrRetro == 0 ? aNitro : aRetro,
             pictureNumber, "_m_b.NCGR");
    arc_readFileToEnd(buf, gCupPicture->mCupPictureNcgrFile, 0xe00);
    g2du_unpackCharacterDataBG(&gCupPicture->mCupPictureNcgr, gCupPicture->mCupPictureNcgrFile);
}

void cpic_loadScreen(void) {
    char buf[0x100];
    s32 pictureIndex;
    s32 nitroOrRetro;
    s32 pictureNumber;

    pictureIndex = gCupPicture->mCupPictureIndex;
    nitroOrRetro = data_0216aea8[pictureIndex * 2];
    pictureNumber = data_0216aeac[pictureIndex * 2];
    snprintf(buf, 0x100, "%s%s%02d%s", aDataCuppictureSelect_cup_, nitroOrRetro == 0 ? aNitro : aRetro,
             pictureNumber, "_m_picture.NSCR");
    arc_readFileToEnd(buf, gCupPicture->mCupPictureNscrFile, 0x824);
    g2du_unpackScreenData(&gCupPicture->mCupPictureNscr, gCupPicture->mCupPictureNscrFile);
}
#pragma thumb off
