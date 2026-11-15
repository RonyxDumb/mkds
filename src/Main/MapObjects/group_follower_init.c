#include "Main/MapObjects/group_follower_init.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/MapObjects/group_paths.h"

const u8 gItemObjectResponsesHundreds5Item2[16] = {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item11[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds2Effect3[12] = {0xf, 0, 2, 2, 2, 0, 2, 0, 2, 2, 2, 0};
const u8 gItemObjectFirstResponsesHundreds2Item8[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item3[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item5[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item5[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item6[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds0Effect1[20] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item8[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds0Effect2[20] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item11[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item9[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item0[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item13[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectResponsesHundreds2Item12[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item13[16] = {3, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item7[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item11[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item6[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item7[16] = {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item13[48] = {3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item2[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0};
const u8 gItemObjectResponsesHundreds0Item2[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item8[16] = {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item6[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item9[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds5Effect0[16] = {0xf, 0xd, 0xd, 0xc, 0xd, 0xc, 0xc, 0xc, 0xa, 4, 0xa, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds1Effect1[16] = {5, 1, 0, 3, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item11[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds2Effect1[12] = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds5Effect1[16] = {5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item10[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item6[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item1[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item9[40] = {3, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 1, 0, 0, 0, 2, 1,
                                                   2, 2, 1, 2, 1, 1, 0, 0, 2, 0, 2, 0, 2, 2, 2, 0, 1, 1, 0, 0};
const u8 gItemObjectResponsesHundreds3Item13[48] = {3, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                    0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds3Effect1[48] = {0xf, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                                               0,   0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0,
                                               0,   0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item2[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item10[40] = {3, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2,
                                                    2, 2, 2, 2, 2, 2, 0, 0, 2, 0, 2, 0, 2, 2, 2, 0, 2, 2, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item7[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item2[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item9[16] = {3, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds3Effect0[48] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item6[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item3[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds4Effect1[40] = {0xf, 0, 1, 1, 0,   1, 1, 2, 0, 0, 1, 0, 1, 0, 2, 0, 0,   0,   1, 2,
                                               0,   1, 0, 0, 0xc, 2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0xc, 0xc, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item2[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item9[16] = {3, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item10[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item7[16] = {3, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds3Effect2[48] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item12[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item9[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item13[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item10[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds5Effect3[16] = {5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item5[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds4Effect2[40] = {0xf, 0, 0, 0, 0,   0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0,   0,   0, 2,
                                               0,   0, 0, 0, 0xc, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0xc, 0xc, 0, 0};
const u8 *gItemObjectResponsesByKind[6][14] = {
    {gItemObjectResponsesHundreds0Item0, gItemObjectResponsesHundreds0Item1, gItemObjectResponsesHundreds0Item2,
     gItemObjectResponsesHundreds0Item3, gItemObjectResponsesHundreds0Item4, gItemObjectResponsesHundreds0Item5,
     gItemObjectResponsesHundreds0Item6, gItemObjectResponsesHundreds0Item7, gItemObjectResponsesHundreds0Item8,
     gItemObjectResponsesHundreds0Item9, gItemObjectResponsesHundreds0Item10, gItemObjectResponsesHundreds0Item11,
     gItemObjectResponsesHundreds0Item12, gItemObjectResponsesHundreds0Item13},
    {gItemObjectResponsesHundreds1Item0, gItemObjectResponsesHundreds1Item1, gItemObjectResponsesHundreds1Item2,
     gItemObjectResponsesHundreds1Item3, gItemObjectResponsesHundreds1Item4, gItemObjectResponsesHundreds1Item5,
     gItemObjectResponsesHundreds1Item6, gItemObjectResponsesHundreds1Item7, gItemObjectResponsesHundreds1Item8,
     gItemObjectResponsesHundreds1Item9, gItemObjectResponsesHundreds1Item10, gItemObjectResponsesHundreds1Item11,
     gItemObjectResponsesHundreds1Item12, gItemObjectResponsesHundreds1Item13},
    {gItemObjectResponsesHundreds2Item0, gItemObjectResponsesHundreds2Item1, gItemObjectResponsesHundreds2Item2,
     gItemObjectResponsesHundreds2Item3, gItemObjectResponsesHundreds2Item4, gItemObjectResponsesHundreds2Item5,
     gItemObjectResponsesHundreds2Item6, gItemObjectResponsesHundreds2Item7, gItemObjectResponsesHundreds2Item8,
     gItemObjectResponsesHundreds2Item9, gItemObjectResponsesHundreds2Item10, gItemObjectResponsesHundreds2Item11,
     gItemObjectResponsesHundreds2Item12, gItemObjectResponsesHundreds2Item13},
    {gItemObjectResponsesHundreds3Item0, gItemObjectResponsesHundreds3Item1, gItemObjectResponsesHundreds3Item2,
     gItemObjectResponsesHundreds3Item3, gItemObjectResponsesHundreds3Item4, gItemObjectResponsesHundreds3Item5,
     gItemObjectResponsesHundreds3Item6, gItemObjectResponsesHundreds3Item7, gItemObjectResponsesHundreds3Item8,
     gItemObjectResponsesHundreds3Item9, gItemObjectResponsesHundreds3Item10, gItemObjectResponsesHundreds3Item11,
     gItemObjectResponsesHundreds3Item12, gItemObjectResponsesHundreds3Item13},
    {gItemObjectResponsesHundreds4Item0, gItemObjectResponsesHundreds4Item1, gItemObjectResponsesHundreds4Item2,
     gItemObjectResponsesHundreds4Item3, gItemObjectResponsesHundreds4Item4, gItemObjectResponsesHundreds4Item5,
     gItemObjectResponsesHundreds4Item6, gItemObjectResponsesHundreds4Item7, gItemObjectResponsesHundreds4Item8,
     gItemObjectResponsesHundreds4Item9, gItemObjectResponsesHundreds4Item10, gItemObjectResponsesHundreds4Item11,
     gItemObjectResponsesHundreds4Item12, gItemObjectResponsesHundreds4Item13},
    {gItemObjectResponsesHundreds5Item0, gItemObjectResponsesHundreds5Item1, gItemObjectResponsesHundreds5Item2,
     gItemObjectResponsesHundreds5Item3, gItemObjectResponsesHundreds5Item4, gItemObjectResponsesHundreds5Item5,
     gItemObjectResponsesHundreds5Item6, gItemObjectResponsesHundreds5Item7, gItemObjectResponsesHundreds5Item8,
     gItemObjectResponsesHundreds5Item9, gItemObjectResponsesHundreds5Item10, gItemObjectResponsesHundreds5Item11,
     gItemObjectResponsesHundreds5Item12, gItemObjectResponsesHundreds5Item13}};
const u8 gItemObjectFirstResponsesHundreds0Item6[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item12[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds1Effect0[16] = {0xf, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item1[16] = {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item13[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item1[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item7[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item3[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item6[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item5[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item2[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gKartResponsesHundreds4Effect3[40] = {0xf, 0, 1, 1, 0,   1, 1, 2, 0, 0, 1, 0, 1, 0, 2, 0, 0,   0,   1, 2,
                                               0,   1, 0, 0, 0xc, 2, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0xc, 0xc, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item5[40] = {3, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                                                        0, 1, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds2Effect1[12] = {0xf, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0};
const u8 gItemObjectFirstResponsesHundreds0Item11[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item7[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item7[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item11[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item13[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds4Effect1[40] = {5, 1, 1, 1, 1, 1, 1, 0, 0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                                                    0, 1, 1, 4, 4, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 4, 4, 0, 0};
const u8 gKartFirstResponsesHundreds4Effect2[40] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0};
const u8 gKartResponsesHundreds0Effect2[20] = {0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item7[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item8[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds1Effect2[16] = {0xf, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item4[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item9[40] = {3, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                                                        0, 1, 0, 2, 2, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 2, 2, 0, 0};
const u8 gKartFirstResponsesHundreds5Effect0[16] = {5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds5Effect2[16] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item11[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item13[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item0[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds2Effect0[12] = {0xf, 0, 2, 2, 2, 4, 2, 8, 2, 2, 2, 0};
const u8 gKartFirstResponsesHundreds0Effect0[20] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item0[40] = {3, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 2, 2, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0};
const u8 gItemObjectResponsesHundreds3Item1[48] = {3, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0,
                                                   0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item0[16] = {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item11[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item1[40] = {3, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item8[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectResponsesHundreds3Item2[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item3[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item12[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item2[40] = {3, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
                                                   2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item11[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item3[40] = {3, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
                                                   2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0};
const u8 gItemObjectResponsesHundreds3Item4[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds5Effect1[16] = {0xf, 0xd, 0xd, 0xc, 0xd, 0xc, 0xc, 0xc, 2, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item1[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item4[16] = {3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item4[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item8[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item9[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectResponsesHundreds3Item5[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item0[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds0Effect3[20] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds1Effect3[16] = {0xf, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item5[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item6[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item5[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item1[16] = {3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item0[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item7[40] = {3, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
                                                   2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item9[16] = {3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item10[48] = {3, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0,
                                                    0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item8[40] = {3, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
                                                   2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0};
const u8 gItemObjectResponsesHundreds3Item12[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item7[12] = {3, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectFirstResponsesHundreds2Item1[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds5Effect2[16] = {0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 *gKartFirstResponsesByKind[6][4] = {{gKartFirstResponsesHundreds0Effect0, gKartFirstResponsesHundreds0Effect1,
                                              gKartFirstResponsesHundreds0Effect2, gKartFirstResponsesHundreds0Effect3},
                                             {gKartFirstResponsesHundreds1Effect0, gKartFirstResponsesHundreds1Effect1,
                                              gKartFirstResponsesHundreds1Effect2, gKartFirstResponsesHundreds1Effect3},
                                             {gKartFirstResponsesHundreds2Effect0, gKartFirstResponsesHundreds2Effect1,
                                              gKartFirstResponsesHundreds2Effect2, gKartFirstResponsesHundreds2Effect3},
                                             {gKartFirstResponsesHundreds3Effect0, gKartFirstResponsesHundreds3Effect1,
                                              gKartFirstResponsesHundreds3Effect2, gKartFirstResponsesHundreds3Effect3},
                                             {gKartFirstResponsesHundreds4Effect0, gKartFirstResponsesHundreds4Effect1,
                                              gKartFirstResponsesHundreds4Effect2, gKartFirstResponsesHundreds4Effect3},
                                             {gKartFirstResponsesHundreds5Effect0, gKartFirstResponsesHundreds5Effect1,
                                              gKartFirstResponsesHundreds5Effect2,
                                              gKartFirstResponsesHundreds5Effect3}};
const u8 gKartResponsesHundreds3Effect3[48] = {0xf, 0, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                                               0,   0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0,
                                               0,   0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item11[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds3Effect1[48] = {5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds1Effect1[16] = {0xf, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item8[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item11[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds1Effect0[16] = {5, 1, 0, 3, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds4Effect0[40] = {0xf, 4,   0xa, 2, 0xb, 9,   0xa, 2,   5,   7,   9,   4, 9, 0xa,
                                               2,   0xc, 0,   0, 0xa, 2,   5,   0xa, 4,   7,   0xc, 2, 0, 5,
                                               4,   0,   5,   5, 0xa, 0xa, 9,   0,   0xc, 0xc, 5,   0};
const u8 gItemObjectResponsesHundreds5Item10[16] = {3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item6[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds2Effect2[12] = {0xf, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0};
const u8 gItemObjectFirstResponsesHundreds2Item12[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item2[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item4[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item5[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item6[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item2[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item12[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item0[16] = {3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds4Effect3[40] = {5, 1, 1, 1, 1, 1, 1, 0, 0, 2, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                                                    0, 1, 1, 4, 4, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 4, 4, 0, 0};
const u8 gItemObjectResponsesHundreds2Item1[12] = {3, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0};
const u8 gItemObjectFirstResponsesHundreds3Item8[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item10[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item4[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item10[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item11[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 *gKartResponsesByKind[6][4] = {{gKartResponsesHundreds0Effect0, gKartResponsesHundreds0Effect1,
                                         gKartResponsesHundreds0Effect2, gKartResponsesHundreds0Effect3},
                                        {gKartResponsesHundreds1Effect0, gKartResponsesHundreds1Effect1,
                                         gKartResponsesHundreds1Effect2, gKartResponsesHundreds1Effect3},
                                        {gKartResponsesHundreds2Effect0, gKartResponsesHundreds2Effect1,
                                         gKartResponsesHundreds2Effect2, gKartResponsesHundreds2Effect3},
                                        {gKartResponsesHundreds3Effect0, gKartResponsesHundreds3Effect1,
                                         gKartResponsesHundreds3Effect2, gKartResponsesHundreds3Effect3},
                                        {gKartResponsesHundreds4Effect0, gKartResponsesHundreds4Effect1,
                                         gKartResponsesHundreds4Effect2, gKartResponsesHundreds4Effect3},
                                        {gKartResponsesHundreds5Effect0, gKartResponsesHundreds5Effect1,
                                         gKartResponsesHundreds5Effect2, gKartResponsesHundreds5Effect3}};
const u8 gItemObjectResponsesHundreds1Item0[16] = {3, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item0[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item8[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item13[16] = {3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item3[16] = {3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item12[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item12[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item1[16] = {3, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item7[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item4[16] = {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item8[16] = {3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item10[16] = {3, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item1[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item5[16] = {3, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item10[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds1Item3[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds1Effect2[16] = {5, 1, 0, 3, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item3[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0};
const u8 gItemObjectResponsesHundreds2Item0[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectFirstResponsesHundreds5Item13[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item4[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item10[12] = {3, 0, 2, 2, 2, 0, 2, 2, 2, 2, 2, 0};
const u8 gKartFirstResponsesHundreds3Effect3[48] = {5, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 *gItemObjectFirstResponsesByKind[6][14] = {
    {gItemObjectFirstResponsesHundreds0Item0, gItemObjectFirstResponsesHundreds0Item1,
     gItemObjectFirstResponsesHundreds0Item2, gItemObjectFirstResponsesHundreds0Item3,
     gItemObjectFirstResponsesHundreds0Item4, gItemObjectFirstResponsesHundreds0Item5,
     gItemObjectFirstResponsesHundreds0Item6, gItemObjectFirstResponsesHundreds0Item7,
     gItemObjectFirstResponsesHundreds0Item8, gItemObjectFirstResponsesHundreds0Item9,
     gItemObjectFirstResponsesHundreds0Item10, gItemObjectFirstResponsesHundreds0Item11,
     gItemObjectFirstResponsesHundreds0Item12, gItemObjectFirstResponsesHundreds0Item13},
    {gItemObjectFirstResponsesHundreds1Item0, gItemObjectFirstResponsesHundreds1Item1,
     gItemObjectFirstResponsesHundreds1Item2, gItemObjectFirstResponsesHundreds1Item3,
     gItemObjectFirstResponsesHundreds1Item4, gItemObjectFirstResponsesHundreds1Item5,
     gItemObjectFirstResponsesHundreds1Item6, gItemObjectFirstResponsesHundreds1Item7,
     gItemObjectFirstResponsesHundreds1Item8, gItemObjectFirstResponsesHundreds1Item9,
     gItemObjectFirstResponsesHundreds1Item10, gItemObjectFirstResponsesHundreds1Item11,
     gItemObjectFirstResponsesHundreds1Item12, gItemObjectFirstResponsesHundreds1Item13},
    {gItemObjectFirstResponsesHundreds2Item0, gItemObjectFirstResponsesHundreds2Item1,
     gItemObjectFirstResponsesHundreds2Item2, gItemObjectFirstResponsesHundreds2Item3,
     gItemObjectFirstResponsesHundreds2Item4, gItemObjectFirstResponsesHundreds2Item5,
     gItemObjectFirstResponsesHundreds2Item6, gItemObjectFirstResponsesHundreds2Item7,
     gItemObjectFirstResponsesHundreds2Item8, gItemObjectFirstResponsesHundreds2Item9,
     gItemObjectFirstResponsesHundreds2Item10, gItemObjectFirstResponsesHundreds2Item11,
     gItemObjectFirstResponsesHundreds2Item12, gItemObjectFirstResponsesHundreds2Item13},
    {gItemObjectFirstResponsesHundreds3Item0, gItemObjectFirstResponsesHundreds3Item1,
     gItemObjectFirstResponsesHundreds3Item2, gItemObjectFirstResponsesHundreds3Item3,
     gItemObjectFirstResponsesHundreds3Item4, gItemObjectFirstResponsesHundreds3Item5,
     gItemObjectFirstResponsesHundreds3Item6, gItemObjectFirstResponsesHundreds3Item7,
     gItemObjectFirstResponsesHundreds3Item8, gItemObjectFirstResponsesHundreds3Item9,
     gItemObjectFirstResponsesHundreds3Item10, gItemObjectFirstResponsesHundreds3Item11,
     gItemObjectFirstResponsesHundreds3Item12, gItemObjectFirstResponsesHundreds3Item13},
    {gItemObjectFirstResponsesHundreds4Item0, gItemObjectFirstResponsesHundreds4Item1,
     gItemObjectFirstResponsesHundreds4Item2, gItemObjectFirstResponsesHundreds4Item3,
     gItemObjectFirstResponsesHundreds4Item4, gItemObjectFirstResponsesHundreds4Item5,
     gItemObjectFirstResponsesHundreds4Item6, gItemObjectFirstResponsesHundreds4Item7,
     gItemObjectFirstResponsesHundreds4Item8, gItemObjectFirstResponsesHundreds4Item9,
     gItemObjectFirstResponsesHundreds4Item10, gItemObjectFirstResponsesHundreds4Item11,
     gItemObjectFirstResponsesHundreds4Item12, gItemObjectFirstResponsesHundreds4Item13},
    {gItemObjectFirstResponsesHundreds5Item0, gItemObjectFirstResponsesHundreds5Item1,
     gItemObjectFirstResponsesHundreds5Item2, gItemObjectFirstResponsesHundreds5Item3,
     gItemObjectFirstResponsesHundreds5Item4, gItemObjectFirstResponsesHundreds5Item5,
     gItemObjectFirstResponsesHundreds5Item6, gItemObjectFirstResponsesHundreds5Item7,
     gItemObjectFirstResponsesHundreds5Item8, gItemObjectFirstResponsesHundreds5Item9,
     gItemObjectFirstResponsesHundreds5Item10, gItemObjectFirstResponsesHundreds5Item11,
     gItemObjectFirstResponsesHundreds5Item12, gItemObjectFirstResponsesHundreds5Item13}};
const u8 gItemObjectFirstResponsesHundreds2Item9[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item6[40] = {3, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds4Effect0[40] = {5, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 4, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item4[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0};
const u8 gItemObjectFirstResponsesHundreds3Item9[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item7[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item5[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds0Effect0[20] = {0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 6, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds0Effect3[20] = {0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds5Item3[16] = {3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item3[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item3[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item12[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds3Item8[48] = {3, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
                                                   0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0,
                                                   0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds2Effect0[12] = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds3Effect0[48] = {0xf, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                                               0,   0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 4, 0,
                                               0,   0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds3Effect2[48] = {0xf, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
                                               0,   0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 2, 0, 2, 0,
                                               0,   0, 0, 2, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item12[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds2Item4[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectFirstResponsesHundreds3Item0[48] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item6[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds5Item4[16] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartResponsesHundreds0Effect1[20] = {0xf, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item0[40] = {3, 2, 1, 1, 2, 1, 2, 1, 0, 2, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1,
                                                   2, 2, 1, 2, 1, 1, 0, 0, 2, 0, 2, 0, 1, 1, 1, 0, 1, 1, 0, 0};
const u8 gItemObjectResponsesHundreds4Item4[40] = {3, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
                                                   2, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0};
const u8 gKartFirstResponsesHundreds2Effect2[12] = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds2Item10[12] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gKartFirstResponsesHundreds1Effect3[16] = {5, 1, 0, 3, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds1Item2[16] = {3, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds0Item9[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item12[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds4Item1[40] = {3, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 2,
                                                   2, 2, 2, 2, 2, 2, 0, 0, 2, 0, 2, 0, 2, 2, 2, 0, 2, 2, 0, 0};
const u8 gItemObjectResponsesHundreds2Item3[12] = {3, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0};
const u8 gItemObjectResponsesHundreds4Item13[40] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                    0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0};
const u8 gKartResponsesHundreds5Effect3[16] = {0xf, 0xd, 0xd, 0xc, 0xd, 0xc, 0xc, 0xc, 2, 0, 2, 0, 0, 0, 0, 0};
const u8 gItemObjectResponsesHundreds0Item5[20] = {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const u8 gItemObjectFirstResponsesHundreds4Item13[40] = {3, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
                                                         0, 1, 0, 2, 2, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 2, 2, 0, 0};
const u8 gKartFirstResponsesHundreds2Effect3[12] = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

#pragma thumb on
void InitGroupFollower(GroupFollower *follower, CourseMapRow *row, s32 speed) {
    GroupFollower *followerCopy = follower;
    u32 value = (u32) row;
    u32 speedCopy = speed;
    u32 unused;
    value = *(const u16 *) ((value) + 38u);
    InitGroupFollowerForGroup(followerCopy, value, speedCopy);
}
#pragma thumb off
