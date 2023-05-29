vector<int> v(4, 0);
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        v[1]=big;
        v[2]=medium;
        v[3]=small;
    }
    
    bool addCar(int carType) {
        if(v[carType]){
            v[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */