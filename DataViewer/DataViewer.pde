String[] log;
int maxAvg = -2000000;
int minAvg = 2000000;



void LoadFile()
{
    log = loadStrings("log.txt");
}




boolean Checks()
{
    if(!log[0].equals("Version: 1"))
        return false;
    
    return true;
}




void setup()
{
    size(500, 500);
    stroke(0);
    
    LoadFile();
    
    if(!Checks())
        exit();
    
    for(int i = 6; i < log.length; i++)
    {
        maxAvg = max(maxAvg, Integer.valueOf(log[i]));
        minAvg = min(minAvg, Integer.valueOf(log[i]));
    }
    
    minAvg --;
    
    if(minAvg > 0)
        minAvg = 0;
        
    float xStart = 0;
    float yStart = 0;
    float xEnd = 0;
    float yEnd = height / 2;
    
    for(int i = 5; i < log.length - 1; i++)
    {       
        int avgThisGen = Integer.valueOf(log[i]);
        
        xStart = map(i - 6, 0, log.length - 6, 0, width) + 1;
        yStart = height - map(avgThisGen, minAvg, maxAvg, 0, height);
        
        if(i != 5)
            line(xStart, yStart, xEnd, yEnd);
        
        xEnd = xStart;
        yEnd = yStart;
    }
    
    stroke(255, 0, 0);
    line(0, height - map(1, minAvg, maxAvg, 0, height), width, height - map(1, minAvg, maxAvg, 0, height));
}



void draw()
{
    
}
