#include <iostream>
#include <vector>
#include <array>
#include <limits>




std::vector<std::array<int, 2>> misereChildrenPairs (int red, int blue) {
    std::vector<std::array<int, 2>> childrenPairVector;
    if (blue - 1 >= 0) {
        std::array<int, 2> arr;
        arr[0] = red;                
        arr[1] = blue - 1;
        childrenPairVector.push_back(arr);
    }
    if (red - 1 >= 0) {
        std::array<int, 2> arr;
        arr[0] = red - 1;                
        arr[1] = blue;
        childrenPairVector.push_back(arr);
    }
    if (blue - 2 >= 0) {
        std::array<int, 2> arr;
        arr[0] = red;                
        arr[1] = blue - 2;
        childrenPairVector.push_back(arr);
    }
    if (red - 2 >= 0) {
        std::array<int, 2> arr;
        arr[0] = red - 2;                
        arr[1] = blue;
        childrenPairVector.push_back(arr);
    }
    return childrenPairVector;
}








std::array<int, 2> misereBestMove (int red, int blue, bool currentNodeType, int & parentCentralizedValue) {    

    int centralizedValue;
    if (currentNodeType == 1) {        
        centralizedValue = std::numeric_limits<int>::min();
    } else {        
        centralizedValue = std::numeric_limits<int>::max();
    }

    int returnRed;
    int returnBlue;
    int centro = centralizedValue;


    auto children = misereChildrenPairs(red, blue);

    for (auto i : children) {
        
        int childRed = i[0];
        int childBlue = i[1];

        if (childRed == 0 || childBlue == 0) { 
            if (currentNodeType == 1) {
                if (centralizedValue < (-1)*((childRed * 2) + (childBlue * 3))) {
                    centralizedValue = (-1)*((childRed * 2) + (childBlue * 3));
                    if (centralizedValue >= parentCentralizedValue) {
                        //  Alpha-Beta Pruning Happening Here
                        break;
                    } 
                } 
            } else {
                if (centralizedValue > ((childRed * 2) + (childBlue * 3))) {
                    centralizedValue = ((childRed * 2) + (childBlue * 3));
                    if (centralizedValue <= parentCentralizedValue) {
                        //  Alpha-Beta Pruning Happening Here
                        break;
                    } 
                } 
            }
        } else {
            misereBestMove(childRed, childBlue, !currentNodeType, centralizedValue);
        }

        if (centro != centralizedValue) {
            centro = centralizedValue;
            returnRed = childRed;
            returnBlue = childBlue;
        }
    }

    if (children.size() == 0) {
        if (currentNodeType == 1) {
            int nodeUtilityValue = (-1) * ((red * 2)+(blue * 3));
            if (parentCentralizedValue >= nodeUtilityValue) {
                parentCentralizedValue = nodeUtilityValue;
            }
        } else {
            int nodeUtilityValue = ((red * 2)+(blue * 3));
            if (parentCentralizedValue <= nodeUtilityValue) {
                parentCentralizedValue = nodeUtilityValue;
            }
        }
    } else {
        if (currentNodeType == 1) {
            if (parentCentralizedValue >= centralizedValue) {
                parentCentralizedValue = centralizedValue;
            }
        } else if (currentNodeType == 0) {
            if (parentCentralizedValue <= centralizedValue) {
                parentCentralizedValue = centralizedValue;
            }
        } 
        
    }

    std::array<int,2> returnArray = {returnRed, returnBlue};
    
    return returnArray;

}