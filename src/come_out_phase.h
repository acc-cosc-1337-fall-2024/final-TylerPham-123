//
#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h"

class ComeOutPhase : public Phase {
public:
    RollOutcome get_outcome(const Roll& roll) const override;
};

#endif