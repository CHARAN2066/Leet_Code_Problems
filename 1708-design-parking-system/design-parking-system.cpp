class ParkingSystem {
public:
    int a,b,c;
    int x=0,y=0,z=0;
    ParkingSystem(int big, int medium, int small) {
        a=big;
        b=medium;
        c=small;
    }
    
    bool addCar(int carType) {
        if(carType==1)
        {
            if(x<a)
            {
                x++;
                return true;
            }
        }

        if(carType==2)
        {
            if(y<b)
            {
                y++;
                return true;
            }
        }

        if(carType==3)
        {
            if(z<c)
            {
                z++;
                return true;
            }
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */