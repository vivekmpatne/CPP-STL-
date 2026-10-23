#include<bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<int, int> mp = {
        {1, 10}, {2, 20}, {3, 30}
    };

    auto it = mp.find(2);
    mp.erase(it);

    // Yahan erase(it) sirf erased element ka iterator invalidate karta hai. Baaki elements ke iterators valid rehte hain.

    // next prediction 
    printf("\n=======\n");
    unordered_map<int, int> mp2 = {
    {1, 10}, {2, 20}, {3, 30}
    };

    auto it1 = mp2.find(1); // 10
    auto it2 = mp2.find(2); // 20
 
    mp2.erase(it2); // 2->20 gone

    cout << it1->second << " "; // it1->sec =>10
    cout<<it2->second<<" ";  // undefined behavior


    cout << "\n";

    // Next prediction: erase() in a loop
    printf("=======\n");

    unordered_map<int, int> mp3 = {
    {1, 10}, {2, 20}, {3, 30}
    };

    // un-safe => segmentation falult ( core dumped)
    // for (auto it = mp3.begin(); it != mp3.end(); ++it) {
    //     if (it->first == 2) {
    //         mp.erase(it);
    //     }
    // }

    //safe one ( this also not safe )
    // for (auto it = mp3.begin(); it != mp3.end();) {
    //     cout<<"inside loop: "<<it->first<<" "<<it->second<<" \n";
    //     if (it->first == 2) {
    //         it = mp3.erase(it);
    //         cout<<"inside if: "<<it->first<<" "<<it->second<<" \n";
    //     } else {
    //         ++it;
    //         cout<<"inside else: "<<it->first<<" "<<it->second<<" \n";
    //     }
    //     cout <<"size: "<< mp3.size()<<" \n";
    //     //cout<<it->first<<" "<<it->second<<" \n"; // segmentaion flaut here ( Map mein ab sirf key 1 bachi hai. Uske baad iterator mp3.end() par pahunch gaya. )
    // }
    //     cout <<"final size: "<<mp3.size()<<" \n";


    /*
        Maan lo loop key 2 par pahunchta hai.

        Step 1: it key 2 ko point karta hai.

        Step 2: mp.erase(it) key 2 ko delete kar deta hai. Saath mein, it iterator invalid ho jata hai.

        Step 3: Loop ke end par ++it execute hota hai.

        Lekin it invalid hai! Usko increment karna undefined behavior (UB) hai. Tumhare environment mein isse segmentation fault aaya.

        ++it ko it++ karne se fix kyun nahi hua?
        Dono iterator ko increment karte hain. Difference sirf itna hai:
            - ++it: pehle increment, phir updated iterator return.
            - it++: purani iterator value return, phir increment.
        Dono invalid iterator par use karna unsafe hai. Isliye ++it ko it++ se replace karne par problem solve nahi hoti.
    */


    // prediction
    printf("\n=== size ====\n");

    unordered_map<int, int> mp4 = {
    {1, 10}, {2, 20}, {3, 30}, {4, 40}
    };

    for (auto it = mp4.begin(); it != mp4.end();) {
        if (it->first % 2 == 0) {  // 2 and 4 => erase.
            it = mp4.erase(it);
        } else {
            ++it;
        }
    }

    cout << mp4.size()<<" \n";

    // quick prediction 

    printf("\n====\n");

    unordered_map<int, int> mp5 = {
    {1, 10}, {2, 20}
    };

    auto it5 = mp5.begin();
    cout<<it5->first<<" "<<it5->second<<" \n";
    cout << mp5.size()<<" \n";

    while (it5 != mp5.end()) {
        // mp5.end() != mp5.end()  // false after all itration 
        cout<<"before erase: "<<it5->first<<" "<<it5->second<<" \n";
        cout<<" before erase size : " << mp5.size()<<" \n";
        it5 = mp5.erase(it5);
        cout << "After erase, size: " <<mp5.size()<<" \n";
    }

    cout << mp5.size()<<" \n";

    /*
        Ek important distinction : 
            begin() se end() tak iteration karte waqt, end() last element nahi hota. Woh ek special past-the-end iterator hai, jo last element ke baad ki position represent karta hai.
    */



    return 0;
}