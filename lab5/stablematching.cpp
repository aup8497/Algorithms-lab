#include <iostream>
#include <string.h>

using namespace std;

int match[1000][1000]={0};
int engaged[1000]={0};
int husband[1000];
// int wp[100][100];
	int m[1000][1000],w[1000][1000],wp[1000][1000];



void stableMatching(int m[1000][1000],int wp[1000][1000],int i,int n ){
int j;

	// cout << "inside stable matching man= " << i << endl;

	for(j=0;j<n;j++){

		if(m[i][j]==-1){
		
			continue;
		}
		if( engaged[m[i][j]]==0 ){
			// cout << "inside if with man=" << i << " and engaged[" <<m[i][j] << "] is "<< engaged[m[i][j]]<<endl;
			
			// cout << "came here when man=" << i ;

			match[m[i][j]][i]=1;
			match[i][m[i][j]]=1;
			// cout << " matched with " << m[i][j] << endl;
			
			husband[m[i][j]]=i;
			// cout << " husband of " << m[i][j] << " is " << i<<  endl;
			engaged[m[i][j]]=1;
			// cout << " lady " << m[i][j] << " got engaged" <<  endl;

			m[i][j]=-1;

			break;

		}
		else{

			int ex=husband[m[i][j]];
			// cout << "ex is " << ex <<" but now is " <<i << endl;



			if( wp[m[i][j]][i] < wp[m[i][j]][ex] ){
				// cout << wp[m[i][j]][i] << " < " << wp[m[i][j]][ex]  << endl;
					// cout << "inside else with man=" << i << " and j= "<< j <<  endl;
 
				match[m[i][j]][ex]=0;
				match[ex][m[i][j]]=0;
				match[m[i][j]][i]=1;
				match[i][m[i][j]]=1;
				husband[m[i][j]]=i;
				m[i][j]=-1;

				stableMatching(m,wp,ex,n);
				break;
			}
		}

	}
	// cout << "came out of the function" << endl;

}


int main(){
int i,j,n;

	cout << "enter the number of men or women";
	cin >> n ;


	cout << "enter mens preferneces \n" ;
	for(i=0;i<n;i++){
		cout << i << ": " ;
		for(j=0;j<n;j++){
			cin >> m[i][j];
		}
	}

	cout << "enter women preferneces \n" ;
	for(i=0;i<n;i++){
		cout << i << ": " ;
		// cout << "\nperson "<< i << "preference order ";
		for(j=0;j<n;j++){
			cin >> w[i][j];
		}
	}	

	for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				//this acts like a dictionary
				wp[i][w[i][j]]=j;
			}
		}	

	// for(i=0;i<n;i++){
	// 		for(j=0;j<n;j++){
	// 			//this acts like a dictionary
	// 			cout << wp[i][j] ;
	// 		}cout << endl;
	// 	}	



	cout << "\nstable matching is : " << endl;

	for(int i=0;i<n;i++){
		// cout << "now came for man =" << i << endl;
	stableMatching( m,wp,i,n);
	}

	// for(i=0;i<n;i++){
	// 	for(j=i;j<n;j++){
	// 		if(match[i][j]==1)
	// 			cout << i << '-' << j << endl; 
	// 	}
	// }

	for(j=0;j<n;j++){
		cout << husband[j] << "-" << j << endl;
	}

return 0;
}
 