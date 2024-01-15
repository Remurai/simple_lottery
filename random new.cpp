# include <iostream>
# include <cstdlib>
# include <time.h>

int exist(int array1[3],int array2[3]){
	int count=0;
	for (int i=0; i<3; i++){
		for (int x=0; x<3; x++){
			
		if (array1[i]==array2[x]){
			
			count ++;}
		}
	}return count;
}

using namespace std;
int main(){
	char repeat;
	
	do{
		int num[3];
		for (int i=0;i<3;i++){	
			cout << "Enter number " << i+1 <<": ";
			cin >> num[i];
			if(num[i] > 10 && num[i] < 0){
        		cout << "Invalid input! Please key in 1 number at a time."<< endl ;
        		return num[i] ;
			}
		}
		
		srand(time(NULL));
		int random[3]={(rand() % 10),(rand() % 10),(rand() % 10)};
		cout << "The winning numbers are: "<<random[0] << random[1] << random[2] << endl;
		cout<<"You have entered: "<<num[0]<<num[1]<<num[2]<<endl;
		
		if(random[0]==num[0] && random[1]==num[1] && random[2]==num[2]){
			cout << "Congratulations you won RM20,000"<< endl;
			break;
			continue;
		}
		
		int temp;
		for (int i=0;i <3; i++){
			for(int x=1; x<3; x++){
				if(random[i] > random[x]){
					temp = random[i];
					random[i] = random[x];
					random[x] = temp;
				}
				temp = num[i];
				num[i] = num[x];
				num[x] = temp;
			}
	    }
	    
	    int matches = exist(random,num);
	
		if(random[0]==num[0] && random[1]==num[1] && random[2]==num[2]){
			cout << "Congratulations you won RM6,000"<< endl;
			break;
			continue;
		}
	
		if(matches > 0 && matches <= 2){
			cout << "Congratulations you won RM1,000"<< endl;
			break;
			continue;
		}else  cout << "You loss!!!" << endl;
		
		cout << "Press y to try again or q to quit." << endl;
		cin>>repeat;
		
		while(repeat!='q'&& repeat!='y'){
	        cout << "\nInvalid input. ";
	        cout << "Please input y to try again or q to quit. ";
	        cin >>repeat;
	    }
	    
		if (repeat=='q') break;
	
	}while(repeat=='y');
	
	system ("pause");
	return 0; 	
}



