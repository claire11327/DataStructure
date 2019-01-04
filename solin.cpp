#include <bits/stdc++.h> 
using namespace std; 
int main(){
	int n = 0;
	int Big_ele = 0;
	int Sma_ele = 0;
	cin >> n;


	int array[n][n];
	int count[n];
	int size = 0;


	for (int i = 0; i < n ;i ++){
		for (int j = 0; j < n ;j ++){
			array[i][j] = -1;
		}
		count[i] = -1;
	} 



	for (int i = 0; i < n ;i ++){
		bool rowexists = false;
		bool colexists = false;
		int row,col,val;
		cin >> row >> col >> val;
		cout << row <<" " << col << " " << val<<endl;
		array[row][col] = val;
		array[col][row] = val;
		for(int j = 0; j <= size;j ++){
			if(row == count[j]){
				rowexists = true;
			}
			if(col == count[j]){
				colexists = true;
			}

		}
		if(!rowexists){
			count[size] = row;
			size ++;
		}
		if(!colexists){
			count[size] = col;
			size ++;
		}
	}
	for (int i = 0; i < n ;i ++){
		cout << count[i] << endl;
	}
	cout<< "size = " << size<<endl;



	stack<int> select[size];
	bool done = false;

	while(!done){
		for (int i = 0; i < size ;i ++){
			bool init = false;
			int small = -1;
			int col = -1;
			for (int j = 0; j < n ;j ++){
				if(array[count[i]][j]!= -1){
					if(!init){
						init = true;
						small = array[count[i]][j];
						col = j;
					}
					else if(array[count[i]][j] < small){
						small = array[count[i]][j];
						col = j;
					}
				}
			}

			select[count[i]].push(col);
			array[count[i]][col] = -1;
		}

		for (int i = 0; i < size ;i ++){
			cout <<  select[i].top() << endl;
		}

		for (int i = 0; i < size ;i ++){
			cout << count[i] << endl;
		}
		cout<< "sec size = " << size<<endl;


		for(int i = 0;i < size;i ++){
			for(int j = 0;j < select[i].size(); j++){
				int ver = select[i].top();
				if(select[ver].top() == i && i != 0){
					break;
				}//if end 
				else{
					//move i from count[]
					if(i == 0){
						ver = 0;
					}
					for(int k = 0;k < size;k ++){
						if(count[k] == ver){
							for(int l = k;l <= size;l++){
								count[l] = count[l+1];
								cout << "lala count[" <<l<<"] = " << count[l] <<endl;
							}
							size--;
							break;
						}
					}
				}
			}
		}

	}
