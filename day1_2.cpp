#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unordered_map>

int simScore(std::vector<int>& left,std::unordered_map<int,size_t>& counts){

    int value = 0;
    for(int i = 0;i < left.size();i++){
        auto iter = counts.find(left[i]);
        if(iter != counts.end())  value += (left[i]*counts[left[i]]);
    }
    return value;
}

int main(){

    std::vector<int> l;
    std::unordered_map<int,size_t> counts;

    std::fstream file;
    file.open("./day1_2.txt");

    std::string line;
    while(std::getline(file,line)){
        std::stringstream ss(line);

        std::string left;
        if(ss >> left){
            l.push_back(std::stoi(left));
        }
        std::string right;
        if(ss >> right){
            int x = std::stoi(right);
            if(counts.find(x) == counts.end()){
                counts[x] = 1;
            }else{
                counts[x]++;
            }
        }
        
    }

    std::cout << simScore(l,counts) << std::endl;

}