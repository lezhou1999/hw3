#include <ctime> // for time(0)
#include <iostream> // for cin and cout
#include <cmath> // for M_PI and others
#include <vector> // for vectors (duh)
#include <cstdlib> // for random
#include <cassert> // for assert in the tests() function
#include "TimeCode.h" // for timecode's (duh)
#include <math.h>
#include <unistd.h>

using namespace std;




struct DryingSnapShot {
	// This is a struct, it's like an object
	// that doesn't have any methods.
	// You can read more about them in the ZyBook
	// just search for "struct"
	string name;
	time_t startTime;
	TimeCode *timeToDry;
};


long long get_time_remaining(DryingSnapShot dss){
	
	
	
	time_t end = time(0);
	time_t duration = (end - dss.startTime); 
	long long int remainingTime = dss.timeToDry->GetTimeCodeAsSeconds() - duration;
	
	return remainingTime;

	


	
}






string drying_snap_shot_to_string(DryingSnapShot dss){

	string a = " takes ";

	string result = dss.name + a + dss.timeToDry->ToString() + "time remaining ";
	// Replace with your code
	return result;
}


double get_sphere_sa(double rad){
	// replace with your code
	double sphereArea;
	sphereArea= 4*rad*rad*M_PI;
	return sphereArea;
}


TimeCode *compute_time_code(double surfaceArea){
	int intArea = floor(surfaceArea);
	int h = intArea/3600;
	int m = intArea % 3600/60;
	int s = intArea % 60;
	TimeCode *tc =new TimeCode(h,m,s);
	return tc;
}


void tests(){
	// get_time_remaining
	/*
	DryingSnapShot dss;
	dss.startTime = time(0);
	TimeCode tc = TimeCode(0, 0, 7);
	dss.timeToDry = &tc;
	TimeCode ans = get_time_remaining(dss);
	assert(ans >(0,0,6)  && ans < (0,0,8));
	sleep(3);
	TimeCode ans2 = get_time_remaining(dss);
	
	assert(ans2 > (0,0,3) && ans2 < (0,0,5));
	//add more tests here

	*/
	
	
	


	// get_sphere_sa
	cout << "test sphere area:"<<endl;
	double sa = get_sphere_sa(2.0);
	assert (50.2654 < sa && sa < 50.2655);
	cout<<"sphere area test pass"<<endl;
	// add more tests here

	
	// compute_time_code
	cout<< "test computetimecode"<<endl;
	TimeCode *tc2 = compute_time_code(1.0);
	//cout << "tc: " << tc.GetTimeCodeAsSeconds() << endl;
	assert(tc2->GetTimeCodeAsSeconds() == 1);
	delete tc2;
	cout<< "computetc test pass" <<endl;

	


	// add more tests here


	cout << "ALL TESTS PASSED!" << endl;

}


int main(){
	// replace with your code
	//tests();
	
	
	bool runing = true;
	vector<DryingSnapShot> toStore;
	vector<TimeCode*> StoreTimeCode;
	while(runing){
		for(vector<DryingSnapShot>::size_type i=0; i<toStore.size();i++){
			long long int currentTime = get_time_remaining(toStore.at(i));
			//cout<< "currentTime is " << currentTime <<endl;
			
			if(currentTime<=0){

			toStore.erase(toStore.begin()+i);
			

			}
			
	
		}
		char inputChar;
		cout<<"Choose an option: (A)dd, (V)iew Current Items, (Q)uit: "<<endl;
		cin >> inputChar;
		DryingSnapShot newdss;
		newdss.startTime = time(0);
		


		if(inputChar=='a'){
			double inputRad;
			double sphereArea;
			int batchName;
			batchName = rand()%100000;
			cout<<"radius: ";
			cin>> inputRad;
			sphereArea = get_sphere_sa(inputRad);
			newdss.name = "Batch- " + std::to_string(batchName);
			cout << newdss.name;
			newdss.timeToDry = compute_time_code(sphereArea);
			
			cout<<" will dry in:" <<newdss.timeToDry->ToString()<<endl;

			
			toStore.push_back(newdss);
			

		}else if(inputChar == 'q'){
			runing = false;

			for(vector<DryingSnapShot>::size_type i=0; i<toStore.size();i++){
				delete toStore.at(i).timeToDry;
			}


		

		}else if (inputChar == 'v'){

			int count =0;
			
			for(vector<DryingSnapShot>::size_type i=0; i<toStore.size();i++){
				long long int currRemain = get_time_remaining(toStore.at(i));
					unsigned long long int time = floor(currRemain);
					int h = time/3600;
					int m = time % 3600/60;
					int s = time % 60;
					TimeCode tc =TimeCode(h,m,s);

				
				cout<< drying_snap_shot_to_string(toStore.at(i))<<  tc.ToString()  <<endl;
				
				count++;

			}
			cout << count <<"items  being tracked"<<endl;

			
			//long long int remainTime = get_time_remaining(newdss);
		}



	}


	return 0;
}