#include <stdio.h>
#include <iostream>
#include <math.h>

class Electric_Field {
private:
    double *E;

public:
    // Default Constructor
    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }

    // Component constructor
    Electric_Field(double x, double y, double z) {
        E = new double[3]{x, y, z};
    }

    // Destructor
    ~Electric_Field() { delete[] E; }

    // Getters
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }

    // Setters
    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    // Function that calculates the magnitude of the vector
    double calculateMagnitude() {
        return std::sqrt( (E[0] * E[0]) + (E[1] * E[1]) + (E[2] * E[2]) );
    }

    // Calculate the inner product of the vector
    double calculateInnerProduct() {
        return ( (E[0] * E[0]) + (E[1] * E[1]) + (E[2] * E[2]) );
    }
};

class Magnetic_Field {
private:
    double *M;

public:
    // Default Constructor
    Magnetic_Field() {
        M = new double[3]{0.0, 0.0, 0.0};
    }

    // Component constructor
    Magnetic_Field(double x, double y, double z) {
        M = new double[3]{x, y, z};
    }

    // Destructor
    ~Magnetic_Field() { delete[] M; }

    // Getters
    double getX() const { return M[0]; }
    double getY() const { return M[1]; }
    double getZ() const { return M[2]; }

    // Setters
    void setX(double x) { M[0] = x; }
    void setY(double y) { M[1] = y; }
    void setZ(double z) { M[2] = z; }

    // Function that calculates the magnitude of the vector
    double calculateMagnitude() {
        return std::sqrt( (M[0] * M[0]) + (M[1] * M[1]) + (M[2] * M[2]) );
    }

    // Output the unit vector
    void printUnitVector() {
        double mag = calculateMagnitude();
        if (mag == 0.0) {
            std::cout << "<0, 0, 0> (Magnitude is zero, unit vector undefined)";
        } else {
            std::cout << "<" << M[0] / mag << ", " 
                      << M[1] / mag << ", " 
                      << M[2] / mag << ">" ;
        }
    }
};

int main() {
    // 1. Electric Field testing
    Electric_Field E_default;
    Electric_Field E_components(1.0, 2.0, 3.0);

    Electric_Field E_setter;
    E_setter.setX(0.0);
    E_setter.setY(5.0);
    E_setter.setZ(10.0);

    std::cout << "--- Electric Field Results ---" << std::endl;
    std::cout << "default magnitude: " << E_default.calculateMagnitude() << std::endl;
    std::cout << "components magnitude: " << E_components.calculateMagnitude() << std::endl;
    std::cout << "inner product: " << E_components.calculateInnerProduct() << std::endl;
    std::cout << "setter magnitude: " << E_setter.calculateMagnitude() << std::endl;

    // 2. Magnetic Field testing
    Magnetic_Field M_default;
    Magnetic_Field M_components(1.0, 2.0, 3.0);

    Magnetic_Field M_setter;
    M_setter.setX(0.0);
    M_setter.setY(5.0);
    M_setter.setZ(10.0);

    std::cout << "\n--- Magnetic Field Results ---" << std::endl;
    std::cout << "default magnitude: " << M_default.calculateMagnitude() << std::endl;
    std::cout << "components magnitude: " << M_components.calculateMagnitude() << std::endl;
    std::cout << "components unit vector: ";
    M_components.printUnitVector();
    std::cout << "\nsetter magnitude: " << M_setter.calculateMagnitude() << std::endl;
    std::cout << "setter unit vector: ";
    M_setter.printUnitVector();

    return 0;
}