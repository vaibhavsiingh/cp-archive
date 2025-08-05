#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int size;
        cin >> size;
        
        int result = 0;
        for (int i = 0; i < size; i++) {
            int num;
            cin >> num;
            result |= num;  // Perform bitwise OR operation
        }
        
        cout << result << endl;
    }
    
    return 0;
}
