 #include<bits/stdc++.h>
using namespace std;

int main(){

    
    unordered_map<int, int> mp;
    
    cout<<mp.size() << " ";             //0
    cout<<mp.bucket_count() << " ";     // 0

    mp.reserve(100);
    printf("\nafter reserve : \n");

    cout<<mp.size()<<" ";                     // 0
    cout<< (mp.bucket_count() >= 100 );  // 1 ( bukket cnt is 100 rsturn truee )

    /*
        Important correction: reserve(100) ka matlab exactly 100 buckets hona nahi hai. Iska matlab hai ki container ko kam se kam 100 elements accommodate karne layak bucket capacity arrange karni hai, current max_load_factor() ko dhyan mein rakhte hue. Actual bucket_count() implementation ke hisaab se 100 se zyada bhi ho sakta hai.
    */

    cout << "\n";

    

    return 0;
}