//
//  main.cpp
//  Understanding
//
//  Created by apurv on 11/11/25.
//

#include <iostream>
#include <map>
using namespace std;
enum VehicleType{
    Small,
    Medium, 
    Large
};

// Vehicle class base class
class Vehicle {
private:
    VehicleType vehicleSize;
    string licensePlate;
    
public:
    void set_vehicle(VehicleType type, string license) {
        vehicleSize = type;
        licensePlate = license;
    }
    void show_data(){
        cout << "Vehicle is " << vehicleSize << " and license no. is " << licensePlate << '\n';
    }
    string get_license(){
        return licensePlate;
    }
    VehicleType get_vehicle_size(){
        return vehicleSize;
    }
};

//Car is children class
class Car: public Vehicle {
public:
    Car(string license) {
        set_vehicle(Medium, license);
    }
};

//Bike is children class
class Bike: public Vehicle {
public:
    Bike(string license) {
        set_vehicle(Small, license);
    }
};

//Truck is children class
class Truck: public Vehicle {
public:
    Truck(string license) {
        set_vehicle(Large, license);
    }
};
class ParkingSlot {
protected:
    int spotNumber;
    Vehicle* vehicle;
    VehicleType size; // Store slot size directly

public:
    ParkingSlot(int spotNumber, VehicleType size)
        : spotNumber(spotNumber), size(size), vehicle(nullptr) {}

    bool isAvailable() const {
        return vehicle == nullptr;
    }

    void occupy(Vehicle* v) {
        if (isAvailable()) {
            vehicle = v;
        } else {
            std::cout << "Spot already occupied by "<< vehicle->get_license() << "\n";
        }
    }

    void vacate() {
        vehicle = nullptr;
    }

    int getSpotNumber() const {
        return spotNumber;
    }

    VehicleType getSize() const {
        return size;
    }
};

// Compact slot just predefines its size
class CompactSpot : public ParkingSlot {
public:
    CompactSpot(int spotNumber) : ParkingSlot(spotNumber, Small) {}
};

class RegularSpot : public ParkingSlot {
public:
    RegularSpot(int spotNumber) : ParkingSlot(spotNumber, Medium) {}
};

class OversizedSpot : public ParkingSlot {
public:
    OversizedSpot(int spotNumber) : ParkingSlot(spotNumber, Small) {}
};

class ParkingManager {
private:
    map<VehicleType, vector<ParkingSlot>> totalSpots;
    map<Vehicle, ParkingSlot> allocatedSpot;
public:
    
};

int main() {
    
    Car C1("UP11BM7237");
    C1.show_data();
    
    Bike B("UP11BM7237"), BB("UP11BM9078");
    CompactSpot spot(89);
    
    spot.occupy(&B);
    spot.occupy(&BB);
    
    return 0;
}
