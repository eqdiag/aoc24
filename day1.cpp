#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

int listDistance(std::vector<int>& left,std::vector<int>& right){
    std::sort(left.begin(),left.end());
    std::sort(right.begin(),right.end());

    int value = 0;
    for(int i = 0;i < left.size();i++){
        value += std::abs(left[i]-right[i]);
    }
    return value;
}

int main(){

    std::vector<int> l;
    std::vector<int> r;

    std::fstream file;
    file.open("./day1.txt");

    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);

        std::string left;
        if(ss >> left){
            l.push_back(std::stoi(left));
        }
        std::string right;
        if(ss >> right){
            r.push_back(std::stoi(right));
        }
        
    }

    std::cout << listDistance(l,r) << std::endl;

}