/*
Author : Martand Singh
Date : 26 Jan 2019
Scope: doubly linked list implementation.
channel : http://www.facebook.com/codemakerz
*/

#include <iostream>

class DoublyLinkList
{
private:
   struct Node
    {
        int item;
        Node *prev;
        Node *next;
    };
    Node *head = NULL;
    Node *current = head;
    int count;

    Node* getNewNode(int item){
        Node *newnode = new Node();
        newnode -> item = item;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }

public:

   DoublyLinkList():count(0){}
   int isEmpty(){
       return (head == NULL);
   }

   void addNode(int isFirstNode = 0){
       int item;
       std::cout << "Enter item: ";
       std::cin >> item;
       Node *newnode = getNewNode(item);
       if(isEmpty()){
           //std::cout << "Empty list.. :(" << std::endl;
           head = newnode;
           current = head;
       }
       else{
           if(isFirstNode){
               newnode -> next = head;
               head -> prev = newnode;
               head = newnode;
           }
           else
           {
                current -> next = newnode;
                current -> next -> prev = current;
                current = current -> next;
           }
           
       }
       std::cout << "Item added." << std::endl;
       count++;
   }

   void deleteFirstNode(){
       if(isEmpty()){
           std::cout << "Empty list" << std::endl;
       }
       else
       {
           head = head -> next;
           head -> prev = NULL;
       }
       count--;
   }
   
   void deleteLastNode(){
        if(isEmpty()){
           std::cout << "Empty list" << std::endl;
        }
        else
        {
           current = current -> prev;
           current -> next = NULL;
        }
        count--;
   }

   void display(){
       if(isEmpty()){
           std::cout << "Empty list.. :(" << std::endl;
       }
       else{
           Node *temp = head;
           std::cout << std::endl;
           std::cout << "Result: ";
           while(temp != NULL){
               std::cout << temp -> item << "-->" ;
               temp = temp -> next;
           }
           
       }
   }

   void getCount(){
       if(count == 0){
           std::cout << "There is nothing in your list..." << std::endl;
       }
       else
       {
           std::cout << "Item count: " << count <<  std::endl;
       }
       
   }

   void reverse(){
       if(isEmpty()){
           std::cout << "Empty list" << std::endl;
       }
       else{
           std::cout << std::endl;
           std::cout << "Result: " << std::endl;

           Node *temp = current;
           while(temp != NULL){
               std::cout << temp -> item << "->";
               temp = temp -> prev;
           }
           
       }
   }

 
};




int main(){
    DoublyLinkList dll;
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
        std::cout << "|7. Reverse              |" << std::endl;
        std::cout << "|8. Exit                 |" << std::endl;
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
                case 1: dll.addNode();
                        break;
                case 2: dll.addNode(1);
                        break;
                case 3: dll.deleteLastNode();
                        break;
                case 4: dll.deleteFirstNode();
                        break;
                case 5: dll.display();
                        break;
                case 6: dll.getCount();
                        break;
                case 7: dll.reverse();
                        break;
                case 8: std::cout << "Thank you..." << std::endl;
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