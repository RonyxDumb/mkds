#include "Main/Sound/sound_mode.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/sound_system.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

// Sets the sound mode to newMode (0 to 5) unless it is already the current one: 0, 1, 3 and 4 stop the sounds, 5 fades
// everything to silence and saves the old mode, and 1 and 2 fade the sequences back in from 5.
void SetSoundMode(SoundModeHolder *modeHolder, u32 newMode) {
    u32 fadeSteps;

    fadeSteps = GetSoundFadeSteps();
    switch (newMode) {
        case SCENE_SOUND_MODE_STOPPED:
            if (modeHolder->mMode != SCENE_SOUND_MODE_STOPPED) {
                StopSoundsOnAllSources(0);
                StopAllPlayingSounds(0);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->mSecondSeqPlayer, 0);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->mSeqPlayer, 0);
                if (modeHolder->mKartStarSeqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(modeHolder->mKartStarSeqPlayer, 0);
                }
                modeHolder->mSoundsEnabled = 0;
                modeHolder->mSeqStartEnabled = 0;
            }
            break;
        case SCENE_SOUND_MODE_SEQUENCES_ONLY:
            if (modeHolder->mMode != SCENE_SOUND_MODE_SEQUENCES_ONLY) {
                StopSoundsOnAllSources(0);
                StopAllPlayingSounds(0);
                if (modeHolder->mMode == SCENE_SOUND_MODE_PAUSED) {
                    fadeSteps = GetSoundFadeSteps();
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->mSeqPlayer, 0x7f, fadeSteps);
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->mSecondSeqPlayer, 0x7f, fadeSteps);
                    if (modeHolder->mKartStarSeqPlayer != NULL) {
                        NNS_SndPlayerMoveVolume(modeHolder->mKartStarSeqPlayer, 0x7f, fadeSteps);
                    }
                }
                modeHolder->mSoundsEnabled = 0;
                modeHolder->mSeqStartEnabled = 1;
            }
            break;
        case SCENE_SOUND_MODE_PLAYING:
            if (modeHolder->mMode != SCENE_SOUND_MODE_PLAYING) {
                if (modeHolder->mMode == SCENE_SOUND_MODE_PAUSED) {
                    u32 fadeStepsNow;

                    fadeStepsNow = GetSoundFadeSteps();
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->mSeqPlayer, 0x7f, fadeStepsNow);
                    NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->mSecondSeqPlayer, 0x7f, fadeStepsNow);
                    if (modeHolder->mKartStarSeqPlayer != NULL) {
                        NNS_SndPlayerMoveVolume(modeHolder->mKartStarSeqPlayer, 0x7f, fadeStepsNow);
                    }
                    StartPlayingSoundsFade(0x7f, fadeSteps);
                }
                modeHolder->mSoundsEnabled = 1;
                modeHolder->mSeqStartEnabled = 1;
            }
            break;
        case SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY:
            if (modeHolder->mMode != SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY) {
                modeHolder->mSoundsEnabled = 0;
                modeHolder->mSeqStartEnabled = 0;
                StopSoundsOnAllSources(5);
                StopAllPlayingSounds(5);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->mSecondSeqPlayer, 5);
            }
            break;
        case SCENE_SOUND_MODE_FADED_OUT:
            if (modeHolder->mMode != SCENE_SOUND_MODE_FADED_OUT) {
                modeHolder->mSoundsEnabled = 0;
                modeHolder->mSeqStartEnabled = 0;
                StopSoundsOnAllSources(fadeSteps);
                StopAllPlayingSounds(fadeSteps);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->mSecondSeqPlayer, fadeSteps);
                NNS_SndPlayerStopSeq(&modeHolder->mScenePlayers->mSeqPlayer, fadeSteps);
                if (modeHolder->mKartStarSeqPlayer != NULL) {
                    NNS_SndPlayerStopSeq(modeHolder->mKartStarSeqPlayer, fadeSteps);
                }
            }
            break;
        case SCENE_SOUND_MODE_PAUSED:
            if (modeHolder->mMode != SCENE_SOUND_MODE_PAUSED) {
                NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->mSeqPlayer, 0, fadeSteps);
                NNS_SndPlayerMoveVolume(&modeHolder->mScenePlayers->mSecondSeqPlayer, 0, fadeSteps);
                if (modeHolder->mKartStarSeqPlayer != NULL) {
                    NNS_SndPlayerMoveVolume(modeHolder->mKartStarSeqPlayer, 0, fadeSteps);
                }
                modeHolder->mSoundsEnabled = 0;
                modeHolder->mSeqStartEnabled = 0;
                StartPlayingSoundsFade(0, fadeSteps);
                modeHolder->mSavedMode = modeHolder->mMode;
            }
            break;
    }
    modeHolder->mMode = newMode;
}
