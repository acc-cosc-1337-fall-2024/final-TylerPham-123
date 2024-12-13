//
#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase {
public:
    PointPhase(int p) : point(p) {}

    RollOutcome get_outcome(const Roll& roll) const override;

private:
    int point;
};

#endif