/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

#include <ctime>
#include <vector>
#include <algorithm>  
#include<cmath>
#include <tuple>
#include <numeric>



vector<int> create_array(int size){
    
    vector<int> v ;

    for(int i=0;i<size;i++){
        int element = rand()%10001 ;
        v.push_back(element);}
        
    sort(v.begin(), v.end());
    return v ;
}

vector<int> decToBinary(int n){
    
    vector<int> v ;
   
    if (n ==0){
        v.push_back(0);
    }
    int i = 0;
    while (n > 0) {
 
        v.push_back(n % 2);
        n = n / 2;
    }
    reverse(v.begin(), v.end());
    
    return v;
}


int biToDecimal(vector<int> v){
    
    reverse(v.begin(), v.end());

    int i =0;
    int sum = 0;
    for (int j: v){
        sum = sum + j*(pow(2,i));
        i++;}
    return sum;
}
        
std::tuple<vector<vector<int>>, vector<vector<int>>,vector<vector<int>>,vector<int>> calculate(vector<int> v1, vector<int> v2){
    
    vector<vector<int>>bv1;
    vector<vector<int>>bv2;
    
    vector<int> res;
    vector<vector<int>>bres;
    
    for(int i=0;i<v1.size();i++){
        
        vector<int> b1 = decToBinary(v1[i]);
        vector<int> b2 = decToBinary(v2[i]);
        
        int size = max(b1.size(),b2.size());
        
        reverse(b1.begin(), b1.end());
        reverse(b2.begin(), b2.end());
        
        while(b1.size()<size){
            b1.push_back(0);
            
        }
        while(b2.size()<size){
            b2.push_back(0);
            
        }
        
        vector<int> b3;
        int x = 1;
        for(int i=0;i<b1.size();i++){
            if(x>0){
                int b = b1[i]&&b2[i];
                b3.push_back(b);
                x = -1 *x;
                
            }else{
                int b = b1[i]||b2[i];
                b3.push_back(b);
                x = -1 *x;
            }
            }
            
        reverse(b1.begin(), b1.end());
        reverse(b2.begin(), b2.end());
        reverse(b3.begin(), b3.end());

        
        bv1.push_back(b1);
        bv2.push_back(b2);
        bres.push_back(b3); 
        
        int res1= biToDecimal(b3);
        res.push_back(res1);
        }
        

     return  std::make_tuple(bv1,bv2,bres,res);    
    //return  {bv1,bv2,bres,res};


    }
    

   
void closest(vector<int> v){
     float average = accumulate( v.begin(), v.end(), 0.0)/v.size(); 
    
}  
    
int main()
{
    srand(time(0));
    vector<vector<int>>Bi_arr1;
    vector<vector<int>>Bi_arr2;
    vector<vector<int>>Bi_res; 
    vector<int> res;
    
    
    int size ;
    cout<<"insert a positive number: "<<endl;
    cin>>size;
    cout<<endl;
    
    vector<int> arr1 =  create_array(size);
    vector<int> arr2 =  create_array(size);
    tie(Bi_arr1,Bi_arr2,Bi_res,res) = calculate(arr1,arr2);
    
    cout<<"the first array is :"<<endl;
    for(int i:arr1)
    cout<<i<<' ';
    cout<<endl;
    
    cout<<"the second array is :"<<endl;
    for(int i:arr2)
    cout<<i<<' ';
    cout<<endl;
    
    cout<<"the first binary array,the second binary array,binary_result and result array are as the following:"<<endl;
    
    for (vector<int> i: Bi_arr1){
        for(int j:i){
            cout <<j;
        }
        cout<<' ';
    }
    cout<<endl;
    
    for (vector<int> i: Bi_arr2){
        for(int j:i){
            cout <<j;
        }
        cout<<' ';
    }
    cout<<endl;
    
    for (vector<int> i: Bi_res){
        for(int j:i){
            cout <<j;
        }
        cout<<' ';
    }
    cout<<endl;
    
    for (int i: res)
        cout <<i<<' ';
        
    cout<<endl;
    closest(res);     

    return 0;
}

