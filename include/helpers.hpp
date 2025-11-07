enum BlockMoveTarget {
    LOW_GOAL,
    HIGH_GOAL,
    LONG_GOAL,
    INTAKE
};

void colourSort();

void startScoring();

void stopScoring();

void startIntaking();

void stopIntaking();

void swapScoringTarget();

void setBlockMovementTarget(BlockMoveTarget target);

void bottomRollerMove(int voltage);