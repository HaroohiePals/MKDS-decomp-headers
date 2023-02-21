#pragma once
#include "oam.h"
#include "scene/scene_statemachine.h"
#include "jnlib/ui/jnLyt.h"

typedef enum
{
    TITLE_SCENE_BUTTON_SINGLE_PLAYER,
    TITLE_SCENE_BUTTON_MULTIPLAYER,
    TITLE_SCENE_BUTTON_NINTENDO_WFC,
    TITLE_SCENE_BUTTON_OPTIONS,
    TITLE_SCENE_BUTTON_RECORDS
} TitleSceneButton;

typedef enum
{
    TITLE_SCENE_STATE_FADE_IN,
    TITLE_SCENE_STATE_BUTTONS_IN,
    TITLE_SCENE_STATE_MAIN,
    TITLE_SCENE_STATE_BUTTONS_OUT,
    TITLE_SCENE_STATE_SELECTED_OUT_EFFECT,
    TITLE_SCENE_STATE_GOTO_SELECTED,
    TITLE_SCENE_STATE_GOTO_NICKNAME
} TitleSceneState;

typedef struct
{
    ssm_t stateMachine;
    ssm_state_t states[7];
    int inactivityCounter; ///< Counts the amount of frames no key was pressed
    u32 introFinished;
    TitleSceneButton selectedButton;
    BOOL selectedBeforeActivation;
    u32 bottomRowLeftRight;
    s16 outEffectOffset;

    u32 introFrame;
    jnui_layout_element_t* layoutElements;
    const jnui_bncl_res_t* layoutBncl;
    const jnui_bnbl_res_t* layoutBnbl;
    const jnui_bnll_res_t* layoutBnll;
    NNSG2dPaletteData* mainPalette;
    NNSG2dCharacterData* mainBgData;
    NNSG2dPaletteData* subPalette;
    NNSG2dCharacterData* subBgData;
    NNSG2dScreenData* mainScreenData;
    NNSG2dScreenData* mainScreenData2;
    NNSG2dScreenData* subScreenData;

    u8 padding[0xC];

    //0xA0
    NNSG2dPaletteData* subObjPalette;
    NNSG2dCharacterData* subObjCharacterData;
    NNSG2dCellDataBank* cellDataBank;

    u32 padding2;

    //0xB0
    oam_buf_t mainOamBuf;
    oam_buf_t subOamBuf;

    u32 field8B8;
} title_state_t;

void title_vblank();
void title_update(scene_manager_t* sceneManager);
void title_init();
void title_finalize();