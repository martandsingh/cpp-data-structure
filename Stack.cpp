
/*
Author : Martand Singh
Date : 25 Jan 2019
Scope: Stack implementation in cpp.
channel : http://www.faceboo.com/codemakerz
*/

#include<iostream>

#define Max 10

class Stack
{
private:
    int items[Max];
    int top;
    int count;
public:
    Stack():top(-1), count(0) {};

    int isFull(){
        if(top == Max - 1)
            return 1;
        else
            return 0;
    }

    int isEmpty(){
        if(top == -1)
            return 1;
        else
            return 0;
    }

    void push(){
        int item;
        std::cout << "Enter the item: ";
        std::cin >> item;
        if(isFull())
        {
            std::cout << "Stack is full." << std::endl;
        }
        else
        {
            top++;
            items[top] = item;
            std::cout << "Item added: " << item << std::endl;    
            count++;
        }
        
    }

    void pop(){
        if(isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
        }
        else
        {
            std::cout << "Item removed: " << items[top] << std::endl;
            top--;
            count--;
        }
    }

    void peak(){
        if(isEmpty()){
            std::cout << "Stack is empty." << std::endl;
        }
        else{
            std::cout << "Peak value: " << items[top] << std::endl;
        }
                
    }

    void display(){
        if(isEmpty())
        {
            std::cout << "Stack is empty... :(" << std::endl;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Result: " << std::endl << std::endl;
            for(int i = top; i >= 0; i--)
            {
                std::cout << "  " << items[i] << std::endl;
                if(i != 0){
                    std::cout << "______" << std::endl;
                }
            }
            
            
        }
        
    }

    void getcount(){
        std::cout << "Total count: " << count << std::endl;
    }

};

int main(){
    int loop = 1;
    int ch;
    Stack st;
    do
    {
        std::cout << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "|      Operations        |" << std::endl;
        std::cout << "|   -----------------    |" << std::endl;
        std::cout << "|1. Push                 |" << std::endl;
        std::cout << "|2. Pop                  |" << std::endl;
        std::cout << "|3. Peak                 |" << std::endl;
        std::cout << "|4. Display              |" << std::endl;
        std::cout << "|5. Count                |" << std::endl;
        std::cout << "|6. Exit                 |" << std::endl;
        std::cout << "--------------------------" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> ch;
        switch (ch)
        {
            case 1: st.push();
                    break;
            case 2: st.pop();
                    break;
            case 3: st.peak();
                    break;
            case 4: st.display();
                    break;
            case 5: st.getcount();
                    break;
            case 6: std::cout << "Thank you..." << std::endl;
                    loop = 0;
                    exit(0);
                    break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
        
    } while (loop);
    
    return 1;
}

