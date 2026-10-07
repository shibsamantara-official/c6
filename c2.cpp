#include <iostream>
using namespace std;

// Base Class 1
class WiFiModule {
public:
    void initializeConnection() {
        cout << "Connecting to Wi-Fi network..." << endl;
    }
};

// Base Class 2
class ZigbeeModule {
public:
    // Overlapping method name
    void initializeConnection() {
        cout << "Connecting to Zigbee mesh network..." << endl;
    }
};

// Derived Class (Multiple Inheritance)
class SmartHub : public WiFiModule, public ZigbeeModule {
public:
    void startHub() {
        cout << "[Starting Smart Hub]" << endl;
        // Resolving ambiguity using scope resolution
        WiFiModule::initializeConnection();
        ZigbeeModule::initializeConnection();
        cout << "Hub integrated successfully.\n" << endl;
    }
};

int main() {
    SmartHub hub;
    hub.startHub();
    return 0;
}