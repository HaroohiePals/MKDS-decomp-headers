#pragma once

typedef enum
{
    JG_OBJECT_LAP_COUNT,
    JG_OBJECT_LAP_FINAL,
    JG_OBJECT_REVERSE,
    JG_OBJECT_FLAG,
    JG_OBJECT_NONE
} JgObject;

typedef enum
{
    JG_STATE_IDLE,
    JG_STATE_REVERSE,
    JG_STATE_LAP_COUNT,
    JG_STATE_FLAG,
    JG_STATE_RESPAWNING,
    JG_STATE_VANISH,
    JG_STATE_APPEAR,

    JG_STATE_COUNT
} JgState;

typedef struct
{
    const char* nsbmdName;
    const char* nsbcaName;
    const char* nsbmaName;
} struc_235;

typedef struct
{
    model_t* model;
    anim_manager_t* nsbcaAnim;
    anim_manager_t* nsbmaAnim;
    bbm_model_t* bbmModel;
} struc_236;

void jg_startRespawning();
void jg_finishRespawning();
void jg_20E79C4();