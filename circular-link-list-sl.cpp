#include <iostream>


/*
Author : Martand Singh
Date : 26 Jan 2019
Scope: circular linked list implementation using single link list.
channel : http://www.facebook.com/codemakerz
*/

class circularlinkedlist
{
private:
    struct Node
    {
       int item;
       //Node *prev;
       Node *next;
    };
    
    Node *head;
    Node *first = head;
    int count;

    Node* getNewNode(int item){
        Node *newnode = new Node();
        newnode -> item = item;
        newnode -> next = NULL;
        return newnode;
    }
    
public:
    circularlinkedlist(): head(NULL), count(0){}
    
    void addLastNode(){
        int item;
        std::cout << "Enter item: ";
        std::cin >> item;
        Node *newnode = getNewNode(item);
        if(head == NULL){
            head = newnode;
            head -> next = head;
            first = head;
            std::cout <<"1";
        }
        else
        {
            head -> next = newnode;
            newnode ->  next = first;
            head = newnode;
             std::cout <<"2";
        }
        count++;
        
    }

    void addFirstNode(){
        if(!head){
            addLastNode();
        }
        else
        {
            int item;
            std::cout << "Enter item: ";
            std::cin >> item;
            Node *newnode = getNewNode(item);
            newnode -> next = first;
            first = newnode;
            head -> next = first;
        }
        count++;
        
    }

    void deleteFirstNode(){
        if(!head){
            std::cout << "No items.. :(";
        }
        else{
            std::cout << "Item deleted: " << first -> item << std::endl;
            first = first -> next;
            head -> next = first;
        }
        count--;
    }

    void deleteLastNode(){
        if(!head){
            std::cout << "No items :(" << std::endl;
        }
        else{
            Node *temp = first;
            while(temp -> next != head){
                if(temp -> next == head){
                    temp -> next = first;
                    head = temp;
                }
                temp = temp -> next;
            }
            count--;
        }
    }

    void getCount(){
        std::cout << "Total items: " << count << std::endl;

    }
    void display(){
        if(!head){
            std::cout << "No items :-(" << std::endl;
        }
        else{
            std::cout << "Result: " << std::endl;
            Node *temp = first;
            
            for(int i =0; i < count; i++){
                std::cout << temp -> item;
                if(i != count -1){
                    std::cout << " --> ";
                }
               
                
                temp = temp -> next;
            }
            std::cout << "{First Node: " << temp -> item << "}" << std::endl;
            std::cout << std::endl;
            
        }
    }
};


int main(){
    circularlinkedlist dll;
    int loop = 1;
    unsigned int ch;
    do
    {
        std::cout << std::endl;
        std::cout << "--------------------------" << std::endl;
        std::cout << "|      Operations        |" << std::endl;
        std::cout << "|   -----------------    |" << std::endl;
        std::cout << "|1. Add Last Node        |" << std::endl;
        std::cout << "|2. Add First Node       |" << std::endl;
        std::cout << "|3. Remove Last Node     |" << std::endl;
        std::cout << "|4. Remove First Node    |" << std::endl;
        std::cout << "|5. Display              |" << std::endl;
        std::cout << "|6. Count                |" << std::endl;
        std::cout << "|7. Exit                 |" << std::endl;
        std::cout << "--------------------------" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> ch;
        if(ch > 65535){
            std::cout << "Invalid integer.." << std::endl;
        }
        else
        {
             switch (ch)
            {
                case 1: dll.addLastNode();
                        break;
                case 2: dll.addFirstNode();
                        break;
                case 3: dll.deleteLastNode();
                        break;
                case 4: dll.deleteFirstNode();
                        break;
                case 5: dll.display();
                        break;
                case 6: dll.getCount();
                        break;
                case 7: std::cout << "Thank you..." << std::endl;
                        loop = 0;
                        exit(0);
                        break;
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        }
        
    } while (loop);
    return 1;
}