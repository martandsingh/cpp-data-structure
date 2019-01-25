/*
Author : Martand Singh
Date : 25 Jan 2019
Scope: Single linked list implementation in cpp.
channel : http://www.facebook.com/codemakerz
*/

#include <iostream>
class singlelinklist
{
private:
    struct Node{
    int item;
    Node *next;
    };

    Node* getNewNode(int item){
        Node *newnode = new Node();
        newnode -> item = item;
        newnode -> next = NULL;
    }

    Node *head;
    Node *current;
    int count;

public:
    singlelinklist(): head(NULL), current(head), count(0) {}
    
    void insertNode(){
        int item;
        std::cout << "Enter item: ";
        std::cin >> item;
        if(!head){
            head = getNewNode(item);
            current = head;
        }
        else{
            current -> next = getNewNode(item);
            current = current -> next;
        }
        count++;

    }

    void removeFirstNode(){
        if(head == NULL){
            std::cout << "Nothing to remove.... :(" << std::endl;
        }
        else{
             head = head -> next;
             count--;
        }
    }

    void display(){
        if(head == NULL){
            std::cout << "List is empty :(" << std::endl;
        }
        else{
            Node *sel = head;
            std::cout << std::endl;
            std::cout << "Result: " << std::endl;
            while(sel != NULL){
                std::cout << "|" << sel->item << "|";
              
                sel = sel -> next;
                if(sel != NULL){
                    std::cout << "-->";
                }
            }
            std::cout << std::endl;
        }
    }

    void getCount(){
        std::cout << "Total count: " << count << std::endl;
    }
};

int main(){
     int loop = 1;
    int ch;
    singlelinklist st;
    do
    {
        std::cout << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "|      Operations        |" << std::endl;
        std::cout << "|   -----------------    |" << std::endl;
        std::cout << "|1. Add Node             |" << std::endl;
        std::cout << "|2. Remove First Node    |" << std::endl;
        std::cout << "|3. Display              |" << std::endl;
        std::cout << "|4. Count                |" << std::endl;
        std::cout << "|5. Exit                 |" << std::endl;
        std::cout << "--------------------------" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> ch;
        switch (ch)
        {
            case 1: st.insertNode();
                    break;
            case 2: st.removeFirstNode();
                    break;
            case 3: st.display();
                    break;
            case 4: st.getCount();
                    break;
            case 5: std::cout << "Thank you..." << std::endl;
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