#pragma once

typedef struct
{
    union
    {
        struct
        {
            u16 mgBalloonInflateFrame;
            u16 mgInventoryBalloonCount;
        };

        struct
        {
            u16 mgShineCount;
        };

        int place;
        int mrCurrentValue;
    };

    int mrTargetValue;
    BOOL ghostAvailable;
} r2d_race_mode_top_hud_state_t;

BOOL r2d_isGhostAvailable(void);
void r2d_initRaceModeTopHud(void);
void r2d_finalizeRaceModeTopHud(void);
void r2d_updateRaceModeTopHud(void);
void r2d_renderRaceModeTopHud(oam_buf_t* oamBuf);