class Solution{
    bool canReachInTime(vector<int>& dist, double &hour, int speed){
        double time = 0;
        for (int i = 0; i < dist.size() - 1; ++i)
            time += ((dist[i] + speed - 1) / speed);
        
        time += ((double)dist.back()) / speed;
        return time <= hour;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour){
        int N = dist.size();
        if (hour <= (double)(N - 1))
            return -1;
        
        int s = 1, e = 1e7;
        while (s < e){
            int mid = s + (e-s)/2;
            if (canReachInTime(dist, hour, mid))
                e=mid;
            else
                s=mid+1;
        }        
        return e;
    }
};