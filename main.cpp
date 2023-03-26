#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <stack>

void flip(char arr[], int i){
    char aux;
    int start = 0;
    while (start < i) {
        aux = arr[start];
        arr[start] = arr[i];
        arr[i] = aux;
        start++;
        i--;
    }
}

bool dfs(std::string curr, std::string end, std::set<std::string>& visited, int max_depth, int& count){
    std::stack<std::pair<std::string, int>> stack;
    stack.push(std::make_pair(curr, 0));

    while(!stack.empty()){
        auto node = stack.top();
        stack.pop();

        curr = node.first;
        int depth = node.second;

        visited.insert(curr);
        count++;

        if (curr == end){
            return true;
        }

        if (depth == max_depth){
            continue;
        }

        for (int i = 1; i < curr.size(); i++){
            std::string next = curr;
            flip(&next[0], i);
            if (visited.count(next) == 0){
                stack.push(std::make_pair(next, depth+1));
            }
        }
    }

    return false;
}

int main(){
    std::string pancake = "abcdefghijk";
    std::cout << "Pancake: ";
    std::cout << pancake << std::endl;
    std::cout << std::endl;
    std::string pancakeEnd = pancake;
    std::random_shuffle(pancake.begin(), pancake.end());
    std::cout << "Pancake desordenado: ";
    std::cout << pancake << std::endl;
    std::cout << std::endl;
    std::set<std::string> visited;
    int count = 0;
    int max_depth = 30; // profundidad máxima de la búsqueda
    bool found = false;
    for(int i = 0; i <= max_depth; i++){
        visited.clear();
        count = 0;
        found = dfs(pancake, pancakeEnd, visited, i, count);
        if(found){
            break;
        }
    }
    std::cout << "Pancake ordenado: ";
    std::cout << pancakeEnd << std::endl;
    std::cout << std::endl;
    if (found){
        std::cout << "Nodos visitados: " << count << std::endl;
    }
    else {
        std::cout << "No se encontro una solucion" << std::endl;
    }
    return 0;
}