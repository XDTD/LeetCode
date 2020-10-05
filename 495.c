//16ms,%80

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if(timeSeriesSize==0)
        return 0;
    int res=0,i;
    for(i=0;i<timeSeriesSize-1;i++){
        int tmp=timeSeries[i+1]-timeSeries[i];
        res+=(tmp<duration?tmp:duration);
    }
    res+=duration;
    return res;
}
