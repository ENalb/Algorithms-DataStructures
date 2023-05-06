#include <iostream>
#include <stack>
#include <string>

void input_text(std::string&);

void selectCommand(std::string&, std::stack<std::string>&, std::stack<std::string>&);

void undo(std::string&, std::stack<std::string>&, std::stack<std::string>&);

void redo(std::string&, std::stack<std::string>&, std::stack<std::string>&);

int main(){
    std::string text;
    input_text(text);
    std::stack<std::string> undo_stack;
    std::stack<std::string> redo_stack;
    undo_stack.push(text);
    redo_stack.push(text);
    selectCommand(text, undo_stack, redo_stack);

    return 0;
}

void input_text(std::string& str){
    std::cout << "Input your text: ";
    std::getline(std::cin, str);
}

void undo(std::string& text, std::stack<std::string>& undo_stack, std::stack<std::string>& redo_stack){
    if(!undo_stack.empty()){
        redo_stack.push(text);
        text = undo_stack.top();
        undo_stack.pop();
        text.erase(text.size()-1);
        std::cout << "Undo: " << text << std::endl;
    }
    else{
        std::cout << "Nothing to undo." << std::endl;
    }
}

void redo(std::string& text, std::stack<std::string>& undo_stack, std::stack<std::string>& redo_stack){
    if(!redo_stack.empty()){
        undo_stack.push(text);
        text = redo_stack.top();
        redo_stack.pop();
        std::cout << "Redo: " << text << std::endl;
    }
    else{
        std::cout << "Nothing to redo." << std::endl;
    }
}

void selectCommand(std::string& text, std::stack<std::string>& undo_stack, std::stack<std::string>& redo_stack){
    std::cout << "Current text: " << text << std::endl;
    int num;
    do {
        std::cout << "Select command: " << std::endl;
        std::cout << "1: Undo" << std::endl;
        std::cout << "2: Redo" << std::endl;
        std::cout << "3: Exit" << std::endl;
        std::cout << "Enter number of command: ";
        std::cin >> num;
        switch(num){
        case 1:
            undo(text, undo_stack, redo_stack);
            if(!undo_stack.empty()) {
                std::cout << "Current text: " << text << std::endl;
                undo_stack.push(text);
            }
            break;
        case 2:
            redo(text, undo_stack, redo_stack);
            if(!redo_stack.empty()) {
                std::cout << "Current text: " << text << std::endl;
                undo_stack.push(text);
            }
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid number" << std::endl;
        }
    } while (num != 3);
}