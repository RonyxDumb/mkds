#include "Main/MapObjects/kart_balloons_kind_descriptor.h"
#include "Main/MapObjects/shine16.h"
#include "Main/Race/standings_balloons.h"
#include "Main/MapObjects/map_object_model_frame.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/MapObjects/balloon.h"
#include "Main/MapObjects/balloon_velocity.h"
#include "Main/MapObjects/while_requested_full_volume_wrapper.h"
#include "Main/MapObjects/trophy.h"
#include "Main/MapObjects/balloon_target.h"
#include "Main/MapObjects/balloon_draw.h"
#include "Main/MapObjects/data_02156000.h"
#include "Main/Kart/code_0208fd8c.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Kart/camera.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Graphics/emitters.h"
#include "Main/Graphics/effects.h"
#include "fx_mtx33.h"
#include "Main/Course/code_02042044.h"
#include "Main/MapObjects/bound.h"
#include "Main/Kart/kart_effects.h"
#include "Main/MapObjects/shine_balloon.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/MapObjects/balloon_park.h"
#include "Main/MapObjects/map_object_park.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Sound/code_0210b760.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/MapObjects/map_object_kind_update_list.h"
#include "Main/System/heap_call.h"
#include "Main/System/heap.h"
#include "Main/MapObjects/shine_battle.h"
#include "code_02147cd8.h"
#include "Main/Sound/sound_source_init.h"
#include "Main/MapObjects/woodbox.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/sphere_collision.h"
#include "Main/Sound/shine16_track_params.h"
#include "Main/MapObjects/data_0217b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/MapObjects/send_obj_shadow.h"
#include "Main/MapObjects/code_020e6b58.h"
#include "Main/MapObjects/data_02167000.h"
#include "Main/MapObjects/data_0217c000.h"
#include "player.h"
#include "code_0212d214.h"
#include "code_021479b4.h"
#include "Main/Item/code_021035ac.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Kart/karts.h"
#include "Main/System/init_after_startup.h"

const MapObjectKindDescriptor gKartBalloonsKindDescriptor = {0,
                                                             {0, 0},
                                                             0x364,
                                                             InitKartBalloons,
                                                             CreateKartBalloonsKindData,
                                                             0,
                                                             0,
                                                             0,
                                                             CreateKartBalloonsUpdateList};

BOOL BalloonKartHitByKartCallback(u16 hitKartIndex, u16 hitByKartIndex) {
    Kart *kart;
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;
    Vec3 balloonPos;
    s32 balloonOrShineCount;

    kart = GetKart(hitKartIndex);
    GetStandingsKartBalloons();
    if (GetBalloonOrShineCount(hitByKartIndex) >= 3 || GetBalloonOrShineCount(hitKartIndex) == 0) {
        kartBalloons = GetStandingsKartBalloons() + hitKartIndex;
        inflatingBalloon = IsKartInflatingBalloon(hitKartIndex) != 0
                               ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)]
                               : 0;
        lastBalloon = GetBalloonOrShineCount(hitKartIndex) != 0
                          ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex) - 1]
                          : 0;
        if (GetBalloonOrShineCount(hitKartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(hitKartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            if (hitKartIndex == gRaceSetup->mEntryIndex) {
                StartBalloonWithoutKart(lastBalloon, NULL);
            } else {
                balloonPos.x = kart->mPos.x;
                balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
                balloonPos.z = kart->mPos.z;
                lastBalloon->mMapObject.mFlags &= ~4;
                lastBalloon->mMapObject.mFlags &= ~2;
                lastBalloon->mMapObject.mFlags &= ~8;
                lastBalloon->mMapObject.mAlpha = 0x1f;
                StartBalloonWithoutKart(lastBalloon, &balloonPos);
            }
            StartSoundFullVolumeWrapper(kart, 0x153);
            if (GetBalloonOrShineCount(hitKartIndex) == 0) {
                EliminateKartAndCheckWinner(hitKartIndex);
            }
            return FALSE;
        }
    } else {
        kartBalloons = GetStandingsKartBalloons() + hitKartIndex;
        inflatingBalloon = IsKartInflatingBalloon(hitKartIndex) != 0
                               ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)]
                               : 0;
        lastBalloon = GetBalloonOrShineCount(hitKartIndex) != 0
                          ? kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex) - 1]
                          : 0;
        if (GetBalloonOrShineCount(hitKartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(hitKartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitKartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(hitKartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            kartBalloons = GetStandingsKartBalloons() + hitByKartIndex;
            balloonOrShineCount = GetBalloonOrShineCount(hitByKartIndex);
            kartBalloons->mBalloons[balloonOrShineCount + 1] =
                kartBalloons->mBalloons[GetBalloonOrShineCount(hitByKartIndex)];
            kartBalloons->mBalloons[GetBalloonOrShineCount(hitByKartIndex)] = lastBalloon;
            AddBalloonOrShineCountAndMoveRank(hitByKartIndex, 1);
            DisableBalloonHorizontalPull(lastBalloon);
            SetBalloonKartIndex(lastBalloon, hitByKartIndex);
            if (GetBalloonOrShineCount(hitByKartIndex) >= 2 && IsKartInflatingBalloon(hitByKartIndex) != 0) {
                kartBalloons->mState = 4;
            }
            SetupKartFollowEffect(StartEffect(0x7a, &kart->mPos), kart->mIndex, 0x20);
            SetupKartFollowEffect(StartEffect(0x7b, &kart->mPos), kart->mIndex, 0x20);
            StartSoundFullVolumeWrapper(GetKart(hitByKartIndex), 0x14f);
            if (GetBalloonOrShineCount(hitKartIndex) == 0) {
                EliminateKartAndCheckWinner(hitKartIndex);
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 BalloonKartsHitEachOtherCallback(u16 firstKartIndex, u16 secondKartIndex) {
    KartBalloons *firstKartBalloons;
    KartBalloons *secondKartBalloons;
    Balloon *firstInflatingBalloon;
    Balloon *firstLastBalloon;
    Balloon *secondInflatingBalloon;
    Balloon *secondLastBalloon;
    SoundStartParams soundStartParams;
    s32 balloonOrShineCount;

    firstKartBalloons = GetStandingsKartBalloons();
    firstKartBalloons += firstKartIndex;
    firstInflatingBalloon = IsKartInflatingBalloon(firstKartIndex) != 0
                                ? firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)]
                                : 0;
    firstLastBalloon = GetBalloonOrShineCount(firstKartIndex) != 0
                           ? firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex) - 1]
                           : 0;
    if (GetBalloonOrShineCount(firstKartIndex) != 0 && firstLastBalloon != NULL) {
        if (IsKartInflatingBalloon(firstKartIndex) != 0 && firstInflatingBalloon != NULL) {
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = firstLastBalloon;
            AddBalloonOrShineCountAndMoveRank(firstKartIndex, -1);
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = firstInflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(firstKartIndex, -1);
        }
    }
    secondKartBalloons = GetStandingsKartBalloons();
    secondKartBalloons += secondKartIndex;
    secondInflatingBalloon = IsKartInflatingBalloon(secondKartIndex) != 0
                                 ? secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)]
                                 : 0;
    secondLastBalloon = GetBalloonOrShineCount(secondKartIndex) != 0
                            ? secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex) - 1]
                            : 0;
    if (GetBalloonOrShineCount(secondKartIndex) != 0 && secondLastBalloon != NULL) {
        if (IsKartInflatingBalloon(secondKartIndex) != 0 && secondInflatingBalloon != NULL) {
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = secondLastBalloon;
            AddBalloonOrShineCountAndMoveRank(secondKartIndex, -1);
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = secondInflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(secondKartIndex, -1);
        }
    }
    if (firstLastBalloon != NULL) {
        secondKartBalloons = GetStandingsKartBalloons();
        secondKartBalloons += secondKartIndex;
        balloonOrShineCount = GetBalloonOrShineCount(secondKartIndex);
        secondKartBalloons->mBalloons[balloonOrShineCount + 1] =
            secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)];
        secondKartBalloons->mBalloons[GetBalloonOrShineCount(secondKartIndex)] = firstLastBalloon;
        AddBalloonOrShineCountAndMoveRank(secondKartIndex, 1);
        DisableBalloonHorizontalPull(firstLastBalloon);
        SetBalloonKartIndex(firstLastBalloon, secondKartIndex);
        if (GetBalloonOrShineCount(secondKartIndex) >= 2 && IsKartInflatingBalloon(secondKartIndex) != 0) {
            secondKartBalloons->mState = 4;
        }
    }
    if (secondLastBalloon != NULL) {
        firstKartBalloons = GetStandingsKartBalloons();
        firstKartBalloons += firstKartIndex;
        balloonOrShineCount = GetBalloonOrShineCount(firstKartIndex);
        firstKartBalloons->mBalloons[balloonOrShineCount + 1] =
            firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)];
        firstKartBalloons->mBalloons[GetBalloonOrShineCount(firstKartIndex)] = secondLastBalloon;
        AddBalloonOrShineCountAndMoveRank(firstKartIndex, 1);
        DisableBalloonHorizontalPull(secondLastBalloon);
        SetBalloonKartIndex(secondLastBalloon, firstKartIndex);
        if (GetBalloonOrShineCount(firstKartIndex) >= 2 && IsKartInflatingBalloon(firstKartIndex) != 0) {
            firstKartBalloons->mState = 4;
        }
    }
    if (firstKartIndex == gRaceSetup->mEntryIndex || secondKartIndex == gRaceSetup->mEntryIndex) {
        soundStartParams.mSoundId = 0x14f;
        soundStartParams.mPositionSource = NULL;
        soundStartParams.mFalloffIndex = 2;
        soundStartParams.mDistanceSquared = GetHorizontalCameraDistanceSquared(NULL);
        StartSoundFromParams(&soundStartParams);
    }
    return 1;
}

BOOL BalloonKartHitCallback(u16 kartIndex, u16 hitByKartIndex) {
    Kart *kart;
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;
    Vec3 balloonPos;

    kartBalloons = GetStandingsKartBalloons() + kartIndex;
    inflatingBalloon =
        IsKartInflatingBalloon(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] : 0;
    lastBalloon =
        GetBalloonOrShineCount(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex) - 1] : 0;
    if (GetBalloonOrShineCount(kartIndex) != 0 && lastBalloon != NULL) {
        if (IsKartInflatingBalloon(kartIndex) != 0 && inflatingBalloon != NULL) {
            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = lastBalloon;
            AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = inflatingBalloon;
        } else {
            AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
        }
    }
    if (lastBalloon != NULL) {
        kart = GetKart(kartIndex);
        GetStandingsKartBalloons();
        if (kartIndex == gRaceSetup->mEntryIndex) {
            StartBalloonWithoutKart(lastBalloon, NULL);
        } else {
            balloonPos.x = kart->mPos.x;
            balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
            balloonPos.z = kart->mPos.z;
            lastBalloon->mMapObject.mFlags &= ~4;
            lastBalloon->mMapObject.mFlags &= ~2;
            lastBalloon->mMapObject.mFlags &= ~8;
            lastBalloon->mMapObject.mAlpha = 0x1f;
            StartBalloonWithoutKart(lastBalloon, &balloonPos);
        }
        StartSoundFullVolumeWrapper(kart, 0x153);
        if (GetBalloonOrShineCount(kartIndex) == 0) {
            EliminateKartAndCheckWinner(kartIndex);
        }
        return TRUE;
    }
    return FALSE;
}

void BalloonKartEliminatedCallback(u16 kartIndex) {
    KartBalloons *kartBalloons;
    Balloon *inflatingBalloon;
    Balloon *lastBalloon;

    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    BalloonKartHitCallback(kartIndex, kartIndex);
    if (GetBalloonOrShineCount(kartIndex) == 0) {
        return;
    }
    do {
        kartBalloons = GetStandingsKartBalloons() + kartIndex;
        inflatingBalloon =
            IsKartInflatingBalloon(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] : 0;
        lastBalloon =
            GetBalloonOrShineCount(kartIndex) != 0 ? kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex) - 1] : 0;
        if (GetBalloonOrShineCount(kartIndex) != 0 && lastBalloon != NULL) {
            if (IsKartInflatingBalloon(kartIndex) != 0 && inflatingBalloon != NULL) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = lastBalloon;
                AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = inflatingBalloon;
            } else {
                AddBalloonOrShineCountAndMoveRank(kartIndex, -1);
            }
        }
        if (lastBalloon != NULL) {
            ParkBalloon(lastBalloon, kartIndex);
        }
    } while (GetBalloonOrShineCount(kartIndex) != 0);
}

void BalloonEndCallback(void) {
    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    ResetBalloons();
}

void BalloonKartOffsetCallback(u16 kartIndex, Vec3 *offset) {
    KartBalloons *kartBalloons;
    Balloon *balloon;
    s32 balloonIndex;
    s32 balloonCount;

    kartBalloons = GetStandingsKartBalloons() + kartIndex;
    if (offset == NULL) {
        return;
    }
    balloonCount = (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0) + GetBalloonOrShineCount(kartIndex);
    balloonIndex = 0;
    if (balloonCount <= 0) {
        return;
    }
    do {
        balloon = kartBalloons->mBalloons[balloonIndex];
        balloon->mMapObject.mPos.x += offset->x;
        balloon->mMapObject.mPos.y += offset->y;
        balloon->mMapObject.mPos.z += offset->z;
        balloonIndex++;
    } while (balloonIndex < balloonCount);
}

// Init of the kind 0x69 object: creates and parks the kind 0x6c balloon objects (0x20 in mode 2, else 4), fills the
// frame indices, offsets and start timer, sets Standings.mKartBalloons and registers the callbacks in Standings (four
// hit callbacks, the kart-eliminated and the end callback). If kind 0x6c already exists it parks itself instead.
void InitKartBalloons(KartBalloonsObject *kartBalloonsObject) {
    RaceSetup *raceSetup;
    s32 kartCount;
    s32 index;
    KartBalloons *kartBalloons;
    s32 balloonIndex;
    s32 rowOffset;
    s32 offset;

    if (CountMapObjectsOfKind(MAP_OBJECT_KIND_BALLOON) == 0) {
        raceSetup = gRaceSetup;
        kartCount = raceSetup->mKartCount;
        if (raceSetup->mMode == MODE_BATTLE) {
            CreateParkedMapObjects(MAP_OBJECT_KIND_BALLOON, 0x20, kartBalloonsObject);
        } else {
            CreateParkedMapObjects(MAP_OBJECT_KIND_BALLOON, 4, kartBalloonsObject);
        }
        for (index = 0; index < kartCount; index++) {
            kartBalloons = &kartBalloonsObject->mKartBalloons[index];
            if (kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[2] != 0) {
                kartBalloons->mBalloonNsbtpFrameIndex = kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[2];
            } else {
                switch (GetCurrentEntry(index)->mPlayer.mTeamIndex) {
                    case 0:
                        kartBalloons->mBalloonNsbtpFrameIndex = 1;
                        break;
                    case 1:
                        kartBalloons->mBalloonNsbtpFrameIndex = 3;
                        break;
                    default:
                        kartBalloons->mBalloonNsbtpFrameIndex = index;
                        break;
                }
            }
        }
        for (index = 0, rowOffset = 0; index < 8; index++, rowOffset -= 0x600) {
            for (balloonIndex = 0, offset = rowOffset; balloonIndex < 8; balloonIndex++, offset += 0xc00) {
                kartBalloonsObject->mBalloonOffsets[index][balloonIndex] = offset;
            }
        }
        if (GetRaceUseChainCameras() != 0) {
            kartBalloonsObject->mStartTimer = 0xffff;
        } else {
            kartBalloonsObject->mStartTimer = 0x3c;
        }
        SetStandingsKartBalloons(kartBalloonsObject->mKartBalloons);
        SetStandingsKartHitByKartCallback((s32(*)(s32, s32)) BalloonKartHitByKartCallback);
        SetStandingsKartsHitEachOtherCallback((void (*)(s32, s32)) BalloonKartsHitEachOtherCallback);
        SetStandingsKartHitCallback(BalloonKartHitCallback);
        SetStandingsKartEliminatedCallback(BalloonKartEliminatedCallback);
        SetStandingsEndCallback(BalloonEndCallback);
        SetStandingsKartOffsetCallback(BalloonKartOffsetCallback);
    } else {
        ParkMapObject(&kartBalloonsObject->mMapObject);
    }
}

// Per-frame step of the kind 0x69 object: after mStartTimer runs out it steps every kart's KartBalloons (makes,
// inflates, holds and deflates its balloons), updates the kart's count and hands each balloon its kart index, target
// position and velocity.
void UpdateKartBalloons(void *mapObjectList, KartBalloonsObject *kartBalloonsObject) {
    Balloon *balloon;
    s32 kartIndex;
    s32 balloonIndex;
    s32 kartCount;
    s32 balloonCount;
    s32 sideOffset;
    s32 swingStep;
    s32 swingPerFrameDecrement;
    Vec3 balloonPos;
    Vec3 addend;
    Vec3 oddBalloonAddend;
    Vec3 *kartVector;

    kartCount = gRaceSetup->mKartCount;
    if (kartBalloonsObject->mStartTimer > 0) {
        kartBalloonsObject->mStartTimer--;
        if (kartBalloonsObject->mStartTimer > 0) {
            return;
        }
        for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
            KartBalloons *kartBalloons = &kartBalloonsObject->mKartBalloons[kartIndex];
            GetKart((u16) kartIndex);
            kartBalloons->mState = 1;
            if (kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[0] != 0 ||
                kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[1] != 0) {
                kartBalloons->mRemainingSpawnCount = kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[0];
                AddBalloonsLeftToMake(kartIndex, kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[0] +
                                                     kartBalloonsObject->mMapObject.mCourseMapRow->mSettings[1]);
            } else {
                kartBalloons->mRemainingSpawnCount = 1;
                AddBalloonsLeftToMake(kartIndex, 5);
            }
        }
        return;
    }
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        Kart *kart;
        KartBalloons *kartBalloons = &kartBalloonsObject->mKartBalloons[kartIndex];
        GetChaseCamera();
        kart = GetKart((u16) kartIndex);
        balloonPos.x = kart->mPos.x;
        balloonPos.y = kart->mPos.y + GetKartBalloonOrShineHeight(kart) - 0xf666;
        balloonPos.z = kart->mPos.z;
        switch (kartBalloons->mState) {
            case 0:
                if (kartBalloons->mSpawnTimer > 0) {
                    kartBalloons->mSpawnTimer--;
                    break;
                }
                if (GetBalloonsLeftToMake(kartIndex) == 0) {
                    break;
                }
                if (GetBalloonOrShineCount(kartIndex) >= 3) {
                    break;
                }
                if (GetKartMicInflateTimer(kartIndex) <= 0 && GetKartSelectKeyInflate(kartIndex) <= 0) {
                    break;
                }
                balloon = StartBalloon(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                if (balloon == NULL) {
                    break;
                }
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = balloon;
                UpdateBalloonInflating(balloon, kartIndex, 0xcd);
                kartBalloons->mState = 2;
                SetKartInflatingBalloon(kartIndex, 1);
                AddBalloonsLeftToMake(kartIndex, -1);
                break;
            case 1:
                if (IsKartInflatingBalloon(kartIndex) != 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex,
                                           0x266);
                    break;
                }
                if (GetBalloonsLeftToMake(kartIndex) != 0 && GetBalloonOrShineCount(kartIndex) < 3) {
                    if (kartBalloons->mRemainingSpawnCount > 0) {
                        balloon = StartBalloon(kartBalloons->mBalloonNsbtpFrameIndex, &balloonPos);
                        if (balloon != NULL) {
                            kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = balloon;
                            UpdateBalloonInflating(balloon, kartIndex, 0x266);
                            SetKartInflatingBalloon(kartIndex, 1);
                            AddBalloonsLeftToMake(kartIndex, -1);
                            kartBalloons->mRemainingSpawnCount--;
                        }
                    }
                } else {
                    kartBalloons->mState = 0;
                }
                break;
            case 2:
                if (GetKartMicInflateTimer(kartIndex) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)];
                UpdateBalloonInflating(balloon, kartIndex, 0xcd);
                if (GetBalloonScaleFactor(balloon) >= 0x800) {
                    kartBalloons->mState = 3;
                }
                break;
            case 3:
                if (GetKartMicInflateTimer(kartIndex) < 0) {
                    kartBalloons->mState = 4;
                    break;
                }
                if (GetKartSelectKeyInflate(kartIndex) > 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex, 0x10);
                } else if (GetKartMicInflateTimer(kartIndex) > 0) {
                    UpdateBalloonInflating(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex, 0x29);
                } else {
                    balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)];
                    UpdateBalloonShrinking(balloon, kartIndex, 0xe);
                    if (GetBalloonScaleFactor(balloon) <= 0x400) {
                        kartBalloons->mState = 4;
                    }
                }
                break;
            case 4:
                UpdateBalloonShrinking(kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)], kartIndex, 0x19a);
                break;
        }
        if (IsKartInflatingBalloon(kartIndex) != 0) {
            balloon = kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)];
            if (GetBalloonScaleFactor(balloon) <= 0) {
                kartBalloons->mBalloons[GetBalloonOrShineCount(kartIndex)] = NULL;
                SetKartInflatingBalloon(kartIndex, 0);
                AddBalloonsLeftToMake(kartIndex, 1);
                kartBalloons->mSpawnTimer = 0;
                kartBalloons->mState = 0;
            } else if (GetBalloonScaleFactor(balloon) >= 0x1000) {
                SetKartInflatingBalloon(kartIndex, 0);
                AddBalloonOrShineCountAndMoveRank(kartIndex, 1);
                if (kartBalloons->mRemainingSpawnCount <= 0) {
                    kartBalloons->mSpawnTimer = 30;
                    kartBalloons->mState = 0;
                }
                StartSoundFullVolumeWrapper(GetKart((u16) kartIndex), 0x152);
            }
        } else if (kartBalloons->mRemainingSpawnCount <= 0) {
            kartBalloons->mState = 0;
        }
        if (kartIndex == gRaceSetup->mEntryIndex) {
            if (GetKartMicInflateTimer(kartIndex) > 0 || GetKartSelectKeyInflate(kartIndex) > 0) {
                swingStep = GetBalloonOrShineCount(kartIndex) >= 3 ? 600 : 300;
                swingPerFrameDecrement = GetBalloonOrShineCount(kartIndex) >= 3 ? 200 : 100;
                kartBalloons->mSwing += kartBalloons->mSwingPerFrame;
                if (kartBalloons->mSwing >= 0) {
                    if (kartBalloons->mSwingPerFrame < 0) {
                        kartBalloons->mSwingPerFrame = -swingStep;
                    } else {
                        kartBalloons->mSwingPerFrame -= swingPerFrameDecrement;
                    }
                } else {
                    if (kartBalloons->mSwingPerFrame >= 0) {
                        kartBalloons->mSwingPerFrame = swingStep;
                    } else {
                        kartBalloons->mSwingPerFrame += swingPerFrameDecrement;
                    }
                }
            } else {
                swingStep = GetBalloonOrShineCount(kartIndex) >= 3 ? 600 : 300;
                if (kartBalloons->mSwing >= 0) {
                    kartBalloons->mSwing = kartBalloons->mSwing < swingStep ? 0 : kartBalloons->mSwing - swingStep;
                } else {
                    kartBalloons->mSwing = kartBalloons->mSwing > -swingStep ? 0 : kartBalloons->mSwing + swingStep;
                }
            }
            balloonCount = GetBalloonOrShineCount(kartIndex) + (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0);
            for (balloonIndex = 0; balloonIndex < balloonCount; balloonIndex++) {
                Balloon *balloon = kartBalloons->mBalloons[balloonIndex];
                sideOffset = kartBalloons->mSwing + kartBalloonsObject->mBalloonOffsets[balloonCount - 1][balloonIndex];
                if (sideOffset != 0) {
                    kartVector = &kart->mUnk_150;
                    addend.x = MUL_FIXED12_NO_ROUND(kartVector->x, sideOffset);
                    addend.y = MUL_FIXED12_NO_ROUND(kartVector->y, sideOffset);
                    addend.z = MUL_FIXED12_NO_ROUND(kartVector->z, sideOffset);
                    AddBalloonVelocity(balloon, &addend);
                }
                if ((balloonIndex & 1) == 1) {
                    kartVector = &kart->mUnk_168;
                    oddBalloonAddend.x = MUL_FIXED12_NO_ROUND(kartVector->x, -0xcd);
                    oddBalloonAddend.y = MUL_FIXED12_NO_ROUND(kartVector->y, -0xcd);
                    oddBalloonAddend.z = MUL_FIXED12_NO_ROUND(kartVector->z, -0xcd);
                    AddBalloonVelocity(balloon, &oddBalloonAddend);
                }
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                SetBalloonKartIndex(balloon, kartIndex);
                SetBalloonDrawCountAndList(balloon, 1, NULL);
                balloon->mMapObject.mFlags &= ~4;
                balloon->mMapObject.mFlags &= ~2;
                balloon->mMapObject.mFlags &= ~8;
                balloon->mMapObject.mAlpha = 0x1f;
            }
        } else {
            balloonCount = GetBalloonOrShineCount(kartIndex) + (IsKartInflatingBalloon(kartIndex) != 0 ? 1 : 0);
            for (balloonIndex = 0; balloonIndex < balloonCount; balloonIndex++) {
                balloon = kartBalloons->mBalloons[balloonIndex];
                SetBalloonTargetPosAndVelocity(balloon, &balloonPos, &kart->mVelocity);
                SetBalloonKartIndex(balloon, kartIndex);
                if (balloonIndex == 0) {
                    SetBalloonDrawCountAndList(balloon, balloonCount, kartBalloons->mBalloons);
                    balloon->mMapObject.mFlags &= ~4;
                    balloon->mMapObject.mFlags &= ~2;
                    balloon->mMapObject.mFlags &= ~8;
                    balloon->mMapObject.mAlpha = 0x1f;
                } else {
                    SetBalloonDrawCountAndList(balloon, 0, NULL);
                    balloon->mMapObject.mFlags |= gBalloonHideFirstFlag;
                    balloon->mMapObject.mFlags |= gBalloonHideSecondFlag;
                    balloon->mMapObject.mFlags |= gBalloonHideThirdFlag;
                }
            }
        }
    }
}

MapObjectKindData *CreateKartBalloonsKindData(void) {
    RaceSetup *raceSetup;
    s32 mode;

    raceSetup = gRaceSetup;
    mode = raceSetup->mMode;
    if (mode == MODE_BATTLE && raceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
        return CreateEmptyMapObjectKindData();
    }
    if (mode != MODE_MISSION_RUN) {
        return 0;
    }
    return CreateEmptyMapObjectKindData();
}

MapObjectList *CreateKartBalloonsUpdateList(void) {
    return CreateMapObjectUpdateList(NULL, UpdateKartBalloons, NULL);
}
