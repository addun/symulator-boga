//
// Created by adrian on 18/05/17.
//

#ifndef SIMULATOR_OF_GOD_HYSTERESIS_H
#define SIMULATOR_OF_GOD_HYSTERESIS_H


class Hysteresis {

public:
    Hysteresis(bool hysteresis, double upperValue, double *currentValue, double lowerValue);

public:
    enum States {
        UPPER = 1,
        LOWER = 0
    };
    States hysteresis;
    double upperValue;
    double *currentValue;
    double lowerValue;

public:
    bool canChangeState();

    void switchDirection();

    double getUpperValue() const;

    void setUpperValue(double upperValue);

    double getLowerValue() const;

    void setLowerValue(double lowerValue);

    bool isLower();

    bool isUpper();

    void setLower();

    void setUpper();

    void switchStateIfCan();
};


#endif //SIMULATOR_OF_GOD_HYSTERESIS_H
