class RideSharingSystem {
public:
    queue<int> driver;
    queue<int> rider;
    map<int,int> rid;
    RideSharingSystem() {
        
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);   
        rid[riderId]=0; 
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty()){
            if(rid[rider.front()]==1){
                rider.pop();
            }
            else{
                break;
            }
        }
        if(driver.empty()||rider.empty())
        return {-1,-1};
        int a=driver.front();
        int b=rider.front();
        driver.pop();
        rider.pop();
        return {a,b};
    }
    
    void cancelRider(int riderId) {
        rid[riderId]=1;   
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */