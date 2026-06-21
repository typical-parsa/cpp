#include <iostream>
#include "dynamicArray.h"

using namespace std;

class solution{
    private:
        dynamicArray* inputArray;

        int newArea(int minHeigth, int width){
            return minHeigth * width;
        }

        int minValue(int firstWall, int secondWall){
            if (firstWall < secondWall){
                return firstWall;
            }else if (firstWall > secondWall){
                return secondWall;
            }else{
                return firstWall;
            }
        }

    public:
        solution(){
            this->inputArray = new dynamicArray();
        }

        ~solution(){
            delete this->inputArray;
        }

        void addElement(int value){
            this->inputArray->pushElement(value);
        }

        int findMaxArea(){
            int maxAreaValue = 0;
            int bestLeft = 0;
            int bestRight = 0;
            int leftWall = 0;
            int rightWall = this->inputArray->getSize() - 1;
            while (leftWall < rightWall){
                int minHeight = this->minValue(this->inputArray->atIndex(leftWall), this->inputArray->atIndex(rightWall));
                int area = newArea(minHeight, rightWall - leftWall);
                if (area > maxAreaValue){
                    maxAreaValue = area;
                    bestLeft = leftWall;
                    bestRight = rightWall;
                }
                if (this->inputArray->atIndex(leftWall) < this->inputArray->atIndex(rightWall)){
                    leftWall++;
                }else{
                    rightWall--;
                }
            }
            cout << "Best Walls are at index \nleft : " << bestLeft << "\nright : " << bestRight << "\nwidth : " <<  bestRight - bestLeft << "\narea : " << maxAreaValue << endl; 
            return maxAreaValue;
        }
};

int main(){
    solution sol;
    sol.addElement(1);
    sol.addElement(8);
    sol.addElement(6);
    sol.addElement(2);
    sol.addElement(5);
    sol.addElement(4);
    sol.addElement(8);
    sol.addElement(3);
    sol.addElement(7);
    cout << sol.findMaxArea() << endl;

}