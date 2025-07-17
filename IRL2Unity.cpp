#include <iostream>
#include <cmath>
#include <limits>
#include <string>

struct ImperialWeight {
    double pounds;
    double ounces;
};

struct MetricMass {
    double kilograms;
};

struct Length {
    double meters;
};

struct ImperialLength {
    double feet;
    double inches;
};

struct PhysicsCalc {
    static double PoundsOuncesToKg(double pounds, double ounces) {
        return pounds * 0.45359237 + ounces * 0.0283495231;
    }

    static ImperialWeight KgToPoundsOunces(double kg) {
        double totalPounds = kg / 0.45359237;
        double pounds = floor(totalPounds);
        double ounces = (totalPounds - pounds) * 16.0;
        return { pounds, ounces };
    }

    static double FeetInchesToMeters(double feet, double inches) {
        return feet * 0.3048 + inches * 0.0254;
    }

    static ImperialLength MetersToFeetInches(double meters) {
        double totalFeet = meters / 0.3048;
        double feet = floor(totalFeet);
        double inches = (totalFeet - feet) * 12.0;
        return { feet, inches };
    }

    static double CalculateForce(double massKg, double acceleration) {
        return massKg * acceleration;
    }

    static double KineticEnergy(double massKg, double velocity) {
        return 0.5 * massKg * velocity * velocity;
    }

    static double PotentialEnergy(double massKg, double heightMeters, double gravity = 9.81) {
        return massKg * gravity * heightMeters;
    }

    static double DragForce(double airDensity, double velocity, double dragCoefficient, double area) {
        return 0.5 * airDensity * velocity * velocity * dragCoefficient * area;
    }
};

void ClearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void ShowMenu() {
    std::cout << "=== IRL2Unity ===\n";
    std::cout << "1. Pounds/Ounces to Kilograms\n";
    std::cout << "2. Kilograms to Pounds/Ounces\n";
    std::cout << "3. Feet/Inches to Meters\n";
    std::cout << "4. Meters to Feet/Inches\n";
    std::cout << "5. Calculate Force (N = kg * m/s^2)\n";
    std::cout << "6. Calculate Kinetic Energy (J)\n";
    std::cout << "7. Calculate Potential Energy (J)\n";
    std::cout << "8. Calculate Drag Force (F = 0.5 * p * v^2 * Cd * A)\n";
    std::cout << "0. Exit\n";
    std::cout << "Select option: ";
}

int main() {
    int choice = -1;
    while (choice != 0) {
        ShowMenu();
        if (!(std::cin >> choice)) {
            ClearInput();
            std::cout << "Invalid input, try again.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            double lbs, oz;
            std::cout << "Enter pounds: ";
            std::cin >> lbs;
            std::cout << "Enter ounces: ";
            std::cin >> oz;
            double kg = PhysicsCalc::PoundsOuncesToKg(lbs, oz);
            std::cout << lbs << " lbs " << oz << " oz = " << kg << " kg\n";
            break;
        }
        case 2: {
            double kg;
            std::cout << "Enter kilograms: ";
            std::cin >> kg;
            ImperialWeight iw = PhysicsCalc::KgToPoundsOunces(kg);
            std::cout << kg << " kg = " << iw.pounds << " lbs " << iw.ounces << " oz\n";
            break;
        }
        case 3: {
            double ft, inch;
            std::cout << "Enter feet: ";
            std::cin >> ft;
            std::cout << "Enter inches: ";
            std::cin >> inch;
            double meters = PhysicsCalc::FeetInchesToMeters(ft, inch);
            std::cout << ft << " ft " << inch << " in = " << meters << " m\n";
            break;
        }
        case 4: {
            double meters;
            std::cout << "Enter meters: ";
            std::cin >> meters;
            ImperialLength il = PhysicsCalc::MetersToFeetInches(meters);
            std::cout << meters << " m = " << il.feet << " ft " << il.inches << " in\n";
            break;
        }
        case 5: {
            double mass, accel;
            std::cout << "Enter mass (kg): ";
            std::cin >> mass;
            std::cout << "Enter acceleration (m/s^2): ";
            std::cin >> accel;
            double force = PhysicsCalc::CalculateForce(mass, accel);
            std::cout << "Force = " << force << " N\n";
            break;
        }
        case 6: {
            double mass, velocity;
            std::cout << "Enter mass (kg): ";
            std::cin >> mass;
            std::cout << "Enter velocity (m/s): ";
            std::cin >> velocity;
            double ke = PhysicsCalc::KineticEnergy(mass, velocity);
            std::cout << "Kinetic Energy = " << ke << " J\n";
            break;
        }
        case 7: {
            double mass, height;
            std::cout << "Enter mass (kg): ";
            std::cin >> mass;
            std::cout << "Enter height (m): ";
            std::cin >> height;
            double pe = PhysicsCalc::PotentialEnergy(mass, height);
            std::cout << "Potential Energy = " << pe << " J\n";
            break;
        }
        case 8: {
            double airDensity, velocity, dragCoeff, area;
            std::cout << "Enter air density (kg/m^3): ";
            std::cin >> airDensity;
            std::cout << "Enter velocity (m/s): ";
            std::cin >> velocity;
            std::cout << "Enter drag coefficient (Cd): ";
            std::cin >> dragCoeff;
            std::cout << "Enter cross-sectional area (m^2): ";
            std::cin >> area;
            double drag = PhysicsCalc::DragForce(airDensity, velocity, dragCoeff, area);
            std::cout << "Drag Force = " << drag << " N\n";
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option, try again.\n";
        }
    }
    return 0;
}
