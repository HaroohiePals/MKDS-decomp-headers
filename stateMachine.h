#pragma once

typedef void (*state_machine_init_func_t)(void* userData);
typedef void (*state_machine_state_func_t)(void* userData);

typedef struct
{
    state_machine_init_func_t initFunc;
    state_machine_state_func_t stateFunc;
} state_machine_state_t;

#define SM_STATE(init, update)	{(state_machine_init_func_t)(init), (state_machine_state_func_t)(update)}

typedef struct
{
    const state_machine_state_t* states;
    u32 counter;
    void* userData;
    u16 nrStates;
    u16 curState;
    u16 nextState;
    u16 gotoNextState;
} state_machine_t;

void sm_init(state_machine_t* stateMachine, const state_machine_state_t* states, u16 nrStates, void* userData);
void sm_gotoState(state_machine_t* stateMachine, u16 state);
void sm_execute(state_machine_t* stateMachine);
