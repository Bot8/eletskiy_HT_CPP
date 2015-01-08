#include <iostream>

using namespace std;

struct
{
    unsigned onboardVideo: 1;    // 0 - yes, 1 - no
    unsigned formFactor: 1;      // 0 - ATX, 1 - mATX
    unsigned numOfCores: 4;
    unsigned CPUFreq: 16;        // MHz
    unsigned memoryType: 3;      // 0 - DDR, 1 - DDR2, 2 - DRR3
    unsigned memoryCapacity: 16; // Mb
} PC1;

struct
{
    bool onboardVideo;               // 0 - yes, 1 - no
    unsigned int formFactor;         // 0 - ATX, 1 - mATX
    unsigned int numOfCores;
    unsigned int CPUFreq;            // MHz
    unsigned int memoryType: 3;      // 0 - DDR, 1 - DDR2, 2 - DRR3
    unsigned int memoryCapacity: 16; // Mb
} PC2;

int main(){

    PC1.onboardVideo = true;
    PC1.formFactor = 1;
    PC1.numOfCores = 2;
    PC1.CPUFreq = 4000;
    PC1.memoryType = 3;
    PC1.memoryCapacity = 32000;

    cout << "[" << PC1.onboardVideo << "]" << endl;
    cout << "[" << PC1.formFactor << "]" << endl;
    cout << "[" << PC1.numOfCores << "]" << endl;
    cout << "[" << PC1.CPUFreq << "]" << endl;
    cout << "[" << PC1.memoryType << "]" << endl;
    cout << "[" << PC1.memoryCapacity << "]" << endl;

    PC2.onboardVideo = true;
    PC2.formFactor = 1;
    PC2.numOfCores = 2;
    PC2.CPUFreq = 4000;
    PC2.memoryType = 3;
    PC2.memoryCapacity = 32000;

    cout << "[" << PC2.onboardVideo << "]" << endl;
    cout << "[" << PC2.formFactor << "]" << endl;
    cout << "[" << PC2.numOfCores << "]" << endl;
    cout << "[" << PC2.CPUFreq << "]" << endl;
    cout << "[" << PC2.memoryType << "]" << endl;
    cout << "[" << PC2.memoryCapacity << "]" << endl;

    cout << endl << "PC1 size [" << sizeof(PC1) << "]" << endl;
    cout << endl << "PC2 size [" << sizeof(PC2) << "]" << endl;

    return 0;
}