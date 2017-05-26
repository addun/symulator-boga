//
// Created by adrian on 18/05/17.
//

#include "Hysteresis.h"

Hysteresis::Hysteresis(bool hysteresis, double upperValue, double *currentValue, double lowerValue) : upperValue(
        upperValue), currentValue(currentValue), lowerValue(lowerValue) {
    if (hysteresis) {
        this->hysteresis = States::UPPER;
    } else {
        this->hysteresis = States::LOWER;
    }
}

double Hysteresis::getUpperValue() const {
    return upperValue;
}

void Hysteresis::setUpperValue(double upperValue) {
    Hysteresis::upperValue = upperValue;
}

double Hysteresis::getLowerValue() const {
    return lowerValue;
}

void Hysteresis::setLowerValue(double lowerValue) {
    Hysteresis::lowerValue = lowerValue;
}

bool Hysteresis::canChangeState() {
    return *currentValue > upperValue || *currentValue < lowerValue;
}

void Hysteresis::switchDirection() {
    if (isLower()) {
        setUpper();
    } else if (isUpper()) {
        setLower();
    }
}

bool Hysteresis::isLower() {
    return hysteresis == States::LOWER;
}

bool Hysteresis::isUpper() {
    return hysteresis == States::UPPER;
}

void Hysteresis::setLower() {
    hysteresis = States::LOWER;
}

void Hysteresis::setUpper() {
    hysteresis = States::UPPER;
}

void Hysteresis::switchStateIfCan() {
    if (canChangeState()) {
        if (*currentValue > upperValue)
            setUpper();
        else if (*currentValue < lowerValue)
            setLower();

    }
}
