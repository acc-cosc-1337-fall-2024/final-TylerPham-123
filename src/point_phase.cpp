//
#include "point_phase.h"

RollOutcome PointPhase::get_outcome(const Roll& roll) const {
    int rolled_value = roll.roll_value();
    if (rolled_value == point) {
        return RollOutcome::point;
    } else if (rolled_value == 7) {
        return RollOutcome::seven_out;
    } else {
        return RollOutcome::nopoint;
    }
}