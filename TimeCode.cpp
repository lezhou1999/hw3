
#include"TimeCode.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


#include <iostream>


TimeCode::TimeCode(unsigned int hr, unsigned int min, long long unsigned int sec){

    this->t=ComponentsToSeconds(hr,min,sec);



}
TimeCode::TimeCode(const TimeCode& tc){

    this->t=tc.t;



}





void TimeCode::SetHours(unsigned int hours){
    
    
        unsigned int restTime;
        restTime = this->t-3600*GetHours();
        this->t = restTime+3600*hours;
    
        

    

    

}

void TimeCode::SetMinutes(unsigned int minutes){
     if(minutes>=60){
         throw invalid_argument("the input is invalid, input is:" + minutes);
    }
    else{
        unsigned int restTime;
        restTime= 3600*GetHours()+GetSeconds()+60*minutes;
        this->t=restTime;  
    }
    
        

    
    

}

void TimeCode::SetSeconds(unsigned int seconds){
    if(seconds>=60){
         throw invalid_argument("the input is invalid, input is:" + seconds);
    }
    
   

    else{

        unsigned int restTime;
        restTime= 3600*GetHours()+60*GetMinutes()+seconds;
        this->t=restTime;
    }
    


}


void TimeCode::reset(){

    this->t=0;

    

}

unsigned int TimeCode:: GetHours()const{

    unsigned int hour;
    hour = this->t/3600;
    return hour;

}

unsigned int TimeCode:: GetMinutes()const{

    unsigned int minutes;
    unsigned int hour;
    hour = this->t/3600;
    minutes = (t-(hour*3600))/60;
    return minutes;
    
    
    

}


unsigned int TimeCode::GetSeconds() const{

    unsigned int mins;
    unsigned int hour;
    unsigned int sec;
    hour = this->t/3600;
    mins = (this->t-(hour*3600))/60;
    sec= this->t-(hour*3600+mins*60);
    return sec;


}



void TimeCode::GetComponents (unsigned int& hr, unsigned int& min, unsigned int& sec)const {
    
    hr = this->t/3600;
    min = (this->t-hr*3600)/60;
    sec = this->t-hr*3600-min*60;



}

long long unsigned int TimeCode:: ComponentsToSeconds(unsigned int hr, unsigned int min , unsigned long long int sec){

    long long unsigned int t;
    t = 3600*hr+60*min+sec;
    return t;
    }

string TimeCode::ToString() const{
    string finalOut = "";
    unsigned int mins;
    unsigned int hour;
    unsigned int sec;
    hour = this->t/3600;
    mins = (this->t-(hour*3600))/60;
    sec= this->t-(hour*3600+mins*60);
    std::string hourOut = std::to_string(hour);
    finalOut.append(hourOut+":");
    std::string minsOut = std::to_string(mins);
    finalOut.append(minsOut +":");
    std::string secOut = std::to_string(sec);
    finalOut.append(secOut);

    return finalOut;


}
TimeCode TimeCode::operator+(const TimeCode& other)const{
    
    TimeCode timeAdd;

    timeAdd.t = this->t + other.t;
    return timeAdd;

}

TimeCode TimeCode::operator-(const TimeCode& other)const{
    if (this->t<other.t){
        throw invalid_argument("other is bigger than timecode");

    }
    else{
        TimeCode timeDecrease;

        timeDecrease.t = this->t - other.t;
        return timeDecrease;
    }

    

    
}

TimeCode TimeCode::operator*(double a)const{

    TimeCode timeTimes;

    timeTimes.t = this->t *a;
    return timeTimes;


    
}

TimeCode TimeCode::operator/(double a)const{

    
    TimeCode timeDivede;

    timeDivede.t = this->t /a;
    return timeDivede;
    
}

bool TimeCode::operator == (const TimeCode& other) const{

    if(this->t==other.t){
        return true;
    }
    else{
        return false;
    }


}

bool TimeCode::operator != (const TimeCode& other) const{

    if(this->t!=other.t){
        return true;
    }
    else{
        return false;
    }
    
}

bool TimeCode::operator < (const TimeCode& other) const{

    if(this->t<other.t){
        return true;
    }
    else{
        return false;
    }
    
}
    
bool TimeCode::operator <= (const TimeCode& other) const{

    if(this->t<=other.t){
        return true;
    }
    else{
        return false;
    }
    
}

bool TimeCode::operator > (const TimeCode& other) const{

    if(this->t>other.t){
        return true;
    }
    else{
        return false;
    }
    
}

bool TimeCode::operator >= (const TimeCode& other) const{

    if(this->t>=other.t){
        return true;
    }
    else{
        return false;
    }
    
}